
struct s0 {
    int8_t[10] pad10;
    uint16_t f10;
    int16_t f12;
    int16_t f14;
    int16_t f16;
    int32_t f18;
    int32_t f22;
};

int16_t fun_407d40(struct s0* a1, uint32_t a2) {
    uint32_t ebx3;
    uint32_t eax4;
    int32_t edx5;
    int32_t edi6;
    uint32_t ecx7;
    int16_t ax8;
    uint32_t eax9;
    int32_t edx10;
    uint32_t eax11;
    uint32_t eax12;
    int16_t cx13;
    uint32_t eax14;

    ebx3 = a2;
    *(int16_t*)&eax4 = a1->f12;
    edx5 = a1->f22;
    edi6 = a1->f18;
    ecx7 = eax4 & 0xffff;
    if ((ebx3 & 0xffff) > ecx7) {
        ax8 = a1->f14;
        a1->f10 = (uint16_t)(a1->f10 >> *(int8_t*)&ecx7);
        if (ax8 == a1->f16) {
            a1->f14 = 0x800;
            eax9 = (uint32_t)edx5((int32_t)a1 + 0x2222, 0x800, edi6);
            a1->f16 = *(int16_t*)&eax9;
            if (*(int16_t*)&eax9) {
                a1->f14 = 0;
            } else {
                return 1;
            }
        }
        *(int16_t*)&eax9 = a1->f14;
        edx10 = 0;
        *(int8_t*)((int32_t)&edx10 + 1) = *(int8_t*)((eax9 & 0xffff) + (int32_t)a1 + 0x2222);
        a1->f10 = (uint16_t)(a1->f10 | *(uint16_t*)&edx10);
        eax11 = eax9 + 1;
        a1->f14 = *(int16_t*)&eax11;
        *(int16_t*)&eax11 = a1->f12;
        a1->f10 = (uint16_t)(a1->f10 >> (int8_t)(*(int8_t*)&ebx3 - *(int8_t*)&eax11));
        eax12 = eax11 - ebx3 + 8;
        a1->f12 = *(int16_t*)&eax12;
        return 0;
    } else {
        cx13 = *(int16_t*)&ebx3;
        eax14 = eax4 - ebx3;
        a1->f10 = (uint16_t)(a1->f10 >> *(int8_t*)&cx13);
        a1->f12 = *(int16_t*)&eax14;
        return 0;
    }
}
