#include "type_convert.h"

// ��������char_p_convert_cstring
// ������pc
// �������ͣ�CString
// Function��char*->CString ��ͬ����ת��
CString char_p_convert_cstring(char* pc) {
    USES_CONVERSION;
    CString cstr = A2T(pc);
    return cstr;
}
