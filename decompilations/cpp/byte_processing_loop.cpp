
struct s0 {
    int8_t[4] pad4;
    uint16_t f4;
    int8_t[12] pad18;
    int32_t f18;
    int8_t[4] pad26;
    int32_t f26;
};

uint32_t translate_byte_v1(struct s0* a1);

uint32_t fun_407cb0(struct s0* a1, uint32_t a2);

void load_constants(int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6);

uint16_t byte_processing_loop1(struct s0* a1) {
    struct s0* esi2;
    uint32_t eax3;
    uint32_t ebx4;
    uint32_t ebx5;
    int32_t v6;
    uint32_t eax7;
    int32_t ecx8;
    int32_t ebp9;
    int8_t* edi10;
    uint32_t ecx11;
    int8_t* ecx12;
    int32_t eax13;
    int32_t ecx14;
    int32_t edi15;
    int32_t v16;
    int32_t ecx17;

    esi2 = a1;
    esi2->f4 = 0x1000;
    eax3 = translate_byte_v1(esi2);
    *(uint16_t*)&ebx4 = *(uint16_t*)&eax3;
    ebx5 = ebx4 & 0xffff;
    if (*(uint16_t*)&ebx5 >= 0x305) {
        addr_0x407aab_2:
        *(uint16_t*)&eax3 = (uint16_t)(esi2->f4 - 0x1000);
        v6 = esi2->f18;
        esi2->f26((int32_t)esi2 + 0x101e, eax3, v6);
        return *(uint16_t*)&ebx5;
    } else {
        do {
            if (*(uint16_t*)&ebx5 >= 0x100) {
                ebx5 = ebx5 - 0xfe;
                eax7 = fun_407cb0(esi2, ebx5);
                eax3 = eax7 & 0xffff;
                if (!eax3) 
                    break;
                ecx8 = 0;
                ebp9 = (int32_t)(esi2 + 1);
                *(uint16_t*)&ecx8 = esi2->f4;
                edi10 = (int8_t*)(ecx8 + ebp9);
                ecx11 = ecx8 + ebx5;
                esi2->f4 = *(uint16_t*)&ecx11;
                ecx12 = (int8_t*)((int32_t)edi10 - eax3);
                do {
                    --ebx5;
                    *edi10 = *ecx12;
                    ++edi10;
                    ++ecx12;
                } while (ebx5);
            } else {
                eax13 = 0;
                ebp9 = (int32_t)(esi2 + 1);
                *(uint16_t*)&eax13 = esi2->f4;
                ecx14 = eax13 + 1;
                esi2->f4 = *(uint16_t*)&ecx14;
                *(int8_t*)(eax13 + ebp9) = *(int8_t*)&ebx5;
            }
            if (esi2->f4 >= 0x2000) {
                edi15 = (int32_t)esi2 + 0x101e;
                v16 = esi2->f18;
                esi2->f26(edi15, 0x1000, v16);
                ecx17 = 0;
                *(uint16_t*)&ecx17 = esi2->f4;
                load_constants(ebp9, edi15, ecx17 - 0x1000, edi15, 0x1000, v16);
                esi2->f4 = (uint16_t)(esi2->f4 - 0x1000);
            }
            eax3 = translate_byte_v1(esi2);
            *(uint16_t*)&ebx5 = *(uint16_t*)&eax3;
            ebx5 = ebx5 & 0xffff;
        } while (*(uint16_t*)&ebx5 < 0x305);
        goto addr_0x407aa4_11;
    }
    ebx5 = 0x306;
    goto addr_0x407aab_2;
    addr_0x407aa4_11:
    goto addr_0x407aab_2;
}
