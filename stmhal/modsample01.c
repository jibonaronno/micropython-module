
/*******************************************************
Sample Module Example.
*******************************************************/

#include <stdio.h>

#include "modmachine.h"
#include "py/gc.h"
#include "py/runtime.h"
#include "py/mphal.h"
//#include "extmod/machine_mem.h"
//#include "extmod/machine_pulse.h"
//#include "extmod/machine_i2c.h"
//#include "lib/utils/pyexec.h"
//#include "lib/fatfs/ff.h"
//#include "lib/fatfs/diskio.h"
#include "gccollect.h"
#include "irq.h"
//#include "rng.h"
//#include "storage.h"
#include "pin.h"
#include "timer.h"
//#include "usb.h"
//#include "rtc.h"
//#include "i2c.h"
#include "spi.h"
#include "wdt.h"



STATIC mp_obj_t func_001(void)
{
	printf("This is a sample function from a sample module\r\n\\stmhal\\modsample01.c -> func_001\r\n");
	return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(func_001_obj, func_001);

STATIC mp_obj_t func_002(mp_obj_t ui32_value)
{
	uint32_t ui32_data01 = mp_obj_get_int(ui32_value);
	ui32_data01 = ui32_data01 * 2;
	return MP_OBJ_NEW_SMALL_INT(ui32_data01);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(func_002_obj, func_002);



STATIC const mp_map_elem_t sample01_module_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__),            MP_OBJ_NEW_QSTR(MP_QSTR_sample01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_func001),                (mp_obj_t)&func_001_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_func002),                (mp_obj_t)&func_002_obj },
};


STATIC MP_DEFINE_CONST_DICT(sample01_module_globals, sample01_module_globals_table);

const mp_obj_module_t sample01_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&sample01_module_globals,
};
