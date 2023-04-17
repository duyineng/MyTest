//��Teacher�ṹ����з�װ����װ��TLV��ʽ�����ݣ��Ϳ��Կ�ƽ̨������
//�Զ��õ����ݺ��ٽ��н��룬�Ϳ����õ�ԭ����Teacher�ṹ��

#include"itcast_asn1_der.h"
#include"der_teacher.h"
#include<stdlib.h>

//�Խ�ʦ�ṹ����б���
int TeacherEncode(Teacher *pTeacher, unsigned char **out, int *outlen)
{
	int ret = 0;
	ITCAST_ANYBUF *pTmp = NULL,*pHeadBuf = NULL;
	ITCAST_ANYBUF *pTmpBuf = NULL;	//char*ת����ITCAST_ANYBUF����������
	ITCAST_ANYBUF *pOutData = NULL;
	unsigned char *tmpout = NULL;
	int tmpoutlen = 0;

	/*
	  ��char*���͵�nameת����ITCAST_ANYBUF���ͣ��ⲽ��û�н���TLV��ʽת����Ҳ����û�б���
	  ��Դ����Է��֣�ʵ���Ͼ��ǽ�pTeacher->nameָ����ڴ�ռ䣬��������pTmpBuf->pDataָ���
	  �ڴ�ռ䣬strlen(pTeacher->name)��ֵ����pTmpBuf->dataLen
	*/
	ret = DER_ITCAST_String_To_AnyBuf(&pTmpBuf, pTeacher->name, strlen(pTeacher->name));
	if (ret != 0)
	{
		printf("DER_ITCAST_String_To_AnyBuf error��%d\n", ret);	//Ҳ���Խ�����д����־
		return ret;
	}

	//��name���б���
	ret = DER_ItAsn1_WritePrintableString(pTmpBuf, &pHeadBuf);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pTmpBuf);
		printf("DER_ItAsn1_WritePrintableString error��%d\n", ret);
		return ret;
	}

	DER_ITCAST_FreeQueue(pTmpBuf);	//�ͷ�pHeadBufָ����ڴ�ռ䣬pHeadBuf��ֵ�����ı�

	pTmp = pHeadBuf;

	//��age���б���
	ret = DER_ItAsn1_WriteInteger(pTeacher->age, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteInteger error��%d\n", ret);
		return ret;
	}

	pTmp = pTmp->next;

	//��p���б���
	ret = EncodeChar(pTeacher->p, pTeacher->plen, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("EncodeChar error��%d\n", ret);
		return ret;
	}
	pTmp = pTmp->next;

	//��plen���б���
	ret = DER_ItAsn1_WriteInteger(pTeacher->plen, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteInteger plen error��%d\n", ret);
		return ret;
	}

	//�����ṹ��
	DER_ItAsn1_WriteSequence(pHeadBuf, &pOutData);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteSequence error��%d\n", ret);
		return ret;
	}

	//��������ַ�������ʽ����
	*out = (unsigned char*)malloc(pOutData->pData);	
	if (*out == NULL)
	{
		ret = ITDER_MemoryErr;
		DER_ITCAST_FreeQueue(pOutData);
		printf("malloc(pOutData->pData) error��%d\n", ret);
		return ITDER_MemoryErr;
	}
	memcpy(*out, pOutData->pData, pOutData->dataLen);

	*outlen = pOutData->dataLen;

	DER_ITCAST_FreeQueue(pOutData);

	return ret;
}

int TeacherDecode(unsigned char *indata, int inLen, Teacher **pStruct)
{
	int ret = 0;
	ITCAST_ANYBUF *pTmp = NULL, *pHead = NULL;
	ITCAST_ANYBUF *pOutData = NULL;
	ITCAST_ANYBUF *tmpAnyBuf = NULL;
	Teacher *pStrTeacher = NULL;

	//ת��DER���ģ���unsigned char *ת����ITCAST_ANYBUF
	ret = DER_ITCAST_String_To_AnyBuf(&tmpAnyBuf, indata, inLen);
	if (ret != 0)
	{
		printf("Decode DER_ITCAST_String_To_AnyBuf��%d\n", ret);
		return ret;
	}

	//�����ṹ��
	ret = DER_ItAsn1_ReadSequence(tmpAnyBuf, &pHead);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(tmpAnyBuf);
		printf("Decode DER_ItAsn1_ReadSequence��%d\n", ret);
		return ret;
	}
	DER_ITCAST_FreeQueue(tmpAnyBuf);

	//��Teacher�ṹ��malloc�ռ�
	pStrTeacher = (Teacher*)malloc(sizeof(Teacher));
	if (pStrTeacher == NULL)
	{
		DER_ITCAST_FreeQueue(pHead);
		ret == -1;
		printf("Teacher malloc error:%d\n", ret);
		return ret;
	}
	memset(pStrTeacher, 0, sizeof(Teacher));

	pTmp = pHead;

	//����name
	ret = DER_ItAsn1_ReadPrintableString(pTmp, &pOutData);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadPrintableString name��%d\n", ret);
		return ret;
	}

	memcpy(pStrTeacher->name, pOutData->pData, pOutData->dataLen);
	//Ҳ����strcpy(pStructTeacher->name,pOutData->pData);

	pTmp = pTmp->next;

	//����age
	DER_ItAsn1_ReadInteger(pTmp, &pStrTeacher->age);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadInteger age��%d\n", ret);
		return ret;
	}

	pTmp = pTmp->next;

	//����p
	ret = DER_ItAsn1_ReadPrintableString(pTmp, &pOutData);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadPrintableString p��%d\n", ret);
		return ret;
	}

	//��Teacher�ṹ���е�pָ�뿪�ٿռ�
	//pStrTeacher->p = malloc(pOutData->dataLen + 1);
	//if (pStrTeacher->p == NULL)
	//{
	//	freeTeacher(&pStrTeacher);
	//	DER_ITCAST_FreeQueue(pHead);
	//	ret == -1;
	//	printf("Teacher->p malloc error:%d\n", ret);
	//	return ret;
	//}

	pStrTeacher->p = malloc(pOutData->dataLen);
	if (pStrTeacher->p == NULL)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		ret == -1;
		printf("Teacher->p malloc error:%d\n", ret);
		return ret;
	}

	memcpy(pStrTeacher->p, pOutData->pData, pOutData->dataLen);

	pTmp = pTmp->next;

	//����plen
	DER_ItAsn1_ReadInteger(pTmp, &pStrTeacher->plen);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadInteger plen��%d\n", ret);
		return ret;
	}
	*pStruct = pStrTeacher;
	return 0;
}

void freeTeacher(Teacher** pTeacher)	//Ҳ����void freeTeacher(Teacher* pTeacher)
{
	if (pTeacher == NULL)
		return;

	if (pTeacher != NULL)
	{
		if ((*pTeacher)->p != NULL)
		{
			free((*pTeacher)->p);
			(*pTeacher)->p == NULL;
		}

		free(*pTeacher);
		*pTeacher = NULL;
	}
}