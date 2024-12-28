#include "type_convert.h"

// 函数名：char_p_convert_cstring
// 参数：pc
// 返回类型：CString
// Function：char*->CString 不同类型转化
CString char_p_convert_cstring(char* pc) {
    USES_CONVERSION;
    CString cstr = A2T(pc);
    return cstr;
}
