/*********************************************************************************************************
 * Copyright (c) 2007,深圳科陆电子科技股份有限公司
 * All rights reserved.
 *
 * 文件名称：FaCfg.h
 * 摘    要：本文件主要用来宏定义那些在各种终端中不一样的常量
 * 当前版本：1.0
 * 作    者：岑坚宇
 * 完成日期：2007年4月
 *********************************************************************************************************/
#ifndef FACFG_H
#define FACFG_H
#include "syscfg.h"


#define FA_TYPE_D82			1
#define FA_TYPE_C82			2
#define FA_TYPE_K32			3

//终端类型选择
//#define	FA_TYPE				FA_TYPE_K32
#define	FA_TYPE			FA_TYPE_C82
//#define	FA_TYPE			FA_TYPE_D82

//地方版本定义，使用拼音全称
#define VER_STD          0   //标准国网集中器

//1-3 沿用负控定义，目前没有使用
#define VER_GUANGDONG    1   //广东版
#define VER_JIANGXI      2   //江西版
#define VER_CHENGDE      3   //承德版

//以下集中器从4开始使用
//#define VER_HEBEI        4   //河北版
//#define VER_JIBEI        5   //冀北版
#define VER_ZJ			 6   //浙江
//#define VER_HUNAN		7	//湖南

//面向对象测试，正式发布版本需去掉 20161027  CL
//#define GW_OOB_DEBUG_MTR_RATE_CUR_VOL	1

// #define GW_OOB_DEBUG_0x31050700	1
// #define GW_OOB_DEBUG_0x31060600	1
// #define GW_OOB_DEBUG_0x310C0600	1
// #define GW_OOB_DEBUG_0x310D0600	1
// #define GW_OOB_DEBUG_0x310E0600	1
// #define GW_OOB_DEBUG_0x310F0600	1
// #define GW_OOB_DEBUG_0x31050600  1

#define GW_OOB_DEBUG_0x40010201	1	//台体测试软件9月份表地址为TSA,不是OCT-STRING

//#if 0
#ifndef VER_HUNAN
#define GW_OOB_PROTO_UPDATA_20170406	1//20170406勘误更新 浙江试挂按老协议，发货要求新协议
#endif
//#endif



//用于区分国网南网远程模块开关机时序
#define MODULE_FOR_GW	0
#define MODULE_FOR_NW	1

//#define EN_SPECIAL_TRANSFORMER	1
#define EN_CONCENTRATOR			1

#define MTREXC_ADDR_TPYE_TSA	1	//抄表事件中电表地址类型为TSA,用来控制电表地址类型的宏定义

#if FA_TYPE == FA_TYPE_D82
	#define FA_NAME		"CL790D82-45"
	//#define EN_CCT		1	//是否允许集抄功能
	//#define EN_CCT485		1	//是否允许集抄485口
    #define EN_CTRL		1	//是否允许控制功能
	//#define EN_VARCPS		1	//是否允许无功补偿(VAR compensator)功能
#elif FA_TYPE == FA_TYPE_C82
	#define FA_NAME		"CL818C82"
	//#define EN_CCT			1	//是否允许集抄功能
	//#define EN_CCT485		1	//是否允许集抄485口
	//#define EN_CTRL		1	//是否允许控制功能
	//#define EN_VARCPS		1	//是否允许无功补偿(VAR compensator)功能
#else
	#define FA_NAME		"CL818K32"
#endif


#define PRO_698		1
#define PRO_DLMS	1

#define DLMS_863_VER	1//863协议软件版本，对块数据有差别
//#define ENGLISH_DISP	1
#define ETH_RDMTR_INV	5	//使用网络或光纤抄表间隔

#define PN_S_PHASE_SURPROID	7
#define PN_3_PHASE_SURPROID	6

#ifndef SYS_WIN
#define EN_AC			1	//是否允许交采功能

#if FA_TYPE == FA_TYPE_C82

//#define EN_ETHTOGPRS   1   //   是否允许以太网和GPRS切换

#elif FA_TYPE == FA_TYPE_D82

#define EN_ETHTOGPRS   1   //   是否允许以太网和GPRS切换

#endif

#endif

//#define EN_INMTR		1	//是否允许内部DL645
//#define EN_ESAM			1	//是否允许使用加密模块

//#define EN_MTR_UNSUPID	1	//是否支持电表不支持ID的判断
#define EN_SBJC_V2   	   1		//四表集抄功能
#define EN_SBJC_V2_CVTEXTPRO		1

#define MAXPNMASK         0x7F

//逻辑抄表口定义
#define PORT_AC			1	//终端交流采样通信接口
#define PORT_GB485		2	//国标负控485抄表口
//#define PORT_CCT_485	3	//集中器485抄表口	
#define PORT_IN485		4	//内表485口
#define PORT_RJ45		5	//内表485口
#define PORT_CCT_PLC	31	//集中器载波或无线抄表口

#define MAX_CCT_485     4   //最多集抄录485项.
//硬件相关配置
#define YXNUM	2
#define YKNUM	5


//调试输出开关的序号定义
#define  DB_CRITICAL	   0	
#define  DB_DB			   1
#define  DB_LOADCTRL       2
#define  DB_FAPROTO        3
#define  DB_FAFRM     	   4	
#define  DB_POINT          5  
#define  DB_FA             6 
#define  DB_TASK           7
#define  DB_645            8
#define  DB_645FRM         9
#define  DB_OIIF           10
#define  DB_SYS            11
#define  DB_GLOBAL         12
#define  DB_ABB            13
#define  DB_FUJ			   14
#define  DB_EDMI		   15
#define  DB_FS  		   16


#define  DB_VBREAK         17   //电压断相
#define  DB_VMISS          18   //电压缺相
#define  DB_POLAR          19   //电流反极性
#define  DB_IOVER          20   //相电流过负荷
#define  DB_OVLOAD         21   //负荷过载
#define  DB_OVDEC          22   //超合同用电
#define  DB_IUNBAL         23   //三相负荷不平衡
#define  DB_METER_EXC      24   //电表异常类
#define  DB_OVCPS          25   //无功过补欠补类
#define  DB_DIFF           26   //差动
#define  DB_EXC1           27   //异常1
#define  DB_CPS            28   //无功补偿
#define  DB_EXC3           29   //异常3
#define  DB_EXC4           30   //异常4
#define  DB_EXC5           31   //异常5
#define  DB_LANDIS         32
#define  DB_OSTAR          33  //蜀达表
#define  DB_ZHEJ	       34
#define  DB_DLMS	       35	//爱拓利表
#define  DB_DLMS_RJ		   36	//863-DLMS 网络抄表
#define  DB_DLMS_ERR	   37	//863-DLMS 抄表异常
#define	 DB_DLMS_FlOW	   38
#define  DB_HND				DB_DLMS_RJ
#define  DB_WS		       DB_DLMS_ERR	//威盛表
#define  DB_COMPENSATE     DB_DLMS_FlOW   //无功补偿
#define  DB_TASKDB         39	//任务数据库
#define SOCKETS_DEBUG      	46  //以太网和GPRS切换模式
/*
#define PPP_DEBUG          	40
#define ETHARP_DEBUG       	41
#define NETIF_DEBUG        	42
#define PBUF_DEBUG         	43
#define API_LIB_DEBUG      	44
#define API_MSG_DEBUG      	45
#define SOCKETS_DEBUG      	46
#define ICMP_DEBUG         	47
#define INET_DEBUG         	48
#define IP_DEBUG           	49
#define IP_REASS_DEBUG      50
#define RAW_DEBUG           51
#define MEM_DEBUG           52
#define MEMP_DEBUG          53
#define SYS_DEBUG           54
#define TCP_DEBUG           55
#define TCP_INPUT_DEBUG     56
#define TCP_FR_DEBUG        57
#define TCP_RTO_DEBUG       58
#define TCP_REXMIT_DEBUG    59
#define TCP_CWND_DEBUG      60
#define TCP_WND_DEBUG       61
#define TCP_OUTPUT_DEBUG    62
#define TCP_RST_DEBUG       63
#define TCP_QLEN_DEBUG      64
#define UDP_DEBUG           65
#define TCPIP_DEBUG         66
#define PPP_DEBUG           67
#define SLIP_DEBUG          68
#define DHCP_DEBUG          69

#define	 LOG_CRITICAL    80
#define	 LOG_ERR         81
#define	 LOG_NOTICE      82
#define	 LOG_WARNING     83
#define	 LOG_INFO        84
#define	 LOG_DETAIL      85
#define	 LOG_DEBUG       86
*/
#define DB_METER		90

#define DB_HT3A			91		//恒通
#define DB_HL645		91		//华隆
#define DB_AH645		91		//安徽
#define DB_HB645		91		//湖北
#define DB_TJ645		91		//天津
#define DB_DL645V07		91		//07版645协议
#define DB_NMG645		91		//内蒙古645表(带谐波)
#define DB_BJ645		91		//北京97版645表
#define DB_645_Q		8		//97版645的无功表
#define DB_MODBUS		91		//modbus协议
#define DB_SHCMD09		91

#ifdef EN_SBJC_V2
#define DB_Ext645		91		//四表扩展645
#endif

#define DB_DP		 	92		//数据处理
#define DB_MSCHED	 	93		//电表调度
#define DB_CCT	 		94		//集抄
#define DB_CCTRXFRM		95		//集抄接收帧
#define DB_CCTTXFRM		96		//集抄发送帧
#define	DB_MULTITEMP    97		//多通道温度计协议
#define DB_FAPROTO645	97		//内部645
#define	DB_MTRX   	 	98		//抄表高级信息
#define DB_CCT_EXC		99		//集抄事件


#define DB_DISPLAY		100		//显示
#define DB_INMTR		101		//内表
#define DB_CCT_TEST     102     //临时测试用 
#define DB_RJ45_RD      103     //RJ45抄表
#define DB_RJ45_TASK    104     //RJTASK任务数据
#define DB_PRIME_RD     105     //Prime抄表
#define DB_DL69845		106		//698.45协议
#define DB_ESAM			107		//ESAM

//跟上面重复的定义
#define DB_LANDLMS		DB_LANDIS		//兰吉尔DLMS
#define	DB_1107			DB_LANDIS		//山东A1700
#define DB_LANZMC		DB_LANDIS		//兰吉尔ZMC表

//跟上面重复的定义
#define DB_ABB2		DB_ABB		//ABB圆表
#define	DB_EMAIL	DB_ABB		//EMAIL电表
#define DB_COMPENMTR	111		//补抄开关
#define DB_CTRL			112     //控制开关
#ifdef EN_SBJC_V2_CVTEXTPRO	   
#define DB_CVTEXT		113      //接口转换器扩展
#endif
#define DB_CCT_SCH		114		//搜表
#define DB_AC			115		//交采信息


#endif //FACFG_H
