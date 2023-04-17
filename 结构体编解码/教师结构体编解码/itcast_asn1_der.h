#ifndef _ITCAST_MESSAGE_DER_
#define _ITCAST_MESSAGE_DER_

#ifdef __cplusplus
extern "C" {
#endif

#define ITCASTDER_NoErr 0 

//���º궨�壬Ϊ���Ƿ����޸ĺ���ֲ
typedef int					ITCAST_INT ;
typedef unsigned char       ITCAST_UINT8;
typedef unsigned short      ITCAST_UINT16;
typedef unsigned long		ITCAST_UINT32;
typedef signed long         ITCAST_SINT32;

#define  TRUE  1
#define  FALSE 0


#define    ITDER_NoErr                    0	
#define    ITDER_MemoryErr                200
#define	   ITDER_LengthErr                201
#define	   ITDER_LengthNotEqualErr        202
#define	   ITDER_DataRangeErr             203
#define	   ITDER_InvalidTagErr            204



/* 
   The ID's for universal tag numbers 0-31.  Tag number 0 is reserved for
   encoding the end-of-contents value when an indefinite-length encoding
   is used 
   ���ö���Ǻ����ڲ�ʹ�õģ�һ�����ǵ��õ��ˣ������õ�
   */
enum {
        
	    ITCAST_DER_ID_RESERVED,
		ITCAST_DER_ID_BOOLEAN, 
		ITCAST_DER_ID_INTEGER,
		ITCAST_DER_ID_BITSTRING,
		ITCAST_DER_ID_OCTETSTRING,
		ITCAST_DER_ID_NULL,
		ITCAST_DER_ID_OBJECT_IDENTIFIER,
		ITCAST_DER_ID_OBJECT_DESCRIPTOR,
		ITCAST_DER_ID_EXTERNAL,
		ITCAST_DER_ID_REAL,
		ITCAST_DER_ID_ENUMERATED, 
		ITCAST_DER_ID_EMBEDDED_PDV, 
		ITCAST_DER_ID_STRING_UTF8, 
		ITCAST_DER_ID_13,
		ITCAST_DER_ID_14, 
		ITCAST_DER_ID_15, 
		ITCAST_DER_ID_SEQUENCE, 
		ITCAST_DER_ID_SET,
		ITCAST_DER_ID_STRING_NUMERIC, 
		ITCAST_DER_ID_STRING_PRINTABLE, 
		ITCAST_DER_ID_STRING_T61,
		ITCAST_DER_ID_STRING_VIDEOTEX, 
		ITCAST_DER_ID_STRING_IA5, 
		ITCAST_DER_ID_TIME_UTC,
		ITCAST_DER_ID_TIME_GENERALIZED, 
		ITCAST_DER_ID_STRING_GRAPHIC, 
		ITCAST_DER_ID_STRING_ISO646,
		ITCAST_DER_ID_STRING_GENERAL, 
		ITCAST_DER_ID_STRING_UNIVERSAL, 
		ITCAST_DER_ID_29,
		ITCAST_DER_ID_STRING_BMP
		
		};


/* Whether the encoding is constructed or primitive */

#define ITCAST_DER_CONSTRUCTED			    0x20
#define ITCAST_DER_PRIMITIVE			    0x00

/* The encodings for the universal types */
#define ITCAST_DER_UNIVERSAL			    0x00
#define ITCAST_DER_APPLICATION		   	    0x40
#define ITCAST_DER_CONTEXT_SPECIFIC	        0x80
#define ITCAST_DER_PRIVATE				    0xC0

#define ITCAST_DER_RESERVED		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_RESERVED )
#define ITCAST_DER_BOOLEAN			  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BOOLEAN )
#define ITCAST_DER_INTEGER			  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_INTEGER )
#define ITCAST_DER_BITSTRING		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BITSTRING )
#define ITCAST_DER_OCTETSTRING		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OCTETSTRING )
#define ITCAST_DER_NULL			      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_NULL )
#define ITCAST_DER_OBJECT_IDENTIFIER  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OBJECT_IDENTIFIER )
#define ITCAST_DER_OBJECT_DESCRIPTOR  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OBJECT_DESCRIPTOR )
#define ITCAST_DER_EXTERNAL		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_EXTERNAL )
#define ITCAST_DER_REAL			      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_REAL )
#define ITCAST_DER_ENUMERATED		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_ENUMERATED )
#define ITCAST_DER_EMBEDDED_PDV	      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_EMBEDDED_PDV )
#define ITCAST_DER_STRING_UTF8		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_UTF8 )
#define ITCAST_DER_13				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_13 )
#define ITCAST_DER_14				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_14 )
#define ITCAST_DER_15				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_15 )
#define ITCAST_DER_SEQUENCE		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_CONSTRUCTED | ITCAST_DER_ID_SEQUENCE )
#define ITCAST_DER_SET				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_CONSTRUCTED | ITCAST_DER_ID_SET )
#define ITCAST_DER_STRING_NUMERIC	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_NUMERIC )
#define ITCAST_DER_STRING_PRINTABLE   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_PRINTABLE )
#define ITCAST_DER_STRING_T61		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_T61 )
#define ITCAST_DER_STRING_VIDEOTEX	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_VIDEOTEX )
#define ITCAST_DER_STRING_IA5		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_IA5 )
#define ITCAST_DER_TIME_UTC		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_TIME_UTC )
#define ITCAST_DER_TIME_GENERALIZED   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_TIME_GENERALIZED )
#define ITCAST_DER_STRING_GRAPHIC	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_GRAPHIC )
#define ITCAST_DER_STRING_ISO646	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_ISO646 )
#define ITCAST_DER_STRING_GENERAL	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_GENERAL )
#define ITCAST_DER_STRING_UNIVERSAL   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_UNIVERSAL )
#define ITCAST_DER_29				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BER29 )
#define ITCAST_DER_STRING_BMP		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_BMP )


/* Masks to extract information from a tag number */

#define ITCAST_DER_CLASS_MASK			0xC0
#define ITCAST_DER_CONSTRUCTED_MASK	    0x20
#define ITCAST_DER_SHORT_ID_MASK		0x1F
#define ITCAST_DER_FIRST_NOT_ID_MASK    0x7F     //xia
#define ITCAST_DER_FIRST_YES_ID_MASK    0x80     //xia
#define ITCAST_DER_ALL_YES_ID_MASK      0xFF     //xia
/* The maximum size for the short tag number encoding, and the magic value
   which indicates that a long encoding of the number is being used */

#define ITASN1_MAX_SHORT_BER_ID	    30
#define ITASN1_LONG_BER_ID		    0x1F

   
#define		DER_ITCAST_Free(memblock) {if(memblock) {free(memblock); memblock=NULL;}}	//�꺯��

#define DER_ITASN1_LOW_IDENTIFIER(cTag)     (cTag & ITCAST_DER_SHORT_ID_MASK)

//��һ��Ϊ�꣬���漸��ȫ���������Ķ��壬��ʵ���ǱȽϴ�ĺ꺯����
#define  DER_CREATE_LOW_ITCAST_ANYBUF(point) \
	     point = (ITCAST_ANYBUF *)malloc(sizeof(ITCAST_ANYBUF)); \
         if (point==NULL) return 7002; \
		 memset(point,0,sizeof(ITCAST_ANYBUF)); \
         point->dataLen = 0; \
         point->dataType = 0; \
	     point->memoryType = DER_ITASN1_MEMORY_MALLOC; \
	     point->pData = NULL; \
	     point->unusedBits = 0; \
	     point->next = NULL; \
         point->prev = NULL

#define DER_ITASN1_LOW_CREATEUINT8(point,size) \
	    point = malloc(size); \
		if (point==NULL) return 7002; \
        //memset(point,0,size)

#define DER_ITASN1_LOW_CREATEUINT32(point) \
	    point = malloc(sizeof(ITCAST_UINT32)); \
		if (point==NULL) return 7002; \
        memset(point,0,sizeof(ITCAST_UINT32))

#define DER_ITASN1_LOW_CHECKERR(iResult,iErrNumber) \
	    if (iResult == iErrNumber) \
            return iErrNumber
#define DER_DACERT_LOW_FREE_ANYBUF(point) \
	    DER_ITCAST_Free(point->pData); \
        DER_ITCAST_Free(point)
#define DER_ITASN1_MEMORY_STATIC     1
#define DER_ITASN1_MEMORY_MALLOC     2

typedef struct ITCAST_ANYBUF_{
	
    unsigned char 	  *pData;	//ָ��һ����TLV������ָ��TLV�е�V�����п��ܣ����������
    ITCAST_UINT32     dataLen;	//TLV�е�L�����ݵĳ��ȣ�Ҳ����V�Ĵ�С
    
    ITCAST_UINT32     unusedBits;  /* for bit string �����û��*/  
    ITCAST_UINT32     memoryType;	//���û��
    ITCAST_UINT32     dataType;		//TLV�е�T�����ݵ�����
    struct ITCAST_ANYBUF_ *next;    //ָ����һ�����
    struct ITCAST_ANYBUF_ *prev;	//ָ����һ�����
    
}ITCAST_ANYBUF;
 
typedef ITCAST_UINT8     ITASN1_BOOLEAN;
typedef ITCAST_ANYBUF    ITASN1_INTEGER;
typedef ITCAST_ANYBUF    ITASN1_OCTETSTRING;
typedef ITCAST_ANYBUF    ITASN1_BITSTRING;
typedef ITCAST_ANYBUF    ITASN1_PRINTABLESTRING;
/*begin of bmpstring*/
typedef ITCAST_ANYBUF	 ITASN1_BMPSTRING;
/*end of bmpstring*/
typedef ITCAST_ANYBUF    ITASN1_ENUMERATED;
typedef ITCAST_ANYBUF    ITASN1_IA5STRING;
typedef ITCAST_ANYBUF    ITASN1_SEQUENCE;
typedef ITCAST_ANYBUF    ITASN1_SET; 
//typedef time_t       ITASN1_GENERALIZEDTIME;
//typedef time_t       ITASN1_UTCTIME;

/*
  �����ͽ��б��룬����һ�����ͱ���������һ��ITASN1_INTEGER���͵�ָ������ĵ�ַ��
  �ں������ڻ�mallocһƬ�ڴ�ռ䣬�������ָ�����ָ����Ƭ�ڴ�ռ䣬�����Դ�����������ʽ����
  �����ITASN1_INTEGER���͵�ָ���������ָ��ĳ�Ա����p->Data���Ǳ���������ݣ�ֱ�Ӷ��Ƕ������ģ�
  
  ANYBUF���͵��е�pDataָ�����һ��TLV��ʽ�����ݣ�����int���ݱ������д��о�

  ����integer:��������ͱ���
  ����ppDerInteger:��������������һ��ָ���ITASN1_INTEGER���͵�ָ�����
*/
ITCAST_INT
DER_ItAsn1_WriteInteger(ITCAST_UINT32 integer, ITASN1_INTEGER **ppDerInteger);

/*
  �Ա��������ͽ��н���
  ����pDerInteger:�����������ʾ�����������
  ����pInteger:����������Ϊ����֮�󴫳������ݣ����ں��������ȶ������ͱ�����
  �ٰ����ͱ����ĵ�ַ����ȥ����󴫳���ֵ���ǽ�����ԭʼ����
*/
ITCAST_INT
DER_ItAsn1_ReadInteger(ITASN1_INTEGER *pDerInteger, ITCAST_UINT32 *pInteger);

/*
  ��unsigned char *����ת����ITCAST_ANYBUF���ͣ����ǰ��ַ���ת����ITCAST_ANYBUF
  ����pOriginBuf:�����������ȴ���һ��ITCAST_ANYBUF���͵�ָ��ĵ�ַ���õ�ָ��ĵ�ַ�����ܿ���ָ���ָ��
  �����ڲ������ռ䣬���ڴ�ռ�ΪITCAST_ANYBUF�������ݵı������������ָ��ָ����Ƭ�ڴ�ռ䣬����ٴ������ָ��ĵ�ַ���õ�ָ��ĵ�ַ�󣬾���ͨ����ַ�ҵ�ָ�룬
  �ҵ�ָ�룬Ҳ���ҵ���ָ��ָ����ڴ�ռ�
  ����strOrigin�������������ת�����ַ���
  ����strOriginLen��strOrigin�ַ����ĳ��ȣ������ַ������Ҵ��볤�ȣ�����������֪���ַ����Ĵ�С
*/
ITCAST_INT
DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf, unsigned char * strOrigin, int strOriginLen);

/*
  ���ַ������б��룬����һ��ITASN1_PRINTABLESTRING�������ݵ�ָ�룬���������String_To_AnyBuf������������
  ����һ��ָ��ITASN1_PRINTABLESTRING�������ݵ�ָ��
  ����pPrintString:�������������һ��ITASN1_PRINTABLESTRING�������ݵ�ָ�룬ָ��ָ��Ҫ��������� 
  ����ppDerPrintString���������������ں������涨��һ��ITASN1_PRINTABLESTRING����ָ�룬�������ָ��ĵ�ַ��
  �����ڲ���malloc�ռ䣬�������ָ��ָ�������ַ��
  ����һ��ָ��ITASN1_PRINTABLESTRING���͵�ָ�룬ָ��ָ��ľ��Ǳ��������ݣ�
*/
ITCAST_INT
DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);

/*
  ���ַ������н���
  ����pDerPrintString�����������ITASN1_PRINTABLESTRING���͵����ݣ�Ϊ����ǰ�����ݣ�
  �������е�pData��Աָ����ָ����ڴ�ռ��ǿ������ģ���Ϊ��û�н���
  ����ppPrintString������������Ϊ����֮������ݣ�����pData��Աָ��ָ����ڴ�ռ����ܶ�����
*/
ITCAST_INT
DER_ItAsn1_ReadPrintableString(ITASN1_PRINTABLESTRING *pDerPrintString, ITASN1_PRINTABLESTRING **ppPrintString);	

/*
  ֱ�Ӷ��ַ������б��룬���ǽ��ַ���ֱ��ת����TLV�˸�ʽ������Ҫ�ȵ���DER_ITCAST_String_To_AnyBuf���������ַ���ת��
  ����pData��������ַ���
  ����dataLen��pData�ĳ���
  ����outBuf������������ITCAST_ANYBUF���͵����ݣ�����TLV��ʽ������
*/
int EncodeChar(char *pData, int dataLen, ITCAST_ANYBUF **outBuf);

/*
  ���л������ṹ���Ա���������֮�󣬶�һ�����ṹ����б���
  ����pSequence�����������Ϊ�����ͷ���
  ����ppDerSequence�����л�������ݣ�ΪITCAST_ANYBUF����TLV��ʽ
*/
ITCAST_INT
DER_ItAsn1_WriteSequence(ITASN1_SEQUENCE *pSequence, ITCAST_ANYBUF **ppDerSequence);

//�����л�������ݽ��з����л�
ITCAST_INT
DER_ItAsn1_ReadSequence(ITCAST_ANYBUF *pDerSequence, ITASN1_SEQUENCE **ppSequence);

//�ͷſռ䣬����������������ͷŽ��
ITCAST_INT
DER_ITCAST_FreeQueue(ITCAST_ANYBUF *pAnyBuf);


ITCAST_INT
DER_ItAsn1_WriteBitString(ITASN1_BITSTRING *pBitString, ITASN1_BITSTRING **ppDerBitString);

ITCAST_INT
DER_ItAsn1_ReadBitString(ITASN1_BITSTRING *pDerBitString, ITASN1_BITSTRING **ppBitString);

ITCAST_INT
DER_ItAsn1_WriteNull(ITCAST_ANYBUF ** ppDerNull);

ITCAST_INT
DER_ItAsn1_ReadNull(ITCAST_ANYBUF * ppDerNull, ITCAST_UINT8 * pInt);


int WriteNullSequence(ITCAST_ANYBUF **pOutData);

int EncodeUnsignedChar(unsigned char *pData, int dataLen, ITCAST_ANYBUF **outBuf);

int DecodeChar(ITCAST_ANYBUF *inBuf, char **Data, int *pDataLen);

#ifdef __cplusplus
}
#endif

#endif
