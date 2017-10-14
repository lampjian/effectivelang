/**********************************************************************
 * 版权所有 (C)2016, Zhou Zhaoxiong。
 *
 * 文件名称：PointerTest.c
 * 文件标识：无
 * 内容摘要：演示指针的用法
 * 其它说明：无
 * 当前版本：V1.0
 * 作    者：Zhou Zhaoxiong
 * 完成日期：20160712
 *
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 重定义数据类型
typedef signed   int        INT32;
typedef unsigned int        UINT32;
typedef unsigned char       UINT8;

// 结构体定义
typedef struct
{
	UINT32   iAge;                    // 年龄
	UINT8    szAddr1[100];            // 地址1
	UINT8   *pszAddr2;                // 地址2
	UINT8  **pszAddr3;                // 地址3
} T_PeopleInfo;


/****************************************************************
 * 功能描述: 主函数
 * 输入参数: 无
 * 输出参数: 无
 * 返 回 值: 0-执行完成
 * 其他说明: 无
 * 修改日期       版本号        修改人        修改内容
 * -------------------------------------------------------------
 * 20160712        V1.0     Zhou Zhaoxiong     创建
 ****************************************************************/
INT32 main(void)
{
	T_PeopleInfo tPeopleInfo = {0};

	// 结构体变量赋值
	// 对iAge赋值
	tPeopleInfo.iAge = 10;

	// 对szAddr1赋值
	strncpy(tPeopleInfo.szAddr1, "Chongqing, China!", strlen("Chongqing, China!"));

	// 对pszAddr2赋值
	tPeopleInfo.pszAddr2 = (UINT8 *)malloc(100);
	if (tPeopleInfo.pszAddr2 == NULL)
	{
		return -1;
	}
	strncpy(tPeopleInfo.pszAddr2, "Chengdu, China!", strlen("Chengdu, China!"));

	// 对pszAddr3赋值
	tPeopleInfo.pszAddr3 = (UINT8 *)malloc(100);
	if (tPeopleInfo.pszAddr3 == NULL)
	{
		return -2;
	}
	strncpy(tPeopleInfo.pszAddr3, "Wuhan, China!", strlen("Wuhan, China!"));

	// 打印变量的值
	printf("Age=%d, Addr1=%s, Addr2=%s, Addr3=%s\n", tPeopleInfo.iAge, tPeopleInfo.szAddr1, tPeopleInfo.pszAddr2, tPeopleInfo.pszAddr3);

	return 0;
}
