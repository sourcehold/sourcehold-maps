
struct s0 {
    int8_t[2] pad2;
    int16_t f2;
    int8_t[2] pad6;
    int16_t f6;
    int16_t f8;
    uint8_t f10;
};

uint32_t fun_407d40(struct s0* a1, int32_t a2);

int16_t translate_byte_v1(struct s0* a1) {
    uint8_t al2;
    uint32_t eax3;
    void* eax4;
    uint32_t ecx5;
    int32_t edx6;
    uint32_t edi7;
    void* ebp8;
    uint32_t eax9;
    int32_t ecx10;
    uint32_t eax11;
    uint32_t ebx12;
    uint32_t eax13;
    int32_t edi14;
    uint32_t edi15;
    uint32_t eax16;
    uint32_t eax17;
    uint32_t eax18;
    void* ecx19;
    uint32_t edx20;
    uint32_t edi21;
    uint32_t edx22;
    uint32_t eax23;
    uint32_t eax24;
    uint32_t eax25;
    void* eax26;
    uint32_t ecx27;
    int32_t ecx28;
    uint32_t eax29;
    int16_t ax30;
    uint32_t edx31;
    uint32_t eax32;

    al2 = a1->f10;
    if (1 & al2) {
        eax3 = fun_407d40(a1, 1);
        if (!*(int16_t*)&eax3) {
            eax4 = (void*)0;
            ecx5 = 0;
            *(uint8_t*)&eax4 = a1->f10;
            edx6 = 0;
            *(int8_t*)&ecx5 = *(int8_t*)((int32_t)eax4 + (int32_t)a1 + 0x2b22);
            edi7 = ecx5;
            ebp8 = (void*)(edi7 & 0xffff);
            *(int8_t*)&edx6 = *(int8_t*)((int32_t)a1 + (uint32_t)ebp8 + 0x30e2);
            eax9 = fun_407d40(a1, edx6);
            if (!*(int16_t*)&eax9) {
                ecx10 = 0;
                *(uint8_t*)&ecx10 = *(uint8_t*)((int32_t)a1 + (uint32_t)ebp8 + 0x30f2);
                if (ecx10) {
                    eax11 = 0;
                    *(uint8_t*)&eax11 = a1->f10;
                    ebx12 = (uint32_t)((1 << *(uint8_t*)&ecx10) - 1) & eax11;
                    eax13 = fun_407d40(a1, ecx10);
                    if (!*(int16_t*)&eax13 || (ebx12 & 0xffff) + (uint32_t)ebp8 == 0x10e) {
                        edi14 = 0;
                        *(int16_t*)&edi14 = *(int16_t*)((int32_t)a1 + (uint32_t)ebp8 * 2 + 0x3102);
                        edi7 = edi14 + ebx12;
                    } else {
                        return 0x306;
                    }
                }
                edi15 = edi7 + 0x100;
                return *(int16_t*)&edi15;
            } else {
                return 0x306;
            }
        } else {
            return 0x306;
        }
    }
    eax16 = fun_407d40(a1, 1);
    if (*(int16_t*)&eax16) {
        return 0x306;
    }
    if (!a1->f2) 
        goto addr_0x407bb2_14;
    eax17 = 0;
    *(uint8_t*)&eax17 = a1->f10;
    if (!*(uint8_t*)&eax17) {
        eax18 = fun_407d40(a1, 8);
        if (!*(int16_t*)&eax18) {
            ecx19 = (void*)0;
            edx20 = 0;
            *(uint8_t*)&ecx19 = a1->f10;
            *(int8_t*)&edx20 = *(int8_t*)((int32_t)ecx19 + (int32_t)a1 + 0x2ea2);
            edi21 = edx20;
        } else {
            return 0x306;
        }
    } else {
        edx22 = 0;
        *(uint8_t*)&edx22 = *(uint8_t*)((eax17 & 0xff) + (int32_t)a1 + 0x2c22);
        edi21 = edx22;
        if (*(int16_t*)&edi21 == 0xff) {
            if (!(*(uint8_t*)&eax17 & 63)) {
                eax23 = fun_407d40(a1, 6);
                if (!*(int16_t*)&eax23) {
                    *(uint8_t*)&edx22 = a1->f10;
                    eax24 = 0;
                    *(int8_t*)&eax24 = *(int8_t*)((edx22 & 0x7f) + (int32_t)a1 + 0x2e22);
                    edi21 = eax24;
                } else {
                    return 0x306;
                }
            } else {
                eax25 = fun_407d40(a1, 4);
                if (!*(int16_t*)&eax25) {
                    eax26 = (void*)0;
                    ecx27 = 0;
                    *(uint8_t*)&eax26 = a1->f10;
                    *(int8_t*)&ecx27 = *(int8_t*)((int32_t)eax26 + (int32_t)a1 + 0x2d22);
                    edi21 = ecx27;
                } else {
                    return 0x306;
                }
            }
        }
    }
    ecx28 = 0;
    *(int8_t*)&ecx28 = *(int8_t*)((edi21 & 0xffff) + (int32_t)a1 + 0x2fa2);
    eax29 = fun_407d40(a1, ecx28);
    ax30 = 0x306;
    if (!*(int16_t*)&eax29) 
        goto addr_0x407ca7_28;
    addr_0x407caa_29:
    return ax30;
    addr_0x407ca7_28:
    ax30 = *(int16_t*)&edi21;
    goto addr_0x407caa_29;
    addr_0x407bb2_14:
    edx31 = 0;
    *(uint8_t*)&edx31 = a1->f10;
    edi21 = edx31;
    eax32 = fun_407d40(a1, 8);
    if (*(int16_t*)&eax32) {
        return 0x306;
    }
}