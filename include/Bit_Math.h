#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set_Bit(var,bitnum)     var|=(1<<bitnum)
#define Clear_Bit(var,bitnum)   var&=~(1<<bitnum)
#define Toggle_Bit(var,bitnum)  var^=(1<<bitnum)
#define Get_Bit(var,bitnum)     ((var>>bitnum)&0x01)
#define Set_Byte(var,value)     var=value

#define NULL   (void*)(0)

#endif
