#pragma once
typedef struct _Teacher
{
	char name[64];
	int age;
	char *p;	//�����ǽ�ʦ��˵����Ϣ��ָ��һƬ�ڴ�ռ䣬Ҳ����Ϊ��
	int plen;		//pָ����ڴ�ռ�ĳ���
}Teacher;
int TeacherEncode(Teacher *pTeacher, unsigned char **out, int *outlen);
int TeacherDecode(unsigned char *indata, int inLen, Teacher **pStruct);
void freeTeacher(Teacher** pTeacher);