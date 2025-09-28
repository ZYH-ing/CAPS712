/***************************************************************************
 * @file     csu39fx10_rstmu.h
 * @version  V1.0.0
 * @author   0531
 * @date     2020-10-09 PM
 * @brief    该文件包含了...
 * 
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 ****************************************************************************
 * @par 头文件
 *       csu39fx10.h \n
 *       cs_common.h \n
 * @attention
 *  硬件平台:	\n
 *  SDK版本：	.0.0
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2018/08/17  <td>1.0      <td>0531	  <td>创建初始版本
 * </table>
 *
 *****************************************************************************/

#ifndef __CSU39FX10_RSTMU_H__
#define __CSU39FX10_RSTMU_H__

// Include external header file.
#include "csu39fx10.h"
#include "cs_common.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup csu39fx10_sdk_chip	csu39fx10_sdk_chip
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib	fwlib 
 * @{
 */

/**
 * @addtogroup csu39fx10_sdk_chip_fwlib_rstmu	rstmu 
 * @{
 */

/** 
 * @addtogroup	rstmu_reg_rstsr	reg: RSTSR 
 * @{
 */
//RSTSR
//EMCF
#define RSTMU_EMCF_REG							RSTSR
#define RSTMU_EMCF_POS							(2)
#define RSTMU_EMCF_BITS							C_REG_BITS1
#define RSTMU_EMCF_RESET						(0x00<< RSTMU_EMCF_POS)
#define RSTMU_EMCF_SET							(0x01<< RSTMU_EMCF_POS)
#define RSTMU_EMCF_CLR							(0x00<< RSTMU_EMCF_POS)
#define RSTMU_EMCF_MASK							(RSTMU_EMCF_BITS<< RSTMU_EMCF_POS)
#define __RSTMU_EMCF_GET()						M_REG_GET(RSTMU_EMCF_REG, RSTMU_EMCF_POS, RSTMU_EMCF_BITS)
#define __RSTMU_EMCF_SET(CLR)					M_REG_SET(RSTMU_EMCF_REG, RSTMU_EMCF_POS, RSTMU_EMCF_BITS, CLR)
#define __RSTMU_EMCF_GET_SHIFT()				M_REG_GET_SHIFT(RSTMU_EMCF_REG, RSTMU_EMCF_POS, RSTMU_EMCF_BITS)
#define __RSTMU_EMCF_SET_SHIFT(POS_CLR)			M_REG_SET_SHIFT(RSTMU_EMCF_REG, RSTMU_EMCF_POS, RSTMU_EMCF_BITS, POS_CLR)

//ILOPF
#define RSTMU_ILOPF_REG							RSTSR
#define RSTMU_ILOPF_POS							(1)
#define RSTMU_ILOPF_BITS						C_REG_BITS1
#define RSTMU_ILOPF_RESET						(0x00<< RSTMU_ILOPF_POS)
#define RSTMU_ILOPF_SET							(0x01<< RSTMU_ILOPF_POS)
#define RSTMU_ILOPF_CLR							(0x00<< RSTMU_ILOPF_POS)
#define RSTMU_ILOPF_MASK						(RSTMU_ILOPF_BITS<< RSTMU_ILOPF_POS)
#define __RSTMU_ILOPF_GET()						M_REG_GET(RSTMU_ILOPF_REG, RSTMU_ILOPF_POS, RSTMU_ILOPF_BITS)
#define __RSTMU_ILOPF_SET(CLR)					M_REG_SET(RSTMU_ILOPF_REG, RSTMU_ILOPF_POS, RSTMU_ILOPF_BITS, CLR)
#define __RSTMU_ILOPF_GET_SHIFT()				M_REG_GET_SHIFT(RSTMU_ILOPF_REG, RSTMU_ILOPF_POS, RSTMU_ILOPF_BITS)
#define __RSTMU_ILOPF_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(RSTMU_ILOPF_REG, RSTMU_ILOPF_POS, RSTMU_ILOPF_BITS, POS_CLR)

//WWDTF
#define RSTMU_WWDTF_REG							RSTSR
#define RSTMU_WWDTF_POS							(0)
#define RSTMU_WWDTF_BITS						C_REG_BITS1
#define RSTMU_WWDTF_RESET						(0x00<< RSTMU_WWDTF_POS)
#define RSTMU_WWDTF_SET							(0x01<< RSTMU_WWDTF_POS)
#define RSTMU_WWDTF_CLR							(0x00<< RSTMU_WWDTF_POS)
#define RSTMU_WWDTF_MASK						(RSTMU_WWDTF_BITS<< RSTMU_WWDTF_POS)
#define __RSTMU_WWDTF_GET()						M_REG_GET(RSTMU_WWDTF_REG, RSTMU_WWDTF_POS, RSTMU_WWDTF_BITS)
#define __RSTMU_WWDTF_SET(CLR)					M_REG_SET(RSTMU_WWDTF_REG, RSTMU_WWDTF_POS, RSTMU_WWDTF_BITS, CLR)
#define __RSTMU_WWDTF_GET_SHIFT()				M_REG_GET_SHIFT(RSTMU_WWDTF_REG, RSTMU_WWDTF_POS, RSTMU_WWDTF_BITS)
#define __RSTMU_WWDTF_SET_SHIFT(POS_CLR)		M_REG_SET_SHIFT(RSTMU_WWDTF_REG, RSTMU_WWDTF_POS, RSTMU_WWDTF_BITS, POS_CLR)
/**@}*/ /*** end of group rstmu_reg_rstsr */

/** 
 * @addtogroup	rstmu_reg_lvdcon	reg: LVDCON 
 * @{
 */
//LVDCON
//LVDEN
#define RSTMU_LVDEN_REG							LVDCON
#define RSTMU_LVDEN_POS							(4)
#define RSTMU_LVDEN_BITS						C_REG_BITS1
#define RSTMU_LVDEN_DIS							(0x00<< RSTMU_LVDEN_POS)
#define RSTMU_LVDEN_EN							(0x01<< RSTMU_LVDEN_POS)
#define RSTMU_LVDEN_MASK						(RSTMU_LVDEN_BITS<< RSTMU_LVDEN_POS)
#define __RSTMU_LVDEN_GET()						M_REG_GET(RSTMU_LVDEN_REG, RSTMU_LVDEN_POS, RSTMU_LVDEN_BITS)
#define __RSTMU_LVDEN_SET(EN)					M_REG_SET(RSTMU_LVDEN_REG, RSTMU_LVDEN_POS, RSTMU_LVDEN_BITS, EN)
#define __RSTMU_LVDEN_GET_SHIFT()				M_REG_GET_SHIFT(RSTMU_LVDEN_REG, RSTMU_LVDEN_POS, RSTMU_LVDEN_BITS)
#define __RSTMU_LVDEN_SET_SHIFT(POS_EN)			M_REG_SET_SHIFT(RSTMU_LVDEN_REG, RSTMU_LVDEN_POS, RSTMU_LVDEN_BITS, POS_EN)

//LVDF- READONLY
#define RSTMU_LVDF_REG							LVDCON
#define RSTMU_LVDF_POS							(3)
#define RSTMU_LVDF_BITS							C_REG_BITS1
#define RSTMU_LVDF_RESET						(0x00<< RSTMU_LVDF_POS)
#define RSTMU_LVDF_SET							(0x01<< RSTMU_LVDF_POS)
#define RSTMU_LVDF_MASK							(RSTMU_LVDF_BITS<< RSTMU_LVDF_POS)
#define __RSTMU_LVDF_GET()						M_REG_GET(RSTMU_LVDF_REG, RSTMU_LVDF_POS, RSTMU_LVDF_BITS)
#define __RSTMU_LVDF_GET_SHIFT()				M_REG_GET_SHIFT(RSTMU_LVDF_REG, RSTMU_LVDF_POS, RSTMU_LVDF_BITS)
/**@}*/ /*** end of group rstmu_reg_lvdcon */
/*******************************************************************************/




/******************************** dividing line ********************************/
/** 
 * @addtogroup rstmu_api	api
 * @{
 */
/** 
 * @name rstmu_api
 * @{
 */

/**
 * @brief 	<b>Description:</b> low voltage detection module enable.
 * @details <b>Function prototype:</b> void rstmu_lvd_enable(bool _enable);
 * @param[in]  bool _enable  true-> enable, false-> disable.
 * @param[out] null .
 * 
 * @return  null
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			rstmu_lvd_enable(true);
 *		}
 * @endcode
 */
void rstmu_lvd_enable(bool _enable);

/**
 * @brief 	<b>Description:</b> read the low voltage flag status.
 * @details <b>Function prototype:</b> bool rstmu_get_lvd(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  bool ststus 	true-> low voltage, false-> normal
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool status;
 * 			status= rstmu_get_lvd();
 *		}
 * @endcode
 */
bool rstmu_get_lvd(void);

/**
 * @brief 	<b>Description:</b> read the emc reset flag status.
 * @details <b>Function prototype:</b> bool rstmu_get_emcreset(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  bool ststus 	true-> emc reset, false-> normal
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool status;
 * 			status= rstmu_get_emcreset();
 *		}
 * @endcode
 */
bool rstmu_get_emcreset(void);

/**
 * @brief 	<b>Description:</b> read the illegal instruction reset flag status.
 * @details <b>Function prototype:</b> bool rstmu_get_ilopreset(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  bool ststus 	true-> illegal instruction reset, false-> normal
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool status;
 * 			status= rstmu_get_ilopreset();
 *		}
 * @endcode
 */
bool rstmu_get_ilopreset(void);

/**
 * @brief 	<b>Description:</b> read the wwdt reset flag status.
 * @details <b>Function prototype:</b> bool rstmu_get_wrstmureset(void);
 * @param[in]  null .
 * @param[out] null .
 * 
 * @return  bool ststus 	true-> wwdt reset, false-> normal
 * @par Example
 * @code
 *		void test( void )
 *		{
 * 			bool status;
 * 			status= rstmu_get_wrstmureset();
 *		}
 * @endcode
 */
bool rstmu_get_wrstmureset(void);
/**@}*/ /*** end of name rstmu_api */
/**@}*/ /*** end of group rstmu_api */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib_rstmu */
/**@}*/ /*** end of group csu39fx10_sdk_chip_fwlib */
/**@}*/ /*** end of group csu39fx10_sdk_chip */
/*******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif  //__CSU39FX10_RSTMU_H__


/*** (C) COPYRIGHT 2020 Chipsea Technologies (Shenzhen) Corp. ***/
