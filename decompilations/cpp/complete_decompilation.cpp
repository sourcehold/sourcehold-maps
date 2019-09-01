
void fun_410b88(void** a1, void** a2, void** a3, ...);

void** fun_410bf4(void** a1, void** a2, void** a3, int32_t a4, void** a5, void** a6, void** a7, ...);

void** fun_410c30(void** a1, void** a2, void** a3, ...);

void** fun_40850c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14);

void fun_40bed0(int32_t ecx);

struct s0 {
    uint8_t f0;
    int8_t[98] pad99;
    int32_t f99;
    int16_t f101;
    int32_t f102;
    int8_t[2] pad111;
    uint8_t f111;
};

struct s0* g41ebe4 = (struct s0*)0x423c10;

void** fun_4180f9(uint32_t a1, int32_t a2, void** a3, void* a4, void** a5, int32_t a6, ...);

void** fun_40bfd0(void** a1) {
    uint8_t ah2;
    uint8_t ah3;
    uint8_t ah4;
    uint8_t ah5;
    uint8_t ah6;
    uint32_t eax7;
    uint32_t v8;
    uint8_t ah9;
    uint8_t ah10;
    uint8_t ah11;
    uint8_t ah12;
    void** v13;
    uint32_t eax14;
    uint32_t v15;
    uint8_t ah16;
    uint8_t ah17;
    uint8_t ah18;
    uint8_t ah19;
    uint32_t eax20;
    uint32_t v21;
    uint8_t ah22;
    uint8_t ah23;
    uint8_t ah24;
    uint8_t ah25;
    void** eax26;
    void** v27;
    void** v28;
    void** ebx29;
    void** esi30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    struct s0* eax39;
    void** v40;
    void* v41;
    void** v42;
    int32_t v43;
    int32_t v44;
    int32_t v45;
    int32_t v46;
    int32_t v47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    void** v52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;

    asm("fld qword [esp+0x94]");
    asm("fld qword [esp+0x9c]");
    asm("fld qword [esp+0xa4]");
    asm("fld qword [esp+0xac]");
    asm("fld qword [esp+0xb4]");
    asm("fstp qword [esp+0x48]");
    asm("fld qword [esp+0xbc]");
    asm("fstp qword [esp+0x40]");
    asm("fld qword [esp+0xc4]");
    asm("fstp qword [esp+0x38]");
    asm("fld qword [esp+0xcc]");
    asm("fstp qword [esp+0x30]");
    asm("fldz");
    asm("fcom st0, st4");
    asm("fnstsw ax");
    ah2 = (uint8_t)(ah3 & 69);
    if (!ah2) {
        addr_0x40c071_5:
        asm("fstp st0");
        asm("fstp st0");
        asm("fstp st0");
    } else {
        asm("fld qword [0x40bfb8]");
        asm("fcom st0, st5");
        asm("fnstsw ax");
        ah4 = (uint8_t)(ah2 & 69);
        if (ah4 == 1) {
            asm("fstp st0");
            goto addr_0x40c071_5;
        } else {
            asm("fxch st0, st4");
            asm("fcom st0, st1");
            asm("fnstsw ax");
            ah5 = (uint8_t)(ah4 & 69);
            if (ah5 == 1 || (ah6 = (uint8_t)(ah5 & 69), ah6 == 0)) {
                addr_0x40c079_9:
                asm("fstp st1");
                asm("fstp st1");
                asm("fstp st1");
                asm("fstp st1");
            } else {
                asm("fld st5");
                asm("fadd st0, st1");
                asm("fld1");
                asm("fcompp");
                asm("fnstsw ax");
                if ((ah6 & 69) != 1) {
                    asm("fld qword [0x40bfc0]");
                    asm("fmul st6, st0");
                    asm("fld qword [0x40bfc8]");
                    asm("fadd st7, st0");
                    asm("fxch st0, st7");
                    asm("fnstcw word [esp+0x5e]");
                    asm("fldcw word [esp+0x5c]");
                    asm("fistp qword [esp+0x50]");
                    asm("fldcw word [esp+0x5e]");
                    asm("fmul st1, st0");
                    asm("fxch st0, st1");
                    asm("fadd st0, st6");
                    asm("fnstcw word [esp+0x5e]");
                    asm("fldcw word [esp+0x5c]");
                    asm("fistp qword [esp+0x50]");
                    asm("fldcw word [esp+0x5e]");
                    asm("fxch st0, st3");
                    eax7 = v8 >> 8;
                    asm("fcom st0, st1");
                    asm("fnstsw ax");
                    ah9 = (uint8_t)(*(uint8_t*)((int32_t)&eax7 + 1) & 69);
                    if (ah9 == 1 || ((ah10 = (uint8_t)(ah9 & 69), ah10 == 0) || ((ah11 = (uint8_t)(ah10 & 69), ah11 == 1) || ((ah12 = (uint8_t)(ah11 & 69), ah12 == 0) || (ah12 & 69) == 1)))) {
                        asm("fstp st0");
                        asm("fstp st0");
                        asm("fstp st0");
                        asm("fstp st0");
                        asm("fstp st0");
                        asm("fstp st0");
                        v13 = (void**)0x40bf10;
                        goto addr_0x40c3ca_13;
                    } else {
                        asm("fxch st0, st2");
                        asm("fmul st0, st3");
                        asm("fadd st0, st5");
                        asm("fnstcw word [esp+0x5e]");
                        asm("fldcw word [esp+0x5c]");
                        asm("fistp qword [esp+0x50]");
                        asm("fldcw word [esp+0x5e]");
                        asm("fxch st0, st1");
                        asm("fmul st0, st2");
                        asm("fadd st0, st4");
                        asm("fnstcw word [esp+0x5e]");
                        asm("fldcw word [esp+0x5c]");
                        asm("fistp qword [esp+0x50]");
                        asm("fldcw word [esp+0x5e]");
                        eax14 = v15 >> 8;
                        asm("fcom qword [esp+0x48]");
                        asm("fnstsw ax");
                        ah16 = (uint8_t)(*(uint8_t*)((int32_t)&eax14 + 1) & 69);
                        if (!ah16 || ((ah17 = (uint8_t)(ah16 & 69), ah17 == 1) || ((ah18 = (uint8_t)(ah17 & 69), ah18 == 0) || ((ah19 = (uint8_t)(ah18 & 69), ah19 == 1) || (ah19 & 69) == 1)))) {
                            asm("fstp st0");
                            asm("fstp st0");
                            asm("fstp st0");
                            asm("fstp st0");
                            v13 = (void**)0x40bf50;
                            goto addr_0x40c3ca_13;
                        } else {
                            asm("fld qword [esp+0x48]");
                            asm("fmul st0, st2");
                            asm("fadd st0, st4");
                            asm("fnstcw word [esp+0x5e]");
                            asm("fldcw word [esp+0x5c]");
                            asm("fistp qword [esp+0x50]");
                            asm("fldcw word [esp+0x5e]");
                            asm("fld qword [esp+0x40]");
                            asm("fmul st0, st2");
                            asm("fadd st0, st4");
                            asm("fnstcw word [esp+0x5e]");
                            asm("fldcw word [esp+0x5c]");
                            asm("fistp qword [esp+0x50]");
                            asm("fldcw word [esp+0x5e]");
                            asm("fxch st0, st2");
                            eax20 = v21 >> 8;
                            asm("fcom qword [esp+0x38]");
                            asm("fnstsw ax");
                            ah22 = (uint8_t)(*(uint8_t*)((int32_t)&eax20 + 1) & 69);
                            if (!ah22 || (ah23 = (uint8_t)(ah22 & 69), ah23 == 1)) {
                                asm("fstp st0");
                                goto addr_0x40c3bc_18;
                            }
                            asm("fxch st0, st2");
                            asm("fcomp qword [esp+0x30]");
                            asm("fnstsw ax");
                            ah24 = (uint8_t)(ah23 & 69);
                            if (!ah24) {
                                addr_0x40c3bc_18:
                                asm("fstp st0");
                                goto addr_0x40c3be_20;
                            } else {
                                asm("fxch st0, st1");
                                asm("fcomp qword [esp+0x30]");
                                asm("fnstsw ax");
                                ah25 = (uint8_t)(ah24 & 69);
                                if (ah25 == 1) {
                                    addr_0x40c3be_20:
                                    asm("fstp st0");
                                    asm("fstp st0");
                                    v13 = (void**)0x40bf90;
                                    goto addr_0x40c3ca_13;
                                } else {
                                    asm("fld qword [esp+0x38]");
                                    asm("fadd qword [esp+0x30]");
                                    asm("fld1");
                                    asm("fcompp");
                                    asm("fnstsw ax");
                                    if ((ah25 & 69) != 1) {
                                        asm("fld qword [esp+0x38]");
                                        asm("fmul st0, st1");
                                        asm("fadd st0, st2");
                                        asm("fnstcw word [esp+0x5e]");
                                        asm("fldcw word [esp+0x5c]");
                                        asm("fistp qword [esp+0x50]");
                                        asm("fldcw word [esp+0x5e]");
                                        asm("fld qword [esp+0x30]");
                                        asm("fmulp st1, st0");
                                        asm("faddp st1, st0");
                                        asm("fnstcw word [esp+0x5e]");
                                        asm("fldcw word [esp+0x5c]");
                                        asm("fistp qword [esp+0x50]");
                                        asm("fldcw word [esp+0x5e]");
                                        fun_410b88(a1, 0x406a73, 32);
                                        fun_410bf4(a1, (int32_t)__zero_stack_offset() - 0x84 - 4 - 4 + 96, 32, 0x40c488, a1, 0x406a73, 32);
                                        eax26 = fun_410c30(a1, 0x406a73, 32);
                                        goto addr_0x40c4a0_24;
                                    } else {
                                        goto addr_0x40c3be_20;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    goto addr_0x40c079_9;
                }
            }
        }
    }
    asm("fxch st0, st1");
    asm("fstp tword [esp+0x30]");
    asm("fstp tword [esp+0x20]");
    fun_40850c(a1, fun_40bed0, v27, v28, ebx29, esi30, v31, v32, v33, v34, v35, v36, v37, v38);
    asm("fld tword [esp+0x28]");
    asm("fld tword [esp+0x40]");
    asm("fxch st0, st1");
    asm("fstp qword [esp]");
    asm("fstp qword [esp]");
    eax39 = g41ebe4;
    eax26 = fun_4180f9((uint32_t)eax39 + 64, "white_x=%f, white_y=%f\n", v40, v41, v42, v43, (uint32_t)eax39 + 64, "white_x=%f, white_y=%f\n", v44, v45, v46, v47);
    addr_0x40c4a3_28:
    return eax26;
    addr_0x40c3ca_13:
    eax26 = fun_40850c(a1, v13, v48, v49, ebx29, esi30, v50, v51, v52, v53, v54, v55, v56, v57);
    addr_0x40c4a0_24:
    goto addr_0x40c4a3_28;
}

void** fun_410de8(void** a1, uint32_t a2, void** a3, void** a4) {
    void** eax5;

    asm("fld qword [esp+0x44]");
    asm("fmul qword [0x410dd8]");
    asm("fadd qword [0x410de0]");
    asm("fnstcw word [esp+0x2e]");
    asm("fldcw word [esp+0x2c]");
    asm("fistp qword [esp+0x20]");
    asm("fldcw word [esp+0x2e]");
    fun_410b88(a1, 0x406a78, 4, a1, 0x406a78, 4);
    fun_410bf4(a1, (int32_t)__zero_stack_offset() - 52 - 4 - 4 + 28, 4, 0x410e58, a1, 0x406a78, 4, a1, (int32_t)__zero_stack_offset() - 52 - 4 - 4 + 28, 4, 0x410e58, a1, 0x406a78, 4);
    eax5 = fun_410c30(a1, 0x406a78, 4, a1, 0x406a78, 4);
    return eax5;
}

int32_t fun_41ce41(void* a1, int32_t a2);

void** fun_417a9f(void* a1, int32_t a2);

int32_t read_bytes(void* a1, int32_t a2, uint32_t a3, void** a4);

uint32_t convert_and_write(void** a1, void** a2);

void fun_41ce36(void* a1);

uint32_t convert_file(void* a1, void* a2, int32_t a3) {
    void* esp4;
    int32_t eax5;
    void** eax6;
    int32_t eax7;
    void** eax8;
    uint32_t eax9;

    esp4 = (void*)((int32_t)__zero_stack_offset() - 4 - 4);
    if (a3 || (eax5 = fun_41ce41(a2, 0), esp4 = (void*)((int32_t)esp4 - 4 - 4 - 4 + 4 + 8), eax5 == -1)) {
        eax6 = fun_417a9f(a1, "rb");
        if (eax6) {
            eax7 = read_bytes((int32_t)esp4 - 4 - 4 - 4 + 4 + 8 - 4 - 4 + 28, 4, 1, eax6);
            if (!eax7 || a3 > -1) {
                return 5;
            } else {
                eax8 = fun_417a9f(a2, "wb");
                if (eax8) {
                    eax9 = convert_and_write(eax6, eax8);
                    if (eax9) {
                        fun_41ce36(a2);
                    }
                    return eax9;
                } else {
                    return 2;
                }
            }
        } else {
            return 1;
        }
    } else {
        return 3;
    }
}

int32_t g41d1cc = 0x730f14c0;

void fun_4021c6(int8_t* a1, int8_t* a2, int8_t* a3, int8_t* a4, int8_t* a5, int8_t* a6, int8_t* a7, int8_t* a8, int8_t* a9, int8_t* a10) {
    goto g41d1cc;
}

int32_t g41d1c8 = 0x730f1500;

int32_t fun_4021c0(int8_t* a1, int8_t* a2, int8_t* a3, int8_t* a4, int8_t* a5, int8_t* a6, int8_t* a7, int8_t* a8, int8_t* a9, int8_t* a10, int8_t* a11, int8_t* a12, int8_t* a13, int8_t* a14, int8_t* a15, int8_t* a16, int8_t* a17, int8_t* a18, int8_t* a19, int8_t* a20, int8_t* a21, int8_t* a22, int8_t* a23, int8_t* a24, int8_t* a25, int8_t* a26, int8_t* a27, int8_t* a28, int8_t* a29, int8_t* a30, int8_t* a31, int8_t* a32, int8_t* a33, int8_t* a34, int8_t* a35, int8_t* a36, int8_t* a37, int8_t* a38, int8_t* a39, int8_t* a40, int8_t* a41, int8_t* a42, int8_t* a43, int8_t* a44, int8_t* a45, int8_t* a46, int8_t* a47, int8_t* a48, int8_t* a49, int8_t* a50, int8_t* a51, int8_t* a52, int8_t* a53, int8_t* a54, int8_t* a55, int8_t* a56, int8_t* a57, int8_t* a58, int8_t* a59, int8_t* a60, int8_t* a61, int8_t* a62, int8_t* a63, int8_t* a64, int8_t* a65, int8_t* a66, int8_t* a67, int8_t* a68, int8_t* a69, int8_t* a70, int8_t* a71, int8_t* a72, int8_t* a73, int8_t* a74, int8_t* a75, int8_t* a76, int8_t* a77, int8_t* a78, int8_t* a79, int8_t* a80, int8_t* a81, int8_t* a82, int8_t* a83, int8_t* a84, int8_t* a85, int8_t* a86, int8_t* a87, int8_t* a88, int8_t* a89, int8_t* a90, int8_t* a91, int8_t* a92, int8_t* a93, int8_t* a94, int8_t* a95, int8_t* a96, int8_t* a97, int8_t* a98, int8_t* a99, int8_t* a100, int8_t* a101) {
    goto g41d1c8;
}

int32_t g41d050 = 0x76cc5410;

void fun_417530(void* a1, int32_t a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10, void* a11, void* a12, void* a13, void* a14, void* a15, void* a16, void* a17, void* a18);

int32_t g41d000 = 0x76a9f420;

int32_t g41d004 = 0x76a9f120;

int32_t g41d008 = 0x76a9ed80;

int32_t g41d054 = 0x76cc6910;

void fun_4174d7(void* a1, void* a2, int32_t a3, void* a4, int32_t a5, void* a6, void* a7);

void fun_401db0(void* a1, int32_t a2, int32_t a3, int8_t* a4, int32_t a5, int32_t a6, int32_t a7, int32_t a8, int32_t a9, int8_t* a10, int32_t a11, int32_t a12, int32_t a13, int32_t a14, int32_t a15, int8_t* a16, int32_t a17, int32_t a18, int32_t a19, int32_t a20, int8_t* a21, int8_t* a22, int8_t* a23) {
    int8_t* v24;
    void* v25;
    void* esi26;
    int32_t esi27;
    void** esp28;
    void* v29;
    void* edi30;
    void* ecx31;
    void* ebx32;
    void* v33;
    void* eax34;
    void* esp35;
    void* v36;
    int32_t eax37;
    int32_t v38;
    void** esp39;
    void* v40;
    void* ebp41;
    void* ebp42;
    int32_t eax43;
    int32_t v44;
    int32_t v45;
    int32_t v46;
    int32_t v47;
    void* v48;
    void* v49;
    void* v50;
    void* v51;
    void* v52;
    void* v53;
    void* v54;
    void* v55;
    void* v56;
    void* v57;
    void* v58;
    void* v59;
    void* v60;
    void* v61;
    void* v62;
    void* v63;
    int8_t v64;
    void* v65;
    void* v66;
    void* v67;
    void* v68;
    void* v69;
    void* v70;
    void* v71;
    void* v72;
    void** esp73;
    void* v74;
    void* v75;
    void* v76;
    void* v77;
    void* v78;
    void* v79;
    void* v80;
    void* v81;
    int8_t v82;
    void** esp83;
    void* v84;
    void* v85;
    void* v86;
    void* v87;
    void* v88;
    void* v89;
    void* v90;
    void* v91;
    uint32_t ecx92;
    int32_t v93;
    int8_t v94;
    int8_t* eax95;
    void* ecx96;
    void* edx97;
    int8_t* edi98;
    uint32_t ecx99;
    int8_t v100;
    uint32_t ecx101;
    int8_t v102;
    int32_t v103;
    int8_t* eax104;
    void* edx105;
    int8_t v106;
    int32_t v107;
    void* v108;
    void* esp109;
    void* esp110;
    int32_t eax111;
    void* esp112;
    int32_t eax113;
    void* esp114;
    int32_t eax115;
    void** esp116;
    int8_t v117;
    int32_t v118;
    void* v119;
    void* v120;
    void* v121;
    void* v122;
    void* v123;
    void* v124;
    void* v125;
    void* v126;
    int32_t eax127;
    int32_t v128;
    void** esp129;
    void* v130;
    void* v131;
    void* v132;
    void* v133;
    void* v134;
    void* v135;
    void* v136;
    void* v137;
    void* v138;
    void* v139;
    void* v140;
    void* v141;
    void* v142;
    void* v143;
    void* v144;
    void* v145;
    int32_t v146;
    void* v147;
    void* v148;
    void* v149;
    void* v150;
    void* v151;
    void* v152;
    void* v153;
    void* v154;
    int32_t eax155;
    int32_t v156;
    void* v157;
    void* v158;
    void* v159;
    void* v160;
    void* v161;
    void* v162;
    void* v163;
    void* v164;
    void* v165;
    void* v166;
    void* v167;
    void* v168;
    void* v169;
    void* v170;
    void* v171;
    void* v172;
    void* v173;
    void* v174;
    void* v175;
    void* v176;
    void* v177;
    void* v178;
    void* v179;
    void* v180;
    void* v181;
    void* v182;
    void* v183;
    void* v184;
    void* v185;
    void* v186;
    void* v187;
    void* v188;
    void* v189;
    void* v190;
    void* v191;

    v24 = (int8_t*)__return_address();
    v25 = esi26;
    esi27 = g41d050;
    esp28 = (void**)((int32_t)__zero_stack_offset() - 0x1f4 - 4 - 4 - 4);
    v29 = edi30;
    ecx31 = (void*)39;
    ebx32 = (void*)(esp28 + 64);
    while (ecx31) {
        ecx31 = (void*)((uint32_t)ecx31 - 1);
        esi27 = esi27 + 4;
    }
    v33 = (void*)(esp28 + 5);
    eax34 = (void*)esi27();
    esp35 = (void*)(esp28 - 1 - 1 + 1);
    v36 = eax34;
    if (!eax34 && (eax37 = (int32_t)esi27(), esp35 = (void*)((int32_t)esp35 - 4 - 4 + 4), !eax37)) {
        goto v38;
    }
    esp39 = (void**)((int32_t)esp35 - 4);
    v40 = ebp41;
    ebp42 = a1;
    eax43 = v44 - 1;
    if (!eax43) {
        if (!1) {
            if (v45) {
                addr_0x4020e6_9:
                if (v46 != 10) {
                    addr_0x40211f_10:
                    if (v47 == 90) {
                        fun_417530(ebx32, "Microsoft Windows Millennium Edition", ebp42, v40, v33, v29, v25, v36, v48, 0x94, 0x9c, v49, v50, v51, v52, v53, v54, v55);
                        esp39 = esp39 - 1 - 1 - 1 - 1 + 1 + 3;
                        goto addr_0x402135_12;
                    }
                } else {
                    fun_417530(ebx32, "Microsoft Windows 98", ebp42, v40, v33, v29, v25, v36, v56, 0x94, 0x9c, v57, v58, v59, v60, v61, v62, v63);
                    esp39 = esp39 - 1 - 1 - 1 - 1 + 1 + 3;
                    ebx32 = (void*)((uint32_t)ebx32 + 20);
                    if (v64 == 65) {
                        fun_417530(ebx32, " SE", ebp42, v40, v33, v29, v25, v36, v65, 0x94, 0x9c, v66, v67, v68, v69, v70, v71, v72);
                        esp39 = esp39 - 1 - 1 - 1 - 1 + 1 + 3;
                        ebx32 = (void*)((uint32_t)ebx32 + 3);
                    }
                    if (1) 
                        goto addr_0x402135_12; else 
                        goto addr_0x40211f_10;
                }
            } else {
                esp73 = esp39 - 1;
                fun_417530(esp73 + 66, "Microsoft Windows 95", ebp42, v40, v33, v29, v25, v36, v74, 0x94, 0x9c, v75, v76, v77, v78, v79, v80, v81);
                esp39 = esp73 - 1 - 1 - 1 + 1 + 3;
                ebx32 = (void*)(esp39 + 70);
                if (v82 == 67 || v82 == 66) {
                    esp83 = esp39 - 1;
                    fun_417530(esp83 + 71, " OSR2", ebp42, v40, v33, v29, v25, v36, v84, 0x94, 0x9c, v85, v86, v87, v88, v89, v90, v91);
                    esp39 = esp83 - 1 - 1 - 1 + 1 + 3;
                    ebx32 = (void*)((int32_t)esp39 + 0x11d);
                }
                if (1) 
                    goto addr_0x402135_12; else 
                    goto addr_0x4020e6_9;
            }
        }
    }
    if (eax43 - 1) {
        addr_0x402135_12:
        ecx92 = 0xffffffff;
    } else {
        if (!1) {
            ecx31 = (void*)5;
            ebx32 = (void*)(esp39 + 70);
            while (ecx31) {
                ecx31 = (void*)((uint32_t)ecx31 - 1);
            }
        }
        if (!1 && !v93) {
            ecx31 = (void*)0x9c;
            ebx32 = (void*)((uint32_t)ebx32 + 22);
            while (ecx31) {
                ecx31 = (void*)((uint32_t)ecx31 - 1);
            }
        }
        if (!v36) 
            goto addr_0x401f70_38; else 
            goto addr_0x401e6f_39;
    }
    do {
        if (!ecx92) 
            break;
        --ecx92;
    } while (v94);
    if ((uint32_t)((int32_t)~ecx92 - 1) >= (uint32_t)ebp42) {
        eax95 = v24;
        ecx96 = (void*)((uint32_t)ebp42 - 1);
        edx97 = ecx96;
        edi98 = eax95;
        ecx99 = (uint32_t)ecx96 >> 2;
        while (ecx99) {
            --ecx99;
            *edi98 = v100;
            edi98 = edi98 + 4;
        }
        ecx101 = (uint32_t)edx97 & 3;
        while (ecx101) {
            --ecx101;
            *edi98 = v102;
            ++edi98;
        }
        *(int8_t*)((int32_t)eax95 + (uint32_t)ebp42 - 1) = 0;
        goto v103;
    } else {
        eax104 = (int8_t*)(esp39 + 65);
        edx105 = (void*)((int32_t)v24 - (int32_t)(esp39 + 65));
        do {
            *(int8_t*)((int32_t)edx105 + (int32_t)eax104) = v106;
            ++eax104;
        } while (v106);
        goto v107;
    }
    addr_0x401f70_38:
    v108 = (void*)(esp39 + 4);
    g41d000(0x80000002, "SYSTEM\\CurrentControlSet\\Control\\ProductOptions", 0, 1);
    esp109 = (void*)(esp39 - 1 - 1 - 1 - 1 - 1 - 1 + 1);
    g41d004(v108, "ProductType", 0, 0);
    g41d008((int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0);
    esp110 = (void*)((int32_t)esp109 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4);
    esi27 = g41d054;
    eax111 = (int32_t)esi27("WINNT", (int32_t)esp110 + 0xb4, (int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0);
    esp112 = (void*)((int32_t)esp110 - 4 - 4 - 4 + 4);
    if (!eax111) {
        fun_417530(ebx32, " Professional", ebp42, "WINNT", (int32_t)esp110 + 0xb4, (int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0, (int32_t)esp109 + 0xb4, (int32_t)esp109 + 20, 0x80000002, "SYSTEM\\CurrentControlSet\\Control\\ProductOptions", 0, 1, v108, v40);
        esp112 = (void*)((int32_t)esp112 - 4 - 4 - 4 - 4 + 4 + 12);
        ebx32 = (void*)((uint32_t)ebx32 + 13);
    }
    eax113 = (int32_t)esi27("LANMANNT", (int32_t)esp112 + 0xb4, "WINNT", (int32_t)esp110 + 0xb4, (int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0);
    esp114 = (void*)((int32_t)esp112 - 4 - 4 - 4 + 4);
    if (!eax113) {
        fun_417530(ebx32, " Server", ebp42, "LANMANNT", (int32_t)esp112 + 0xb4, "WINNT", (int32_t)esp110 + 0xb4, (int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0, (int32_t)esp109 + 0xb4, (int32_t)esp109 + 20, 0x80000002, "SYSTEM\\CurrentControlSet\\Control\\ProductOptions", 0, 1);
        esp114 = (void*)((int32_t)esp114 - 4 - 4 - 4 - 4 + 4 + 12);
        ebx32 = (void*)((uint32_t)ebx32 + 7);
    }
    eax115 = (int32_t)esi27("SERVERNT", (int32_t)esp114 + 0xb4, "LANMANNT", (int32_t)esp112 + 0xb4, "WINNT", (int32_t)esp110 + 0xb4, (int32_t)esp109 + 0xb4, v108, "ProductType", 0, 0);
    esp39 = (void**)((int32_t)esp114 - 4 - 4 - 4 + 4);
    if (eax115) 
        goto addr_0x40202a_57;
    esp116 = esp39 - 1;
    goto addr_0x402019_59;
    addr_0x401e6f_39:
    if (v117 == 1) {
        if (!1 && v118 == 1) {
            fun_417530(ebx32, "Microsoft Windows XP", ebp42, v40, v33, v29, v25, v36, v119, 0x94, 0x9c, v120, v121, v122, v123, v124, v125, v126);
            esp39 = esp39 - 1 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 20);
        }
        eax127 = v128;
        esp129 = esp39 - 1;
        if (!(*(uint8_t*)((int32_t)&eax127 + 1) & 2)) {
            fun_417530(ebx32, " Professional", ebp42, v40, v33, v29, v25, v36, v130, 0x94, 0x9c, v131, v132, v133, v134, v135, v136, v137);
            esp39 = esp129 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 13);
            goto addr_0x40202a_57;
        } else {
            fun_417530(ebx32, " Home Edition", ebp42, v40, v33, v29, v25, v36, v138, 0x94, 0x9c, v139, v140, v141, v142, v143, v144, v145);
            esp39 = esp129 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 13);
            goto addr_0x40202a_57;
        }
    }
    if (v117 != 3) {
        addr_0x40202a_57:
        if (1) {
            fun_4174d7(ebx32, ebp42, ", %s, Build %d", esp39 + 11, 0, v40, v33);
            esp39 = esp39 - 1 - 1 - 1 - 1 - 1 - 1 + 1 + 5;
            goto addr_0x402135_12;
        } else {
            fun_4174d7(ebx32, ebp42, ", version %d.%d %s, Build %d", 0x9c, "ProductType", esp39 + 11, 0);
            esp39 = esp39 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 + 1 + 7;
            goto addr_0x402135_12;
        }
    } else {
        if (!1 && v146 == 1) {
            fun_417530(ebx32, "Microsoft Windows .NET", ebp42, v40, v33, v29, v25, v36, v147, 0x94, 0x9c, v148, v149, v150, v151, v152, v153, v154);
            esp39 = esp39 - 1 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 22);
        }
        eax155 = v156;
        esp116 = esp39 - 1;
        v108 = ebp42;
        if ((int8_t)*(uint8_t*)&eax155 < (int8_t)0) 
            goto addr_0x401f03_71;
    }
    if (!(*(uint8_t*)&eax155 & 2)) {
        if (*(int16_t*)&eax155 != 0x400) {
            fun_417530(ebx32, " Server", v108, v40, v33, v29, v25, v36, v157, 0x94, 0x9c, v158, v159, v160, v161, v162, v163, v164);
            esp39 = esp116 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 7);
            goto addr_0x40202a_57;
        } else {
            fun_417530(ebx32, " Web Server", v108, v40, v33, v29, v25, v36, v165, 0x94, 0x9c, v166, v167, v168, v169, v170, v171, v172);
            esp39 = esp116 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 11);
            goto addr_0x40202a_57;
        }
    } else {
        if (0) {
            addr_0x402019_59:
            fun_417530(ebx32, " Advanced Server", v108, v40, v33, v29, v25, v36, v173, 0x94, 0x9c, "ProductType", 0, 0, v174, v175, 0x80000002, "SYSTEM\\CurrentControlSet\\Control\\ProductOptions");
            esp39 = esp116 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 16);
            goto addr_0x40202a_57;
        } else {
            fun_417530(ebx32, " Enterprise Server", v108, v40, v33, v29, v25, v36, v176, 0x94, 0x9c, v177, v178, v179, v180, v181, v182, v183);
            esp39 = esp116 - 1 - 1 - 1 + 1 + 3;
            ebx32 = (void*)((uint32_t)ebx32 + 18);
            goto addr_0x40202a_57;
        }
    }
    addr_0x401f03_71:
    fun_417530(ebx32, " DataCenter Server", v108, v40, v33, v29, v25, v36, v184, 0x94, 0x9c, v185, v186, v187, v188, v189, v190, v191);
    esp39 = esp116 - 1 - 1 - 1 + 1 + 3;
    ebx32 = (void*)((uint32_t)ebx32 + 18);
    goto addr_0x40202a_57;
}

void fun_406c0c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void** fun_4029a0(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14, void** a15);

void fun_402b2c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void fun_4039f8(void** a1, void** a2, void** a3, void** a4);

void fun_404c24(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10) {
    void** ebx11;
    void** esi12;
    void** ebp13;
    void** ebx14;
    void** esi15;
    void** edi16;
    void** ebp17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;

    ebx11 = (void**)0;
    esi12 = (void**)0;
    ebp13 = (void**)0;
    if (a1) {
        ebx11 = *(void***)a1;
        ebp13 = *(void***)(ebx11 + 0x24c);
    }
    if (a2) {
        esi12 = *(void***)a2;
    }
    if (esi12) {
        fun_406c0c(ebx11, esi12, 0x7fff, 0xff, ebx14, esi15, edi16, ebp17);
        if (*(void****)(ebx11 + 0x220)) {
            v18 = *(void***)(ebx11 + 0x224);
            fun_4029a0(ebx11, v18, 0x7fff, 0xff, ebx14, esi15, edi16, ebp17, v19, v20, v21, __return_address(), a1, a2, a3);
            *(void***)(ebx11 + 0x224) = (void**)0;
            *(void****)(ebx11 + 0x220) = (void***)0;
        }
        v22 = ebp13;
        fun_402b2c(esi12, v22, 0, 0xff, ebx14, esi15, edi16, ebp17);
        *(void***)a2 = (void**)0;
    }
    if (ebx11) {
        fun_4039f8(ebx11, v22, 0, 0xff);
        fun_402b2c(ebx11, ebp13, 0, 0x404cb4, ebx11, v22, 0, 0xff);
        *(void***)a1 = (void**)0;
    }
    return;
}

void** fun_4075f0(void** a1, int32_t a2, uint32_t a3, int32_t a4, void** a5, void** a6, void** a7, void** a8);

void fun_417ac0(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void fun_4065a4(void** a1, void** a2, void** a3, void** a4) {
    void** edi5;
    void** ebx6;
    void** esi7;
    void** edi8;
    void** v9;
    void** eax10;
    void** v11;

    edi5 = a4;
    if (a1 && a2) {
        fun_406c0c(a1, a2, 0x1000, 0, ebx6, esi7, edi8, v9);
        eax10 = fun_4075f0(a1, 0x100, 3, 0x4065cc, a1, a2, 0x1000, 0);
        *(void***)(a1 + 0x114) = eax10;
        fun_417ac0(eax10, a2, edi5 + (uint8_t)edi5 * 2, 0, ebx6, esi7, edi8, v11);
        *(void***)(a2 + 16) = *(void***)(a1 + 0x114);
        *(void***)(a1 + 0x118) = edi5;
        *(void***)(a2 + 20) = edi5;
        *(uint8_t*)(a2 + 0xb9) = (uint8_t)(*(uint8_t*)(a2 + 0xb9) | 16);
        *(void***)(a2 + 8) = (void**)((uint8_t)*(void***)(a2 + 8) | 8);
    }
    return;
}

void** fun_4029dc(void** a1, void** a2);

void** fun_408404(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6);

int32_t fun_4028b0(int16_t cx);

void** fun_402940(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, ...) {
    void** eax13;
    void** eax14;
    void** eax15;
    void** v16;
    void** v17;
    void** ebx18;
    void** esi19;

    if (!a1 || !a2) {
        eax13 = (void**)0;
    } else {
        eax14 = *(void***)(a1 + 0x248);
        if (!eax14) 
            goto addr_0x40298c_7; else 
            goto addr_0x402966_8;
    }
    addr_0x402999_9:
    return eax13;
    addr_0x40298c_7:
    eax13 = fun_4029dc(a1, a2);
    goto addr_0x402999_9;
    addr_0x402966_8:
    eax15 = (void**)eax14(a1, a2);
    if (!eax15) {
        fun_408404(a1, fun_4028b0, v16, v17, ebx18, esi19);
    }
    eax13 = eax15;
    goto addr_0x402999_9;
}

void fun_402bb4(int16_t cx, void** a2, void** a3);

void fun_40cb50(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7);

void fun_40c918(void** a1, void** a2, void** a3, uint32_t a4, void** a5, void** a6, void** a7, void** a8);

struct s1 {
    int8_t[109] pad109;
    uint8_t f109;
};

void fun_402da0(struct s1* ecx);

void fun_40b648(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7);

void fun_410f38(void** a1, void** a2, void** a3);

void fun_411198(void** a1, void** a2, void** a3, void** a4);

void fun_40d41c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void** fun_40da88(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void fun_411244(void** a1, void** a2, void** a3, void** a4);

void fun_4112f0(void** a1, void** a2, void** a3, void** a4);

void** fun_40bb48(void** a1, void** a2, void** a3, void** a4);

void** fun_40d044(void** a1, void** a2, void** a3, void** a4);

void fun_40d1e0(void** a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, void** a6, void** a7, void** a8);

uint32_t fun_4076f4(void** a1, void** a2, void** a3, void** a4);

void** fun_410b44(void** a1, void** a2, void** a3, void** a4);

void fun_402e04(int16_t cx, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void** v10;
    void** esi11;
    void** v12;
    void** ebx13;
    void** ebp14;
    void** esi15;
    void** v16;
    void** v17;
    void** v18;
    void** ecx19;
    void** v20;
    uint32_t v21;
    void** v22;
    void** v23;
    void* edx24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** edi37;
    void* ebx38;
    void** edi39;
    void* ebx40;
    void** edx41;
    int32_t v42;
    int32_t v43;
    void** ebx44;
    void** esi45;
    uint32_t eax46;

    v9 = (void**)__return_address();
    v10 = esi11;
    v12 = ebx13;
    ebp14 = a7;
    esi15 = a8;
    v16 = esi15;
    fun_402bb4(cx, ebp14, v16);
    if (!((uint8_t)*(void***)(esi15 + 8) & 8)) {
        if (*(uint8_t*)(esi15 + 25) != 3) {
            addr_0x402e53_6:
            if (!((uint8_t)*(void***)(esi15 + 8) & 16)) {
                addr_0x402e9d_7:
                if ((uint8_t)*(void***)(esi15 + 8) & 32) {
                    v17 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi15 + 25));
                    v16 = esi15 + 90;
                    fun_40cb50(ebp14, v16, v17, v18, v12, v10, v9);
                }
            } else {
                ecx19 = esi15 + 80;
                if (!(*(uint8_t*)(ebp14 + 0x72) & 8)) {
                    addr_0x402e83_10:
                    v20 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi15 + 25));
                    v21 = static_cast<uint32_t>((uint16_t)*(void***)(esi15 + 22));
                    v22 = *(void***)(esi15 + 76);
                    fun_40c918(ebp14, v22, ecx19, v21, v20, v16, v17, v23);
                    goto addr_0x402e9d_7;
                } else {
                    if (*(uint8_t*)(esi15 + 25) != 3) 
                        goto addr_0x402e83_10;
                    edx24 = (void*)0;
                    if (!*(void***)(esi15 + 22)) 
                        goto addr_0x402e83_10; else 
                        goto addr_0x402e71_14;
                }
            }
        } else {
            v16 = (void**)fun_402da0;
            fun_408404(ebp14, fun_402da0, v25, v26, v12, v10);
            goto addr_0x402e50_16;
        }
    } else {
        v17 = (void**)static_cast<uint32_t>((uint16_t)*(void***)(esi15 + 20));
        v16 = *(void***)(esi15 + 16);
        fun_40b648(ebp14, v16, v17, v27, v12, v10, v9);
        goto addr_0x402e50_16;
    }
    if ((uint8_t)*(void***)(esi15 + 8) & 64) {
        v17 = (void**)static_cast<uint32_t>((uint16_t)*(void***)(esi15 + 20));
        v16 = *(void***)(esi15 + 0x7c);
        fun_410f38(ebp14, v16, v17);
    }
    if ((uint8_t)*(void***)(esi15 + 9) & 1) {
        v28 = (void**)static_cast<uint32_t>((uint8_t)*(void***)(esi15 + 0x6c));
        v17 = *(void***)(esi15 + 0x68);
        v16 = *(void***)(esi15 + 100);
        fun_411198(ebp14, v16, v17, v28);
    }
    if ((uint8_t)*(void***)(esi15 + 9) & 4) {
        v28 = *(void***)(esi15 + 0xb0);
        v17 = *(void***)(esi15 + 0xac);
        v16 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi15 + 0xb5));
        v29 = (void**)static_cast<uint32_t>((uint8_t)*(void***)(esi15 + 0xb4));
        v30 = *(void***)(esi15 + 0xa8);
        v31 = *(void***)(esi15 + 0xa4);
        v32 = *(void***)(esi15 + 0xa0);
        fun_40d41c(ebp14, v32, v31, v30, v29, v16, v17, v28);
    }
    if ((uint8_t)*(void***)(esi15 + 9) & 64) {
        v16 = *(void***)(esi15 + 0xec);
        v33 = *(void***)(esi15 + 0xe8);
        v34 = *(void***)(esi15 + 0xe4);
        v35 = *(void***)(esi15 + 0xe0);
        v36 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi15 + 0xdc));
        fun_40da88(ebp14, v36, v35, v34, v33, v16, v17, v28);
    }
    if ((int8_t)*(void***)(esi15 + 8) < (int8_t)0) {
        v28 = (void**)static_cast<uint32_t>((uint8_t)*(void***)(esi15 + 0x78));
        v17 = *(void***)(esi15 + 0x74);
        v16 = *(void***)(esi15 + 0x70);
        fun_411244(ebp14, v16, v17, v28);
    }
    if ((uint8_t)*(void***)(esi15 + 9) & 2) {
        v16 = esi15 + 60;
        fun_4112f0(ebp14, v16, v17, v28);
        *(uint8_t*)(ebp14 + 0x69) = (uint8_t)(*(uint8_t*)(ebp14 + 0x69) | 2);
    }
    if ((uint8_t)*(void***)(esi15 + 9) & 32 && (edi37 = (void**)0, (int8_t)0 < (int8_t)*(void***)(esi15 + 0xd8))) {
        ebx38 = (void*)0;
        esi15 = esi15;
        do {
            v16 = (void**)((int32_t)ebx38 + (uint8_t)*(void***)(esi15 + 0xd4));
            fun_40bb48(ebp14, v16, v17, v28);
            ebx38 = (void*)((int32_t)ebx38 + 16);
            ++edi37;
        } while ((int8_t)edi37 < (int8_t)*(void***)(esi15 + 0xd8));
    }
    edi39 = (void**)0;
    if ((int8_t)0 < (int8_t)*(void***)(esi15 + 48)) {
        ebx40 = (void*)0;
        esi15 = esi15;
        while (1) {
            edx41 = *(void***)(esi15 + 56);
            if ((uint1_t)(*(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40) < 0) | (uint1_t)(*(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40) == 0)) {
                if (*(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40)) {
                    if (*(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40) != -1) {
                        addr_0x403036_40:
                        ebx40 = (void*)((uint32_t)ebx40 + 16);
                        ++edi39;
                        if ((int8_t)edi39 < (int8_t)*(void***)(esi15 + 48)) 
                            continue; else 
                            break;
                    } else {
                        v28 = (void**)0;
                        v17 = *(void***)((uint8_t)edx41 + (uint32_t)ebx40 + 8);
                        v16 = *(void***)((uint8_t)edx41 + (uint32_t)ebx40 + 4);
                        fun_40d044(ebp14, v16, v17, 0);
                    }
                } else {
                    v42 = *(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40 + 8);
                    v43 = *(int32_t*)((uint8_t)edx41 + (uint32_t)ebx40 + 4);
                    fun_40d1e0(ebp14, v43, v42, 0, 0, v16, v17, v28);
                    *(int32_t*)((uint8_t)*(void***)(esi15 + 56) + (uint32_t)ebx40) = -2;
                    goto addr_0x403036_40;
                }
            } else {
                v16 = (void**)0x402de0;
                fun_40850c(ebp14, 0x402de0, v17, v28, v12, v10, v9, a2, a3, a4, a5, a6, a7, a8);
            }
            *(int32_t*)((uint8_t)*(void***)(esi15 + 56) + (uint32_t)ebx40) = -3;
            goto addr_0x403036_40;
        }
    }
    if (*(void***)(esi15 + 0xc0) && (ebx44 = *(void***)(esi15 + 0xbc), (uint8_t)ebx44 < (uint8_t)(ebx44 + (uint32_t)(*(void***)(esi15 + 0xc0) + (uint8_t)*(void***)(esi15 + 0xc0) * 4) * 4))) {
        esi45 = esi15;
        do {
            eax46 = fun_4076f4(ebp14, ebx44, v17, v28);
            if (eax46 != 1 && (*(void***)(ebx44 + 16) && (((uint8_t)*(void***)(ebx44 + 16) & 6) == 2 && (*(uint8_t*)(ebx44 + 3) & 32 || (eax46 == 3 || *(uint8_t*)(ebp14 + 0x6e) & 1))))) {
                v28 = *(void***)(ebx44 + 12);
                v17 = *(void***)(ebx44 + 8);
                fun_410b44(ebp14, ebx44, v17, v28);
            }
            ebx44 = ebx44 + 20;
        } while ((uint8_t)ebx44 < (uint8_t)(*(void***)(esi45 + 0xbc) + (uint32_t)(*(void***)(esi45 + 0xc0) + (uint8_t)*(void***)(esi45 + 0xc0) * 4) * 4));
    }
    goto a6;
    addr_0x402e71_14:
    esi15 = esi15;
    do {
        *(int8_t*)((uint32_t)edx24 + (uint8_t)*(void***)(esi15 + 76)) = (int8_t)~*(int8_t*)((uint32_t)edx24 + (uint8_t)*(void***)(esi15 + 76));
        edx24 = (void*)((uint32_t)edx24 + 1);
    } while ((int32_t)edx24 < (int32_t)static_cast<uint32_t>((uint16_t)*(void***)(esi15 + 22)));
    goto addr_0x402e83_10;
    addr_0x402e50_16:
    goto addr_0x402e53_6;
}

int32_t fun_40906c(void** a1, uint32_t a2, void** a3);

void fun_403678(void** a1, void** a2, void** a3);

void fun_404bc0(void** a1, void** a2, void** a3, void** a4) {
    void** ebp5;
    uint32_t v6;
    void** v7;
    int32_t eax8;
    int32_t v9;
    int32_t eax10;
    void** ebx11;
    int32_t edi12;
    void** esi13;
    void** v14;
    void** v15;

    ebp5 = a1;
    eax8 = fun_40906c(ebp5, v6, v7);
    v9 = eax8;
    eax10 = 0;
    if (0 < v9) {
        do {
            ebx11 = a2;
            edi12 = eax10 + 1;
            if ((uint8_t)0 < (uint8_t)*(void***)(ebp5 + 0xcc)) {
                esi13 = (void**)0;
                do {
                    v14 = *(void***)ebx11;
                    fun_403678(ebp5, v14, v15);
                    ++esi13;
                    ebx11 = ebx11 + 4;
                } while ((uint8_t)esi13 < (uint8_t)*(void***)(ebp5 + 0xcc));
            }
            eax10 = edi12;
        } while (eax10 < v9);
    }
    return;
}

struct s2 {
    int8_t[68] pad68;
    uint8_t f68;
};

void fun_4030bf(struct s2* ecx);

void** fun_410d98(void** a1, void** a2, void** a3, void** a4);

void fun_4030dc(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6) {
    void** v7;
    void** v8;
    void** ebp9;
    void** v10;
    void** edi11;
    void** v12;
    void** esi13;
    void** v14;
    void** ebx15;
    void** edi16;
    void** esi17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** ebp23;
    void* ebx24;
    void** edx25;
    void** v26;
    void** v27;
    int32_t v28;
    int32_t v29;
    int32_t v30;
    void** ebx31;
    void** esi32;
    uint32_t eax33;

    v7 = (void**)__return_address();
    v8 = ebp9;
    v10 = edi11;
    v12 = esi13;
    v14 = ebx15;
    edi16 = a4;
    esi17 = a5;
    if (!((uint8_t)*(void***)(edi16 + 0x68) & 4)) {
        v18 = (void**)fun_4030bf;
        fun_408404(edi16, fun_4030bf, v19, v20, v14, v12);
    }
    if (esi17) {
        if ((uint8_t)*(void***)(esi17 + 9) & 2 && !(*(uint8_t*)(edi16 + 0x69) & 2)) {
            v18 = esi17 + 60;
            fun_4112f0(edi16, v18, v21, v22);
        }
        ebp23 = (void**)0;
        if ((int8_t)0 < (int8_t)*(void***)(esi17 + 48)) {
            ebx24 = (void*)0;
            while (1) {
                edx25 = *(void***)(esi17 + 56);
                if ((uint1_t)(*(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24) < 0) | (uint1_t)(*(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24) == 0)) {
                    if (*(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24) < 0) {
                        if (*(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24) != -1) {
                            addr_0x403196_12:
                            ebx24 = (void*)((uint32_t)ebx24 + 16);
                            ++ebp23;
                            if ((int8_t)ebp23 < (int8_t)*(void***)(esi17 + 48)) 
                                continue; else 
                                break;
                        } else {
                            v26 = (void**)0;
                            v27 = *(void***)((uint8_t)edx25 + (uint32_t)ebx24 + 8);
                            v18 = *(void***)((uint8_t)edx25 + (uint32_t)ebx24 + 4);
                            fun_40d044(edi16, v18, v27, 0);
                        }
                    } else {
                        v28 = *(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24);
                        v29 = *(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24 + 8);
                        v30 = *(int32_t*)((uint8_t)edx25 + (uint32_t)ebx24 + 4);
                        fun_40d1e0(edi16, v30, v29, 0, v28, v18, v27, 0);
                        *(int32_t*)((uint8_t)*(void***)(esi17 + 56) + (uint32_t)ebx24) = -2;
                        goto addr_0x403196_12;
                    }
                } else {
                    v18 = (void**)0x402de0;
                    fun_40850c(edi16, 0x402de0, v27, 0, v14, v12, v10, v8, v7, a1, a2, a3, a4, a5);
                }
                *(int32_t*)((uint8_t)*(void***)(esi17 + 56) + (uint32_t)ebx24) = -3;
                goto addr_0x403196_12;
            }
        }
        if (*(void***)(esi17 + 0xc0) && (ebx31 = *(void***)(esi17 + 0xbc), (uint8_t)ebx31 < (uint8_t)(ebx31 + (uint32_t)(*(void***)(esi17 + 0xc0) + (uint8_t)*(void***)(esi17 + 0xc0) * 4) * 4))) {
            esi32 = esi17;
            do {
                v18 = ebx31;
                eax33 = fun_4076f4(edi16, v18, v27, v26);
                if (eax33 != 1 && (*(void***)(ebx31 + 16) && ((uint8_t)*(void***)(ebx31 + 16) & 8 && (*(uint8_t*)(ebx31 + 3) & 32 || (eax33 == 3 || *(uint8_t*)(edi16 + 0x6e) & 1))))) {
                    v26 = *(void***)(ebx31 + 12);
                    v27 = *(void***)(ebx31 + 8);
                    v18 = ebx31;
                    fun_410b44(edi16, v18, v27, v26);
                }
                ebx31 = ebx31 + 20;
            } while ((uint8_t)ebx31 < (uint8_t)(*(void***)(esi32 + 0xbc) + (uint32_t)(*(void***)(esi32 + 0xc0) + (uint8_t)*(void***)(esi32 + 0xc0) * 4) * 4));
        }
    }
    *(void***)(edi16 + 0x68) = (void**)((uint8_t)*(void***)(edi16 + 0x68) | 8);
    fun_410d98(edi16, v18, v27, v26);
    goto a3;
}

void** fun_402a10(void** a1, void** a2);

void** fun_4029a0(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14, void** a15) {
    void** eax16;
    void** eax17;

    if (a1 && a2) {
        eax16 = *(void***)(a1 + 0x24c);
        if (!eax16) {
            eax17 = fun_402a10(a1, a2);
        } else {
            eax17 = (void**)eax16(a1, a2);
        }
    }
    return eax17;
}

void load_constants(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14, void** a15, void** a16);

struct s3 {
    int8_t[510] pad510;
    uint8_t f510;
};

void fun_407e50(void** a1, struct s3* a2, void** a3, void** a4, void** a5);

/* dynamic_constant_loading? */
void dynamic_constant_loading_(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7);

uint32_t byte_processing_loop1(void** a1, void** a2, void** a3, void** a4, void** a5);

/* file_processor? */
uint32_t file_processor_(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10) {
    uint8_t* edi11;
    void** ax12;
    int32_t edx13;
    uint8_t di14;
    uint8_t cx15;
    int32_t ecx16;
    int32_t edx17;
    void** edi18;
    void** esi19;
    void** edi20;
    void** edi21;
    uint32_t eax22;
    int16_t ax23;
    uint32_t eax24;

    *(void***)(a3 + 26) = a2;
    edi11 = (uint8_t*)(a3 + 0x2222);
    *(void***)(a3 + 22) = a1;
    *(void***)(a3 + 18) = a4;
    *(void***)(a3 + 14) = (void**)0x800;
    ax12 = (void**)a1(edi11, 0x800, a4);
    if (!(int1_t)(ax12 == 4)) {
        *(uint8_t*)&edx13 = (uint8_t)static_cast<uint16_t>(*(uint8_t*)(a3 + 0x2223));
        di14 = (uint8_t)static_cast<uint16_t>(*edi11);
        cx15 = (uint8_t)static_cast<uint16_t>(*(uint8_t*)(a3 + 0x2224));
        *(uint8_t*)(a3 + 2) = di14;
        *(uint8_t*)(a3 + 6) = *(uint8_t*)&edx13;
        *(uint8_t*)(a3 + 10) = cx15;
        *(void***)(a3 + 12) = (void**)0;
        *(void***)(a3 + 14) = (void**)3;
        *(void***)(a3 + 16) = ax12;
        if (*(uint8_t*)&edx13 < (uint8_t)4 || *(uint8_t*)&edx13 > (uint8_t)6) {
            return 1;
        } else {
            ecx16 = 16 - edx13;
            edx17 = 0xffff >> *(int8_t*)&ecx16;
            *(void***)(a3 + 8) = *(void***)&edx17;
            if (di14 <= (uint8_t)1) {
                if (di14) {
                    load_constants(a3 + 0x2fa2, 0x41d760, 0x100, edi18, esi19, __return_address(), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
                    fun_407e50(a3, 0x41d860, a3 + 0x2fa2, 0x41d760, 0x100);
                }
                edi20 = a3 + 0x30e2;
                load_constants(edi20, 0x41d740, 16, edi18, esi19, __return_address(), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
                dynamic_constant_loading_(16, edi20, 0x41d750, a3 + 0x2b22, edi20, 0x41d740, 16);
                load_constants(a3 + 0x30f2, 0x41d710, 16, 16, edi20, 0x41d750, a3 + 0x2b22, edi20, 0x41d740, 16, edi18, esi19, __return_address(), a1, a2, a3);
                load_constants(a3 + 0x3102, 0x41d720, 32, a3 + 0x30f2, 0x41d710, 16, 16, edi20, 0x41d750, a3 + 0x2b22, edi20, 0x41d740, 16, edi18, esi19, __return_address());
                edi21 = a3 + 0x30a2;
                load_constants(edi21, 0x41d690, 64, a3 + 0x3102, 0x41d720, 32, a3 + 0x30f2, 0x41d710, 16, 16, edi20, 0x41d750, a3 + 0x2b22, edi20, 0x41d740, 16);
                dynamic_constant_loading_(64, edi21, 0x41d6d0, a3 + 0x2a22, edi18, esi19, __return_address());
                eax22 = byte_processing_loop1(a3, 64, edi21, 0x41d6d0, a3 + 0x2a22);
                ax23 = (int16_t)(*(int16_t*)&eax22 - 0x306);
                *(int16_t*)&eax22 = -ax23;
                eax24 = eax22 - (eax22 + (uint1_t)(eax22 < eax22 + (uint1_t)!!ax23));
                *(uint8_t*)&eax24 = (uint8_t)(*(uint8_t*)&eax24 & 0xfc);
                return eax24 + 4;
            } else {
                return 2;
            }
        }
    } else {
        return 3;
    }
}

void** fun_408578(void** a1, void** a2);

void** fun_408404(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6) {
    void* esp7;
    void** ebx8;
    void** edx9;
    void** eax10;
    void* eax11;
    void** eax12;
    void* ecx13;
    void* edi14;
    void** ebp15;
    void** esi16;
    uint32_t eax17;
    void* edx18;
    void* edx19;
    void* edx20;

    esp7 = (void*)((int32_t)__zero_stack_offset() - 28 - 4 - 4 - 4 - 4);
    ebx8 = a2;
    edx9 = *(void***)(a1 + 0x6c);
    if (!((uint8_t)edx9 & 0xc0000)) {
        addr_0x4084de_3:
        eax10 = *(void***)(a1 + 64);
        if (eax10) {
            eax10(a1, ebx8);
        }
    } else {
        if (!(int1_t)(*(void***)ebx8 == 35)) {
            if ((uint8_t)edx9 & 0x80000) {
                ebx8 = (void**)((int32_t)esp7 + 16);
                goto addr_0x4084de_3;
            }
        } else {
            eax11 = (void*)1;
            if (*(void***)(ebx8 + 1) != 32) {
                do {
                    eax11 = (void*)((uint32_t)eax11 + 1);
                    if ((int32_t)eax11 > (int32_t)14) 
                        break;
                } while (*(int8_t*)((uint32_t)eax11 + (uint8_t)ebx8) != 32);
            }
            if (!((uint8_t)edx9 & 0x80000)) 
                goto addr_0x4084c4_13; else 
                goto addr_0x40844c_14;
        }
    }
    eax12 = fun_408578(a1, ebx8);
    return eax12;
    addr_0x4084c4_13:
    ebx8 = (void**)((uint8_t)ebx8 + (uint32_t)eax11);
    goto addr_0x4084de_3;
    addr_0x40844c_14:
    ecx13 = (void*)0;
    edi14 = (void*)((uint32_t)eax11 + 0xffffffff);
    ebp15 = (void**)((int32_t)esp7 + 16);
    if ((int32_t)0 >= (int32_t)edi14) 
        goto addr_0x4084bc_16;
    esi16 = ebp15;
    eax17 = (uint32_t)edi14 & 3;
    if (!((uint1_t)((int32_t)edi14 < (int32_t)0) | (uint1_t)(edi14 == 0))) {
        if (!eax17) {
            do {
                addr_0x408490_19:
                *(int8_t*)((uint32_t)ecx13 + (uint8_t)esi16) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)ecx13 + 1);
                edx18 = (void*)((uint32_t)ecx13 + 1);
                *(int8_t*)((uint32_t)edx18 + (uint8_t)esi16) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)edx18 + 1);
                edx19 = (void*)((uint32_t)ecx13 + 2);
                *(int8_t*)((uint32_t)edx19 + (uint8_t)esi16) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)edx19 + 1);
                edx20 = (void*)((uint32_t)ecx13 + 3);
                *(int8_t*)((uint32_t)edx20 + (uint8_t)esi16) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)edx20 + 1);
                ecx13 = (void*)((uint32_t)ecx13 + 4);
            } while ((int32_t)ecx13 < (int32_t)edi14);
            goto addr_0x4084bc_16;
        } else {
            if ((int32_t)eax17 > (int32_t)1) {
                if ((int32_t)eax17 > (int32_t)2) {
                    ecx13 = (void*)1;
                }
                *(int8_t*)((uint32_t)ecx13 + (uint8_t)ebp15) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)ecx13 + 1);
                ecx13 = (void*)((uint32_t)ecx13 + 1);
            }
        }
    }
    *(int8_t*)((uint32_t)ecx13 + (uint8_t)esi16) = *(int8_t*)((uint8_t)ebx8 + (uint32_t)ecx13 + 1);
    ecx13 = (void*)((uint32_t)ecx13 + 1);
    if ((int32_t)ecx13 >= (int32_t)edi14) {
        addr_0x4084bc_16:
        *(int8_t*)((uint32_t)ecx13 + (uint8_t)ebp15) = 0;
        ebx8 = ebp15;
        goto addr_0x4084de_3;
    } else {
        esi16 = esi16;
        goto addr_0x408490_19;
    }
}

void fun_4178d3(void** a1, void** a2, void** a3, void** a4);

void** fun_402a10(void** a1, void** a2) {
    void** v3;
    void** v4;
    void** v5;

    if (a1 && a2) {
        fun_4178d3(a2, v3, v4, v5);
    }
    return a2;
}

void** fun_40aaf8(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, ...);

void** fun_410cd0(void** a1) {
    void** v2;
    void** v3;
    void** v4;
    void** ebx5;
    void** v6;
    void** v7;
    void** v8;
    void** v9;
    void** v10;
    void** eax11;

    v2 = (void**)(8 - *(uint8_t*)(a1 + 0x12c));
    v3 = (void**)(*(uint8_t*)(a1 + 0x12c) + ((int32_t)__zero_stack_offset() - 40 - 4 + 24));
    eax11 = fun_40aaf8(a1, v3, v2, v4, ebx5, v6, v7, v8, v9, v10, 0x474e5089, 0xa1a0a0d);
    if (*(uint8_t*)(a1 + 0x12c) <= 2) {
        *(uint8_t*)(a1 + 0x69) = (uint8_t)(*(uint8_t*)(a1 + 0x69) | 16);
    }
    return eax11;
}

void fun_40b930(void* ecx);

void** fun_410edc(void** a1, uint32_t a2, void** a3, void** a4) {
    void*** esp5;
    void** v6;
    void** v7;
    void** ebx8;
    void** esi9;
    void** v10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** eax18;

    esp5 = (void***)((int32_t)__zero_stack_offset() - 36 - 4 - 4);
    if ((int32_t)a2 > (int32_t)3) {
        fun_40850c(a1, fun_40b930, v6, v7, ebx8, esi9, v10, v11, v12, v13, v14, v15, v16, v17);
        esp5 = esp5 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    fun_410b88(a1, 0x406aaa, 1);
    fun_410bf4(a1, esp5 + 31, 1, 0x410f17, a1, 0x406aaa, 1);
    eax18 = fun_410c30(a1, 0x406aaa, 1);
    return eax18;
}

void** fun_40ce3c(void** a1, void** a2, void** a3);

struct s4 {
    void** f0;
    int8_t[3] pad4;
    void** f4;
    int8_t[3] pad8;
    uint32_t f8;
    uint32_t f12;
    void** f16;
};

void** fun_40abd8(void** a1, void** a2, void** a3, void** a4, struct s4* a5, void** a6, void** a7, int32_t a8, void** a9, void** a10, void** a11);

void fun_407670(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8);

void fun_407694(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, ...);

void** fun_40aec0(void** a1, struct s4* a2, void** a3);

void** fun_40b9b8(void** a1, void** a2, int32_t a3, void** a4, void** a5, uint32_t a6, void** a7, void** a8) {
    void** ebp9;
    void** v10;
    void** v11;
    void** ebx12;
    void** esi13;
    void** edi14;
    void** ebp15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** eax22;
    void* esp23;
    void** v24;
    void** eax25;
    void*** esp26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void* esp34;
    int32_t v35;
    void** eax36;
    void* edx37;
    uint32_t eax38;
    void** v39;
    uint32_t eax40;
    uint32_t eax41;
    void** v42;
    void** v43;
    void** v44;
    void** v45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    void* esp50;
    void* v51;
    void** ebx52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;
    void** v58;
    void* esp59;
    uint32_t edx60;
    uint32_t eax61;
    void** v62;
    uint32_t eax63;
    uint32_t eax64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** v70;
    void** v71;
    void** v72;
    void** v73;

    ebp9 = a5;
    if (!a2) {
        addr_0x40b9eb_4:
        eax22 = fun_40850c(a1, 0x40b958, v10, v11, ebx12, esi13, edi14, ebp15, v16, v17, v18, v19, v20, v21);
    } else {
        esp23 = (void*)((int32_t)__zero_stack_offset() - 60 - 4 - 4 - 4 - 4 - 4);
        v10 = (void**)((int32_t)esp23 + 32);
        v24 = a2;
        eax25 = fun_40ce3c(a1, v24, v10);
        esp26 = (void***)((int32_t)esp23 - 4 - 4 - 4 - 4 + 4 + 16);
        if (eax25) 
            goto addr_0x40ba00_9; else 
            goto addr_0x40b9eb_4;
    }
    addr_0x40bb20_10:
    return eax22;
    addr_0x40ba00_9:
    if (a3) {
        v24 = (void**)0x40b990;
        fun_40850c(a1, 0x40b990, v10, v27, ebx12, esi13, edi14, ebp15, v28, v29, v30, v31, v32, v33);
        esp26 = esp26 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    if (!a4) {
        ebp9 = (void**)0;
    }
    if (ebp9) {
        esp34 = (void*)(esp26 - 12);
        eax36 = fun_40abd8(a1, a4, ebp9, 0, (int32_t)esp34 + 44, v24, v10, v35, ebx12, esi13, edi14);
        ebp9 = eax36;
        esp26 = (void***)((int32_t)esp34 - 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    edx37 = (void*)((uint8_t)ebp9 + (uint8_t)eax25 + 2);
    eax38 = (uint32_t)edx37 >> 24;
    *(int8_t*)&v39 = *(int8_t*)&eax38;
    eax40 = (uint32_t)edx37 >> 16;
    *(int8_t*)(&v39 + 1) = *(int8_t*)&eax40;
    eax41 = (uint32_t)edx37 >> 8;
    *(int8_t*)(&v39 + 2) = *(int8_t*)&eax41;
    *(int8_t*)(&v39 + 3) = *(int8_t*)&edx37;
    v42 = (void**)4;
    fun_40aaf8(a1, esp26 + 24, 4, v43, ebx12, esi13, edi14, ebp15, v44, v45, v39, v46);
    fun_40aaf8(a1, 0x406a82, 4, 0x40ba69, a1, esp26 + 24, 4, v47, ebx12, esi13, edi14, ebp15);
    fun_407670(a1, esp26 + 24, 4, v48, ebx12, esi13, edi14, ebp15);
    fun_407694(a1, 0x406a82, 4, 0x40ba85, a1, esp26 + 24, 4, v49, ebx12, esi13, edi14, ebp15);
    esp50 = (void*)(esp26 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    *(int8_t*)((int32_t)v51 + (uint8_t)eax25 + 1) = 0;
    ebx52 = eax25 + 2;
    if (v53 && ebx52) {
        v42 = ebx52;
        fun_407694(a1, v53, v42, v54, ebx12, esi13, edi14, ebp15, v55, v56, v39, v57);
        fun_40aaf8(a1, v53, ebx52, 0x40babb, a1, v53, v42, v58, ebx12, esi13, edi14, ebp15);
        esp50 = (void*)((int32_t)esp50 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    if (ebp9) {
        esp59 = (void*)((int32_t)esp50 - 8);
        fun_40aec0(a1, (int32_t)esp59 + 40, v42);
        esp50 = (void*)((int32_t)esp59 - 4 - 4 - 4 + 4 + 16);
    }
    edx60 = *(uint32_t*)(a1 + 0x110);
    eax61 = edx60 >> 24;
    *(int8_t*)&v62 = *(int8_t*)&eax61;
    eax63 = edx60 >> 16;
    *(int8_t*)(&v62 + 1) = *(int8_t*)&eax63;
    eax64 = edx60 >> 8;
    *(int8_t*)(&v62 + 2) = *(int8_t*)&eax64;
    *(int8_t*)(&v62 + 3) = *(int8_t*)&edx60;
    fun_40aaf8(a1, (int32_t)esp50 + 20, 4, v65, ebx12, esi13, edi14, ebp15, v66, v62, v39, v67);
    eax22 = fun_4029a0(a1, v39, 4, v68, ebx12, esi13, edi14, ebp15, v69, v62, v39, v70, v71, v72, v73);
    goto addr_0x40bb20_10;
}

struct s5 {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    void* f4;
};

void fun_40bd90(int32_t ecx);

void** fun_40bdb0(void** a1, struct s5* a2, void** a3, void** a4) {
    void*** esp5;
    void** eax6;
    void** v7;
    void** v8;
    void** ebx9;
    void** esi10;
    void** edi11;
    void** ebp12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** eax19;
    void** v20;
    void** esi21;
    void* bl22;
    void* dl23;
    void** eax24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    uint32_t v40;

    esp5 = (void***)((int32_t)__zero_stack_offset() - 28 - 4 - 4 - 4 - 4);
    eax6 = a3;
    if (!((uint8_t)*(void**)&eax6 & 2)) {
        if (!a2->f3 || (uint8_t)a2->f3 > (uint8_t)*(void**)(a1 + 0x128)) {
            eax19 = fun_40850c(a1, fun_40bd90, v7, v8, ebx9, esi10, edi11, ebp12, v13, v14, v15, v16, v17, v18);
        } else {
            *(void**)&v20 = a2->f3;
            esi21 = (void**)1;
            goto addr_0x40be5d_5;
        }
    } else {
        bl22 = (void*)8;
        if (eax6 != 3) {
            bl22 = *(void**)(a1 + 0x128);
        }
        if (!a2->f0) 
            goto addr_0x40bdf5_9;
        if ((uint8_t)a2->f0 > (uint8_t)bl22) 
            goto addr_0x40bdf5_9;
        dl23 = a2->f1;
        if (!dl23) 
            goto addr_0x40bdf5_9;
        if ((uint8_t)dl23 > (uint8_t)bl22) 
            goto addr_0x40bdf5_9;
        *(void**)&eax6 = a2->f2;
        if (!*(void**)&eax6) 
            goto addr_0x40bdf5_9;
        if ((uint8_t)*(void**)&eax6 <= (uint8_t)bl22) 
            goto addr_0x40be08_15; else 
            goto addr_0x40bdf5_9;
    }
    addr_0x40beb3_16:
    return eax19;
    addr_0x40be5d_5:
    eax24 = a3;
    if (!(*(uint8_t*)&eax24 & 4)) {
        addr_0x40be89_17:
        fun_410b88(a1, 0x406aa0, esi21, a1, 0x406aa0, esi21);
        fun_410bf4(a1, esp5 + 28, esi21, 0x40be9c, a1, 0x406aa0, esi21, a1, esp5 + 28, esi21, 0x40be9c, a1, 0x406aa0, esi21);
        eax19 = fun_410c30(a1, 0x406aa0, esi21, a1, 0x406aa0, esi21);
        goto addr_0x40beb3_16;
    } else {
        if (!a2->f4 || (uint8_t)a2->f4 > (uint8_t)*(void**)(a1 + 0x128)) {
            eax19 = fun_40850c(a1, fun_40bd90, v25, v26, ebx9, esi10, edi11, ebp12, v27, v28, v29, v20, v30, v31);
            goto addr_0x40beb3_16;
        } else {
            *(void**)((int32_t)esp5 + (uint8_t)esi21 + 28) = a2->f4;
            ++esi21;
            goto addr_0x40be89_17;
        }
    }
    addr_0x40bdf5_9:
    eax19 = fun_40850c(a1, fun_40bd90, v32, v33, ebx9, esi10, edi11, ebp12, v34, v35, v36, v37, v38, v39);
    goto addr_0x40beb3_16;
    addr_0x40be08_15:
    *(void**)&v40 = a2->f0;
    v20 = (void**)(v40 & 0xff0000ff | static_cast<uint32_t>((uint8_t)dl23) << 8 | ((uint8_t)eax6 & 0xff) << 16);
    esi21 = (void**)3;
    goto addr_0x40be5d_5;
}

struct s6 {
    void** f0;
    int8_t[3] pad4;
    uint8_t f4;
};

uint32_t fun_4076f4(void** a1, void** a2, void** a3, void** a4) {
    void** ebp5;
    void*** eax6;
    void* ecx7;
    void* v8;
    struct s6* edx9;
    void*** ebx10;
    uint32_t eax11;
    void** esi12;
    struct s6* edi13;
    int32_t ecx14;
    int1_t zf15;
    void** esi16;
    struct s6* edi17;
    int32_t ecx18;
    int1_t zf19;
    void** esi20;
    struct s6* edi21;
    int32_t ecx22;
    int1_t zf23;
    void** esi24;
    struct s6* edi25;
    int32_t ecx26;
    int1_t zf27;
    void** esi28;
    struct s6* edi29;
    uint32_t ecx30;
    int1_t zf31;
    void** esi32;
    struct s6* edi33;
    int32_t ecx34;
    int1_t zf35;
    void** esi36;
    struct s6* edi37;
    int32_t ecx38;
    int1_t zf39;
    uint32_t eax40;

    ebp5 = a2;
    if (a1) 
        goto addr_0x40770f_2;
    if (!ebp5) 
        goto addr_0x4077fb_4;
    addr_0x40770f_2:
    eax6 = *(void****)(a1 + 0x220);
    if ((uint1_t)((uint1_t)((int32_t)eax6 < 0) | (uint1_t)(eax6 == 0))) {
        goto addr_0x4077fb_4;
    }
    ecx7 = (void*)((int32_t)(eax6 + (int32_t)eax6 * 4) + (uint8_t)*(void***)(a1 + 0x224));
    v8 = ecx7;
    edx9 = (struct s6*)((uint32_t)ecx7 - 5);
    ebx10 = eax6;
    eax11 = (uint32_t)-(int32_t)eax6 & 3;
    if (!eax11) {
        do {
            addr_0x407798_7:
            esi12 = ebp5;
            edi13 = edx9;
            ecx14 = 4;
            zf15 = 1;
            while (ecx14) {
                --ecx14;
                zf15 = *(void***)esi12 == edi13->f0;
                edi13->f0 = *(void***)esi12;
                edi13 = (struct s6*)&edi13->pad4;
                ++esi12;
            }
            if (zf15) 
                goto addr_0x407720_11;
            --edx9;
            esi16 = ebp5;
            edi17 = edx9;
            ecx18 = 4;
            zf19 = 1;
            while (ecx18) {
                --ecx18;
                zf19 = *(void***)esi16 == edi17->f0;
                edi17->f0 = *(void***)esi16;
                edi17 = (struct s6*)&edi17->pad4;
                ++esi16;
            }
            if (zf19) 
                goto addr_0x407720_11;
            --edx9;
            esi20 = ebp5;
            edi21 = edx9;
            ecx22 = 4;
            zf23 = 1;
            while (ecx22) {
                --ecx22;
                zf23 = *(void***)esi20 == edi21->f0;
                edi21->f0 = *(void***)esi20;
                edi21 = (struct s6*)&edi21->pad4;
                ++esi20;
            }
            if (zf23) 
                goto addr_0x407720_11;
            --edx9;
            esi24 = ebp5;
            edi25 = edx9;
            ecx26 = 4;
            zf27 = 1;
            while (ecx26) {
                --ecx26;
                zf27 = *(void***)esi24 == edi25->f0;
                edi25->f0 = *(void***)esi24;
                edi25 = (struct s6*)&edi25->pad4;
                ++esi24;
            }
            if (zf27) 
                goto addr_0x407720_11;
            ebx10 = ebx10 - 4;
            --edx9;
        } while (ebx10);
        goto addr_0x4077fb_4;
    } else {
        if ((int32_t)eax11 < (int32_t)3) {
            if ((int32_t)eax11 < (int32_t)2) {
                esi28 = ebp5;
                edi29 = edx9;
                ecx30 = 4;
                zf31 = 1;
                while (ecx30) {
                    --ecx30;
                    zf31 = *(void***)esi28 == edi29->f0;
                    edi29->f0 = *(void***)esi28;
                    edi29 = (struct s6*)&edi29->pad4;
                    ++esi28;
                }
                if (zf31) 
                    goto addr_0x407720_11;
                --ebx10;
                edx9 = (struct s6*)((uint32_t)v8 - 10);
            }
            esi32 = ebp5;
            edi33 = edx9;
            ecx34 = 4;
            zf35 = 1;
            while (ecx34) {
                --ecx34;
                zf35 = *(void***)esi32 == edi33->f0;
                edi33->f0 = *(void***)esi32;
                edi33 = (struct s6*)&edi33->pad4;
                ++esi32;
            }
            if (zf35) 
                goto addr_0x407720_11;
            --ebx10;
            --edx9;
        }
        esi36 = ebp5;
        edi37 = edx9;
        ecx38 = 4;
        zf39 = 1;
        while (ecx38) {
            --ecx38;
            zf39 = *(void***)esi36 == edi37->f0;
            edi37->f0 = *(void***)esi36;
            edi37 = (struct s6*)&edi37->pad4;
            ++esi36;
        }
        if (zf39) {
            addr_0x407720_11:
            eax40 = static_cast<uint32_t>(edx9->f4);
        } else {
            --edx9;
            --ebx10;
            if (!ebx10) {
                addr_0x4077fb_4:
                eax40 = 0;
            } else {
                goto addr_0x407798_7;
            }
        }
    }
    return eax40;
}

void** fun_410b44(void** a1, void** a2, void** a3, void** a4) {
    void** eax5;

    fun_410b88(a1, a1, a4);
    fun_410bf4(a1, a3, a4, 0x410b64, a1, a1, a4);
    eax5 = fun_410c30(a1, a1, a4);
    return eax5;
}

struct s7 {
    int8_t[2] pad2;
    uint16_t f2;
    uint16_t f4;
    uint16_t f6;
    uint16_t f8;
};

void fun_40c830(void* ecx);

void fun_40c918(void** a1, void** a2, void** a3, uint32_t a4, void** a5, void** a6, void** a7, void** a8) {
    void*** esp9;
    int32_t v10;
    void** v11;
    uint32_t eax12;
    struct s7* v13;
    uint32_t ebx14;
    uint32_t eax15;
    uint32_t edx16;
    uint32_t eax17;
    uint32_t ecx18;
    void** v19;
    uint32_t ecx20;
    void** v21;
    void** v22;
    void** v23;
    void** ebx24;
    int32_t v25;
    void** v26;

    esp9 = (void***)((int32_t)__zero_stack_offset() - 4);
    if (v10 != 3) {
        if (v10) {
            if (v10 != 2) {
                v11 = (void**)0x40c8f0;
            } else {
                eax12 = static_cast<uint32_t>(v13->f2);
                ebx14 = eax12 >> 8;
                *(uint8_t*)&a3 = *(uint8_t*)&ebx14;
                *(int8_t*)(&a3 + 1) = *(int8_t*)&eax12;
                eax15 = static_cast<uint32_t>(v13->f4);
                edx16 = eax15 >> 8;
                *(uint8_t*)(&a3 + 2) = *(uint8_t*)&edx16;
                *(int8_t*)(&a3 + 3) = *(int8_t*)&eax15;
                eax17 = static_cast<uint32_t>(v13->f6);
                ecx18 = eax17 >> 8;
                *(uint8_t*)&a4 = *(uint8_t*)&ecx18;
                *(int8_t*)((int32_t)&a4 + 1) = *(int8_t*)&eax17;
                if (!(int1_t)(*(void**)(v19 + 0x127) == 8) || !((uint8_t)(*(uint8_t*)&ebx14 | *(uint8_t*)&edx16) | *(uint8_t*)&ecx18)) {
                    fun_410b88(v19, 0x406ab9, 6, v19, 0x406ab9, 6);
                    fun_410bf4(v19, esp9 + 16, 6, 0x40ca58, v19, 0x406ab9, 6, v19, esp9 + 16, 6, 0x40ca58, v19, 0x406ab9, 6);
                    fun_410c30(v19, 0x406ab9, 6, v19, 0x406ab9, 6);
                    goto addr_0x40ca82_9;
                } else {
                    v11 = (void**)0x40c8b0;
                }
            }
        } else {
            ecx20 = static_cast<uint32_t>((uint8_t)*(void**)(v19 + 0x127));
            if ((int32_t)static_cast<uint32_t>(v13->f8) < (int32_t)(1 << *(uint8_t*)&ecx20)) {
                fun_410b88(v19, 0x406ab9, 2, v19, 0x406ab9, 2);
                fun_410bf4(v19, esp9 + 16, 2, 0x40c9c9, v19, 0x406ab9, 2, v19, esp9 + 16, 2, 0x40c9c9, v19, 0x406ab9, 2);
                fun_410c30(v19, 0x406ab9, 2, v19, 0x406ab9, 2);
                goto addr_0x40ca82_9;
            } else {
                v11 = (void**)0x40c870;
            }
        }
    } else {
        if ((uint1_t)((int8_t)v21 < (int8_t)0) | (uint1_t)(v21 == 0)) 
            goto addr_0x40c941_16; else 
            goto addr_0x40c936_17;
    }
    addr_0x40ca7c_18:
    fun_40850c(v19, v11, v22, v23, ebx24, __return_address(), a1, a2, a3, *(void***)&a4, a5, a6, a7, a8);
    addr_0x40ca82_9:
    goto v25;
    addr_0x40c941_16:
    v11 = (void**)fun_40c830;
    goto addr_0x40ca7c_18;
    addr_0x40c936_17:
    if ((int8_t)v21 > (int8_t)static_cast<uint32_t>((uint16_t)*(void***)(v19 + 0x118))) 
        goto addr_0x40c941_16;
    fun_410b88(v19, 0x406ab9, v21);
    fun_410bf4(v19, v26, v21, 0x40c95f, v19, 0x406ab9, v21);
    fun_410c30(v19, 0x406ab9, v21);
    goto addr_0x40ca82_9;
}

struct s8 {
    uint8_t f0;
    int8_t[1] pad2;
    uint16_t f2;
    uint16_t f4;
    uint16_t f6;
    uint16_t f8;
};

void fun_40cb50(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7) {
    void*** esp8;
    int32_t eax9;
    int32_t v10;
    uint32_t ecx11;
    void** v12;
    struct s8* v13;
    void** ebx14;
    void** v15;
    void** v16;
    int32_t v17;
    void** v18;
    void** v19;
    void** v20;
    void** ebx21;
    void** esi22;
    uint32_t eax23;
    uint32_t ebx24;
    void** v25;
    uint32_t eax26;
    uint32_t edx27;
    uint32_t eax28;
    uint32_t ecx29;
    void** v30;
    uint32_t edx31;
    int32_t v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;

    esp8 = (void***)((int32_t)__zero_stack_offset() - 4 - 4);
    eax9 = v10;
    if (eax9 != 3) {
        if (!(*(uint8_t*)&eax9 & 2)) {
            ecx11 = static_cast<uint32_t>((uint8_t)*(void**)(v12 + 0x127));
            if ((int32_t)static_cast<uint32_t>(v13->f8) < (int32_t)(1 << *(uint8_t*)&ecx11)) {
                ebx14 = (void**)(esp8 + 16);
                v15 = (void**)2;
                v16 = v12;
                v17 = 0x40cc7d;
                fun_410b88(v16, 0x406a6e, 2, v16, 0x406a6e, 2);
                v18 = (void**)2;
            } else {
                fun_40850c(v12, 0x40cb10, v19, v20, ebx21, esi22, __return_address(), a1, a2, a3, a4, a5, a6, a7);
                goto addr_0x40cc95_8;
            }
        } else {
            eax23 = static_cast<uint32_t>(v13->f2);
            ebx24 = eax23 >> 8;
            *(uint8_t*)&v25 = *(uint8_t*)&ebx24;
            *(int8_t*)(&v25 + 1) = *(int8_t*)&eax23;
            eax26 = static_cast<uint32_t>(v13->f4);
            edx27 = eax26 >> 8;
            *(uint8_t*)(&v25 + 2) = *(uint8_t*)&edx27;
            *(int8_t*)(&v25 + 3) = *(int8_t*)&eax26;
            eax28 = static_cast<uint32_t>(v13->f6);
            ecx29 = eax28 >> 8;
            *(uint8_t*)&v30 = *(uint8_t*)&ecx29;
            *(int8_t*)(&v30 + 1) = *(int8_t*)&eax28;
            if (!(int1_t)(*(void**)(v12 + 0x127) == 8)) 
                goto addr_0x40cc18_11;
            if (!((uint8_t)(*(uint8_t*)&ebx24 | *(uint8_t*)&edx27) | *(uint8_t*)&ecx29)) 
                goto addr_0x40cc18_11; else 
                goto addr_0x40cc06_13;
        }
    } else {
        edx31 = static_cast<uint32_t>((uint16_t)*(void***)(v12 + 0x118));
        if (*(uint16_t*)&edx31 || !(*(uint8_t*)(v12 + 0x230) & 1)) {
            if (static_cast<uint16_t>(v13->f0) <= *(uint16_t*)&edx31) 
                goto addr_0x40cb98_18; else 
                goto addr_0x40cb84_19;
        } else {
            addr_0x40cb98_18:
            ebx14 = (void**)(esp8 + 16);
            goto addr_0x40cba1_20;
        }
    }
    addr_0x40cc82_21:
    fun_410bf4(v12, ebx14, v18, v17, v16, 0x406a6e, v15, v12, ebx14, v18, v17, v16, 0x406a6e, v15);
    fun_410c30(v12, 0x406a6e, v15, v12, 0x406a6e, v15);
    addr_0x40cc95_8:
    goto v32;
    addr_0x40cc18_11:
    ebx14 = (void**)(esp8 + 16);
    v15 = (void**)6;
    v16 = v12;
    v17 = 0x40cc2c;
    fun_410b88(v16, 0x406a6e, 6, v16, 0x406a6e, 6);
    v18 = (void**)6;
    goto addr_0x40cc82_21;
    addr_0x40cc06_13:
    fun_40850c(v12, 0x40cad0, v33, v34, ebx21, esi22, __return_address(), a1, v25, v30, a4, a5, a6, a7);
    goto addr_0x40cc95_8;
    addr_0x40cb84_19:
    fun_40850c(v12, 0x40ca90, v35, v36, ebx21, esi22, __return_address(), a1, a2, a3, a4, a5, a6, a7);
    goto addr_0x40cc95_8;
    addr_0x40cba1_20:
    v15 = (void**)1;
    v16 = v12;
    v17 = 0x40cbb2;
    fun_410b88(v16, 0x406a6e, 1, v16, 0x406a6e, 1);
    v18 = (void**)1;
    goto addr_0x40cc82_21;
}

void fun_40ccb0(void* ecx);

void fun_410f38(void** a1, void** a2, void** a3) {
    void* edx4;
    uint32_t eax5;
    void** v6;
    uint32_t eax7;
    uint32_t eax8;
    void** v9;
    void** ebx10;
    void** esi11;
    void** edi12;
    void** ebp13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;

    if ((int8_t)a3 <= (int8_t)static_cast<uint32_t>((uint16_t)*(void***)(a1 + 0x118))) {
        edx4 = (void*)((uint8_t)a3 + (uint8_t)a3);
        eax5 = (uint32_t)edx4 >> 24;
        *(int8_t*)&v6 = *(int8_t*)&eax5;
        eax7 = (uint32_t)edx4 >> 16;
        *(int8_t*)(&v6 + 1) = *(int8_t*)&eax7;
        eax8 = (uint32_t)edx4 >> 8;
        *(int8_t*)(&v6 + 2) = *(int8_t*)&eax8;
        *(int8_t*)(&v6 + 3) = *(int8_t*)&edx4;
        fun_40aaf8(a1, (int32_t)__zero_stack_offset() - 44 - 4 - 4 - 4 - 4 + 28, 4, v9, ebx10, esi11, edi12, ebp13, v14, v15, v16, v6);
        fun_40aaf8(a1, 0x406a7d, 4, 0x410f9a, a1, (int32_t)__zero_stack_offset() - 44 - 4 - 4 - 4 - 4 + 28, 4, v17, ebx10, esi11, edi12, ebp13);
        fun_407670(a1, (int32_t)__zero_stack_offset() - 44 - 4 - 4 - 4 - 4 + 28, 4, v18, ebx10, esi11, edi12, ebp13);
        fun_407694(a1, 0x406a7d, 4, 0x410fb6, a1, (int32_t)__zero_stack_offset() - 44 - 4 - 4 - 4 - 4 + 28, 4, v19, ebx10, esi11, edi12, ebp13);
        if ((int8_t)0 < (int8_t)a3) {
            if ((int8_t)a3 > (int8_t)0) {
                if (!((uint8_t)a3 & 3)) {
                }
            }
        }
    } else {
        fun_40850c(a1, fun_40ccb0, v20, v21, ebx10, esi11, edi12, ebp13, v22, v23, v24, v25, v26, v27);
    }
}

void fun_40d41c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void*** esp10;
    void** v11;
    void** ebx12;
    int32_t v13;
    void** v14;
    void** v15;
    void** v16;
    void* esp17;
    void** v18;
    void** v19;
    void** v20;
    void** eax21;
    void* esp22;
    void** v23;
    int8_t* edi24;
    int8_t* v25;
    int32_t ecx26;
    void** ecx27;
    void** v28;
    int32_t v29;
    void* ebx30;
    void** v31;
    uint32_t v32;
    void** v33;
    void** eax34;
    void** v35;
    int32_t esi36;
    void* esp37;
    void** v38;
    void** v39;
    int32_t v40;
    void** v41;
    int32_t v42;
    int32_t v43;
    void** v44;
    void** v45;
    int32_t v46;
    int32_t ebp47;
    int32_t v48;
    uint32_t eax49;
    uint32_t v50;
    int32_t v51;
    int8_t* edi52;
    int8_t** v53;
    int32_t ecx54;
    void** ecx55;
    void** eax56;
    int32_t v57;
    uint32_t eax58;
    void** v59;
    uint32_t eax60;
    uint32_t eax61;
    void** v62;
    void** v63;
    void** v64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** v70;
    void** v71;
    void** v72;
    void** v73;
    void** v74;
    int8_t* edi75;
    int8_t** v76;
    int32_t ecx77;
    void** ecx78;
    void** eax79;
    void* ebx80;
    int32_t edx81;
    int8_t* edi82;
    int8_t** v83;
    int32_t ecx84;
    void** ecx85;
    void** eax86;
    void* ebx87;
    int32_t edx88;
    int8_t* edi89;
    int8_t** v90;
    int32_t ecx91;
    void** ecx92;
    void** eax93;
    void* ebx94;
    int32_t edx95;
    int8_t* edi96;
    int8_t** v97;
    int32_t ecx98;
    void** ecx99;
    void** eax100;
    int32_t v101;
    void** v102;
    void** v103;
    void** v104;
    void** v105;
    void** v106;
    int32_t v107;
    void** v108;
    void** v109;
    void** v110;
    void** v111;
    void** v112;
    void** v113;
    void** v114;
    void** v115;
    int32_t esi116;
    int32_t v117;
    uint32_t eax118;
    uint32_t v119;
    int32_t v120;
    void** ebx121;
    void*** v122;
    void** edi123;
    void** v124;
    void** v125;
    void** v126;
    void** v127;
    int32_t eax128;
    void** ebx129;
    void*** v130;
    void** edi131;
    void** v132;
    void** v133;
    void** v134;
    void** v135;
    int32_t eax136;
    void** ebx137;
    void*** v138;
    void** edi139;
    void** v140;
    void** v141;
    void** v142;
    void** v143;
    int32_t eax144;
    void** ebx145;
    void*** v146;
    void** edi147;
    void** v148;
    void** v149;
    void** v150;
    void** v151;
    int32_t v152;
    void** edi153;
    void*** v154;
    void** ebx155;
    void** v156;
    void** v157;
    void** v158;
    void** v159;
    void** edi160;
    void*** v161;
    void** ebx162;
    void** v163;
    void** v164;
    void** v165;
    void** v166;
    void** edi167;
    void*** v168;
    void** ebx169;
    void** v170;
    void** v171;
    void** v172;
    void** v173;
    int32_t esi174;
    int32_t v175;
    void** v176;
    void** v177;
    void** v178;
    void** v179;
    int32_t v180;
    int8_t* edi181;
    int8_t** v182;
    int32_t ecx183;
    int8_t* edi184;
    int8_t** v185;
    int32_t ecx186;
    void** ecx187;
    void** eax188;
    void** ecx189;
    void** eax190;

    v9 = (void**)__return_address();
    esp10 = (void***)((int32_t)__zero_stack_offset() - 4);
    v11 = ebx12;
    if (v13 > 3) {
        fun_40850c(v14, 0x40d3f0, v15, v16, v11, v9, a1, a2, a3, a4, a5, a6, a7, a8);
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    esp17 = (void*)(esp10 - 4);
    v18 = (void**)((int32_t)esp17 + 80);
    eax21 = fun_40ce3c(v19, v20, v18);
    esp22 = (void*)((int32_t)esp17 - 4 - 4 - 4 - 4 + 4);
    v23 = eax21 + 1;
    edi24 = v25;
    ecx26 = -1;
    do {
        if (!ecx26) 
            break;
        --ecx26;
        ++edi24;
    } while (*edi24);
    ecx27 = (void**)~ecx26;
    v28 = ecx27 + 0xffffffff;
    if (v29) {
        v28 = ecx27;
    }
    ebx30 = (void*)((uint8_t)v28 + (uint8_t)v23 + 10);
    eax34 = fun_402940(v31, v32 << 2, v18, v33, v11, v9, a1, a2, a3, a4, a5, a6);
    v35 = eax34;
    esi36 = 0;
    esp37 = (void*)((int32_t)esp22 + 16 - 8 - 4 - 4 - 4 + 4 + 16);
    v38 = (void**)((int32_t)esp37 + 72);
    v39 = (void**)(v40 >> 24);
    v41 = (void**)(v42 >> 24);
    v43 = v42 >> 16;
    v44 = (void**)((int32_t)esp37 + 80);
    v45 = (void**)((int32_t)esp37 + 68);
    if (0 >= v46) 
        goto addr_0x40d689_15;
    ebp47 = v48 - 1;
    eax49 = v50 & 3;
    if (v51 <= 0) {
        addr_0x40d59a_17:
        edi52 = v53[esi36];
        ecx54 = -1;
    } else {
        if (!eax49) 
            goto addr_0x40d5d0_19;
        if ((int32_t)eax49 <= (int32_t)1) 
            goto addr_0x40d59a_17; else 
            goto addr_0x40d541_21;
    }
    do {
        if (!ecx54) 
            break;
        --ecx54;
        ++edi52;
        ++esi36;
    } while (*edi52);
    ecx55 = (void**)~ecx54;
    eax56 = ecx55 + 0xffffffff;
    if (esi36 != ebp47) {
        eax56 = ecx55;
    }
    *(void***)(v35 + esi36 * 4) = eax56;
    ebx30 = (void*)((uint32_t)ebx30 + (uint8_t)eax56);
    ++esi36;
    if (esi36 >= v57) {
        addr_0x40d689_15:
        eax58 = (uint32_t)ebx30 >> 24;
        *(int8_t*)&v59 = *(int8_t*)&eax58;
        eax60 = (uint32_t)ebx30 >> 16;
        *(int8_t*)(&v59 + 1) = *(int8_t*)&eax60;
        eax61 = (uint32_t)ebx30 >> 8;
        *(int8_t*)(&v59 + 2) = *(int8_t*)&eax61;
        *(int8_t*)(&v59 + 3) = *(int8_t*)&ebx30;
        fun_40aaf8(v62, v38, 4, v63, v11, v9, a1, a2, a3, v44, v38, v45);
        fun_40aaf8(v64, 0x406a91, 4, 0x40d6b9, v62, v38, 4, v65, v11, v9, a1, a2);
        fun_407670(v66, v38, 4, v67, v11, v9, a1, a2);
        fun_407694(v68, 0x406a91, 4, 0x40d6e0, v66, v38, 4, v69, v11, v9, a1, a2);
        if (v70 && v23) {
            fun_407694(v71, v70, v23, v72, v11, v9, a1, a2, a3, v44, v38, v45);
            fun_40aaf8(v73, v70, v23, 0x40d71c, v71, v70, v23, v74, v11, v9, a1, a2);
        }
    } else {
        do {
            addr_0x40d5d0_19:
            edi75 = v76[esi36];
            ecx77 = -1;
            do {
                if (!ecx77) 
                    break;
                --ecx77;
                ++edi75;
                ++esi36;
            } while (*edi75);
            ecx78 = (void**)~ecx77;
            eax79 = ecx78 + 0xffffffff;
            if (esi36 != ebp47) {
                eax79 = ecx78;
            }
            *(void***)(v35 + esi36 * 4) = eax79;
            ebx80 = (void*)((uint32_t)ebx30 + (uint8_t)eax79);
            edx81 = esi36 + 1;
            edi82 = v83[edx81];
            ecx84 = -1;
            do {
                if (!ecx84) 
                    break;
                --ecx84;
                ++edi82;
                ++esi36;
            } while (*edi82);
            ecx85 = (void**)~ecx84;
            eax86 = ecx85 + 0xffffffff;
            if (edx81 != ebp47) {
                eax86 = ecx85;
            }
            *(void***)(v35 + edx81 * 4) = eax86;
            ebx87 = (void*)((uint32_t)ebx80 + (uint8_t)eax86);
            edx88 = esi36 + 2;
            edi89 = v90[edx88];
            ecx91 = -1;
            do {
                if (!ecx91) 
                    break;
                --ecx91;
                ++edi89;
                ++esi36;
            } while (*edi89);
            ecx92 = (void**)~ecx91;
            eax93 = ecx92 + 0xffffffff;
            if (edx88 != ebp47) {
                eax93 = ecx92;
            }
            *(void***)(v35 + edx88 * 4) = eax93;
            ebx94 = (void*)((uint32_t)ebx87 + (uint8_t)eax93);
            edx95 = esi36 + 3;
            edi96 = v97[edx95];
            ecx98 = -1;
            do {
                if (!ecx98) 
                    break;
                --ecx98;
                ++edi96;
                ++esi36;
            } while (*edi96);
            ecx99 = (void**)~ecx98;
            eax100 = ecx99 + 0xffffffff;
            if (edx95 != ebp47) {
                eax100 = ecx99;
            }
            *(void***)(v35 + edx95 * 4) = eax100;
            ebx30 = (void*)((uint32_t)ebx94 + (uint8_t)eax100);
            esi36 = esi36 + 4;
        } while (esi36 < v101);
        goto addr_0x40d689_15;
    }
    v102 = (void**)10;
    fun_407694(v103, v44, 10, v104, v11, v9, a1, a2, a3, v44, v38, v45);
    fun_40aaf8(v105, v44, 10, 0x40d79f, v103, v44, 10, v106, v11, v9, a1, a2);
    if (v107 && v28) {
        v102 = v28;
        fun_407694(v108, v109, v102, v110, v11, v9, a1, a2, a3, v44, v38, v45);
        fun_40aaf8(v111, v112, v28, 0x40d7e4, v108, v109, v102, v113, v11, v9, a1, a2);
    }
    fun_4029a0(v114, v59, v102, v115, v11, v9, a1, a2, a3, v44, v38, v45, v41, v39, *(void***)&v43);
    esi116 = 0;
    if (0 >= v117) 
        goto addr_0x40da25_51;
    eax118 = v119 & 3;
    if (v120 > 0) {
        if (!eax118) {
            do {
                addr_0x40d918_54:
                ebx121 = v122[esi116 * 4];
                edi123 = *(void***)(v35 + esi116 * 4);
                if (ebx121 && edi123) {
                    v102 = edi123;
                    fun_407694(v124, ebx121, v102, v125, v11, v9, a1, a2, a3, v44, v38, v45);
                    fun_40aaf8(v126, ebx121, edi123, 0x40d940, v124, ebx121, v102, v127, v11, v9, a1, a2);
                }
                eax128 = esi116 + 1;
                ebx129 = v130[eax128 * 4];
                edi131 = *(void***)(v35 + eax128 * 4);
                if (ebx129 && edi131) {
                    v102 = edi131;
                    fun_407694(v132, ebx129, v102, v133, v11, v9, a1, a2, a3, v44, v38, v45);
                    fun_40aaf8(v134, ebx129, edi131, 0x40d980, v132, ebx129, v102, v135, v11, v9, a1, a2);
                }
                eax136 = esi116 + 2;
                ebx137 = v138[eax136 * 4];
                edi139 = *(void***)(v35 + eax136 * 4);
                if (ebx137 && edi139) {
                    v102 = edi139;
                    fun_407694(v140, ebx137, v102, v141, v11, v9, a1, a2, a3, v44, v38, v45);
                    fun_40aaf8(v142, ebx137, edi139, 0x40d9c0, v140, ebx137, v102, v143, v11, v9, a1, a2);
                }
                eax144 = esi116 + 3;
                ebx145 = v146[eax144 * 4];
                edi147 = *(void***)(v35 + eax144 * 4);
                if (ebx145 && edi147) {
                    v102 = edi147;
                    fun_407694(v148, ebx145, v102, v149, v11, v9, a1, a2, a3, v44, v38, v45);
                    fun_40aaf8(v150, ebx145, edi147, 0x40da00, v148, ebx145, v102, v151, v11, v9, a1, a2);
                }
                esi116 = esi116 + 4;
            } while (esi116 < v152);
            goto addr_0x40da25_51;
        } else {
            if ((int32_t)eax118 > (int32_t)1) {
                if ((int32_t)eax118 > (int32_t)2) {
                    edi153 = *v154;
                    ebx155 = *(void***)v35;
                    if (edi153 && ebx155) {
                        v102 = ebx155;
                        fun_407694(v156, edi153, v102, v157, v11, v9, a1, a2, a3, v44, v38, v45);
                        fun_40aaf8(v158, edi153, ebx155, 0x40d877, v156, edi153, v102, v159, v11, v9, a1, a2);
                    }
                    esi116 = 1;
                }
                edi160 = v161[esi116 * 4];
                ebx162 = *(void***)(v35 + esi116 * 4);
                if (edi160 && ebx162) {
                    v102 = ebx162;
                    fun_407694(v163, edi160, v102, v164, v11, v9, a1, a2, a3, v44, v38, v45);
                    fun_40aaf8(v165, edi160, ebx162, 0x40d8b5, v163, edi160, v102, v166, v11, v9, a1, a2);
                }
                ++esi116;
            }
        }
    }
    edi167 = v168[esi116 * 4];
    ebx169 = *(void***)(v35 + esi116 * 4);
    if (edi167 && ebx169) {
        v102 = ebx169;
        fun_407694(v170, edi167, v102, v171, v11, v9, a1, a2, a3, v44, v38, v45);
        fun_40aaf8(v172, edi167, ebx169, 0x40d8f3, v170, edi167, v102, v173, v11, v9, a1, a2);
    }
    esi174 = esi116 + 1;
    if (esi174 >= v175) {
        addr_0x40da25_51:
        fun_4029a0(v176, v35, v102, v177, v11, v9, a1, a2, a3, v44, v38, v45, v41, v39, *(void***)&v43);
        fun_40aaf8(v178, v45, 4, v179, v11, v9, a1, a2, a3, v44, v38, v45);
        goto v180;
    } else {
        esi116 = esi174;
        goto addr_0x40d918_54;
    }
    addr_0x40d541_21:
    if ((int32_t)eax49 <= (int32_t)2) {
        addr_0x40d571_75:
        edi181 = v182[esi36];
        ecx183 = -1;
    } else {
        edi184 = *v185;
        ecx186 = -1;
        do {
            if (!ecx186) 
                break;
            --ecx186;
            ++edi184;
            ++esi36;
        } while (*edi184);
        ecx187 = (void**)~ecx186;
        eax188 = ecx187 + 0xffffffff;
        if (esi36 == ebp47) 
            goto addr_0x40d564_80; else 
            goto addr_0x40d562_81;
    }
    do {
        if (!ecx183) 
            break;
        --ecx183;
        ++edi181;
        ++esi36;
    } while (*edi181);
    ecx189 = (void**)~ecx183;
    eax190 = ecx189 + 0xffffffff;
    if (esi36 != ebp47) {
        eax190 = ecx189;
    }
    *(void***)(v35 + esi36 * 4) = eax190;
    ebx30 = (void*)((uint32_t)ebx30 + (uint8_t)eax190);
    ++esi36;
    goto addr_0x40d59a_17;
    addr_0x40d564_80:
    *(void***)v35 = eax188;
    ebx30 = (void*)((uint32_t)ebx30 + (uint8_t)eax188);
    esi36 = 1;
    goto addr_0x40d571_75;
    addr_0x40d562_81:
    eax188 = ecx187;
    goto addr_0x40d564_80;
}

void fun_417450(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11);

void fun_40da7f();

void** fun_40da88(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void** ebp10;
    void** v11;
    void** edi12;
    void** v13;
    void** esi14;
    void** v15;
    void** ebx16;
    void** esi17;
    void** v18;
    void* esp19;
    void** ebp20;
    void** v21;
    void** v22;
    void** v23;
    void* esp24;
    void** eax25;
    void** v26;
    void** v27;
    void** v28;
    void* esp29;
    int32_t ecx30;
    int8_t v31;
    int32_t ecx32;
    int8_t v33;
    void* esp34;
    void** v35;
    void** v36;
    void** v37;
    void* esp38;
    void** ebx39;
    void** v40;
    void** v41;
    void** v42;
    void* esp43;
    int32_t ecx44;
    int8_t v45;
    void** ebx46;
    void** v47;
    void** v48;
    void** v49;
    int32_t ecx50;
    int8_t v51;
    void** ebx52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;
    void** v58;
    int32_t v59;
    int32_t v60;
    int32_t v61;
    void** eax62;

    v9 = ebp10;
    v11 = edi12;
    v13 = esi14;
    v15 = ebx16;
    esi17 = a1;
    asm("fld qword [esp+0x90]");
    asm("fstp qword [esp+0x20]");
    v18 = a3;
    esp19 = (void*)((int32_t)__zero_stack_offset() - 0x6c - 4 - 4 - 4 - 4 - 4 - 4 - 4);
    ebp20 = (void**)((int32_t)esp19 + 92);
    fun_417450(ebp20, fun_40da7f, a2, v18, v15, v13, v11, v9, v21, v22, v23);
    esp24 = (void*)((int32_t)esp19 - 4 - 4 + 4 - 4 - 4 - 4);
    eax25 = (void**)((int32_t)esp24 + 76);
    v26 = eax25;
    fun_417450(eax25, fun_40da7f, v27, v28, ebp20, fun_40da7f, a2, v18, v15, v13, v11);
    esp29 = (void*)((int32_t)esp24 - 4 - 4 + 4);
    ecx30 = -1;
    do {
        if (!ecx30) 
            break;
        --ecx30;
        ++esi17;
    } while (v31);
    ecx32 = -1;
    do {
        if (!ecx32) 
            break;
        --ecx32;
        ++esi17;
    } while (v33);
    esp34 = (void*)((int32_t)esp29 + 32);
    fun_40aaf8(esi17, (int32_t)esp34 + 44, 4, v18, v15, v13, v11, v9, v35, v36, v37, v26);
    fun_40aaf8(esi17, 0x406a96, 4, 0x40db28, esi17, (int32_t)esp34 + 44, 4, v18, v15, v13, v11, v9);
    fun_407670(esi17, (int32_t)esp34 + 44, 4, v18, v15, v13, v11, v9);
    fun_407694(esi17, 0x406a96, 4, 0x40db44, esi17, (int32_t)esp34 + 44, 4, v18, v15, v13, v11, v9);
    esp38 = (void*)((int32_t)esp34 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    ebx39 = (void**)((int32_t)esp38 + 0x84);
    fun_407694(esi17, ebx39, 1, v18, v15, v13, v11, v9, v40, v41, v42, v26);
    fun_40aaf8(esi17, ebx39, 1, 0x40db6a, esi17, ebx39, 1, v18, v15, v13, v11, v9);
    esp43 = (void*)((int32_t)esp38 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    ecx44 = -1;
    do {
        if (!ecx44) 
            break;
        --ecx44;
        ++esi17;
    } while (v45);
    ebx46 = (void**)~ecx44;
    if (ebx46) {
        fun_407694(esi17, ebp20, ebx46, v18, v15, v13, v11, v9, v47, v48, v49, v26);
        fun_40aaf8(esi17, ebp20, ebx46, 0x40db98, esi17, ebp20, ebx46, v18, v15, v13, v11, v9);
        esp43 = (void*)((int32_t)esp43 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    ecx50 = -1;
    do {
        if (!ecx50) 
            break;
        --ecx50;
        ++esi17;
    } while (v51);
    ebx52 = (void**)(~ecx50 + 0xffffffff);
    if (ebx52) {
        fun_407694(esi17, v26, ebx52, v18, v15, v13, v11, v9, v53, v54, v55, v26);
        fun_40aaf8(esi17, v26, ebx52, 0x40dbcc, esi17, v26, ebx52, v18, v15, v13, v11, v9);
        esp43 = (void*)((int32_t)esp43 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    eax62 = fun_40aaf8(esi17, (int32_t)esp43 + 40, 4, v18, v15, v13, v11, v9, v56, v57, v58, v26, esi17, (int32_t)esp43 + 40, 4, v18, v15, v13, v11, v9, v59, v60, v61, v26);
    return eax62;
}

struct s9 {
    int8_t[110] pad110;
    uint8_t f110;
};

void fun_40bb2b(struct s9* ecx);

void** fun_40bb48(void** a1, void** a2, void** a3, void** a4) {
    void** v5;
    void** ebp6;
    void** v7;
    void** edi8;
    void** v9;
    void** esi10;
    void** v11;
    void** ebx12;
    void** ebp13;
    void** v14;
    void* ebx15;
    void** edx16;
    void* esp17;
    void** v18;
    void** eax19;
    void*** esp20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** eax27;
    void* edx28;
    uint32_t eax29;
    void** v30;
    uint32_t eax31;
    uint32_t eax32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void* esp39;
    void** ebx40;
    void** v41;
    void** ebx42;
    void** v43;
    void** v44;
    void** v45;
    void** v46;
    void** ebx47;
    void** edi48;
    uint32_t edx49;
    uint32_t eax50;
    void** v51;
    uint32_t edx52;
    uint32_t eax53;
    uint32_t edx54;
    uint32_t eax55;
    void** v56;
    uint32_t edx57;
    uint32_t eax58;
    uint32_t edx59;
    uint32_t eax60;
    void** v61;
    uint32_t edx62;
    uint32_t eax63;
    void** esi64;
    void** v65;
    void** v66;
    void** v67;
    int32_t v68;
    int32_t v69;
    int32_t v70;
    void** v71;
    int32_t v72;
    uint32_t edx73;
    uint32_t eax74;
    void** v75;
    uint32_t eax76;
    uint32_t eax77;
    void** v78;
    void** v79;
    int32_t v80;
    int32_t v81;
    void** v82;
    void** v83;
    void** v84;
    void** v85;
    void** v86;
    void** v87;

    v5 = ebp6;
    v7 = edi8;
    v9 = esi10;
    v11 = ebx12;
    ebp13 = a1;
    v14 = (void**)10;
    if ((int1_t)(*(void***)(a2 + 4) == 8)) {
        v14 = (void**)6;
    }
    ebx15 = (void*)((uint8_t)v14 * (uint8_t)*(void***)(a2 + 12));
    edx16 = *(void***)a2;
    if (!edx16 || (esp17 = (void*)((int32_t)__zero_stack_offset() - 44 - 4 - 4 - 4 - 4 - 4), v18 = (void**)((int32_t)esp17 + 32), eax19 = fun_40ce3c(ebp13, edx16, v18), esp20 = (void***)((int32_t)esp17 - 4 - 4 - 4 - 4 + 4 + 16), !eax19)) {
        eax27 = fun_40850c(ebp13, fun_40bb2b, v18, v21, v11, v9, v7, v5, v14, v22, v23, v24, v25, v26);
    } else {
        edx28 = (void*)((uint8_t)eax19 + (uint32_t)ebx15 + 2);
        eax29 = (uint32_t)edx28 >> 24;
        *(int8_t*)&v30 = *(int8_t*)&eax29;
        eax31 = (uint32_t)edx28 >> 16;
        *(int8_t*)(&v30 + 1) = *(int8_t*)&eax31;
        eax32 = (uint32_t)edx28 >> 8;
        *(int8_t*)(&v30 + 2) = *(int8_t*)&eax32;
        *(int8_t*)(&v30 + 3) = *(int8_t*)&edx28;
        fun_40aaf8(ebp13, esp20 + 24, 4, v33, v11, v9, v7, v5, v14, v34, v30, v35);
        fun_40aaf8(ebp13, 0x406aa5, 4, 0x40bbdc, ebp13, esp20 + 24, 4, v36, v11, v9, v7, v5);
        fun_407670(ebp13, esp20 + 24, 4, v37, v11, v9, v7, v5);
        fun_407694(ebp13, 0x406aa5, 4, 0x40bbf8, ebp13, esp20 + 24, 4, v38, v11, v9, v7, v5);
        esp39 = (void*)(esp20 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
        ebx40 = eax19 + 1;
        if (!v41) 
            goto addr_0x40bc33_10;
        if (!ebx40) 
            goto addr_0x40bc33_10; else 
            goto addr_0x40bc1a_12;
    }
    addr_0x40bd85_13:
    return eax27;
    addr_0x40bc33_10:
    ebx42 = a2 + 4;
    if (ebx42) {
        fun_407694(ebp13, ebx42, 1, v43, v11, v9, v7, v5, v14, v44, v30, v45);
        fun_40aaf8(ebp13, ebx42, 1, 0x40bc48, ebp13, ebx42, 1, v46, v11, v9, v7, v5);
        esp39 = (void*)((int32_t)esp39 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    ebx47 = *(void***)(a2 + 8);
    edi48 = (void**)((int32_t)esp39 + 20);
    if ((uint8_t)ebx47 < (uint8_t)(ebx47 + (uint32_t)(*(void***)(a2 + 12) + (uint8_t)*(void***)(a2 + 12) * 4) * 2)) {
        do {
            if (!(int1_t)(*(void***)(a2 + 4) == 8)) {
                edx49 = static_cast<uint32_t>((uint16_t)*(void***)ebx47);
                eax50 = edx49 >> 8;
                v51 = *(void***)&eax50;
                *(uint8_t*)(&v51 + 1) = *(uint8_t*)&edx49;
                edx52 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(ebx47 + 2));
                eax53 = edx52 >> 8;
                (&v51)[2] = *(void***)&eax53;
                *(uint8_t*)(&v51 + 3) = *(uint8_t*)&edx52;
                edx54 = static_cast<uint32_t>((uint16_t)*(void***)(ebx47 + 4));
                eax55 = edx54 >> 8;
                *(int8_t*)&v56 = *(int8_t*)&eax55;
                *(int8_t*)(&v56 + 1) = *(int8_t*)&edx54;
                edx57 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(ebx47 + 6));
                eax58 = edx57 >> 8;
                *(int8_t*)(&v56 + 2) = *(int8_t*)&eax58;
                *(int8_t*)(&v56 + 3) = *(int8_t*)&edx57;
                edx59 = static_cast<uint32_t>((uint16_t)*(void***)(ebx47 + 8));
                eax60 = edx59 >> 8;
                *(int8_t*)&v61 = *(int8_t*)&eax60;
                *(int8_t*)(&v61 + 1) = *(int8_t*)&edx59;
            } else {
                v51 = *(void***)ebx47;
                *(uint8_t*)(&v51 + 1) = *(uint8_t*)(ebx47 + 2);
                (&v51)[2] = *(void***)(ebx47 + 4);
                *(uint8_t*)(&v51 + 3) = *(uint8_t*)(ebx47 + 6);
                edx62 = static_cast<uint32_t>((uint16_t)*(void***)(ebx47 + 8));
                eax63 = edx62 >> 8;
                *(int8_t*)&v56 = *(int8_t*)&eax63;
                *(int8_t*)(&v56 + 1) = *(int8_t*)&edx62;
            }
            esi64 = (void**)((int32_t)esp39 + 32);
            if (!0) {
                fun_407694(ebp13, esi64, v14, v65, v11, v9, v7, v5, v14, v66, v30, v67, ebp13, esi64, v14, v68, v11, v9, v7, v5, v14, v69, v30, v70);
                fun_40aaf8(ebp13, esi64, v14, 0x40bd1a, ebp13, esi64, v14, v71, v11, v9, v7, v5, ebp13, esi64, v14, 0x40bd1a, ebp13, esi64, v14, v72, v11, v9, v7, v5);
                esp39 = (void*)((int32_t)esp39 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
            }
            ebx47 = ebx47 + 10;
        } while ((uint8_t)ebx47 < (uint8_t)(*(void***)(a2 + 8) + (uint32_t)(*(void***)(a2 + 12) + (uint8_t)*(void***)(a2 + 12) * 4) * 2));
    }
    edx73 = *(uint32_t*)(ebp13 + 0x110);
    eax74 = edx73 >> 24;
    *(int8_t*)&v75 = *(int8_t*)&eax74;
    eax76 = edx73 >> 16;
    *(int8_t*)(&v75 + 1) = *(int8_t*)&eax76;
    eax77 = edx73 >> 8;
    *(int8_t*)(&v75 + 2) = *(int8_t*)&eax77;
    *(int8_t*)(&v75 + 3) = *(int8_t*)&edx73;
    fun_40aaf8(ebp13, edi48, 4, v78, v11, v9, v7, v5, v14, v75, v30, v79, ebp13, edi48, 4, v80, v11, v9, v7, v5, v14, v75, v30, v81);
    eax27 = fun_4029a0(ebp13, v30, 4, v82, v11, v9, v7, v5, v14, v75, v30, v83, v51, v56, v61);
    goto addr_0x40bd85_13;
    addr_0x40bc1a_12:
    fun_407694(ebp13, v41, ebx40, v84, v11, v9, v7, v5, v14, v85, v30, v86);
    fun_40aaf8(ebp13, v41, ebx40, 0x40bc25, ebp13, v41, ebx40, v87, v11, v9, v7, v5);
    esp39 = (void*)((int32_t)esp39 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    goto addr_0x40bc33_10;
}

void** fun_4085f8(void** a1, void** a2);

void** fun_40850c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14) {
    void** ebx15;
    void** ecx16;
    void* eax17;
    void* edx18;
    void** eax19;

    ebx15 = a1;
    ecx16 = a2;
    eax17 = (void*)0;
    if (*(uint8_t*)(ebx15 + 0x6e) & 12 && ((int1_t)(*(void***)ecx16 == 35) && (eax17 = (void*)1, *(void***)(ecx16 + 1) != 32))) {
        do {
            eax17 = (void*)((int32_t)eax17 + 1);
            if ((int32_t)eax17 > 14) 
                break;
        } while (*(int8_t*)((int32_t)eax17 + (uint8_t)ecx16) != 32);
    }
    edx18 = *(void**)(ebx15 + 68);
    if (!edx18) {
        eax19 = fun_4085f8(ebx15, (int32_t)eax17 + (uint8_t)ecx16);
    } else {
        eax19 = (void**)edx18(ebx15, (int32_t)eax17 + (uint8_t)ecx16);
    }
    return eax19;
}

struct s10 {
    int8_t[110] pad110;
    uint8_t f110;
};

void fun_40d1c4(struct s10* ecx);

void fun_40d1e0(void** a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5, void** a6, void** a7, void** a8) {
    uint232_t v1;
    void** v4;
    void** ebp5;
    void** v6;
    void** edi7;
    void** v8;
    void** esi9;
    void** v10;
    void** ebx11;
    void** ebp12;
    void** v13;
    void** esi14;
    void** v15;
    int32_t v16;
    void** v17;
    void** v18;
    void* esp19;
    void** v20;
    void** eax21;
    void*** esp22;
    int32_t v23;
    int32_t v24;
    void** v25;
    void** edi26;
    int32_t ecx27;
    void** v28;
    void* esp29;
    struct s4* edi30;
    void** v31;
    void** v32;
    void** v33;
    void* esp34;
    void** v35;
    int32_t v36;
    void** v37;
    int32_t v38;
    void** v39;
    void** v40;
    void* esp41;
    void** ebx42;
    void** ebx43;
    void** v44;
    int32_t v45;
    void** v46;
    int32_t v47;
    void** v48;
    int32_t v49;
    void** v50;
    void** v51;
    int32_t v52;
    void** v53;
    void** v54;
    int32_t v55;

    *(void***)((int32_t)&v1 + 5) = a1;
    *(int32_t*)((int32_t)&v1 + 9) = a2;
    *(int32_t*)((int32_t)&v1 + 13) = a3;
    *(int32_t*)((int32_t)&v1 + 17) = a4;
    *(int32_t*)((int32_t)&v1 + 21) = a5;
    *(void***)((int32_t)&v1 + 25) = a6;
    *(int32_t*)((int32_t)&v1 + 1) = (int32_t)__return_address();
    asm("in al, dx");
    v4 = ebp5;
    v6 = edi7;
    v8 = esi9;
    v10 = ebx11;
    ebp12 = v13;
    esi14 = v15;
    if (!v16) {
        addr_0x40d214_3:
        fun_40850c(ebp12, fun_40d1c4, v17, v18, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), *(void***)((int32_t)&v1 + 16), *(void***)((int32_t)&v1 + 20));
    } else {
        esp19 = (void*)((int32_t)__zero_stack_offset() - 1 - 4 - 4 - 4 - 4 - 4);
        v17 = (void**)((int32_t)esp19 + 48);
        eax21 = fun_40ce3c(ebp12, v20, v17);
        *(void***)((int32_t)&v1 + 12) = eax21;
        esp22 = (void***)((int32_t)esp19 - 4 - 4 - 4 - 4 + 4 + 16);
        if (eax21) 
            goto addr_0x40d228_6; else 
            goto addr_0x40d214_3;
    }
    addr_0x40d388_7:
    addr_0x40d38b_8:
    goto v23;
    addr_0x40d228_6:
    if (!esi14 || !*(void***)esi14) {
        addr_0x40d238_9:
    } else {
        if (v24 != -1) 
            goto addr_0x40d25c_12; else 
            goto addr_0x40d238_9;
    }
    fun_40d044(ebp12, *(void***)((int32_t)&v1 + 24), esi14, 0);
    fun_4029a0(ebp12, *(void***)((int32_t)&v1 + 24), v25, 0x40d245, ebp12, *(void***)((int32_t)&v1 + 24), esi14, 0, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8));
    goto addr_0x40d38b_8;
    addr_0x40d25c_12:
    edi26 = esi14;
    ecx27 = -1;
    do {
        if (!ecx27) 
            break;
        --ecx27;
        ++edi26;
        ++esi14;
    } while (*(void***)edi26);
    fun_4029a0(ebp12, *(void***)((int32_t)&v1 + 24), v17, v28, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), *(void***)((int32_t)&v1 + 16), *(void***)((int32_t)&v1 + 20), *(void***)((int32_t)&v1 + 24));
    esp29 = (void*)(esp22 - 8 - 4 - 4 - 4 + 4 - 12);
    edi30 = (struct s4*)((int32_t)esp29 + 76);
    fun_40abd8(ebp12, esi14, ~ecx27 + 0xffffffff, v31, edi30, v32, v33, 0x40d27a, ebp12, *(void***)((int32_t)&v1 + 24), v17);
    esp34 = (void*)((int32_t)esp29 - 4 - 4 - 4 - 4 - 4 - 4 + 4 + 48);
    fun_40aaf8(ebp12, (int32_t)esp34 + 40, 4, v35, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), ebp12, (int32_t)esp34 + 40, 4, v36, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12));
    fun_40aaf8(ebp12, 0x406abe, 4, 0x40d2cb, ebp12, (int32_t)esp34 + 40, 4, v37, v10, v8, v6, v4, ebp12, 0x406abe, 4, 0x40d2cb, ebp12, (int32_t)esp34 + 40, 4, v38, v10, v8, v6, v4);
    fun_407670(ebp12, (int32_t)esp34 + 40, 4, v39, v10, v8, v6, v4);
    fun_407694(ebp12, 0x406abe, 4, 0x40d2e7, ebp12, (int32_t)esp34 + 40, 4, v40, v10, v8, v6, v4);
    esp41 = (void*)((int32_t)esp34 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    ebx42 = *(void***)((int32_t)&v1 + 12) + 1;
    if (ebx42) 
        goto addr_0x40d301_17;
    addr_0x40d322_18:
    ebx43 = (void**)((int32_t)esp41 + 39);
    fun_407694(ebp12, ebx43, 1, v44, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), ebp12, ebx43, 1, v45, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12));
    fun_40aaf8(ebp12, ebx43, 1, 0x40d33a, ebp12, ebx43, 1, v46, v10, v8, v6, v4, ebp12, ebx43, 1, 0x40d33a, ebp12, ebx43, 1, v47, v10, v8, v6, v4);
    fun_40aec0(ebp12, edi30, 1);
    fun_40aaf8(ebp12, (int32_t)esp41 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 8 - 4 - 4 - 4 + 4 + 16 + 32, 4, v48, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), ebp12, (int32_t)esp41 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 8 - 4 - 4 - 4 + 4 + 16 + 32, 4, v49, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12));
    goto addr_0x40d388_7;
    addr_0x40d301_17:
    fun_407694(ebp12, v50, ebx42, v51, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12), ebp12, v50, ebx42, v52, v10, v8, v6, v4, *(void***)&v1, *(void***)((int32_t)&v1 + 4), *(void***)((int32_t)&v1 + 8), *(void***)((int32_t)&v1 + 12));
    fun_40aaf8(ebp12, v53, ebx42, 0x40d310, ebp12, v50, ebx42, v54, v10, v8, v6, v4, ebp12, v53, ebx42, 0x40d310, ebp12, v50, ebx42, v55, v10, v8, v6, v4);
    esp41 = (void*)((int32_t)esp41 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    goto addr_0x40d322_18;
}

struct s11 {
    int8_t[110] pad110;
    uint8_t f110;
};

void fun_40d027(struct s11* ecx);

void** fun_40d044(void** a1, void** a2, void** a3, void** a4) {
    void** v5;
    void** ebp6;
    void** v7;
    void** edi8;
    void** v9;
    void** esi10;
    void** v11;
    void** ebx12;
    void** esi13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** eax22;
    void* esp23;
    void** eax24;
    void** ebp25;
    void*** esp26;
    void** v27;
    void** edi28;
    int32_t ecx29;
    void* edx30;
    uint32_t eax31;
    void** v32;
    uint32_t eax33;
    uint32_t eax34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void* esp41;
    void** edi42;
    void** v43;
    void** v44;
    void** v45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    uint32_t edx52;
    uint32_t eax53;
    void** v54;
    uint32_t eax55;
    uint32_t eax56;
    void** v57;
    void** v58;
    void** v59;
    void** v60;
    void** v61;
    void** v62;
    void** v63;

    v5 = ebp6;
    v7 = edi8;
    v9 = esi10;
    v11 = ebx12;
    esi13 = a1;
    if (!a2) {
        addr_0x40d06f_3:
        eax22 = fun_40850c(esi13, fun_40d027, v14, v15, v11, v9, v7, v5, v16, v17, v18, v19, v20, v21);
    } else {
        esp23 = (void*)((int32_t)__zero_stack_offset() - 28 - 4 - 4 - 4 - 4 - 4);
        v14 = (void**)((int32_t)esp23 + 32);
        eax24 = fun_40ce3c(esi13, a2, v14);
        ebp25 = eax24;
        esp26 = (void***)((int32_t)esp23 - 4 - 4 - 4 - 4 + 4 + 16);
        if (ebp25) 
            goto addr_0x40d084_6; else 
            goto addr_0x40d06f_3;
    }
    addr_0x40d1b9_7:
    return eax22;
    addr_0x40d084_6:
    if (!a3 || !*(void***)a3) {
        v27 = (void**)0;
    } else {
        edi28 = a3;
        ecx29 = -1;
        do {
            if (!ecx29) 
                break;
            --ecx29;
            ++edi28;
            ++esi13;
        } while (*(void***)edi28);
        v27 = (void**)(~ecx29 - 1);
    }
    edx30 = (void*)((uint8_t)v27 + (uint8_t)ebp25 + 1);
    eax31 = (uint32_t)edx30 >> 24;
    *(int8_t*)&v32 = *(int8_t*)&eax31;
    eax33 = (uint32_t)edx30 >> 16;
    *(int8_t*)(&v32 + 1) = *(int8_t*)&eax33;
    eax34 = (uint32_t)edx30 >> 8;
    *(int8_t*)(&v32 + 2) = *(int8_t*)&eax34;
    *(int8_t*)(&v32 + 3) = *(int8_t*)&edx30;
    fun_40aaf8(esi13, esp26 + 24, 4, v35, v11, v9, v7, v5, v27, v36, v32, v37);
    fun_40aaf8(esi13, 0x406aaf, 4, 0x40d0e9, esi13, esp26 + 24, 4, v38, v11, v9, v7, v5);
    fun_407670(esi13, esp26 + 24, 4, v39, v11, v9, v7, v5);
    fun_407694(esi13, 0x406aaf, 4, 0x40d105, esi13, esp26 + 24, 4, v40, v11, v9, v7, v5);
    esp41 = (void*)(esp26 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    edi42 = ebp25 + 1;
    if (v43 && edi42) {
        fun_407694(esi13, v43, edi42, v44, v11, v9, v7, v5, v27, v45, v32, v46);
        fun_40aaf8(esi13, v43, edi42, 0x40d132, esi13, v43, edi42, v47, v11, v9, v7, v5);
        esp41 = (void*)((int32_t)esp41 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    if (v27 && a3) {
        fun_407694(esi13, a3, v27, v48, v11, v9, v7, v5, v27, v49, v32, v50);
        fun_40aaf8(esi13, a3, v27, 0x40d161, esi13, a3, v27, v51, v11, v9, v7, v5);
        esp41 = (void*)((int32_t)esp41 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    }
    edx52 = *(uint32_t*)(esi13 + 0x110);
    eax53 = edx52 >> 24;
    *(int8_t*)&v54 = *(int8_t*)&eax53;
    eax55 = edx52 >> 16;
    *(int8_t*)(&v54 + 1) = *(int8_t*)&eax55;
    eax56 = edx52 >> 8;
    *(int8_t*)(&v54 + 2) = *(int8_t*)&eax56;
    *(int8_t*)(&v54 + 3) = *(int8_t*)&edx52;
    fun_40aaf8(esi13, (int32_t)esp41 + 20, 4, v57, v11, v9, v7, v5, v27, v54, v32, v58);
    eax22 = fun_4029a0(esi13, v32, 4, v59, v11, v9, v7, v5, v27, v54, v32, v60, v61, v62, v63);
    goto addr_0x40d1b9_7;
}

void** fun_410d98(void** a1, void** a2, void** a3, void** a4) {
    void** eax5;

    fun_410b88(a1, 0x406a64, 0);
    fun_410bf4(a1, 0, 0, 0x410db0, a1, 0x406a64, 0);
    eax5 = fun_410c30(a1, 0x406a64, 0);
    *(void***)(a1 + 0x68) = (void**)((uint8_t)*(void***)(a1 + 0x68) | 16);
    return eax5;
}

void** fun_417992(void** a1);

void** fun_417e00(void** a1, int32_t a2, void** a3);

void** fun_402aac(int32_t a1, void** a2, void** a3) {
    void** esi4;
    void** eax5;
    void** eax6;

    if (a1 != 2) {
        if (a1 == 1) {
            esi4 = (void**)0x254;
        } else {
            eax5 = (void**)0;
            goto addr_0x402b23_5;
        }
    } else {
        esi4 = (void**)0x120;
    }
    if (!a2) {
        eax6 = fun_417992(esi4);
    } else {
        eax6 = (void**)a2((int32_t)__zero_stack_offset() - 0x274 - 4 - 4 + 16, esi4);
    }
    if (eax6) {
        fun_417e00(eax6, 0, esi4);
    }
    eax5 = eax6;
    addr_0x402b23_5:
    return eax5;
}

void** fun_409780(void** a1, void** a2, void** a3);

void** fun_409670(void** a1, void** a2, void** a3);

void** fun_40de24(void** a1, ...) {
    void** v2;
    void** esi3;
    void** v4;
    void** ebx5;
    void** edi6;
    void** edx7;
    void** eax8;
    uint8_t al9;
    uint8_t dl10;
    uint32_t eax11;
    void** ebx12;
    uint32_t eax13;
    void** v14;
    void** ecx15;
    void** v16;
    void** v17;
    void** v18;
    void** eax19;
    void** esi20;
    void** ebx21;
    void** v22;
    void** ebx23;
    void** esi24;

    v2 = esi3;
    v4 = ebx5;
    edi6 = a1;
    edx7 = *(void***)(edi6 + 0xe4) + 1;
    *(void***)(edi6 + 0xe4) = edx7;
    eax8 = edx7;
    if ((uint8_t)eax8 < (uint8_t)*(void***)(edi6 + 0xd0)) 
        goto addr_0x40e049_2;
    if (!*(int8_t*)(edi6 + 0x123)) 
        goto addr_0x40df44_4;
    *(void***)(edi6 + 0xe4) = (void**)0;
    if (!((uint8_t)*(void***)(edi6 + 0x70) & 2)) {
        do {
            al9 = *(uint8_t*)(edi6 + 0x124);
            dl10 = (uint8_t)(al9 + 1);
            *(uint8_t*)(edi6 + 0x124) = dl10;
            if ((uint8_t)(al9 + 1) > 6) 
                goto addr_0x40df44_4;
            eax11 = static_cast<uint32_t>(dl10) << 2;
            ebx12 = (void**)(((int32_t)*(void**)(eax11 + 0x406ae0) + (uint8_t)*(void***)(edi6 + 0xc8) - (*(int32_t*)(eax11 + 0x406ac4) + 1)) / (uint32_t)*(void**)(eax11 + 0x406ae0));
            *(void***)(edi6 + 0xd4) = ebx12;
            eax13 = static_cast<uint32_t>(*(uint8_t*)(edi6 + 0x124)) << 2;
            eax8 = (void**)(((int32_t)*(void**)(eax13 + 0x406b18) + (uint8_t)*(void***)(edi6 + 0xcc) - (*(int32_t*)(eax13 + 0x406afc) + 1)) / (uint32_t)*(void**)(eax13 + 0x406b18));
            *(void***)(edi6 + 0xd0) = eax8;
        } while (!((uint8_t)*(void***)(edi6 + 0x70) & 2) && (!ebx12 || !eax8));
    } else {
        *(uint8_t*)(edi6 + 0x124) = (uint8_t)(*(uint8_t*)(edi6 + 0x124) + 1);
    }
    if (*(uint8_t*)(edi6 + 0x124) > 6) {
        addr_0x40df44_4:
        v14 = edi6 + 0x74;
    } else {
        ecx15 = *(void***)(edi6 + 0xe8);
        if (!ecx15) {
            addr_0x40e049_2:
            return eax8;
        } else {
            v16 = (void**)((*(uint8_t*)(edi6 + 0x12b) * (uint8_t)*(void**)(edi6 + 0x128) * (uint8_t)*(void***)(edi6 + 0xc8) + 7 >> 3) + 1);
            eax8 = fun_417e00(ecx15, 0, v16);
            goto addr_0x40e046_13;
        }
    }
    do {
        v17 = (void**)4;
        eax19 = fun_409780(v14, 4, v18);
        if (eax19) {
            if (eax19 == 1) 
                break;
            if (*(void***)(edi6 + 0x8c)) 
                goto addr_0x40dfcf_17;
        } else {
            if (!*(void***)(edi6 + 0x84)) {
                esi20 = *(void***)(edi6 + 0xac);
                ebx21 = *(void***)(edi6 + 0xb0);
                v18 = ebx21;
                v17 = (void**)0x406a5f;
                fun_410b88(edi6, 0x406a5f, v18);
                fun_410bf4(edi6, esi20, ebx21, 0x40df88, edi6, 0x406a5f, v18);
                fun_410c30(edi6, 0x406a5f, v18);
                *(void***)(edi6 + 0x68) = (void**)((uint8_t)*(void***)(edi6 + 0x68) | 4);
                *(void***)(edi6 + 0x80) = *(void***)(edi6 + 0xac);
                *(void***)(edi6 + 0x84) = *(void***)(edi6 + 0xb0);
                continue;
            }
        }
        v17 = (void**)0x40abcc;
        addr_0x40dfe0_21:
        fun_408404(edi6, v17, v18, v22, v4, v2);
        continue;
        addr_0x40dfcf_17:
        v17 = *(void***)(edi6 + 0x8c);
        goto addr_0x40dfe0_21;
    } while (!(int1_t)(eax19 == 1));
    if ((uint8_t)*(void***)(edi6 + 0x84) < (uint8_t)*(void***)(edi6 + 0xb0)) {
        ebx23 = (void**)((uint8_t)*(void***)(edi6 + 0xb0) - (uint8_t)*(void***)(edi6 + 0x84));
        esi24 = *(void***)(edi6 + 0xac);
        v18 = ebx23;
        v17 = (void**)0x406a5f;
        fun_410b88(edi6, 0x406a5f, v18);
        fun_410bf4(edi6, esi24, ebx23, 0x40e01b, edi6, 0x406a5f, v18);
        fun_410c30(edi6, 0x406a5f, v18);
        *(void***)(edi6 + 0x68) = (void**)((uint8_t)*(void***)(edi6 + 0x68) | 4);
    }
    eax8 = fun_409670(v14, v17, v18);
    addr_0x40e046_13:
    goto addr_0x40e049_2;
}

struct s12 {
    void** f0;
    int8_t[3] pad4;
    void* f4;
    int8_t[3] pad11;
    uint8_t f11;
};

struct s13 {
    int8_t[1] pad1;
    void** f1;
};

void fun_40e054(struct s12* a1, void** a2, void** a3, struct s13* a4) {
    void** v5;
    void** ebp6;
    void** v7;
    void** edi8;
    void** v9;
    void** esi10;
    void** v11;
    void** ebx12;
    uint32_t eax13;
    void** ecx14;
    void** v15;
    void** esi16;
    int32_t ebp17;
    uint32_t edi18;
    uint32_t eax19;
    void** ebx20;
    uint32_t v21;
    uint32_t v22;
    uint32_t v23;
    uint32_t eax24;
    uint32_t ecx25;
    int32_t ecx26;
    uint32_t eax27;
    void** ecx28;
    void** v29;
    int32_t ebp30;
    uint32_t eax31;
    void** ebx32;
    uint32_t v33;
    uint32_t v34;
    uint32_t ecx35;
    int32_t ecx36;
    uint32_t eax37;
    void** v38;
    int32_t ebp39;
    uint32_t eax40;
    void** ebx41;
    uint32_t v42;
    uint32_t ecx43;
    int32_t ecx44;
    uint32_t eax45;
    void** ebx46;
    uint32_t eax47;
    void** ebp48;
    void** edi49;
    uint32_t eax50;
    void** ebx51;
    void** esi52;
    void** eax53;
    void** v54;

    v5 = ebp6;
    v7 = edi8;
    v9 = esi10;
    v11 = ebx12;
    if ((int8_t)a3 > (int8_t)5) {
        addr_0x40e2f2_2:
        return;
    } else {
        eax13 = static_cast<uint32_t>(a1->f11);
        if (eax13 == 2) {
            ecx14 = a1->f0;
            v15 = ecx14;
            esi16 = a2;
            ebp17 = 6;
            edi18 = 0;
            eax19 = (uint8_t)a3 * 4;
            ebx20 = *(void***)(eax19 + 0x406ac4);
            v21 = eax19;
            if ((uint8_t)ebx20 < (uint8_t)ecx14) {
                v22 = eax19;
                do {
                    v23 = static_cast<uint32_t>(*(uint8_t*)(((uint8_t)ebx20 >> 2) + (uint8_t)a2));
                    eax24 = 3 - ((uint8_t)ebx20 & 3);
                    ecx25 = eax24 + eax24;
                    ecx26 = ebp17;
                    edi18 = edi18 | ((uint32_t)((int32_t)v23 >> *(int8_t*)&ecx25) & 3) << *(uint8_t*)&ecx26;
                    if (ebp17) {
                        ebp17 = ebp17 - 2;
                    } else {
                        ebp17 = 6;
                        eax27 = edi18;
                        *(void***)esi16 = *(void***)&eax27;
                        ++esi16;
                        edi18 = 0;
                    }
                    ebx20 = (void**)((uint8_t)ebx20 + (uint32_t)*(void**)(v22 + 0x406ae0));
                } while ((uint8_t)ebx20 < (uint8_t)v15);
            }
            if (ebp17 != 6) 
                goto addr_0x40e1be_11;
        } else {
            if ((int32_t)eax13 > (int32_t)2) {
                if (eax13 == 4) {
                    ecx28 = a1->f0;
                    v29 = ecx28;
                    esi16 = a2;
                    ebp30 = 4;
                    edi18 = 0;
                    eax31 = (uint8_t)a3 * 4;
                    ebx32 = *(void***)(eax31 + 0x406ac4);
                    v21 = eax31;
                    if ((uint8_t)ebx32 < (uint8_t)ecx28) {
                        v33 = eax31;
                        do {
                            v34 = static_cast<uint32_t>(*(uint8_t*)(((uint8_t)ebx32 >> 1) + (uint8_t)a2));
                            ecx35 = 1 - ((uint8_t)ebx32 & 1) << 2;
                            ecx36 = ebp30;
                            edi18 = edi18 | ((uint32_t)((int32_t)v34 >> *(int8_t*)&ecx35) & 15) << *(uint8_t*)&ecx36;
                            if (ebp30) {
                                ebp30 = ebp30 - 4;
                            } else {
                                ebp30 = 4;
                                eax37 = edi18;
                                *(void***)esi16 = *(void***)&eax37;
                                ++esi16;
                                edi18 = 0;
                            }
                            ebx32 = (void**)((uint8_t)ebx32 + (uint32_t)*(void**)(v33 + 0x406ae0));
                        } while ((uint8_t)ebx32 < (uint8_t)v29);
                    }
                    if (ebp30 != 4) 
                        goto addr_0x40e256_21;
                } else {
                    goto addr_0x40e25c_23;
                }
            } else {
                if (eax13 == 1) {
                    v38 = a1->f0;
                    esi16 = a2;
                    edi18 = 0;
                    ebp39 = 7;
                    eax40 = (uint8_t)a3 * 4;
                    ebx41 = *(void***)(eax40 + 0x406ac4);
                    v21 = eax40;
                    if ((uint8_t)ebx41 < (uint8_t)v38) {
                        v42 = eax40;
                        esi16 = esi16;
                        do {
                            ecx43 = 7 - ((uint8_t)ebx41 & 7);
                            ecx44 = ebp39;
                            edi18 = edi18 | ((uint32_t)((int32_t)static_cast<uint32_t>(*(uint8_t*)(((uint8_t)ebx41 >> 3) + (uint8_t)a2)) >> *(int8_t*)&ecx43) & 1) << *(uint8_t*)&ecx44;
                            if (ebp39) {
                                --ebp39;
                            } else {
                                ebp39 = 7;
                                eax45 = edi18;
                                *(void***)esi16 = *(void***)&eax45;
                                ++esi16;
                                edi18 = 0;
                            }
                            ebx41 = (void**)((uint8_t)ebx41 + (uint32_t)*(void**)(v42 + 0x406ae0));
                        } while ((uint8_t)ebx41 < (uint8_t)v38);
                    }
                    if (ebp39 != 7) 
                        goto addr_0x40e120_32;
                } else {
                    goto addr_0x40e25c_23;
                }
            }
        }
    }
    addr_0x40e2b5_34:
    ebx46 = (void**)(((uint32_t)*(void**)(v21 + 0x406ae0) + (uint8_t)a1->f0 - (uint8_t)(*(void***)(v21 + 0x406ac4) + 1)) / (uint32_t)*(void**)(v21 + 0x406ae0));
    a1->f0 = ebx46;
    a1->f4 = (void*)((uint8_t)ebx46 * a1->f11 + 7 >> 3);
    goto addr_0x40e2f2_2;
    addr_0x40e1be_11:
    addr_0x40e256_21:
    eax47 = edi18;
    *(void***)esi16 = *(void***)&eax47;
    goto addr_0x40e2b5_34;
    addr_0x40e25c_23:
    ebp48 = a1->f0;
    edi49 = (void**)static_cast<uint32_t>((uint8_t)(a1->f11 >> 3));
    eax50 = (uint8_t)a3 * 4;
    ebx51 = *(void***)(eax50 + 0x406ac4);
    v21 = eax50;
    if ((uint8_t)ebx51 < (uint8_t)ebp48) {
        esi52 = a2;
        do {
            eax53 = (void**)((uint8_t)ebx51 * (uint8_t)edi49 + (uint8_t)a2);
            if (esi52 != eax53) {
                fun_417ac0(esi52, eax53, edi49, v54, v11, v9, v7, v5);
            }
            esi52 = (void**)((uint8_t)esi52 + (uint8_t)edi49);
            ebx51 = (void**)((uint8_t)ebx51 + (uint32_t)*(void**)(v21 + 0x406ae0));
        } while ((uint8_t)ebx51 < (uint8_t)ebp48);
        goto addr_0x40e2b5_34;
    }
    addr_0x40e120_32:
    goto addr_0x40e256_21;
}

void** g420818 = (void**)0x78;

void** g420824 = (void**)72;

void fun_4158d0(void** a1, int32_t a2, int32_t a3, int32_t a4);

void fun_415a30(void** a1);

void** fun_409780(void** a1, void** a2, void** a3) {
    void** ebp4;
    void** ebx5;
    void** edi6;
    void** ecx7;
    void** eax8;
    int1_t zf9;
    void** esi10;
    uint32_t eax11;
    uint32_t ecx12;
    void** edi13;
    uint32_t ecx14;
    uint32_t edx15;
    void** edx16;
    void** ecx17;
    int1_t zf18;
    uint32_t eax19;
    uint32_t ecx20;
    void** edx21;
    void** edi22;
    void** edx23;
    uint32_t eax24;
    uint32_t ecx25;
    void** edx26;
    void** ecx27;
    void** edx28;
    void** eax29;
    void** eax30;
    void** eax31;
    void** edi32;
    void* ecx33;
    void* edx34;
    uint32_t ecx35;
    uint32_t ecx36;
    void** eax37;
    uint32_t eax38;
    uint32_t edx39;
    void** edx40;
    void** ecx41;
    void** edx42;
    void** eax43;
    uint32_t eax44;
    uint32_t ecx45;
    void** edx46;
    void** ecx47;
    void** eax48;
    void** eax49;
    uint1_t zf50;
    void** esi51;
    void** edi52;
    void** edx53;
    uint32_t ecx54;
    uint32_t ecx55;
    void** ecx56;
    void** ecx57;
    void** esi58;
    void** esi59;
    void** edi60;
    void** edx61;
    uint32_t ecx62;
    uint32_t ecx63;
    void** ecx64;
    void** ecx65;
    void** esi66;
    void** eax67;
    void** esi68;
    void** edi69;
    void** edx70;
    uint32_t ecx71;
    uint32_t ecx72;
    void** ecx73;
    void** ecx74;

    ebp4 = a1;
    if (!ebp4 || ((ebx5 = *(void***)(ebp4 + 28), ebx5 == 0) || ((edi6 = a2, (int8_t)edi6 > (int8_t)4) || (int8_t)edi6 < (int8_t)0))) {
        addr_0x409bad_2:
        return 0xfffffffe;
    } else {
        if (!*(void***)(ebp4 + 12) || (!*(void***)ebp4 && *(void***)(ebp4 + 4) || (int1_t)(*(void***)(ebx5 + 4) == 0x29a) && !(int1_t)(edi6 == 4))) {
            ecx7 = g420818;
            *(void***)(ebp4 + 24) = ecx7;
            goto addr_0x409bad_2;
        } else {
            if (!*(void***)(ebp4 + 16)) {
                eax8 = g420824;
                *(void***)(ebp4 + 24) = eax8;
                return 0xfffffffb;
            }
            zf9 = (int1_t)(*(void***)(ebx5 + 4) == 42);
            esi10 = *(void***)(ebx5 + 32);
            *(void***)ebx5 = ebp4;
            *(void***)(ebx5 + 32) = edi6;
            if (zf9) {
                eax11 = (uint32_t)((int8_t)(*(void***)(ebx5 + 0x7c) - 1) >> 1);
                if (eax11 > 3) {
                    eax11 = 3;
                }
                ecx12 = ((uint8_t)*(void***)(ebx5 + 40) << 12) - 0x7800 | eax11 << 6;
                if (*(void***)(ebx5 + 100)) {
                    ecx12 = ecx12 | 32;
                }
                edi13 = *(void***)(ebx5 + 20);
                *(void***)(ebx5 + 4) = (void**)0x71;
                ecx14 = ecx12 + (31 - ecx12 % 31);
                edx15 = ecx14 >> 8;
                *(int8_t*)((uint8_t)*(void***)(ebx5 + 8) + (uint8_t)edi13) = *(int8_t*)&edx15;
                edx16 = *(void***)(ebx5 + 20) + 1;
                *(void***)(ebx5 + 20) = edx16;
                *(int8_t*)((uint8_t)edx16 + (uint8_t)*(void***)(ebx5 + 8)) = *(int8_t*)&ecx14;
                ecx17 = *(void***)(ebx5 + 20) + 1;
                zf18 = *(void***)(ebx5 + 100) == 0;
                *(void***)(ebx5 + 20) = ecx17;
                if (!zf18) {
                    eax19 = 0;
                    *(int16_t*)&eax19 = *(int16_t*)(ebp4 + 50);
                    ecx20 = eax19 >> 8;
                    *(int8_t*)((uint8_t)ecx17 + (uint8_t)*(void***)(ebx5 + 8)) = *(int8_t*)&ecx20;
                    edx21 = *(void***)(ebx5 + 8);
                    edi22 = *(void***)(ebx5 + 20) + 1;
                    *(void***)(ebx5 + 20) = edi22;
                    *(int8_t*)((uint8_t)edi22 + (uint8_t)edx21) = *(int8_t*)&eax19;
                    edx23 = *(void***)(ebx5 + 20) + 1;
                    *(void***)(ebx5 + 20) = edx23;
                    eax24 = (uint8_t)*(void***)(ebp4 + 48) & 0xffff;
                    ecx25 = eax24 >> 8;
                    *(int8_t*)((uint8_t)edx23 + (uint8_t)*(void***)(ebx5 + 8)) = *(int8_t*)&ecx25;
                    edx26 = *(void***)(ebx5 + 8);
                    ecx27 = *(void***)(ebx5 + 20) + 1;
                    *(void***)(ebx5 + 20) = ecx27;
                    *(int8_t*)((uint8_t)ecx27 + (uint8_t)edx26) = *(int8_t*)&eax24;
                    *(void***)(ebx5 + 20) = *(void***)(ebx5 + 20) + 1;
                }
                edi6 = a2;
                *(void***)(ebp4 + 48) = (void**)1;
            }
            if (*(void***)(ebx5 + 20)) 
                goto addr_0x4098d7_16;
        }
    }
    if (!*(void***)(ebp4 + 4) && ((int8_t)edi6 <= (int8_t)esi10 && edi6 != 4)) {
        edx28 = g420824;
        *(void***)(ebp4 + 24) = edx28;
        return 0xfffffffb;
    }
    if ((int1_t)(*(void***)(ebx5 + 4) == 0x29a)) {
        if (*(void***)(ebp4 + 4)) {
            eax29 = g420824;
            *(void***)(ebp4 + 24) = eax29;
            return 0xfffffffb;
        }
    }
    if (*(void***)(ebp4 + 4)) {
        addr_0x4099b1_23:
        eax30 = *(void***)(ebx5 + 0x7c);
        eax31 = (void**)*(int32_t*)((uint32_t)(eax30 + (uint8_t)eax30 * 2) * 4 + 0x41d618)(ebx5, edi6);
        if (eax31 == 2 || (int1_t)(eax31 == 3)) {
            *(void***)(ebx5 + 4) = (void**)0x29a;
        }
    } else {
        if (*(void***)(ebx5 + 0x6c)) 
            goto addr_0x4099b1_23;
        if (!edi6) 
            goto addr_0x409ab2_27;
        if (*(void***)(ebx5 + 4) == 0x29a) 
            goto addr_0x409ab2_27; else 
            goto addr_0x4099b1_23;
    }
    if (!eax31 || eax31 == 2) {
        if (!*(void***)(ebp4 + 16)) {
            *(void***)(ebx5 + 32) = (void**)0xffffffff;
        }
        return 0;
    }
    if (!(int1_t)(eax31 == 1)) {
        addr_0x409ab2_27:
        if (edi6 != 4) {
            return 0;
        }
    } else {
        if (edi6 != eax31) {
            fun_4158d0(ebx5, 0, 0, 0);
            if ((int1_t)(edi6 == 3)) {
                *(int16_t*)((uint32_t)(*(void***)(ebx5 + 60) + (uint8_t)*(void**)(ebx5 + 68) * 2) - 2) = 0;
                edi32 = *(void***)(ebx5 + 60);
                ecx33 = (void*)((uint8_t)*(void**)(ebx5 + 68) + (uint8_t)*(void**)(ebx5 + 68) + 0xfffffffe);
                edx34 = ecx33;
                ecx35 = (uint32_t)ecx33 >> 2;
                while (ecx35) {
                    --ecx35;
                    *(void***)edi32 = (void**)0;
                    edi32 = edi32 + 4;
                }
                ecx36 = (uint32_t)edx34 & 3;
                while (ecx36) {
                    --ecx36;
                    *(void***)edi32 = (void**)0;
                    ++edi32;
                }
                edi6 = a2;
            }
        } else {
            fun_415a30(ebx5);
        }
        eax37 = *(void***)(*(void***)(ebp4 + 28) + 20);
        if ((uint8_t)eax37 > (uint8_t)*(void***)(ebp4 + 16)) {
            eax37 = *(void***)(ebp4 + 16);
        }
        if (!eax37) 
            goto addr_0x409a9d_48; else 
            goto addr_0x409a4f_49;
    }
    if (*(void***)(ebx5 + 24)) {
        return 1;
    }
    eax38 = 0;
    *(int16_t*)&eax38 = *(int16_t*)(ebp4 + 50);
    edx39 = eax38 >> 8;
    *(int8_t*)((uint8_t)*(void***)(ebx5 + 8) + (uint8_t)*(void***)(ebx5 + 20)) = *(int8_t*)&edx39;
    edx40 = *(void***)(ebx5 + 8);
    ecx41 = *(void***)(ebx5 + 20) + 1;
    *(void***)(ebx5 + 20) = ecx41;
    *(int8_t*)((uint8_t)ecx41 + (uint8_t)edx40) = *(int8_t*)&eax38;
    edx42 = *(void***)(ebx5 + 8);
    eax43 = *(void***)(ebx5 + 20) + 1;
    *(void***)(ebx5 + 20) = eax43;
    eax44 = (uint8_t)*(void***)(ebp4 + 48) & 0xffff;
    ecx45 = eax44 >> 8;
    *(int8_t*)((uint8_t)eax43 + (uint8_t)edx42) = *(int8_t*)&ecx45;
    edx46 = *(void***)(ebx5 + 8);
    ecx47 = *(void***)(ebx5 + 20) + 1;
    *(void***)(ebx5 + 20) = ecx47;
    *(int8_t*)((uint8_t)ecx47 + (uint8_t)edx46) = *(int8_t*)&eax44;
    *(void***)(ebx5 + 20) = *(void***)(ebx5 + 20) + 1;
    eax48 = *(void***)(*(void***)(ebp4 + 28) + 20);
    if ((uint8_t)eax48 > (uint8_t)*(void***)(ebp4 + 16)) {
        eax48 = *(void***)(ebp4 + 16);
    }
    if (eax48) 
        goto addr_0x409b2f_55;
    addr_0x409b79_56:
    eax49 = (void**)0;
    zf50 = (uint1_t)(*(void***)(ebx5 + 20) == 0);
    *(void***)(ebx5 + 24) = (void**)0xffffffff;
    *(uint8_t*)&eax49 = static_cast<uint8_t>(zf50);
    return eax49;
    addr_0x409b2f_55:
    esi51 = *(void***)(*(void***)(ebp4 + 28) + 16);
    edi52 = *(void***)(ebp4 + 12);
    edx53 = eax48;
    ecx54 = (uint8_t)eax48 >> 2;
    while (ecx54) {
        --ecx54;
        *(void***)edi52 = *(void***)esi51;
        edi52 = edi52 + 4;
        esi51 = esi51 + 4;
    }
    ecx55 = (uint8_t)edx53 & 3;
    while (ecx55) {
        --ecx55;
        *(void***)edi52 = *(void***)esi51;
        ++edi52;
        ++esi51;
    }
    ecx56 = *(void***)(ebp4 + 28);
    *(void***)(ebp4 + 12) = (void**)((uint8_t)*(void***)(ebp4 + 12) + (uint8_t)eax48);
    *(void***)(ecx56 + 16) = (void**)((uint8_t)*(void***)(ecx56 + 16) + (uint8_t)eax48);
    ecx57 = *(void***)(ebp4 + 28);
    esi58 = (void**)((uint8_t)*(void***)(ebp4 + 16) - (uint8_t)eax48);
    *(void***)(ebp4 + 20) = (void**)((uint8_t)*(void***)(ebp4 + 20) + (uint8_t)eax48);
    *(void***)(ebp4 + 16) = esi58;
    *(void***)(ecx57 + 20) = (void**)((uint8_t)*(void***)(ecx57 + 20) - (uint8_t)eax48);
    if (*(void***)(*(void***)(ebp4 + 28) + 20)) 
        goto addr_0x409b79_56;
    *(void***)(*(void***)(ebp4 + 28) + 16) = *(void***)(*(void***)(ebp4 + 28) + 8);
    goto addr_0x409b79_56;
    addr_0x409a9d_48:
    if (!*(void***)(ebp4 + 16)) {
        *(void***)(ebx5 + 32) = (void**)0xffffffff;
        return 0;
    }
    addr_0x409a4f_49:
    esi59 = *(void***)(*(void***)(ebp4 + 28) + 16);
    edi60 = *(void***)(ebp4 + 12);
    edx61 = eax37;
    ecx62 = (uint8_t)eax37 >> 2;
    while (ecx62) {
        --ecx62;
        *(void***)edi60 = *(void***)esi59;
        edi60 = edi60 + 4;
        esi59 = esi59 + 4;
    }
    ecx63 = (uint8_t)edx61 & 3;
    while (ecx63) {
        --ecx63;
        *(void***)edi60 = *(void***)esi59;
        ++edi60;
        ++esi59;
    }
    ecx64 = *(void***)(ebp4 + 28);
    *(void***)(ebp4 + 12) = (void**)((uint8_t)*(void***)(ebp4 + 12) + (uint8_t)eax37);
    *(void***)(ecx64 + 16) = (void**)((uint8_t)*(void***)(ecx64 + 16) + (uint8_t)eax37);
    ecx65 = *(void***)(ebp4 + 28);
    esi66 = (void**)((uint8_t)*(void***)(ebp4 + 16) - (uint8_t)eax37);
    *(void***)(ebp4 + 20) = (void**)((uint8_t)*(void***)(ebp4 + 20) + (uint8_t)eax37);
    edi6 = a2;
    *(void***)(ebp4 + 16) = esi66;
    *(void***)(ecx65 + 20) = (void**)((uint8_t)*(void***)(ecx65 + 20) - (uint8_t)eax37);
    if (*(void***)(*(void***)(ebp4 + 28) + 20)) 
        goto addr_0x409a9d_48;
    *(void***)(*(void***)(ebp4 + 28) + 16) = *(void***)(*(void***)(ebp4 + 28) + 8);
    goto addr_0x409a9d_48;
    addr_0x4098d7_16:
    eax67 = *(void***)(*(void***)(ebp4 + 28) + 20);
    if ((uint8_t)eax67 > (uint8_t)*(void***)(ebp4 + 16)) {
        eax67 = *(void***)(ebp4 + 16);
    }
    if (eax67) 
        goto addr_0x4098ea_74;
    addr_0x409938_75:
    if (!*(void***)(ebp4 + 16)) {
        *(void***)(ebx5 + 32) = (void**)0xffffffff;
        return 0;
    }
    addr_0x4098ea_74:
    esi68 = *(void***)(*(void***)(ebp4 + 28) + 16);
    edi69 = *(void***)(ebp4 + 12);
    edx70 = eax67;
    ecx71 = (uint8_t)eax67 >> 2;
    while (ecx71) {
        --ecx71;
        *(void***)edi69 = *(void***)esi68;
        edi69 = edi69 + 4;
        esi68 = esi68 + 4;
    }
    ecx72 = (uint8_t)edx70 & 3;
    while (ecx72) {
        --ecx72;
        *(void***)edi69 = *(void***)esi68;
        ++edi69;
        ++esi68;
    }
    ecx73 = *(void***)(ebp4 + 28);
    *(void***)(ebp4 + 12) = (void**)((uint8_t)*(void***)(ebp4 + 12) + (uint8_t)eax67);
    *(void***)(ecx73 + 16) = (void**)((uint8_t)*(void***)(ecx73 + 16) + (uint8_t)eax67);
    ecx74 = *(void***)(ebp4 + 28);
    esi10 = (void**)((uint8_t)*(void***)(ebp4 + 16) - (uint8_t)eax67);
    *(void***)(ebp4 + 20) = (void**)((uint8_t)*(void***)(ebp4 + 20) + (uint8_t)eax67);
    edi6 = a2;
    *(void***)(ebp4 + 16) = esi10;
    *(void***)(ecx74 + 20) = (void**)((uint8_t)*(void***)(ecx74 + 20) - (uint8_t)eax67);
    if (*(void***)(*(void***)(ebp4 + 28) + 20)) 
        goto addr_0x409938_75;
    *(void***)(*(void***)(ebp4 + 28) + 16) = *(void***)(*(void***)(ebp4 + 28) + 8);
    goto addr_0x409938_75;
}

void** fun_410d50(void** a1, void** a2, void** a3) {
    void** eax4;

    fun_410b88(a1, 0x406a5f, a3);
    fun_410bf4(a1, a2, a3, 0x410d71, a1, 0x406a5f, a3);
    eax4 = fun_410c30(a1, 0x406a5f, a3);
    *(void***)(a1 + 0x68) = (void**)((uint8_t)*(void***)(a1 + 0x68) | 4);
    return eax4;
}

void fun_408fa4(void** a1, int32_t a2) {
    *(uint8_t*)(a1 + 0x72) = (uint8_t)(*(uint8_t*)(a1 + 0x72) | 8);
    return;
}

void fun_40908c(void** a1, void** a2) {
    *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 32);
    return;
}

struct s14 {
    int32_t f0;
    int8_t f4;
};

void fun_40904c(void** a1, struct s14* a2) {
    *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 8);
    *(int32_t*)(a1 + 0x181) = a2->f0;
    *(int8_t*)(a1 + 0x185) = a2->f4;
    return;
}

void fun_40901c(void** a1) {
    if ((uint8_t)*(void**)(a1 + 0x127) <= 7) {
        *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 4);
        *(void**)(a1 + 0x128) = (void*)8;
    }
    return;
}

void fun_408f98(void** a1) {
    *(uint8_t*)(a1 + 0x72) = (uint8_t)(*(uint8_t*)(a1 + 0x72) | 2);
    return;
}

void fun_408fb0(void** a1, uint32_t a2, void** a3) {
    uint32_t eax4;

    *(uint8_t*)(a1 + 0x71) = (uint8_t)(*(uint8_t*)(a1 + 0x71) | 0x80);
    eax4 = a2 & 0xff;
    *(int16_t*)(a1 + 0x12e) = *(int16_t*)&eax4;
    if (!(int1_t)(a3 == 1)) {
        *(void***)(a1 + 0x6c) = (void**)((uint8_t)*(void***)(a1 + 0x6c) & 0x7f);
    } else {
        *(void***)(a1 + 0x6c) = (void**)((uint8_t)*(void***)(a1 + 0x6c) | 0x80);
    }
    if (*(uint8_t*)(a1 + 0x126) == 2) {
        *(uint8_t*)(a1 + 0x12b) = 4;
    }
    if (!*(uint8_t*)(a1 + 0x126) && (uint8_t)*(void**)(a1 + 0x127) > 7) {
        *(uint8_t*)(a1 + 0x12b) = 2;
    }
    return;
}

void fun_408f8c(void** a1, uint32_t a2, void** a3) {
    *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 1);
    return;
}

void fun_409008(void** a1, uint32_t a2, void** a3) {
    if ((int1_t)(*(void**)(a1 + 0x127) == 16)) {
        *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 16);
    }
    return;
}

void fun_409038(void** a1, uint32_t a2, void** a3) {
    if ((uint8_t)*(void**)(a1 + 0x127) <= 7) {
        *(uint8_t*)(a1 + 0x72) = (uint8_t)(*(uint8_t*)(a1 + 0x72) | 1);
    }
    return;
}

int32_t fun_40906c(void** a1, uint32_t a2, void** a3) {
    if (*(int8_t*)(a1 + 0x123)) {
        *(void***)(a1 + 0x70) = (void**)((uint8_t)*(void***)(a1 + 0x70) | 2);
        return 7;
    } else {
        return 1;
    }
}

void fun_402a34(void** a1, void** a2, void** a3, struct s13* a4);

void fun_4113b0(void** a1, void** a2, void** a3, struct s13* a4);

void fun_4122d4(struct s12* a1, void** a2, void** a3, struct s13* a4);

void fun_40e2fc(void** a1, struct s12* a2, void** a3, struct s13* a4);

void fun_40dc98(void** a1, void** a2);

void fun_403678(void** a1, void** a2, void** a3) {
    void** v4;
    void** eax5;
    void** esi6;
    uint8_t cl7;
    void* dl8;
    void** edx9;
    struct s13* eax10;
    void** v11;
    void** v12;
    void** v13;
    struct s12* esi14;
    void** v15;
    int32_t edx16;
    uint32_t v17;
    void** v18;
    int32_t v19;
    void** v20;
    void** v21;
    void** ebx22;
    void** esi23;

    if (*(void***)(v4 + 0xe4)) {
        addr_0x4036b6_4:
    } else {
        if (*(uint8_t*)(v4 + 0x124)) 
            goto addr_0x4036b6_4; else 
            goto addr_0x403693_7;
    }
    if (!*(int8_t*)(v4 + 0x123)) 
        goto addr_0x4037d4_10;
    if (!((uint8_t)*(void***)(v4 + 0x70) & 2)) 
        goto addr_0x4037d4_10;
    eax5 = (void**)static_cast<uint32_t>(*(uint8_t*)(v4 + 0x124));
    if ((uint8_t)eax5 > (uint8_t)6) 
        goto addr_0x4037d4_10;
    switch (eax5) {
    case 0:
        asm("in al, 0x0");
        *(void***)eax5 = (void**)((uint8_t)*(void***)eax5 + (uint8_t)*(void**)&eax5);
        if (!*(void***)eax5) {
            addr_0x4037d4_10:
            *(uint8_t*)(v4 + 0x108) = *(uint8_t*)(v4 + 0x126);
            esi6 = *(void***)(v4 + 0xd4);
            *(void***)(v4 + 0x100) = esi6;
            cl7 = *(uint8_t*)(v4 + 0x12b);
            *(uint8_t*)(v4 + 0x10a) = cl7;
            dl8 = *(void**)(v4 + 0x128);
            *(void**)(v4 + 0x109) = dl8;
            *(int16_t*)&eax5 = (int16_t)((int8_t)dl8 * (int8_t)cl7);
            edx9 = eax5;
            *(uint8_t*)(v4 + 0x10b) = *(uint8_t*)&edx9;
            eax10 = (struct s13*)((uint8_t)esi6 * *(uint8_t*)(v4 + 0x10b) + 7 >> 3);
            *(struct s13**)(v4 + 0x104) = eax10;
            v11 = v12;
            v13 = *(void***)(v4 + 0xec) + 1;
            fun_402a34(v4, v13, v11, eax10);
            esi14 = (struct s12*)(v4 + 0x100);
            if (!*(int8_t*)(v4 + 0x123) || (*(uint8_t*)(v4 + 0x124) > 5 || (!((uint8_t)*(void***)(v4 + 0x70) & 2) || (v11 = (void**)static_cast<uint32_t>(*(uint8_t*)(v4 + 0x124)), v13 = *(void***)(v4 + 0xec) + 1, fun_40e054(esi14, v13, v11, eax10), !!*(void***)(v4 + 0x100))))) {
                if (*(void***)(v4 + 0x70)) {
                    fun_4113b0(v4, v13, v11, eax10);
                }
                if (*(uint8_t*)(v4 + 0x230) & 4 && *(int8_t*)(v4 + 0x238) == 64) {
                    v15 = *(void***)(v4 + 0xec) + 1;
                    fun_4122d4(esi14, v15, v11, eax10);
                }
                fun_40e2fc(v4, esi14, v11, eax10);
                edx16 = *(int32_t*)(v4 + 0x19c);
                if (!edx16) 
                    goto addr_0x4038f2_20;
            } else {
                fun_40de24(v4, v4);
                break;
            }
        } else {
            fun_40de24(v4, v4);
            break;
        }
        v17 = static_cast<uint32_t>(*(uint8_t*)(v4 + 0x124));
        v18 = *(void***)(v4 + 0xe4);
        edx16(v4, v18, v17, eax10);
        break;
    case 1:
        if ((uint8_t)*(void***)(v4 + 0xe4) & 7) 
            goto addr_0x403732_25;
        if ((uint8_t)*(void***)(v4 + 0xc8) > (uint8_t)4) 
            goto addr_0x4037d4_10;
        addr_0x403732_25:
        fun_40de24(v4, v4);
        break;
    case 2:
        eax5 = (void**)((uint8_t)*(void***)(v4 + 0xe4) & 7);
        if (eax5 == 4) 
            goto addr_0x4037d4_10;
        fun_40de24(v4, v4);
        break;
    case 3:
        if ((uint8_t)*(void***)(v4 + 0xe4) & 3) 
            goto addr_0x403772_30;
        if ((uint8_t)*(void***)(v4 + 0xc8) > (uint8_t)2) 
            goto addr_0x4037d4_10;
        addr_0x403772_30:
        fun_40de24(v4, v4);
        break;
    case 4:
        eax5 = (void**)((uint8_t)*(void***)(v4 + 0xe4) & 3);
        if (eax5 == 2) 
            goto addr_0x4037d4_10;
        fun_40de24(v4, v4);
        break;
    case 5:
        if ((uint8_t)*(void***)(v4 + 0xe4) & 1) 
            goto addr_0x4037ae_35;
        if ((uint8_t)*(void***)(v4 + 0xc8) > (uint8_t)1) 
            goto addr_0x4037d4_10;
        addr_0x4037ae_35:
        fun_40de24(v4, v4);
        break;
    case 6:
        if ((uint8_t)*(void***)(v4 + 0xe4) & 1) 
            goto addr_0x4037d4_10;
        fun_40de24(v4, v4);
    }
    addr_0x4038f2_20:
    goto v19;
    addr_0x403693_7:
    if (!(*(uint8_t*)(v4 + 0x69) & 4)) {
        eax5 = fun_408404(v4, 0x403640, v20, v21, ebx22, esi23);
    }
    fun_40dc98(v4, 0x403640);
    goto addr_0x4036b6_4;
}

void fun_406c0c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void** v10;
    void** edi11;
    void** v12;
    void** esi13;
    void** v14;
    void** ebx15;
    void** ebp16;
    void** esi17;
    void** edi18;
    void** ebx19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void* ebx24;
    void** v25;
    void** v26;
    void** v27;
    uint32_t ebx28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** ebx34;
    void** v35;
    void* ebx36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** ebx41;
    void** v42;
    void* ebx43;
    void** v44;
    void** v45;
    void** ebx46;
    void** v47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;

    v9 = (void**)__return_address();
    v10 = edi11;
    v12 = esi13;
    v14 = ebx15;
    ebp16 = a5;
    esi17 = a6;
    edi18 = a7;
    if (!ebp16 || !esi17) {
        addr_0x407005_4:
        goto a4;
    } else {
        if (!((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x4000))) 
            goto addr_0x406caf_8;
        if (a8 != 0xffffffff) 
            goto addr_0x406c45_10;
    }
    ebx19 = (void**)0;
    if ((int8_t)0 < (int8_t)*(void***)(esi17 + 48)) {
        do {
            v20 = ebx19;
            v21 = (void**)0x4000;
            fun_406c0c(ebp16, esi17, 0x4000, v20, v14, v12, v10, v9);
            ++ebx19;
        } while ((int8_t)ebx19 < (int8_t)*(void***)(esi17 + 48));
    }
    v22 = *(void***)(esi17 + 56);
    fun_4029a0(ebp16, v22, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
    *(void***)(esi17 + 56) = (void**)0;
    *(void***)(esi17 + 48) = (void**)0;
    addr_0x406cac_15:
    goto addr_0x406caf_8;
    addr_0x406c45_10:
    if (!*(void***)(esi17 + 56)) {
        addr_0x406caf_8:
        if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x2000)) {
            v23 = *(void***)(esi17 + 76);
            fun_4029a0(ebp16, v23, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
            *(void***)(esi17 + 8) = (void**)((uint8_t)*(void***)(esi17 + 8) & 0xef);
            *(void***)(esi17 + 76) = (void**)0;
        }
    } else {
        ebx24 = (void*)((uint8_t)a8 << 4);
        if (!*(void***)((uint8_t)*(void***)(esi17 + 56) + (uint32_t)ebx24 + 4)) 
            goto addr_0x406caf_8; else 
            goto addr_0x406c5b_20;
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x100)) {
        *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) & 0xbf);
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x80)) {
        v25 = *(void***)(esi17 + 0xa0);
        fun_4029a0(ebp16, v25, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
        v26 = *(void***)(esi17 + 0xac);
        fun_4029a0(ebp16, v26, v27, 0x406d0d, ebp16, v25, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3);
        *(void***)(esi17 + 0xa0) = (void**)0;
        *(void***)(esi17 + 0xac) = (void**)0;
        if (*(void***)(esi17 + 0xb0)) {
            ebx28 = 0;
            if (*(uint8_t*)(esi17 + 0xb5)) {
                do {
                    v29 = *(void***)(*(void***)(esi17 + 0xb0) + ebx28 * 4);
                    fun_4029a0(ebp16, v29, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
                    *(void***)(*(void***)(esi17 + 0xb0) + ebx28 * 4) = (void**)0;
                    ++ebx28;
                } while ((int32_t)ebx28 < (int32_t)static_cast<uint32_t>(*(uint8_t*)(esi17 + 0xb5)));
            }
            v30 = *(void***)(esi17 + 0xb0);
            fun_4029a0(ebp16, v30, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
            *(void***)(esi17 + 0xb0) = (void**)0;
        }
        *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) & 0xfb);
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 16)) {
        v31 = *(void***)(esi17 + 0xc4);
        fun_4029a0(ebp16, v31, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
        v32 = *(void***)(esi17 + 0xc8);
        fun_4029a0(ebp16, v32, v33, 0x406db2, ebp16, v31, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3);
        *(void***)(esi17 + 0xc4) = (void**)0;
        *(void***)(esi17 + 0xc8) = (void**)0;
        *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) & 0xef);
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 32)) {
        if (a8 == 0xffffffff) {
            if (*(void***)(esi17 + 0xd8)) {
                ebx34 = (void**)0;
                if ((int8_t)0 < (int8_t)*(void***)(esi17 + 0xd8)) {
                    do {
                        v20 = ebx34;
                        v21 = (void**)32;
                        fun_406c0c(ebp16, esi17, 32, v20, v14, v12, v10, v9);
                        ++ebx34;
                    } while ((int8_t)ebx34 < (int8_t)*(void***)(esi17 + 0xd8));
                }
                v35 = *(void***)(esi17 + 0xd4);
                fun_4029a0(ebp16, v35, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
                *(void***)(esi17 + 0xd4) = (void**)0;
                *(void***)(esi17 + 0xd8) = (void**)0;
            }
            *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) & 0xdf);
        } else {
            if (*(void***)(esi17 + 0xd4)) {
                ebx36 = (void*)((uint8_t)a8 << 4);
                v37 = *(void***)((uint8_t)*(void***)(esi17 + 0xd4) + (uint32_t)ebx36);
                fun_4029a0(ebp16, v37, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
                v38 = *(void***)((uint8_t)*(void***)(esi17 + 0xd4) + (uint32_t)ebx36 + 8);
                fun_4029a0(ebp16, v38, v39, 0x406e15, ebp16, v37, 0x4000, v20, v14, v12, v10, v9, a1, a2, a3);
                *(void***)((uint8_t)*(void***)(esi17 + 0xd4) + (uint32_t)ebx36) = (void**)0;
                *(int32_t*)((uint8_t)*(void***)(esi17 + 0xd4) + (uint32_t)ebx36 + 8) = 0;
            }
        }
    }
    if (!((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x200))) 
        goto addr_0x406f33_42;
    if (a8 == 0xffffffff) {
        if (!*(void***)(esi17 + 0xc0)) {
            addr_0x406f33_42:
            if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 8)) {
                v40 = *(void***)(esi17 + 0x7c);
                fun_4029a0(ebp16, v40, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
                *(void***)(esi17 + 0x7c) = (void**)0;
                *(void***)(esi17 + 8) = (void**)((uint8_t)*(void***)(esi17 + 8) & 0xbf);
            }
        } else {
            ebx41 = (void**)0;
            if ((int8_t)0 < (int8_t)*(void***)(esi17 + 0xc0)) {
                do {
                    v20 = ebx41;
                    v21 = (void**)0x200;
                    fun_406c0c(ebp16, esi17, 0x200, v20, v14, v12, v10, v9);
                    ++ebx41;
                } while ((int8_t)ebx41 < (int8_t)*(void***)(esi17 + 0xc0));
            }
            v42 = *(void***)(esi17 + 0xbc);
            fun_4029a0(ebp16, v42, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
            *(void***)(esi17 + 0xbc) = (void**)0;
            *(void***)(esi17 + 0xc0) = (void**)0;
            goto addr_0x406f30_49;
        }
    } else {
        if (!*(void***)(esi17 + 0xbc)) 
            goto addr_0x406f33_42;
        ebx43 = (void*)((uint32_t)(a8 + (uint8_t)a8 * 4) << 2);
        v44 = *(void***)((uint8_t)*(void***)(esi17 + 0xbc) + (uint32_t)ebx43 + 8);
        fun_4029a0(ebp16, v44, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
        *(int32_t*)((uint8_t)*(void***)(esi17 + 0xbc) + (uint32_t)ebx43 + 8) = 0;
        goto addr_0x406f30_49;
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 0x1000)) {
        v45 = *(void***)(esi17 + 16);
        fun_4029a0(ebp16, v45, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
        *(void***)(esi17 + 16) = (void**)0;
        *(void***)(esi17 + 8) = (void**)((uint8_t)*(void***)(esi17 + 8) & 0xf7);
        *(void***)(esi17 + 20) = (void**)0;
    }
    if ((uint8_t)edi18 & ((uint8_t)*(void***)(esi17 + 0xb8) & 64)) {
        if (*(void***)(esi17 + 0xf8)) {
            ebx46 = (void**)0;
            if ((int8_t)0 < (int8_t)*(void***)(esi17 + 4)) {
                esi17 = esi17;
                do {
                    v47 = *(void***)(*(void***)(esi17 + 0xf8) + (uint8_t)ebx46 * 4);
                    fun_4029a0(ebp16, v47, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
                    *(void***)(*(void***)(esi17 + 0xf8) + (uint8_t)ebx46 * 4) = (void**)0;
                    ++ebx46;
                } while ((int8_t)ebx46 < (int8_t)*(void***)(esi17 + 4));
            }
            v48 = *(void***)(esi17 + 0xf8);
            fun_4029a0(ebp16, v48, v21, v20, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
            *(void***)(esi17 + 0xf8) = (void**)0;
        }
        *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) & 0x7f);
    }
    if (a8 != 0xffffffff) {
        edi18 = (void**)((uint8_t)edi18 & 0xffffbddf);
    }
    *(void***)(esi17 + 0xb8) = (void**)((uint8_t)*(void***)(esi17 + 0xb8) & ~(uint8_t)edi18);
    goto addr_0x407005_4;
    addr_0x406f30_49:
    goto addr_0x406f33_42;
    addr_0x406c5b_20:
    v49 = *(void***)((uint8_t)*(void***)(esi17 + 56) + (uint32_t)ebx24 + 4);
    fun_4029a0(ebp16, v49, v50, v51, v14, v12, v10, v9, a1, a2, a3, a4, a5, a6, a7);
    *(int32_t*)((uint8_t)*(void***)(esi17 + 56) + (uint32_t)ebx24 + 4) = 0;
    goto addr_0x406cac_15;
}

uint32_t fun_409bc0(void** a1);

void fun_4039f8(void** a1, void** a2, void** a3, void** a4) {
    void** v5;
    void** v6;
    void** v7;
    void** v8;
    void** v9;
    void** ebx10;
    void** esi11;
    void** edi12;
    void** ebp13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** v41;
    void** v42;
    void** v43;
    void** v44;
    void** v45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    void** v52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;
    void** v58;
    void** v59;
    void** v60;
    void** v61;
    void** v62;
    void** v63;
    void** v64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** v70;
    void** v71;
    void** v72;
    void** v73;
    void** v74;
    void** v75;
    void** v76;
    void** v77;
    void** v78;
    void** v79;
    void** v80;
    void** v81;
    void** v82;
    void** v83;
    void** v84;
    void** v85;
    void** v86;
    void** v87;
    void** v88;
    void** v89;
    void** v90;
    void** v91;
    void** v92;
    void** v93;
    void** v94;
    void** v95;
    void** v96;
    void** v97;
    void** v98;
    void** v99;
    void** v100;
    void** v101;
    void** v102;
    void** v103;
    void** v104;
    void** v105;
    void** v106;
    void** v107;
    void** v108;
    void** v109;
    void** v110;
    void** v111;
    void** v112;
    void** v113;
    void** v114;
    void** v115;
    void** v116;
    void** v117;
    void** v118;
    int32_t ecx119;
    void** v120;
    void* edx121;
    uint32_t v122;
    void** ebx123;
    void** edi124;
    int32_t ecx125;
    void** edi126;
    int32_t ecx127;
    void** v128;

    fun_409bc0(a1 + 0x74);
    v5 = *(void***)(a1 + 0xac);
    fun_4029a0(a1, v5, v6, 0x403a0f, a1 + 0x74, v7, v8, v9, ebx10, esi11, edi12, ebp13, v14, v15, v16);
    v17 = *(void***)(a1 + 0xec);
    fun_4029a0(a1, v17, v18, v19, ebx10, esi11, edi12, ebp13, v20, v21, v22, v23, v24, v25, v26);
    v27 = *(void***)(a1 + 0xe8);
    fun_4029a0(a1, v27, v28, 0x403a3b, a1, v17, v29, v30, ebx10, esi11, edi12, ebp13, v31, v32, v33);
    v34 = *(void***)(a1 + 0xf0);
    fun_4029a0(a1, v34, v35, v36, ebx10, esi11, edi12, ebp13, v37, v38, v39, v40, v41, v42, v43);
    v44 = *(void***)(a1 + 0xf4);
    fun_4029a0(a1, v44, v45, 0x403a67, a1, v34, v46, v47, ebx10, esi11, edi12, ebp13, v48, v49, v50);
    v51 = *(void***)(a1 + 0xf8);
    fun_4029a0(a1, v51, v52, v53, ebx10, esi11, edi12, ebp13, v54, v55, v56, v57, v58, v59, v60);
    v61 = *(void***)(a1 + 0xfc);
    fun_4029a0(a1, v61, v62, 0x403a88, a1, v51, v63, v64, ebx10, esi11, edi12, ebp13, v65, v66, v67);
    v68 = *(void***)(a1 + 0x210);
    fun_4029a0(a1, v68, v69, v70, ebx10, esi11, edi12, ebp13, v71, v72, v73, v74, v75, v76, v77);
    v78 = *(void***)(a1 + 0x1fc);
    fun_4029a0(a1, v78, v79, 0x403aa9, a1, v68, v80, v81, ebx10, esi11, edi12, ebp13, v82, v83, v84);
    v85 = *(void***)(a1 + 0x200);
    fun_4029a0(a1, v85, v86, v87, ebx10, esi11, edi12, ebp13, v88, v89, v90, v91, v92, v93, v94);
    v95 = *(void***)(a1 + 0x204);
    fun_4029a0(a1, v95, v96, 0x403aca, a1, v85, v97, v98, ebx10, esi11, edi12, ebp13, v99, v100, v101);
    v102 = *(void***)(a1 + 0x208);
    fun_4029a0(a1, v102, v103, v104, ebx10, esi11, edi12, ebp13, v105, v106, v107, v108, v109, v110, v111);
    v112 = *(void***)(a1 + 0x20c);
    fun_4029a0(a1, v112, v113, 0x403aeb, a1, v102, v114, v115, ebx10, esi11, edi12, ebp13, v116, v117, v118);
    ecx119 = 16;
    while (ecx119) {
        --ecx119;
    }
    v120 = *(void***)(a1 + 64);
    edx121 = *(void**)(a1 + 68);
    v122 = *(uint32_t*)(a1 + 72);
    ebx123 = *(void***)(a1 + 0x24c);
    edi124 = a1;
    ecx125 = 0x95;
    while (ecx125) {
        --ecx125;
        *(void***)edi124 = (void**)0;
        edi124 = edi124 + 4;
    }
    *(void***)(a1 + 64) = v120;
    *(void**)(a1 + 68) = edx121;
    *(uint32_t*)(a1 + 72) = v122;
    *(void***)(a1 + 0x24c) = ebx123;
    edi126 = a1;
    ecx127 = 16;
    while (ecx127) {
        --ecx127;
        *(void***)edi126 = v128;
        edi126 = edi126 + 4;
    }
    return;
}

void fun_402b2c(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void** v10;
    void** v11;

    if (a1) {
        if (!a2) {
            fun_4178d3(a1, v9, v10, v11);
        } else {
            a2((int32_t)__zero_stack_offset() - 0x278 - 4 + 16, a1);
        }
    }
    return;
}

void fun_402a90(void** a1, void** a2) {
    void** v3;
    void** v4;
    void** v5;
    void** v6;

    fun_402b2c(__return_address(), 0, 0, v3, v4, v5, v6, __return_address());
    return;
}

void** fun_402a74(int32_t a1) {
    void** eax2;

    eax2 = fun_402aac(__return_address(), 0, 0);
    return eax2;
}

int32_t fun_415580();

void fun_407808(void** a1, void** a2, void** a3) {
    int32_t eax4;

    *(int32_t*)(a1 + 0x23c) = 0;
    *(int8_t*)(a1 + 0x239) = 0;
    *(uint8_t*)(a1 + 0x240) = (uint8_t)(*(uint8_t*)(a1 + 0x240) | 1);
    eax4 = fun_415580();
    if (!eax4) {
        *(uint8_t*)(a1 + 0x240) = (uint8_t)(*(uint8_t*)(a1 + 0x240) & 1);
    } else {
        *(uint8_t*)(a1 + 0x240) = (uint8_t)(*(uint8_t*)(a1 + 0x240) | 0xfe);
        *(int32_t*)(a1 + 0x23c) = 0x80;
        *(int8_t*)(a1 + 0x239) = 9;
    }
    return;
}

struct s15 {
    int8_t[36] pad36;
    int32_t f36;
    int32_t f40;
    int32_t f44;
};

struct s16 {
    int8_t[84] pad84;
    int32_t f84;
};

struct s17 {
    int8_t[76] pad76;
    int32_t f76;
};

struct s18 {
    int8_t[76] pad76;
    int32_t f76;
};

struct s19 {
    int8_t[332] pad332;
    int32_t f332;
};

struct s20 {
    int8_t[332] pad332;
    int32_t f332;
};

struct s21 {
    int8_t[80] pad80;
    int32_t f80;
};

struct s22 {
    int8_t[80] pad80;
    int32_t f80;
};

struct s23 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
    int8_t[3] pad52;
    void** f52;
    int8_t[3] pad56;
    void** f56;
};

struct s24 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
    int8_t[3] pad52;
    void** f52;
    int8_t[3] pad56;
    void** f56;
};

void fun_40aa88(void** a1, void** a2, void** a3, int32_t a4, void** a5, void** a6, void** a7, void** a8) {
    int32_t ebx9;
    int32_t ebx10;
    int8_t dl11;
    int32_t ebx12;
    int8_t dl13;
    uint1_t cf14;
    struct s15* esp15;
    int32_t edx16;
    int32_t ecx17;
    struct s16* ebx18;
    struct s17* ebx19;
    struct s18* ebx20;
    struct s19* ebx21;
    struct s20* ebx22;
    struct s21* ebx23;
    struct s22* ebx24;
    int32_t* esp25;
    int32_t* esp26;
    int32_t ebx27;
    struct s23* esp28;
    int32_t* esp29;
    int32_t* esp30;
    int32_t ebx31;
    struct s24* esp32;

    *(uint8_t*)(ebx9 - 0x75) = (uint8_t)(*(int8_t*)(ebx10 - 0x75) - (uint8_t)(dl11 + (uint1_t)(*(uint8_t*)(ebx12 - 0x75) < (uint8_t)(dl13 + cf14))));
    esp15 = (struct s15*)((int32_t)__return_address() + 4);
    edx16 = esp15->f40;
    ecx17 = esp15->f44;
    ebx18->f84 = esp15->f36;
    if (!edx16) {
        ebx19->f76 = 0x40ab50;
    } else {
        ebx20->f76 = edx16;
    }
    if (!ecx17) {
        ebx21->f332 = 0x40ab8c;
    } else {
        ebx22->f332 = ecx17;
    }
    if (ebx23->f80) {
        ebx24->f80 = 0;
        esp25 = (int32_t*)((int32_t)esp15 - 8 - 4);
        *esp25 = (int32_t)"Attempted to set both read_data_fn and write_data_fn in";
        esp26 = esp25 - 1;
        *esp26 = ebx27;
        esp28 = (struct s23*)(esp26 - 1);
        esp28->f0 = 0x40aae1;
        fun_40850c(esp28->f4, esp28->f8, esp28->f12, esp28->f16, esp28->f20, esp28->f24, esp28->f28, esp28->f32, esp28->f36, esp28->f40, esp28->f44, esp28->f48, esp28->f52, esp28->f56);
        esp29 = (int32_t*)(&esp28->f4 - 8 - 4);
        *esp29 = (int32_t)"the same structure.  Resetting read_data_fn to NULL.";
        esp30 = esp29 - 1;
        *esp30 = ebx31;
        esp32 = (struct s24*)(esp30 - 1);
        esp32->f0 = 0x40aaef;
        fun_40850c(esp32->f4, esp32->f8, esp32->f12, esp32->f16, esp32->f20, esp32->f24, esp32->f28, esp32->f32, esp32->f36, esp32->f40, esp32->f44, esp32->f48, esp32->f52, esp32->f56);
        esp15 = (struct s15*)(&esp32->f4 + 32);
    }
    goto *(int32_t*)((int32_t)esp15 + 4 + 24);
}

void fun_403e80(int32_t ecx);

void fun_403eb8(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13) {
    void** v14;
    void** v15;
    void** edi16;
    void** v17;
    void** esi18;
    void** v19;
    void** ebx20;
    void** esi21;
    void** eax22;
    void** edi23;
    void** edx24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** eax29;
    void** v30;
    void** v31;
    void** v32;
    int32_t v33;
    int32_t v34;
    int32_t v35;
    void** eax36;
    void** edx37;
    void** edx38;
    void** edx39;
    void** edx40;
    void** edx41;
    void** eax42;
    uint8_t ah43;
    void** edx44;
    void** eax45;
    void** edx46;
    int32_t ebx47;
    void** edx48;
    void** eax49;
    uint8_t ah50;
    void** edx51;
    void** eax52;
    void** edx53;
    int32_t ecx54;
    void** edx55;
    uint8_t ah56;
    void** edx57;
    void** eax58;
    void** edx59;
    void** v60;
    void** v61;
    void** ebx62;
    void** ebx63;
    void** v64;
    void** v65;
    void** eax66;
    void** v67;
    void** v68;
    void** v69;
    void** ebx70;
    uint32_t edx71;
    uint32_t eax72;
    void** edx73;
    void** edx74;
    void** ecx75;
    uint8_t* edx76;
    void** ecx77;
    uint8_t* edx78;
    void** ecx79;
    void** edx80;
    void** edx81;
    void** ebx82;
    void** edx83;
    void** eax84;
    void** edx85;
    void** eax86;
    void** edx87;
    void** ecx88;
    void** eax89;
    void** eax90;
    void** edx91;
    uint8_t* ecx92;
    void** eax93;
    void** eax94;
    void** edx95;
    uint8_t* ecx96;
    void** eax97;
    void** edx98;
    void** edx99;
    void** eax100;
    void** edx101;
    void** edx102;
    void** edx103;
    void** eax104;
    void** edx105;
    void** edx106;
    void** edx107;
    void** eax108;
    void** edx109;
    void** edx110;

    v14 = (void**)__return_address();
    asm("in al, dx");
    v15 = edi16;
    v17 = esi18;
    v19 = ebx20;
    esi21 = a9;
    eax22 = a10;
    edi23 = a11;
    if ((int8_t)eax22 <= (int8_t)2) {
        if (!eax22) {
            eax22 = (void**)1;
        }
        if ((int8_t)edi23 < (int8_t)0 || (!a12 || (int1_t)(eax22 == 1))) {
            edi23 = (void**)0;
        }
        edx24 = edi23;
        *(uint8_t*)(esi21 + 0x1f9) = *(uint8_t*)&edx24;
        *(int8_t*)(esi21 + 0x1f8) = *(int8_t*)&eax22;
        if (!((uint1_t)((int8_t)edi23 < (int8_t)0) | (uint1_t)(edi23 == 0))) 
            goto addr_0x403f1a_9;
    } else {
        fun_40850c(esi21, fun_403e80, v25, v26, v19, v17, v15, v14, a1, a2, a3, a4, a5, a6);
        goto addr_0x4047f8_11;
    }
    addr_0x404513_12:
    if (!*(void***)(esi21 + 0x208)) {
        eax29 = fun_402940(esi21, 10, v27, v28, v19, v17, v15, v14, a1, a2, a3, a4);
        *(void***)(esi21 + 0x208) = eax29;
        eax36 = fun_402940(esi21, 10, v30, 0x40452b, esi21, 10, v31, v32, v19, v17, v15, v14, esi21, 10, v33, 0x40452b, esi21, 10, v34, v35, v19, v17, v15, v14);
        *(void***)(esi21 + 0x20c) = eax36;
        *(void***)*(void***)(esi21 + 0x208) = (void**)8;
        *(void***)eax36 = (void**)8;
        edx37 = *(void***)(esi21 + 0x20c);
        *(uint8_t*)(*(void***)(esi21 + 0x208) + 2) = (uint8_t)8;
        *(uint8_t*)(edx37 + 2) = (uint8_t)8;
        edx38 = *(void***)(esi21 + 0x20c);
        *(void***)(*(void***)(esi21 + 0x208) + 4) = (void**)8;
        *(void***)(edx38 + 4) = (void**)8;
        edx39 = *(void***)(esi21 + 0x20c);
        *(uint8_t*)(*(void***)(esi21 + 0x208) + 6) = (uint8_t)8;
        *(uint8_t*)(edx39 + 6) = (uint8_t)8;
        edx40 = *(void***)(esi21 + 0x20c);
        eax22 = *(void***)(esi21 + 0x208);
        *(void***)(eax22 + 8) = (void**)8;
        *(void***)(edx40 + 8) = (void**)8;
    }
    asm("fldz");
    asm("fld qword [0x403eb0]");
    asm("fld qword [0x403ea8]");
    asm("fld1");
    if (!a13) {
        addr_0x4045e5_15:
        edx41 = *(void***)(esi21 + 0x20c);
        eax42 = *(void***)(esi21 + 0x208);
        *(void***)eax42 = (void**)8;
        *(void***)edx41 = (void**)8;
    } else {
        asm("fld qword [ecx]");
        asm("fcom st0, st4");
        asm("fnstsw ax");
        ah43 = (uint8_t)(*(uint8_t*)(&eax22 + 1) & 69);
        if (ah43 != 1) {
            asm("fcom st0, st1");
            asm("fnstsw ax");
            *(uint8_t*)(&eax42 + 1) = (uint8_t)(ah43 & 5);
            if (*(uint8_t*)(&eax42 + 1)) {
                asm("fstp st0");
            } else {
                asm("fld st3");
                asm("fdivrp st1, st0");
                asm("fadd st0, st2");
                edx44 = *(void***)(esi21 + 0x20c);
                asm("fnstcw word [esp+0x1e]");
                asm("fldcw word [esp+0x1c]");
                asm("fistp dword [esp+0x18]");
                eax45 = a3;
                asm("fldcw word [esp+0x1e]");
                *(void***)edx44 = eax45;
                asm("fld qword [edi]");
                asm("fmul st0, st3");
                asm("fadd st0, st2");
                edx46 = *(void***)(esi21 + 0x208);
                asm("fnstcw word [esp+0x1e]");
                asm("fldcw word [esp+0x1c]");
                asm("fistp dword [esp+0x18]");
                eax42 = a3;
                asm("fldcw word [esp+0x1e]");
                *(void***)edx46 = eax42;
            }
        } else {
            asm("fstp st0");
            goto addr_0x4045e5_15;
        }
    }
    ebx47 = 1;
    if (!0) {
        do {
            if (!a13) {
                addr_0x40469c_24:
                edx48 = *(void***)(esi21 + 0x20c);
                eax49 = *(void***)(esi21 + 0x208);
                *(void***)(eax49 + ebx47 * 2) = (void**)8;
                *(void***)(edx48 + ebx47 * 2) = (void**)8;
            } else {
                asm("fld qword [edi+ebx*8]");
                asm("fcom st0, st4");
                asm("fnstsw ax");
                ah50 = (uint8_t)(*(uint8_t*)(&eax42 + 1) & 69);
                if (ah50 != 1) {
                    asm("fcom st0, st1");
                    asm("fnstsw ax");
                    *(uint8_t*)(&eax49 + 1) = (uint8_t)(ah50 & 5);
                    if (*(uint8_t*)(&eax49 + 1)) {
                        asm("fstp st0");
                    } else {
                        asm("fld st3");
                        asm("fdivrp st1, st0");
                        asm("fadd st0, st2");
                        edx51 = *(void***)(esi21 + 0x20c);
                        asm("fnstcw word [esp+0x1e]");
                        asm("fldcw word [esp+0x1c]");
                        asm("fistp dword [esp+0x18]");
                        eax52 = a3;
                        asm("fldcw word [esp+0x1e]");
                        *(void***)(edx51 + ebx47 * 2) = eax52;
                        asm("fld qword [edi+ebx*8]");
                        asm("fmul st0, st3");
                        asm("fadd st0, st2");
                        edx53 = *(void***)(esi21 + 0x208);
                        asm("fnstcw word [esp+0x1e]");
                        asm("fldcw word [esp+0x1c]");
                        asm("fistp dword [esp+0x18]");
                        eax49 = a3;
                        asm("fldcw word [esp+0x1e]");
                        *(void***)(edx53 + ebx47 * 2) = eax49;
                    }
                } else {
                    asm("fstp st0");
                    goto addr_0x40469c_24;
                }
            }
            ecx54 = ebx47 + 1;
            if (!a13) {
                addr_0x40474f_31:
                edx55 = *(void***)(esi21 + 0x20c);
                eax42 = *(void***)(esi21 + 0x208);
                *(void***)(eax42 + ecx54 * 2) = (void**)8;
                *(void***)(edx55 + ecx54 * 2) = (void**)8;
            } else {
                asm("fld qword [edi+ecx*8]");
                asm("fcom st0, st4");
                asm("fnstsw ax");
                ah56 = (uint8_t)(*(uint8_t*)(&eax49 + 1) & 69);
                if (ah56 != 1) {
                    asm("fcom st0, st1");
                    asm("fnstsw ax");
                    *(uint8_t*)(&eax42 + 1) = (uint8_t)(ah56 & 5);
                    if (*(uint8_t*)(&eax42 + 1)) {
                        asm("fstp st0");
                    } else {
                        asm("fld st3");
                        asm("fdivrp st1, st0");
                        asm("fadd st0, st2");
                        edx57 = *(void***)(esi21 + 0x20c);
                        asm("fnstcw word [esp+0x1e]");
                        asm("fldcw word [esp+0x1c]");
                        asm("fistp dword [esp+0x18]");
                        eax58 = a3;
                        asm("fldcw word [esp+0x1e]");
                        *(void***)(edx57 + ecx54 * 2) = eax58;
                        asm("fld qword [eax+ecx*8]");
                        asm("fmul st0, st3");
                        asm("fadd st0, st2");
                        edx59 = *(void***)(esi21 + 0x208);
                        asm("fnstcw word [esp+0x1e]");
                        asm("fldcw word [esp+0x1c]");
                        asm("fistp dword [esp+0x18]");
                        eax42 = a3;
                        asm("fldcw word [esp+0x1e]");
                        *(void***)(edx59 + ecx54 * 2) = eax42;
                    }
                } else {
                    asm("fstp st0");
                    goto addr_0x40474f_31;
                }
            }
            ebx47 = ebx47 + 2;
        } while (ebx47 <= 4);
    }
    asm("fstp st0");
    asm("fstp st0");
    asm("fstp st0");
    asm("fstp st0");
    addr_0x4047f8_11:
    goto a8;
    addr_0x403f1a_9:
    if (*(void***)(esi21 + 0x1fc) || (eax22 = fun_402940(esi21, edi23, v60, v61, v19, v17, v15, v14, a1, a2, a3, a4), *(void***)(esi21 + 0x1fc) = eax22, ebx62 = (void**)0, (int8_t)0 >= (int8_t)edi23)) {
        addr_0x403f9e_39:
        if (*(void***)(esi21 + 0x200)) 
            goto addr_0x4040ac_40;
        ebx63 = (void**)((uint8_t)edi23 + (uint8_t)edi23);
        eax66 = fun_402940(esi21, ebx63, v64, v65, v19, v17, v15, v14, a1, a2, a3, a4);
        *(void***)(esi21 + 0x200) = eax66;
        eax22 = fun_402940(esi21, ebx63, v67, 0x403fb8, esi21, ebx63, v68, v69, v19, v17, v15, v14);
        *(void***)(esi21 + 0x204) = eax22;
        ebx70 = (void**)0;
        if ((int8_t)0 >= (int8_t)edi23) 
            goto addr_0x4040ac_40;
    } else {
        edx71 = (uint8_t)edi23 & 3;
        if (!edx71) {
            do {
                addr_0x403f6c_43:
                *(int8_t*)((uint8_t)ebx62 + (uint8_t)*(void***)(esi21 + 0x1fc)) = -1;
                *(int8_t*)((uint8_t)*(void***)(esi21 + 0x1fc) + (uint8_t)ebx62 + 1) = -1;
                *(int8_t*)((uint8_t)*(void***)(esi21 + 0x1fc) + (uint8_t)ebx62 + 2) = -1;
                eax22 = *(void***)(esi21 + 0x1fc);
                *(int8_t*)((uint8_t)eax22 + (uint8_t)ebx62 + 3) = -1;
                ebx62 = ebx62 + 4;
            } while ((int8_t)ebx62 < (int8_t)edi23);
            goto addr_0x403f9e_39;
        } else {
            if ((int32_t)edx71 > (int32_t)1) {
                if ((int32_t)edx71 > (int32_t)2) {
                    *(void***)eax22 = (void**)0xff;
                    ebx62 = (void**)1;
                }
                *(int8_t*)((uint8_t)ebx62 + (uint8_t)*(void***)(esi21 + 0x1fc)) = -1;
                ++ebx62;
            }
            eax22 = *(void***)(esi21 + 0x1fc);
            *(int8_t*)((uint8_t)ebx62 + (uint8_t)eax22) = -1;
            ++ebx62;
            if ((int8_t)ebx62 >= (int8_t)edi23) 
                goto addr_0x403f9e_39; else 
                goto addr_0x403f6b_49;
        }
    }
    eax72 = (uint8_t)edi23 & 3;
    if (!((uint1_t)((int8_t)edi23 < (int8_t)0) | (uint1_t)(edi23 == 0))) {
        if (!eax72) {
            do {
                addr_0x40403c_52:
                edx73 = *(void***)(esi21 + 0x204);
                *(void***)(*(void***)(esi21 + 0x200) + (uint8_t)ebx70 * 2) = (void**)0x100;
                *(void***)(edx73 + (uint8_t)ebx70 * 2) = (void**)0x100;
                edx74 = ebx70 + 1;
                ecx75 = *(void***)(esi21 + 0x204);
                *(void***)(*(void***)(esi21 + 0x200) + (uint8_t)edx74 * 2) = (void**)0x100;
                *(void***)(ecx75 + (uint8_t)edx74 * 2) = (void**)0x100;
                edx76 = (uint8_t*)(ebx70 + 2);
                ecx77 = *(void***)(esi21 + 0x204);
                *(void***)(*(void***)(esi21 + 0x200) + (uint32_t)edx76 * 2) = (void**)0x100;
                *(void***)(ecx77 + (uint32_t)edx76 * 2) = (void**)0x100;
                edx78 = (uint8_t*)(ebx70 + 3);
                ecx79 = *(void***)(esi21 + 0x204);
                eax22 = *(void***)(esi21 + 0x200);
                *(void***)(eax22 + (uint32_t)edx78 * 2) = (void**)0x100;
                *(void***)(ecx79 + (uint32_t)edx78 * 2) = (void**)0x100;
                ebx70 = ebx70 + 4;
            } while ((int8_t)ebx70 < (int8_t)edi23);
            goto addr_0x4040ac_40;
        } else {
            if ((int32_t)eax72 > (int32_t)1) {
                if ((int32_t)eax72 > (int32_t)2) {
                    *(void***)*(void***)(esi21 + 0x200) = (void**)0x100;
                    *(void***)eax22 = (void**)0x100;
                    ebx70 = (void**)1;
                }
                edx80 = *(void***)(esi21 + 0x204);
                *(void***)(*(void***)(esi21 + 0x200) + (uint8_t)ebx70 * 2) = (void**)0x100;
                *(void***)(edx80 + (uint8_t)ebx70 * 2) = (void**)0x100;
                ++ebx70;
            }
        }
    }
    edx81 = *(void***)(esi21 + 0x204);
    eax22 = *(void***)(esi21 + 0x200);
    *(void***)(eax22 + (uint8_t)ebx70 * 2) = (void**)0x100;
    *(void***)(edx81 + (uint8_t)ebx70 * 2) = (void**)0x100;
    ++ebx70;
    if ((int8_t)ebx70 >= (int8_t)edi23) {
        addr_0x4040ac_40:
        ebx82 = (void**)0;
        if ((int8_t)0 < (int8_t)edi23) {
            eax22 = (void**)((uint8_t)edi23 & 3);
            asm("fldz");
            asm("fld qword [0x403ea0]");
            asm("fld qword [0x403ea8]");
            if (!((uint1_t)((int8_t)edi23 < (int8_t)0) | (uint1_t)(edi23 == 0))) {
                if (!eax22) {
                    do {
                        addr_0x4042a8_60:
                        asm("fld qword [ebp+ebx*8+0x0]");
                        asm("fcom st0, st3");
                        asm("fnstsw ax");
                        if ((*(uint8_t*)(&eax22 + 1) & 69) != 1) {
                            asm("fmul st0, st2");
                            asm("fadd st0, st1");
                            edx83 = *(void***)(esi21 + 0x204);
                            asm("fnstcw word [esp+0x1e]");
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax84 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(edx83 + (uint8_t)ebx82 * 2) = eax84;
                            asm("fld st1");
                            asm("fdiv qword [ebp+ebx*8+0x0]");
                            asm("fadd st0, st1");
                            edx85 = *(void***)(esi21 + 0x200);
                            asm("fnstcw word [esp+0x1e]");
                            a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax86 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(edx85 + (uint8_t)ebx82 * 2) = eax86;
                        } else {
                            asm("fstp st0");
                            edx87 = *(void***)(esi21 + 0x204);
                            eax86 = *(void***)(esi21 + 0x200);
                            *(void***)(eax86 + (uint8_t)ebx82 * 2) = (void**)0x100;
                            *(void***)(edx87 + (uint8_t)ebx82 * 2) = (void**)0x100;
                        }
                        ecx88 = ebx82 + 1;
                        asm("fld qword [ebp+ecx*8+0x0]");
                        asm("fcom st0, st3");
                        asm("fnstsw ax");
                        if ((*(uint8_t*)(&eax86 + 1) & 69) != 1) {
                            asm("fmul st0, st2");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax89 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x204) + (uint8_t)ecx88 * 2) = eax89;
                            asm("fld st1");
                            asm("fdiv qword [ebp+ecx*8+0x0]");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax90 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x200) + (uint8_t)ecx88 * 2) = eax90;
                        } else {
                            asm("fstp st0");
                            edx91 = *(void***)(esi21 + 0x204);
                            eax90 = *(void***)(esi21 + 0x200);
                            *(void***)(eax90 + (uint8_t)ecx88 * 2) = (void**)0x100;
                            *(void***)(edx91 + (uint8_t)ecx88 * 2) = (void**)0x100;
                        }
                        ecx92 = (uint8_t*)(ebx82 + 2);
                        asm("fld qword [ebp+ecx*8+0x0]");
                        asm("fcom st0, st3");
                        asm("fnstsw ax");
                        if ((*(uint8_t*)(&eax90 + 1) & 69) != 1) {
                            asm("fmul st0, st2");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax93 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x204) + (uint32_t)ecx92 * 2) = eax93;
                            asm("fld st1");
                            asm("fdiv qword [ebp+ecx*8+0x0]");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax94 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x200) + (uint32_t)ecx92 * 2) = eax94;
                        } else {
                            asm("fstp st0");
                            edx95 = *(void***)(esi21 + 0x204);
                            eax94 = *(void***)(esi21 + 0x200);
                            *(void***)(eax94 + (uint32_t)ecx92 * 2) = (void**)0x100;
                            *(void***)(edx95 + (uint32_t)ecx92 * 2) = (void**)0x100;
                        }
                        ecx96 = (uint8_t*)(ebx82 + 3);
                        asm("fld qword [ebp+ecx*8+0x0]");
                        asm("fcom st0, st3");
                        asm("fnstsw ax");
                        if ((*(uint8_t*)(&eax94 + 1) & 69) != 1) {
                            asm("fmul st0, st2");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax97 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x204) + (uint32_t)ecx96 * 2) = eax97;
                            asm("fld st1");
                            asm("fdiv qword [ebp+ecx*8+0x0]");
                            asm("fadd st0, st1");
                            asm("fnstcw word [esp+0x1e]");
                            a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax22 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(*(void***)(esi21 + 0x200) + (uint32_t)ecx96 * 2) = eax22;
                        } else {
                            asm("fstp st0");
                            edx98 = *(void***)(esi21 + 0x204);
                            eax22 = *(void***)(esi21 + 0x200);
                            *(void***)(eax22 + (uint32_t)ecx96 * 2) = (void**)0x100;
                            *(void***)(edx98 + (uint32_t)ecx96 * 2) = (void**)0x100;
                        }
                        ebx82 = ebx82 + 4;
                    } while ((int8_t)ebx82 < (int8_t)edi23);
                    goto addr_0x40450d_73;
                } else {
                    if ((int8_t)eax22 > (int8_t)1) {
                        if ((int8_t)eax22 > (int8_t)2) {
                            asm("fld qword [ebp+0x0]");
                            asm("fcom st0, st3");
                            asm("fnstsw ax");
                            if ((*(uint8_t*)(&eax22 + 1) & 69) != 1) {
                                asm("fmul st0, st2");
                                asm("fadd st0, st1");
                                edx99 = *(void***)(esi21 + 0x204);
                                asm("fnstcw word [esp+0x1e]");
                                asm("fldcw word [esp+0x1c]");
                                asm("fistp dword [esp+0x18]");
                                eax100 = a3;
                                asm("fldcw word [esp+0x1e]");
                                *(void***)edx99 = eax100;
                                asm("fld st1");
                                asm("fdiv qword [ebp+0x0]");
                                asm("fadd st0, st1");
                                edx101 = *(void***)(esi21 + 0x200);
                                asm("fnstcw word [esp+0x1e]");
                                a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                                asm("fldcw word [esp+0x1c]");
                                asm("fistp dword [esp+0x18]");
                                eax22 = a3;
                                asm("fldcw word [esp+0x1e]");
                                *(void***)edx101 = eax22;
                            } else {
                                asm("fstp st0");
                                edx102 = *(void***)(esi21 + 0x204);
                                eax22 = *(void***)(esi21 + 0x200);
                                *(void***)eax22 = (void**)0x100;
                                *(void***)edx102 = (void**)0x100;
                            }
                            ebx82 = (void**)1;
                        }
                        asm("fld qword [ebp+ebx*8+0x0]");
                        asm("fcom st0, st3");
                        asm("fnstsw ax");
                        if ((*(uint8_t*)(&eax22 + 1) & 69) != 1) {
                            asm("fmul st0, st2");
                            asm("fadd st0, st1");
                            edx103 = *(void***)(esi21 + 0x204);
                            asm("fnstcw word [esp+0x1e]");
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax104 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(edx103 + (uint8_t)ebx82 * 2) = eax104;
                            asm("fld st1");
                            asm("fdiv qword [ebp+ebx*8+0x0]");
                            asm("fadd st0, st1");
                            edx105 = *(void***)(esi21 + 0x200);
                            asm("fnstcw word [esp+0x1e]");
                            a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                            asm("fldcw word [esp+0x1c]");
                            asm("fistp dword [esp+0x18]");
                            eax22 = a3;
                            asm("fldcw word [esp+0x1e]");
                            *(void***)(edx105 + (uint8_t)ebx82 * 2) = eax22;
                        } else {
                            asm("fstp st0");
                            edx106 = *(void***)(esi21 + 0x204);
                            eax22 = *(void***)(esi21 + 0x200);
                            *(void***)(eax22 + (uint8_t)ebx82 * 2) = (void**)0x100;
                            *(void***)(edx106 + (uint8_t)ebx82 * 2) = (void**)0x100;
                        }
                        ++ebx82;
                    }
                }
            }
            asm("fld qword [ebp+ebx*8+0x0]");
            asm("fcom st0, st3");
            asm("fnstsw ax");
            if ((*(uint8_t*)(&eax22 + 1) & 69) != 1) {
                asm("fmul st0, st2");
                asm("fadd st0, st1");
                edx107 = *(void***)(esi21 + 0x204);
                asm("fnstcw word [esp+0x1e]");
                asm("fldcw word [esp+0x1c]");
                asm("fistp dword [esp+0x18]");
                eax108 = a3;
                asm("fldcw word [esp+0x1e]");
                *(void***)(edx107 + (uint8_t)ebx82 * 2) = eax108;
                asm("fld st1");
                asm("fdiv qword [ebp+ebx*8+0x0]");
                asm("fadd st0, st1");
                edx109 = *(void***)(esi21 + 0x200);
                asm("fnstcw word [esp+0x1e]");
                a4 = (void**)(*(uint16_t*)(&a4 + 2) | 0xc00);
                asm("fldcw word [esp+0x1c]");
                asm("fistp dword [esp+0x18]");
                eax22 = a3;
                asm("fldcw word [esp+0x1e]");
                *(void***)(edx109 + (uint8_t)ebx82 * 2) = eax22;
            } else {
                asm("fstp st0");
                edx110 = *(void***)(esi21 + 0x204);
                eax22 = *(void***)(esi21 + 0x200);
                *(void***)(eax22 + (uint8_t)ebx82 * 2) = (void**)0x100;
                *(void***)(edx110 + (uint8_t)ebx82 * 2) = (void**)0x100;
            }
            ++ebx82;
            if ((int8_t)ebx82 >= (int8_t)edi23) {
                addr_0x40450d_73:
                asm("fstp st0");
                asm("fstp st0");
                asm("fstp st0");
                goto addr_0x404513_12;
            } else {
                goto addr_0x4042a8_60;
            }
        }
    } else {
        goto addr_0x40403c_52;
    }
    addr_0x403f6b_49:
    goto addr_0x403f6c_43;
}

void fun_403240(void* ecx);

void fun_404de4(void*** a1, void** a2, uint32_t a3);

void fun_404ef4(void** a1, void** a2, uint32_t a3, uint32_t a4) {
    void** v5;
    void** esi6;
    void** ebx7;
    void** v8;
    void** ebx9;
    void** edi10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;

    v5 = esi6;
    if (a3 <= 0x253 || a4 <= 0x11f) {
        *(void**)(a1 + 68) = (void*)0;
        ebx7 = (void**)((int32_t)__zero_stack_offset() - 4 + 0xffffffb0);
        if (a2) {
            fun_417450(ebx7, fun_403240, a2, v8, ebx9, v5, edi10, v11, v12, v13, v14);
            fun_40850c(a1, ebx7, v15, 0x404f34, ebx7, fun_403240, a2, v16, ebx9, v5, edi10, v17, v18, v19);
        }
        fun_417450(ebx7, 0x403280, 0x406a40, v20, ebx9, v5, edi10, v21, v22, v23, v24);
        fun_40850c(a1, ebx7, v25, 0x404f56, ebx7, 0x403280, 0x406a40, v26, ebx9, v5, edi10, v27, v28, v29);
    }
    if (a3 <= 0x253) {
        *(void***)(a1 + 64) = (void**)0;
        *(void***)(a1 + 0x6c) = (void**)0;
        fun_408404(a1, 0x403520, 0x406a40, v30, ebx9, v5);
    }
    if (a4 <= 0x11f) {
        *(void***)(a1 + 64) = (void**)0;
        *(void***)(a1 + 0x6c) = (void**)0;
        fun_408404(a1, 0x403580, 0x406a40, v31, ebx9, v5);
    }
    fun_404de4((int32_t)__zero_stack_offset() - 4 + 8, a2, a3);
    return;
}

void** fun_4075f0(void** a1, int32_t a2, uint32_t a3, int32_t a4, void** a5, void** a6, void** a7, void** a8) {
    void** v9;
    void** ebx10;
    void** v11;
    void** v12;
    void** ebx13;
    void** esi14;
    void** edi15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** eax20;
    void** esi21;
    void** v22;
    void** v23;
    void** edi24;
    int32_t ecx25;

    v9 = (void**)__return_address();
    ebx10 = (void**)(a2 * a3);
    eax20 = fun_402940(v9, ebx10, v11, v12, ebx13, esi14, edi15, v16, v17, v18, v19, v9);
    esi21 = eax20;
    if ((uint8_t)ebx10 <= (uint8_t)0x8000) {
        v22 = ebx10;
        v23 = esi21;
    } else {
        edi24 = esi21;
        ecx25 = 0x2000;
        while (ecx25) {
            --ecx25;
            *(void***)edi24 = (void**)0;
            edi24 = edi24 + 4;
            esi21 = esi21 + 4;
        }
        v22 = ebx10 + 0xffff8000;
        v23 = esi21 + 0x8000;
    }
    fun_417e00(v23, 0, v22);
    return esi21;
}

void fun_40737c(void*** a1, uint32_t a2, void** a3) {
    void** edi4;
    void** v5;
    void** eax6;
    int32_t ecx7;

    edi4 = *a1;
    if (a2 <= 0x11f) {
        fun_402a90(edi4, v5);
        eax6 = fun_402a74(2);
        edi4 = eax6;
        *a1 = edi4;
    }
    ecx7 = 72;
    while (ecx7) {
        --ecx7;
        *(void***)edi4 = (void**)0;
        edi4 = edi4 + 4;
    }
    return;
}

void fun_407590(void** a1, void** a2, void** a3) {
    void** ebx4;
    void** edi5;
    void** v6;
    void** v7;
    void** v8;
    void** v9;
    void** v10;
    void** v11;
    void** v12;
    void** v13;
    void** edi14;
    int32_t ecx15;

    fun_406c0c(a1, a2, 0x7fff, 0xff, ebx4, edi5, v6, v7);
    if (*(void****)(a1 + 0x220)) {
        v8 = *(void***)(a1 + 0x224);
        fun_4029a0(a1, v8, 0x7fff, 0xff, ebx4, edi5, v9, v10, v11, v12, v13, __return_address(), a1, a2, a3);
        *(void***)(a1 + 0x224) = (void**)0;
        *(void****)(a1 + 0x220) = (void***)0;
    }
    edi14 = a2;
    ecx15 = 72;
    while (ecx15) {
        --ecx15;
        *(void***)edi14 = (void**)0;
        edi14 = edi14 + 4;
    }
    return;
}

uint32_t fun_402770(uint32_t a1, void** a2, void** a3) {
    void** ecx4;
    void** esi5;
    uint32_t eax6;
    uint32_t edi7;
    uint32_t ebx8;
    uint32_t eax9;
    uint32_t ebx10;
    void** ecx11;
    uint32_t edx12;
    uint32_t ebx13;
    void** ecx14;
    uint32_t eax15;
    uint32_t ebx16;
    void** ecx17;
    uint32_t edx18;
    uint32_t ebx19;
    void** ecx20;
    uint32_t eax21;
    uint32_t ebx22;
    void** ecx23;
    uint32_t edx24;
    uint32_t ebx25;
    void** ecx26;
    uint32_t eax27;
    uint32_t ebx28;
    uint32_t ebx29;

    ecx4 = a2;
    if (ecx4) {
        esi5 = a3;
        eax6 = ~a1;
        if ((uint8_t)esi5 >= (uint8_t)8) {
            edi7 = (uint8_t)esi5 >> 3;
            do {
                ebx8 = 0;
                *(void***)&ebx8 = *(void***)ecx4;
                esi5 = esi5 - 8;
                eax9 = *(uint32_t*)((eax6 & 0xff ^ ebx8) * 4 + 0x41d1d8) ^ eax6 >> 8;
                ebx10 = 0;
                *(void***)&ebx10 = *(void***)(ecx4 + 1);
                ecx11 = ecx4 + 1;
                edx12 = *(uint32_t*)((eax9 & 0xff ^ ebx10) * 4 + 0x41d1d8) ^ eax9 >> 8;
                ebx13 = 0;
                *(void***)&ebx13 = *(void***)(ecx11 + 1);
                ecx14 = ecx11 + 1;
                eax15 = *(uint32_t*)((edx12 & 0xff ^ ebx13) * 4 + 0x41d1d8) ^ edx12 >> 8;
                ebx16 = 0;
                *(void***)&ebx16 = *(void***)(ecx14 + 1);
                ecx17 = ecx14 + 1;
                edx18 = *(uint32_t*)((eax15 & 0xff ^ ebx16) * 4 + 0x41d1d8) ^ eax15 >> 8;
                ebx19 = 0;
                *(void***)&ebx19 = *(void***)(ecx17 + 1);
                ecx20 = ecx17 + 1;
                eax21 = *(uint32_t*)((edx18 & 0xff ^ ebx19) * 4 + 0x41d1d8) ^ edx18 >> 8;
                ebx22 = 0;
                *(void***)&ebx22 = *(void***)(ecx20 + 1);
                ecx23 = ecx20 + 1;
                edx24 = *(uint32_t*)((eax21 & 0xff ^ ebx22) * 4 + 0x41d1d8) ^ eax21 >> 8;
                ebx25 = 0;
                *(void***)&ebx25 = *(void***)(ecx23 + 1);
                ecx26 = ecx23 + 1;
                eax27 = *(uint32_t*)((edx24 & 0xff ^ ebx25) * 4 + 0x41d1d8) ^ edx24 >> 8;
                ebx28 = 0;
                *(void***)&ebx28 = *(void***)(ecx26 + 1);
                eax6 = eax27 >> 8 ^ *(uint32_t*)((eax27 & 0xff ^ ebx28) * 4 + 0x41d1d8);
                ecx4 = ecx26 + 1 + 1;
                --edi7;
            } while (edi7);
        }
        if (esi5) {
            do {
                ebx29 = 0;
                *(void***)&ebx29 = *(void***)ecx4;
                eax6 = eax6 >> 8 ^ *(uint32_t*)((eax6 & 0xff ^ ebx29) * 4 + 0x41d1d8);
                ++ecx4;
                --esi5;
            } while (esi5);
        }
        return ~eax6;
    } else {
        return 0;
    }
}

// simplified version:
void load_constants(int8_t* a1, int8_t* a2, uint32_t a3) {
    int8_t* ecx4;
    int8_t* eax5;
    uint32_t edi6;
    uint32_t esi7;
    int8_t* edx8;
    uint32_t edx9;
    uint32_t edx10;

    ecx4 = a2;
    eax5 = a1;
    edi6 = a3;
    esi7 = edi6 >> 2;
    if (esi7) {
        edx8 = eax5 + esi7 * 4;
        do {
            ecx4 = ecx4 + 4;
            *eax5 = *ecx4;
            eax5 = eax5 + 4;
        } while ((uint32_t)eax5 < (uint32_t)edx8);
    }
    edx9 = edi6 - esi7 * 4 - 1;
    if (edx9) {
        edx10 = edx9 - 1;
        if (edx10) {
            if (edx10 - 1) {
                addr_0x407f7e_8:
                return;
            } else {
                *eax5 = *ecx4;
                ++eax5;
                ++ecx4;
            }
        }
        *eax5 = *ecx4;
        ++eax5;
        ++ecx4;
    }
    *eax5 = *ecx4;
    goto addr_0x407f7e_8;
}

void load_constants(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, void** a13, void** a14, void** a15, void** a16) {
    void** ecx17;
    void** eax18;
    void** edi19;
    uint32_t esi20;
    void** edx21;
    uint32_t edx22;
    uint32_t edx23;

    ecx17 = a2;
    eax18 = a1;
    edi19 = a3;
    esi20 = (uint8_t)edi19 >> 2;
    if (esi20) {
        edx21 = eax18 + esi20 * 4;
        do {
            ecx17 = ecx17 + 4;
            *(void***)eax18 = *(void***)ecx17;
            eax18 = eax18 + 4;
        } while ((uint8_t)eax18 < (uint8_t)edx21);
    }
    edx22 = (uint32_t)(edi19 - esi20 * 4) - 1;
    if (edx22) {
        edx23 = edx22 - 1;
        if (edx23) {
            if (edx23 - 1) {
                addr_0x407f7e_8:
                return;
            } else {
                *(void***)eax18 = *(void***)ecx17;
                ++eax18;
                ++ecx17;
            }
        }
        *(void***)eax18 = *(void***)ecx17;
        ++eax18;
        ++ecx17;
    }
    *(void***)eax18 = *(void***)ecx17;
    goto addr_0x407f7e_8;
}

struct s25 {
    uint8_t f0;
    int8_t f1;
};

void fun_407e50(void** a1, struct s3* a2, void** a3, void** a4, void** a5) {
    void** edi6;
    int32_t ebx7;
    struct s25* ebp8;
    uint8_t* edx9;
    uint32_t ecx10;
    void* eax11;
    uint8_t cl12;
    void* esi13;
    void* eax14;
    uint8_t cl15;
    uint32_t eax16;
    void* esi17;
    void* eax18;
    uint8_t cl19;
    uint32_t eax20;
    void* esi21;
    void* eax22;
    void* esi23;

    edi6 = a1;
    ebx7 = 0xff;
    ebp8 = (struct s25*)&a2->f510;
    edx9 = (uint8_t*)(edi6 + 0x30a1);
    do {
        *(uint8_t*)&ecx10 = *edx9;
        eax11 = (void*)0;
        *(uint8_t*)&eax11 = ebp8->f0;
        ecx10 = ecx10 & 0xff;
        if (ecx10 > 8) {
            if (!*(int8_t*)&eax11) {
                cl12 = (uint8_t)(*edx9 - 8);
                esi13 = (void*)(1 << cl12);
                eax14 = (void*)0;
                *edx9 = cl12;
                *(int8_t*)&eax14 = ebp8->f1;
                do {
                    *(int8_t*)((uint8_t)edi6 + (uint32_t)eax14 + 0x2ea2) = *(int8_t*)&ebx7;
                    eax14 = (void*)((uint32_t)eax14 + (int32_t)esi13);
                } while (*(uint16_t*)&eax14 < 0x100);
            } else {
                *(int8_t*)(((uint32_t)eax11 & 0xff) + (uint8_t)edi6 + 0x2c22) = -1;
                if (!(ebp8->f0 & 63)) {
                    cl15 = (uint8_t)(*edx9 - 6);
                    eax16 = 0;
                    *edx9 = cl15;
                    *(uint8_t*)&eax16 = ebp8->f0;
                    esi17 = (void*)(1 << cl15);
                    eax18 = (void*)(eax16 >> 6);
                    do {
                        *(int8_t*)((uint8_t)edi6 + (uint32_t)eax18 + 0x2e22) = *(int8_t*)&ebx7;
                        eax18 = (void*)((uint32_t)eax18 + (int32_t)esi17);
                    } while (*(uint16_t*)&eax18 < 0x80);
                } else {
                    cl19 = (uint8_t)(*edx9 - 4);
                    eax20 = 0;
                    *edx9 = cl19;
                    *(uint8_t*)&eax20 = ebp8->f0;
                    esi21 = (void*)(1 << cl19);
                    eax22 = (void*)(eax20 >> 4);
                    do {
                        *(int8_t*)((uint8_t)edi6 + (uint32_t)eax22 + 0x2d22) = *(int8_t*)&ebx7;
                        eax22 = (void*)((uint32_t)eax22 + (int32_t)esi21);
                    } while (*(uint16_t*)&eax22 < 0x100);
                }
            }
        } else {
            esi23 = (void*)(1 << *(uint8_t*)&ecx10);
            do {
                *(int8_t*)((uint8_t)edi6 + (uint32_t)eax11 + 0x2c22) = *(int8_t*)&ebx7;
                eax11 = (void*)((uint32_t)eax11 + (int32_t)esi23);
            } while (*(uint8_t*)&eax11 < (uint8_t)0x100);
        }
        --ebx7;
        --edx9;
        --ebp8;
    } while (*(int16_t*)&ebx7 >= 0);
    return;
}

/* dynamic_constant_loading? */
void dynamic_constant_loading_(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7) {
    void** ebx8;
    void** edi9;
    uint8_t* esi10;
    void* ebp11;
    uint32_t eax12;
    int32_t edx13;
    uint32_t ecx14;

    ebx8 = a1 + 0xffffffff;
    if (*(int16_t*)&ebx8 >= 0) {
        edi9 = a4;
        esi10 = (uint8_t*)(*(int16_t*)&ebx8 + (uint8_t)a2);
        ebp11 = (void*)((uint8_t)a3 - (uint8_t)a2);
        do {
            eax12 = 0;
            *(int8_t*)&eax12 = *(int8_t*)((uint32_t)esi10 + (uint32_t)ebp11);
            edx13 = 1 << *esi10;
            do {
                ecx14 = eax12;
                eax12 = eax12 + edx13;
                *(int8_t*)((ecx14 & 0xffff) + (uint8_t)edi9) = *(int8_t*)&ebx8;
            } while (*(uint16_t*)&eax12 < 0x100);
            --ebx8;
            --esi10;
        } while (*(int16_t*)&ebx8 >= 0);
    }
    return;
}

uint32_t translate_byte_v1(void** a1);

uint32_t fun_407cb0(void** a1, int16_t a2);

//alternative version by standalone decompiling

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

uint32_t byte_processing_loop1(void** a1, void** a2, void** a3, void** a4, void** a5) {
    void** v6;
    void** v7;
    void** ebx8;
    void** v9;
    void** ebp10;
    void** v11;
    void** esi12;
    void** esi13;
    void** v14;
    void** edi15;
    uint32_t eax16;
    uint32_t ebx17;
    void* ebx18;
    void** v19;
    void* v20;
    uint32_t eax21;
    void* ecx22;
    void** ebp23;
    int8_t* edi24;
    void* ecx25;
    int8_t* ecx26;
    void* eax27;
    int32_t ecx28;
    void** edi29;
    void** v30;
    void* ecx31;

    v6 = (void**)__return_address();
    v7 = ebx8;
    v9 = ebp10;
    v11 = esi12;
    esi13 = a1;
    v14 = edi15;
    *(void***)(esi13 + 4) = (void**)0x1000;
    eax16 = translate_byte_v1(esi13);
    *(void***)&ebx17 = *(void***)&eax16;
    ebx18 = (void*)(ebx17 & 0xffff);
    if ((uint8_t)*(void***)&ebx18 >= (uint8_t)0x305) {
        addr_0x407aab_2:
        *(void***)&eax16 = *(void***)(esi13 + 4) - 0x1000;
        v19 = *(void***)(esi13 + 18);
        *(void***)(esi13 + 26)(esi13 + 0x101e, eax16, v19);
        *(void***)&eax16 = *(void***)&ebx18;
        return eax16;
    } else {
        do {
            if ((uint8_t)*(void***)&ebx18 >= (uint8_t)0x100) {
                ebx18 = (void*)((uint32_t)ebx18 - 0xfe);
                v20 = ebx18;
                eax21 = fun_407cb0(esi13, *(int16_t*)&v20);
                eax16 = eax21 & 0xffff;
                if (!eax16) 
                    break;
                ecx22 = (void*)0;
                ebp23 = esi13 + 30;
                *(void***)&ecx22 = *(void***)(esi13 + 4);
                edi24 = (int8_t*)((int32_t)ecx22 + (uint8_t)ebp23);
                ecx25 = (void*)((int32_t)ecx22 + (uint32_t)ebx18);
                *(void***)(esi13 + 4) = *(void***)&ecx25;
                ecx26 = (int8_t*)((uint32_t)edi24 - eax16);
                do {
                    ebx18 = (void*)((uint32_t)ebx18 - 1);
                    *edi24 = *ecx26;
                    ++edi24;
                    ++ecx26;
                } while (ebx18);
            } else {
                eax27 = (void*)0;
                ebp23 = esi13 + 30;
                *(void***)&eax27 = *(void***)(esi13 + 4);
                ecx28 = (int32_t)eax27 + 1;
                *(void***)(esi13 + 4) = *(void***)&ecx28;
                *(int8_t*)((int32_t)eax27 + (uint8_t)ebp23) = *(int8_t*)&ebx18;
            }
            if ((uint8_t)*(void***)(esi13 + 4) >= (uint8_t)0x2000) {
                edi29 = esi13 + 0x101e;
                v30 = *(void***)(esi13 + 18);
                *(void***)(esi13 + 26)(edi29, 0x1000, v30);
                ecx31 = (void*)0;
                *(void***)&ecx31 = *(void***)(esi13 + 4);
                load_constants(ebp23, edi29, (int32_t)ecx31 - 0x1000, edi29, 0x1000, v30, v14, v11, v9, v7, v6, a1, a2, a3, a4, a5);
                *(void***)(esi13 + 4) = *(void***)(esi13 + 4) + 0xf000;
            }
            eax16 = translate_byte_v1(esi13);
            *(void***)&ebx18 = *(void***)&eax16;
            ebx18 = (void*)((uint32_t)ebx18 & 0xffff);
        } while ((uint8_t)*(void***)&ebx18 < (uint8_t)0x305);
        goto addr_0x407aa4_11;
    }
    ebx18 = (void*)0x306;
    goto addr_0x407aab_2;
    addr_0x407aa4_11:
    goto addr_0x407aab_2;
}

uint32_t fun_407d40(void** a1, uint32_t a2) {
    uint32_t ebx3;
    uint32_t eax4;
    void** edx5;
    void** edi6;
    uint32_t ecx7;
    void** ax8;
    uint32_t eax9;
    int32_t edx10;
    uint32_t eax11;
    uint32_t eax12;
    int16_t cx13;
    uint32_t eax14;

    ebx3 = a2;
    *(void***)&eax4 = *(void***)(a1 + 12);
    edx5 = *(void***)(a1 + 22);
    edi6 = *(void***)(a1 + 18);
    ecx7 = eax4 & 0xffff;
    if ((ebx3 & 0xffff) > ecx7) {
        ax8 = *(void***)(a1 + 14);
        *(uint8_t*)(a1 + 10) = (uint8_t)(*(uint8_t*)(a1 + 10) >> *(int8_t*)&ecx7);
        if (ax8 == *(void***)(a1 + 16)) {
            *(void***)(a1 + 14) = (void**)0x800;
            eax9 = (uint32_t)edx5(a1 + 0x2222, 0x800, edi6);
            *(void***)(a1 + 16) = *(void***)&eax9;
            if (*(void***)&eax9) {
                *(void***)(a1 + 14) = (void**)0;
            } else {
                *(void***)&eax9 = (void**)1;
                return eax9;
            }
        }
        *(void***)&eax9 = *(void***)(a1 + 14);
        edx10 = 0;
        *(int8_t*)((int32_t)&edx10 + 1) = *(int8_t*)((eax9 & 0xffff) + (uint8_t)a1 + 0x2222);
        *(uint8_t*)(a1 + 10) = (uint8_t)(*(uint8_t*)(a1 + 10) | *(uint16_t*)&edx10);
        eax11 = eax9 + 1;
        *(void***)(a1 + 14) = *(void***)&eax11;
        *(void***)&eax11 = *(void***)(a1 + 12);
        *(uint8_t*)(a1 + 10) = (uint8_t)(*(uint8_t*)(a1 + 10) >> (int8_t)(*(int8_t*)&ebx3 - *(int8_t*)&eax11));
        eax12 = eax11 - ebx3 + 8;
        *(void***)(a1 + 12) = *(void***)&eax12;
        *(void***)&eax12 = (void**)0;
        return eax12;
    } else {
        cx13 = *(int16_t*)&ebx3;
        eax14 = eax4 - ebx3;
        *(uint8_t*)(a1 + 10) = (uint8_t)(*(uint8_t*)(a1 + 10) >> *(int8_t*)&cx13);
        *(void***)(a1 + 12) = *(void***)&eax14;
        *(void***)&eax14 = (void**)0;
        return eax14;
    }
}

void fun_418080();

void fun_408368(void* ecx);

void** fun_408578(void** a1, void** a2) {
    int32_t v3;
    int32_t esi4;
    void*** esp5;
    void** v6;
    void** ebx7;
    void** ecx8;
    void** v9;
    int32_t* esp10;
    int32_t v11;
    void* edx12;
    void** ebx13;
    void** esi14;
    struct s0* eax15;
    void* v16;
    void*** esp17;
    void** v18;
    void** ecx19;
    void** v20;
    int32_t v21;
    void* edx22;
    void* ebx23;
    struct s0* eax24;
    void* v25;
    int32_t v26;
    int32_t v27;
    void** eax28;
    void** eax29;

    v3 = esi4;
    esp5 = (void***)((int32_t)__zero_stack_offset() - 36 - 4 - 4);
    v6 = ebx7;
    ecx8 = a2;
    if (!(int1_t)(*(void***)ecx8 == 35)) {
        v9 = ecx8;
        esp10 = (int32_t*)(esp5 - 4 - 4 - 4);
        v11 = (int32_t)"libpng error: %s\n";
    } else {
        edx12 = (void*)0;
        ebx13 = (void**)(esp5 + 16);
        esi14 = ebx13;
        do {
            edx12 = (void*)((uint32_t)edx12 + 1);
            if ((int32_t)edx12 > (int32_t)14) 
                break;
            *(int8_t*)((uint32_t)edx12 + (uint8_t)esi14) = *(int8_t*)((uint32_t)edx12 + (uint8_t)ecx8 + 1);
        } while (*(int8_t*)((uint32_t)edx12 + (uint8_t)ecx8) != 32);
        if ((uint32_t)edx12 + 0xfffffffe > 12) 
            goto addr_0x4085c4_7; else 
            goto addr_0x4085b3_8;
    }
    addr_0x4085d9_9:
    eax15 = g41ebe4;
    fun_4180f9((uint32_t)eax15 + 64, v11, v9, v16, v6, v3);
    fun_418080();
    esp17 = (void***)(esp10 - 1 - 1 + 1 + 4 - 2 - 1 - 1 - 1 + 1 - 10 - 1);
    v18 = ebx13;
    ecx19 = v9;
    if (!(int1_t)(*(void***)ecx19 == 35)) {
        addr_0x408644_11:
        v20 = ecx19;
        v21 = (int32_t)"libpng warning: %s\n";
    } else {
        edx22 = (void*)0;
        ebx23 = (void*)(esp17 + 16);
        do {
            edx22 = (void*)((uint32_t)edx22 + 1);
            if ((int32_t)edx22 > (int32_t)14) 
                break;
            *(int8_t*)((uint32_t)edx22 + (uint32_t)ebx23) = *(int8_t*)((uint32_t)edx22 + (uint8_t)ecx19 + 1);
        } while (*(int8_t*)((uint32_t)edx22 + (uint8_t)ecx19) != 32);
        if ((uint32_t)edx22 + 0xfffffffe > 12) 
            goto addr_0x408644_11; else 
            goto addr_0x40862f_16;
    }
    addr_0x40864d_17:
    eax24 = g41ebe4;
    eax28 = fun_4180f9((uint32_t)eax24 + 64, v21, v20, v25, v18, v26, (uint32_t)eax24 + 64, v21, v20, v25, v18, v27);
    return eax28;
    addr_0x40862f_16:
    eax29 = (void**)(esp17 + 16);
    *(int8_t*)((uint8_t)eax29 + (uint32_t)edx22 + 0xffffffff) = 0;
    v25 = (void*)((uint32_t)edx22 + (uint8_t)ecx19);
    v20 = eax29;
    v21 = (int32_t)"libpng warning no. %s: %s\n";
    goto addr_0x40864d_17;
    addr_0x4085c4_7:
    v16 = edx12;
    v9 = ecx8;
    esp10 = (int32_t*)(esp5 - 4 - 4 - 4);
    v11 = (int32_t)"libpng error: %s, offset=%d\n";
    goto addr_0x4085d9_9;
    addr_0x4085b3_8:
    *(int8_t*)((uint8_t)ebx13 + (uint32_t)edx12 + 0xffffffff) = 0;
    v16 = (void*)((uint32_t)edx12 + (uint8_t)ecx8);
    v9 = ebx13;
    esp10 = (int32_t*)(esp5 - 4 - 4 - 4);
    v11 = (int32_t)fun_408368;
    goto addr_0x4085d9_9;
}

struct s28 {
    int8_t[8] pad8;
    void** f8;
    int8_t[7] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    int32_t f24;
};

struct s27 {
    int8_t* f0;
    void* f4;
    uint32_t f8;
    void*** f12;
    void** f16;
    int8_t[3] pad20;
    uint32_t f20;
    int8_t[4] pad28;
    struct s28* f28;
    int8_t[16] pad48;
    int32_t f48;
};

struct s26 {
    struct s27* f0;
    int8_t[8] pad12;
    void* f12;
    int8_t[20] pad36;
    void* f36;
    int8_t[4] pad44;
    uint32_t f44;
    int8_t* f48;
    void* f52;
    void*** f56;
    void** f60;
    int8_t[3] pad64;
    void** f64;
    int8_t[3] pad68;
    int32_t f68;
    int8_t[4] pad76;
    uint32_t f76;
    int32_t f80;
    void** f84;
    int8_t[3] pad88;
    void* f88;
    uint16_t f92;
    int8_t[2] pad96;
    int32_t f96;
    void** f100;
    int8_t[3] pad104;
    uint16_t f104;
    int8_t[2] pad108;
    void** f108;
    int8_t[3] pad112;
    void* f112;
    int8_t[4] pad120;
    void* f120;
    int8_t[4] pad128;
    void* f128;
    int8_t[5644] pad5776;
    void* f5776;
    int32_t f5780;
    int32_t f5784;
    uint16_t* f5788;
};

void fun_409ee0(void** ecx, struct s26* a2);

void fun_415d10(struct s26* a1, void* a2, void** a3, int32_t a4);

uint32_t fun_409c70(void** ecx, struct s26* a2, int32_t a3) {
    struct s26* ebx4;
    void* eax5;
    void* eax6;
    void* v7;
    void** eax8;
    void** ecx9;
    void** ecx10;
    void** edx11;
    void** eax12;
    void* edx13;
    struct s27* eax14;
    void** edx15;
    void** esi16;
    void*** edi17;
    void** ebp18;
    uint32_t ecx19;
    uint32_t ecx20;
    struct s28* ecx21;
    void** edi22;
    struct s28* ecx23;
    void* eax24;
    struct s27* eax25;
    void** edx26;
    void** esi27;
    void*** edi28;
    void** ebp29;
    uint32_t ecx30;
    uint32_t ecx31;
    struct s28* ecx32;
    void** edi33;
    struct s28* ecx34;
    int32_t edi35;
    void* eax36;
    int32_t ecx37;
    void** edx38;
    struct s27* eax39;
    void** edx40;
    int32_t eax41;
    int32_t eax42;
    void** esi43;
    void*** edi44;
    void** ebp45;
    uint32_t ecx46;
    uint32_t ecx47;
    struct s28* ecx48;
    uint32_t ebp49;
    struct s28* ecx50;

    ebx4 = a2;
    eax5 = ebx4->f12;
    eax6 = (void*)((int32_t)eax5 + 0xfffffffb);
    v7 = (void*)0xffff;
    if ((uint32_t)eax6 < 0xffff) {
        v7 = eax6;
    }
    while ((eax8 = ebx4->f108, (uint8_t)eax8 > (uint8_t)1) || (fun_409ee0(ecx, ebx4), eax8 = ebx4->f108, !!eax8)) {
        ecx9 = (void**)((uint8_t)ebx4->f100 + (uint8_t)eax8);
        ebx4->f100 = ecx9;
        ecx10 = ebx4->f84;
        edx11 = ebx4->f100;
        ebx4->f108 = (void**)0;
        eax12 = (void**)((uint8_t)ecx10 + (uint32_t)v7);
        if (!ecx9 || (uint8_t)edx11 >= (uint8_t)eax12) {
            ebx4->f108 = (void**)((uint8_t)edx11 - (uint8_t)eax12);
            ebx4->f100 = eax12;
            if ((int8_t)ecx10 < (int8_t)0) {
                edx13 = (void*)0;
            } else {
                edx13 = (void*)((uint32_t)ebx4->f48 + (uint8_t)ecx10);
            }
            fun_415d10(ebx4, edx13, (uint8_t)eax12 - (uint8_t)ecx10, 0);
            eax14 = ebx4->f0;
            ebx4->f84 = ebx4->f100;
            edx15 = eax14->f28->f20;
            if ((uint8_t)edx15 > (uint8_t)eax14->f16) {
                edx15 = eax14->f16;
            }
            if (edx15) 
                goto addr_0x409d13_11;
        } else {
            addr_0x409d6a_12:
            ecx = (void**)((uint8_t)ebx4->f100 - (uint8_t)ebx4->f84);
            if ((uint8_t)ecx < (uint8_t)((uint32_t)ebx4->f36 - 0x106)) 
                continue; else 
                goto addr_0x409d82_13;
        }
        addr_0x409d5d_14:
        if (!ebx4->f0->f16) 
            goto addr_0x409e0e_15; else 
            goto addr_0x409d6a_12;
        addr_0x409d13_11:
        esi16 = eax14->f28->f16;
        edi17 = eax14->f12;
        ebp18 = edx15;
        ecx19 = (uint8_t)edx15 >> 2;
        while (ecx19) {
            --ecx19;
            *edi17 = *(void***)esi16;
            edi17 = edi17 + 4;
            esi16 = esi16 + 4;
        }
        ecx20 = (uint8_t)ebp18 & 3;
        while (ecx20) {
            --ecx20;
            *edi17 = *(void***)esi16;
            ++edi17;
            ++esi16;
        }
        ecx21 = eax14->f28;
        eax14->f12 = (void***)((uint32_t)eax14->f12 + (uint8_t)edx15);
        ecx21->f16 = (void**)((uint8_t)ecx21->f16 + (uint8_t)edx15);
        edi22 = eax14->f16;
        ecx23 = eax14->f28;
        eax14->f20 = eax14->f20 + (uint8_t)edx15;
        eax14->f16 = (void**)((uint8_t)edi22 - (uint8_t)edx15);
        ecx23->f20 = (void**)((uint8_t)ecx23->f20 - (uint8_t)edx15);
        if (eax14->f28->f20) 
            goto addr_0x409d5d_14;
        eax14->f28->f16 = eax14->f28->f8;
        goto addr_0x409d5d_14;
        addr_0x409d82_13:
        if ((int8_t)ebx4->f84 < (int8_t)0) {
            eax24 = (void*)0;
        } else {
            eax24 = (void*)((uint32_t)ebx4->f48 + (uint8_t)ebx4->f84);
        }
        fun_415d10(ebx4, eax24, ecx, 0);
        eax25 = ebx4->f0;
        ebx4->f84 = ebx4->f100;
        edx26 = eax25->f28->f20;
        if ((uint8_t)edx26 > (uint8_t)eax25->f16) {
            edx26 = eax25->f16;
        }
        if (!edx26) {
            addr_0x409e01_28:
            ecx = ebx4->f0->f16;
            if (ecx) 
                continue; else 
                goto addr_0x409e0e_15;
        } else {
            esi27 = eax25->f28->f16;
            edi28 = eax25->f12;
            ebp29 = edx26;
            ecx30 = (uint8_t)edx26 >> 2;
            while (ecx30) {
                --ecx30;
                *edi28 = *(void***)esi27;
                edi28 = edi28 + 4;
                esi27 = esi27 + 4;
            }
            ecx31 = (uint8_t)ebp29 & 3;
            while (ecx31) {
                --ecx31;
                *edi28 = *(void***)esi27;
                ++edi28;
                ++esi27;
            }
            ecx32 = eax25->f28;
            eax25->f12 = (void***)((uint32_t)eax25->f12 + (uint8_t)edx26);
            ecx32->f16 = (void**)((uint8_t)ecx32->f16 + (uint8_t)edx26);
            edi33 = eax25->f16;
            ecx34 = eax25->f28;
            eax25->f20 = eax25->f20 + (uint8_t)edx26;
            eax25->f16 = (void**)((uint8_t)edi33 - (uint8_t)edx26);
            ecx34->f20 = (void**)((uint8_t)ecx34->f20 - (uint8_t)edx26);
            if (eax25->f28->f20) 
                goto addr_0x409e01_28;
        }
        eax25->f28->f16 = eax25->f28->f8;
        goto addr_0x409e01_28;
    }
    edi35 = a3;
    if (!edi35) {
        addr_0x409e0e_15:
        return 0;
    } else {
        if ((int8_t)ebx4->f84 < (int8_t)0) {
            eax36 = (void*)0;
        } else {
            eax36 = (void*)((uint32_t)ebx4->f48 + (uint8_t)ebx4->f84);
        }
        ecx37 = 0;
        *(uint8_t*)&ecx37 = static_cast<uint8_t>((uint1_t)(edi35 == 4));
        edx38 = (void**)((uint8_t)ebx4->f100 - (uint8_t)ebx4->f84);
        fun_415d10(ebx4, eax36, edx38, ecx37);
        ebx4->f84 = ebx4->f100;
        eax39 = ebx4->f0;
        edx40 = eax39->f28->f20;
        if ((uint8_t)edx40 > (uint8_t)eax39->f16) {
            edx40 = eax39->f16;
        }
        if (edx40) 
            goto addr_0x409e62_44;
    }
    addr_0x409eb0_45:
    if (ebx4->f0->f16) {
        eax41 = 0;
        *(uint8_t*)&eax41 = static_cast<uint8_t>((uint1_t)(edi35 == 4));
        return eax41 + eax41 + 1;
    } else {
        eax42 = 0;
        *(uint8_t*)&eax42 = static_cast<uint8_t>((uint1_t)(edi35 != 4));
        return (uint32_t)(eax42 - 1) & 2;
    }
    addr_0x409e62_44:
    esi43 = eax39->f28->f16;
    edi44 = eax39->f12;
    ebp45 = edx40;
    ecx46 = (uint8_t)edx40 >> 2;
    while (ecx46) {
        --ecx46;
        *edi44 = *(void***)esi43;
        edi44 = edi44 + 4;
        esi43 = esi43 + 4;
    }
    ecx47 = (uint8_t)ebp45 & 3;
    while (ecx47) {
        --ecx47;
        *edi44 = *(void***)esi43;
        ++edi44;
        ++esi43;
    }
    ecx48 = eax39->f28;
    eax39->f12 = (void***)((uint32_t)eax39->f12 + (uint8_t)edx40);
    ecx48->f16 = (void**)((uint8_t)ecx48->f16 + (uint8_t)edx40);
    ebp49 = eax39->f20;
    ecx50 = eax39->f28;
    eax39->f16 = (void**)((uint8_t)eax39->f16 - (uint8_t)edx40);
    edi35 = a3;
    eax39->f20 = ebp49 + (uint8_t)edx40;
    ecx50->f20 = (void**)((uint8_t)ecx50->f20 - (uint8_t)edx40);
    if (eax39->f28->f20) 
        goto addr_0x409eb0_45;
    eax39->f28->f16 = eax39->f28->f8;
    goto addr_0x409eb0_45;
}

int32_t fun_417280(int32_t a1, int8_t* a2, void* a3);

struct s29 {
    int8_t f0;
    int8_t f1;
};

void fun_409ee0(void** ecx, struct s26* a2) {
    struct s26* ebx3;
    void* edx4;
    void* v5;
    void** eax6;
    void** esi7;
    void* ecx8;
    void* v9;
    struct s27* ebp10;
    int8_t* edi11;
    void* eax12;
    uint32_t ecx13;
    int8_t* esi14;
    uint32_t ecx15;
    void** eax16;
    uint16_t esi17;
    void** ecx18;
    int32_t esi19;
    void*** ecx20;
    void* eax21;
    void* eax22;
    void* esi23;
    void*** ecx24;
    void* eax25;
    void* eax26;
    void* v27;
    int8_t* edi28;
    void* eax29;
    void* esi30;
    void* v31;
    struct s28* ecx32;
    int8_t* edx33;
    int32_t eax34;
    int32_t eax35;
    int8_t* esi36;
    void* eax37;
    uint32_t ecx38;
    void* eax39;
    uint32_t ecx40;
    uint32_t ecx41;
    void** ecx42;
    struct s29* edi43;
    void** ecx44;
    uint32_t eax45;
    int32_t ecx46;

    ebx3 = a2;
    edx4 = ebx3->f36;
    v5 = edx4;
    do {
        eax6 = ebx3->f100;
        esi7 = ebx3->f108;
        ecx8 = (void*)((int32_t)ebx3->f52 - (uint8_t)eax6 - (uint8_t)esi7);
        v9 = ecx8;
        if (ecx8) {
            if (!(int1_t)(ecx8 == 0xffffffff)) {
                addr_0x409f26_4:
                if ((uint8_t)eax6 < (uint8_t)((uint32_t)edx4 + (uint32_t)ebx3->f36 + 0xfffffefa)) {
                    addr_0x409fb0_5:
                    ebp10 = ebx3->f0;
                    if (!ebp10->f4) 
                        break;
                } else {
                    edi11 = ebx3->f48;
                    eax12 = edx4;
                    ecx13 = (uint32_t)edx4 >> 2;
                    esi14 = (int8_t*)((uint32_t)edi11 + (uint32_t)edx4);
                    while (ecx13) {
                        --ecx13;
                        *edi11 = *esi14;
                        edi11 = edi11 + 4;
                        esi14 = esi14 + 4;
                    }
                    ecx15 = (uint32_t)eax12 & 3;
                    while (ecx15) {
                        --ecx15;
                        *edi11 = *esi14;
                        ++edi11;
                        ++esi14;
                    }
                    eax16 = ebx3->f84;
                    esi17 = (uint16_t)(ebx3->f104 - (uint32_t)edx4);
                    ebx3->f100 = (void**)((uint8_t)ebx3->f100 - (uint32_t)edx4);
                    ecx18 = ebx3->f60;
                    ebx3->f104 = esi17;
                    esi19 = ebx3->f68;
                    ebx3->f84 = (void**)((uint8_t)eax16 - (uint32_t)edx4);
                    ecx20 = (void***)(ecx18 + esi19 * 2);
                    do {
                        ecx20 = ecx20 - 2;
                        eax21 = (void*)0;
                        *(void***)&eax21 = *ecx20;
                        if ((uint32_t)eax21 < (uint32_t)edx4) {
                            eax22 = (void*)0;
                        } else {
                            eax22 = (void*)((uint32_t)eax21 - (uint32_t)edx4);
                        }
                        --esi19;
                        *ecx20 = *(void***)&eax22;
                    } while (esi19);
                    esi23 = edx4;
                    ecx24 = ebx3->f56 + (uint32_t)edx4 * 2;
                    do {
                        ecx24 = ecx24 - 2;
                        eax25 = (void*)0;
                        *(void***)&eax25 = *ecx24;
                        if ((uint32_t)eax25 < (uint32_t)edx4) {
                            eax26 = (void*)0;
                        } else {
                            eax26 = (void*)((uint32_t)eax25 - (uint32_t)edx4);
                        }
                        esi23 = (void*)((uint32_t)esi23 - 1);
                        *ecx24 = *(void***)&eax26;
                    } while (esi23);
                    v27 = (void*)((uint32_t)v9 + (uint32_t)edx4);
                    goto addr_0x409fac_23;
                }
            } else {
                v27 = (void*)0xfffffffe;
                goto addr_0x409fac_23;
            }
        } else {
            if (eax6) 
                goto addr_0x409f26_4;
            if (esi7) 
                goto addr_0x409f26_4;
            v27 = edx4;
            goto addr_0x409fac_23;
        }
        edi28 = (int8_t*)((uint8_t)ebx3->f108 + (uint8_t)ebx3->f100 + (uint32_t)ebx3->f48);
        eax29 = ebp10->f4;
        esi30 = eax29;
        v31 = esi30;
        if ((uint32_t)esi30 > (uint32_t)ecx8) {
            v31 = ecx8;
            esi30 = ecx8;
        }
        if (esi30) {
            ecx32 = ebp10->f28;
            ebp10->f4 = (void*)((uint32_t)eax29 - (uint32_t)esi30);
            if (!ecx32->f24) {
                edx33 = ebp10->f0;
                eax34 = ebp10->f48;
                eax35 = fun_417280(eax34, edx33, esi30);
                edx4 = v5;
                ebp10->f48 = eax35;
            }
            esi36 = ebp10->f0;
            eax37 = esi30;
            ecx38 = (uint32_t)esi30 >> 2;
            while (ecx38) {
                --ecx38;
                *edi28 = *esi36;
                edi28 = edi28 + 4;
                esi36 = esi36 + 4;
            }
            eax39 = v31;
            ecx40 = (uint32_t)eax37 & 3;
            while (ecx40) {
                --ecx40;
                *edi28 = *esi36;
                ++edi28;
                ++esi36;
            }
            ecx41 = ebp10->f8 + (uint32_t)eax39;
            ebp10->f0 = (int8_t*)((uint32_t)ebp10->f0 + (uint32_t)eax39);
            ebp10->f8 = ecx41;
        } else {
            eax39 = (void*)0;
        }
        ecx42 = (void**)((uint8_t)ebx3->f108 + (uint32_t)eax39);
        ebx3->f108 = ecx42;
        if ((uint8_t)ecx42 >= (uint8_t)3) {
            edi43 = (struct s29*)((uint8_t)ebx3->f100 + (uint32_t)ebx3->f48);
            ecx44 = (void**)0;
            *(int8_t*)&ecx44 = edi43->f0;
            eax45 = 0;
            ecx46 = ebx3->f80;
            ebx3->f64 = ecx44;
            *(int8_t*)&eax45 = edi43->f1;
            ebx3->f64 = (void**)(((uint8_t)ecx44 << *(uint8_t*)&ecx46 ^ eax45) & ebx3->f76);
            continue;
        }
        addr_0x409fac_23:
        ecx8 = v27;
        goto addr_0x409fb0_5;
    } while ((uint8_t)ecx42 < (uint8_t)0x106 && ebx3->f0->f4);
    return;
}

void fun_407694(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, ...) {
    uint32_t eax13;
    uint32_t eax14;
    uint32_t v15;
    uint32_t eax16;

    eax13 = 1;
    if (!(*(uint8_t*)(a1 + 0x11c) & 32)) {
        if (*(uint8_t*)(a1 + 0x6d) & 8) {
            eax13 = 0;
        }
    } else {
        eax14 = (uint8_t)*(void***)(a1 + 0x6c) & 0x300;
        *(uint8_t*)&eax14 = static_cast<uint8_t>((uint1_t)(eax14 != 0x300));
        eax13 = eax14 & 0xff;
    }
    if (eax13) {
        v15 = *(uint32_t*)(a1 + 0x110);
        eax16 = fun_402770(v15, a1, a2);
        *(uint32_t*)(a1 + 0x110) = eax16;
    }
    return;
}

struct s30 {
    int8_t[110] pad110;
    uint8_t f110;
};

void fun_40a9d0(struct s30* ecx);

void** fun_40aaf8(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, ...) {
    void** eax13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** eax18;

    eax13 = *(void***)(a1 + 76);
    if (!eax13) {
        eax18 = fun_408404(a1, fun_40a9d0, v14, v15, v16, v17);
    } else {
        eax18 = (void**)eax13(a1, a1, a2);
    }
    return eax18;
}

void fun_410b88(void** a1, void** a2, void** a3, ...) {
    void** edx4;
    uint32_t eax5;
    void** v6;
    uint32_t eax7;
    uint32_t eax8;
    void** v9;
    void** ebx10;
    void** esi11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;

    edx4 = a3;
    eax5 = (uint8_t)edx4 >> 24;
    *(int8_t*)&v6 = *(int8_t*)&eax5;
    eax7 = (uint8_t)edx4 >> 16;
    *(int8_t*)(&v6 + 1) = *(int8_t*)&eax7;
    eax8 = (uint8_t)edx4 >> 8;
    *(int8_t*)(&v6 + 2) = *(int8_t*)&eax8;
    *(int8_t*)(&v6 + 3) = *(int8_t*)&edx4;
    fun_40aaf8(a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, v9, ebx10, esi11, v12, v13, v14, v15, v16, v6);
    fun_40aaf8(a1, a2, 4, 0x410bc5, a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, v17, ebx10, esi11, v18, v19);
    fun_407670(a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, v20, ebx10, esi11, v21, v22);
    fun_407694(a1, a2, 4, 0x410bdd, a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, v23, ebx10, esi11, v24, v25);
    return;
}

void** fun_410bf4(void** a1, void** a2, void** a3, int32_t a4, void** a5, void** a6, void** a7, ...) {
    void** v8;
    void** ebx9;
    void** esi10;
    void** edi11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** eax18;

    if (a2 && a3) {
        fun_407694(a1, a2, a3, v8, ebx9, esi10, edi11, v12, v13, v14, v15, __return_address());
        eax18 = fun_40aaf8(a1, a2, a3, 0x410c19, a1, a2, a3, v16, ebx9, esi10, edi11, v17);
    }
    return eax18;
}

void** fun_410c30(void** a1, void** a2, void** a3, ...) {
    uint32_t edx4;
    uint32_t eax5;
    void** v6;
    uint32_t eax7;
    uint32_t eax8;
    void** v9;
    void** ebx10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** eax17;

    edx4 = *(uint32_t*)(a1 + 0x110);
    eax5 = edx4 >> 24;
    *(int8_t*)&v6 = *(int8_t*)&eax5;
    eax7 = edx4 >> 16;
    *(int8_t*)(&v6 + 1) = *(int8_t*)&eax7;
    eax8 = edx4 >> 8;
    *(int8_t*)(&v6 + 2) = *(int8_t*)&eax8;
    *(int8_t*)(&v6 + 3) = *(int8_t*)&edx4;
    eax17 = fun_40aaf8(a1, (int32_t)__zero_stack_offset() - 40 - 4 + 28, 4, v9, ebx10, v11, v12, v13, v14, v15, v16, v6);
    return eax17;
}

void** fun_40abd8(void** a1, void** a2, void** a3, void** a4, struct s4* a5, void** a6, void** a7, int32_t a8, void** a9, void** a10, void** a11) {
    void** v12;
    void** ebp13;
    void** v14;
    void** edi15;
    void** v16;
    void** esi17;
    void** v18;
    void** ebx19;
    void** edi20;
    struct s4* ebp21;
    void** v22;
    void** ebx23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** esi33;
    void** eax34;
    void** v35;
    void** v36;
    uint32_t edi37;
    void** v38;
    void** v39;
    void** v40;
    void** v41;
    void** v42;
    void** eax43;
    uint32_t edx44;
    void** eax45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    uint32_t eax50;
    void** ebx51;
    void** v52;
    void** v53;
    void** v54;
    void** v55;
    void** eax56;
    void** v57;
    void** v58;
    void** v59;
    void** v60;
    void** eax61;
    void** v62;
    void** v63;
    void** v64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** eax70;
    void** v71;
    uint32_t edi72;
    uint32_t eax73;
    void** ebx74;
    void** v75;
    void** v76;
    void** v77;
    void** eax78;
    void** v79;
    void** v80;
    void** v81;
    void** eax82;
    void** v83;
    void** v84;
    void** v85;
    void** v86;
    void** v87;
    void** v88;
    void** v89;
    void** v90;
    void** v91;
    void** v92;
    void** v93;
    void** eax94;
    uint32_t edx95;
    void** eax96;
    void** v97;
    void** v98;
    void** v99;
    void** v100;
    void** v101;
    void** v102;

    v12 = ebp13;
    v14 = edi15;
    v16 = esi17;
    v18 = ebx19;
    edi20 = a3;
    ebp21 = a5;
    ebp21->f12 = 0;
    ebp21->f8 = 0;
    ebp21->f16 = (void**)0;
    ebp21->f0 = (void**)0;
    if (!(int1_t)(a4 == 0xffffffff)) {
        if ((int8_t)a4 > (int8_t)2) {
            v22 = a4;
            ebx23 = (void**)((int32_t)__zero_stack_offset() - 92 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 44);
            fun_417450(ebx23, 0x40abb0, v22, v24, v18, v16, v14, v12, v25, v26, v27);
            fun_40850c(a1, ebx23, v28, 0x40ac3c, ebx23, 0x40abb0, v22, v29, v18, v16, v14, v12, v30, v31);
        }
        *(void***)(a1 + 0x78) = edi20;
        *(void***)(a1 + 0x74) = a2;
        *(void***)(a1 + 0x84) = *(void***)(a1 + 0xb0);
        *(void***)(a1 + 0x80) = *(void***)(a1 + 0xac);
        v32 = a1 + 0x74;
        esi33 = a1;
        while (1) {
            eax34 = fun_409780(v32, 0, v22);
            if (eax34) {
                if (!*(void***)(esi33 + 0x8c)) {
                    v35 = (void**)0x40abcc;
                } else {
                    v35 = *(void***)(esi33 + 0x8c);
                }
                fun_408404(esi33, v35, v22, v36, v18, v16);
            }
            if (*(void***)(esi33 + 0x84)) {
                addr_0x40ad78_13:
                if (*(void***)(esi33 + 0x78)) 
                    continue; else 
                    break;
            } else {
                if (!*(void***)(esi33 + 0x78)) 
                    goto addr_0x40ad84_15;
                edi37 = ebp21->f12;
                if ((int32_t)ebp21->f8 >= (int32_t)edi37) 
                    goto addr_0x40acce_17;
            }
            addr_0x40ad23_18:
            v38 = *(void***)(esi33 + 0xb0);
            eax43 = fun_402940(esi33, v38, v22, v39, v18, v16, v14, v12, v40, v41, v32, v42);
            *(void***)(ebp21->f16 + ebp21->f8 * 4) = eax43;
            edx44 = ebp21->f8;
            eax45 = ebp21->f16;
            v46 = *(void***)(esi33 + 0xb0);
            v47 = *(void***)(esi33 + 0xac);
            v48 = *(void***)(eax45 + edx44 * 4);
            fun_417ac0(v48, v47, v46, 0x40ad32, esi33, v38, v22, v49);
            ebp21->f8 = ebp21->f8 + 1;
            *(void***)(esi33 + 0x84) = *(void***)(esi33 + 0xb0);
            *(void***)(esi33 + 0x80) = *(void***)(esi33 + 0xac);
            goto addr_0x40ad78_13;
            addr_0x40acce_17:
            eax50 = ebp21->f8 + 4;
            ebp21->f12 = eax50;
            ebx51 = ebp21->f16;
            if (!ebx51) {
                eax56 = fun_402940(esi33, eax50 << 2, v22, v52, v18, v16, v14, v12, v53, v54, v32, v55);
                ebp21->f16 = eax56;
            } else {
                eax61 = fun_402940(esi33, eax50 << 2, v22, v57, v18, v16, v14, v12, v58, v59, v32, v60);
                ebp21->f16 = eax61;
                fun_417ac0(eax61, ebx51, edi37 * 4, 0x40ace8, esi33, eax50 << 2, v22, v62);
                fun_4029a0(esi33, ebx51, v22, v63, v18, v16, v14, v12, v64, v65, v32, v66, v67, v68, v69);
            }
            goto addr_0x40ad23_18;
        }
    } else {
        ebp21->f0 = a2;
        ebp21->f4 = edi20;
        goto addr_0x40aeb6_23;
    }
    esi33 = esi33;
    do {
        addr_0x40ad84_15:
        eax70 = fun_409780(v32, 4, v22);
        v71 = eax70;
        if (eax70) {
            if (v71 == 1) 
                break;
            if (*(void***)(esi33 + 0x8c)) 
                goto addr_0x40ae79_27;
        } else {
            if (!*(void***)(esi33 + 0x84)) {
                edi72 = ebp21->f12;
                if ((int32_t)ebp21->f8 >= (int32_t)edi72) {
                    eax73 = ebp21->f8 + 4;
                    ebp21->f12 = eax73;
                    ebx74 = ebp21->f16;
                    if (!ebx74) {
                        eax78 = fun_402940(esi33, eax73 << 2, v22, v75, v18, v16, v14, v12, v76, v77, v32, v71);
                        ebp21->f16 = eax78;
                    } else {
                        eax82 = fun_402940(esi33, eax73 << 2, v22, v79, v18, v16, v14, v12, v80, v81, v32, v71);
                        ebp21->f16 = eax82;
                        fun_417ac0(eax82, ebx74, edi72 * 4, 0x40add3, esi33, eax73 << 2, v22, v83);
                        fun_4029a0(esi33, ebx74, v22, v84, v18, v16, v14, v12, v85, v86, v32, v71, v87, v88, v89);
                    }
                }
                v90 = *(void***)(esi33 + 0xb0);
                eax94 = fun_402940(esi33, v90, v22, v91, v18, v16, v14, v12, v92, v93, v32, v71);
                *(void***)(ebp21->f16 + ebp21->f8 * 4) = eax94;
                edx95 = ebp21->f8;
                eax96 = ebp21->f16;
                v97 = *(void***)(esi33 + 0xb0);
                v98 = *(void***)(esi33 + 0xac);
                v99 = *(void***)(eax96 + edx95 * 4);
                fun_417ac0(v99, v98, v97, 0x40ae1e, esi33, v90, v22, v100);
                ebp21->f8 = ebp21->f8 + 1;
                *(void***)(esi33 + 0x84) = *(void***)(esi33 + 0xb0);
                *(void***)(esi33 + 0x80) = *(void***)(esi33 + 0xac);
                continue;
            }
        }
        v101 = (void**)0x40abcc;
        addr_0x40ae88_36:
        fun_408404(esi33, v101, v22, v102, v18, v16);
        continue;
        addr_0x40ae79_27:
        v101 = *(void***)(esi33 + 0x8c);
        goto addr_0x40ae88_36;
    } while (!(int1_t)(v71 == 1));
    edi20 = (void**)((uint8_t)*(void***)(esi33 + 0xb0) * ebp21->f8);
    if ((uint8_t)*(void***)(esi33 + 0x84) < (uint8_t)*(void***)(esi33 + 0xb0)) {
        edi20 = (void**)((uint8_t)edi20 + ((uint8_t)*(void***)(esi33 + 0xb0) - (uint8_t)*(void***)(esi33 + 0x84)));
    }
    addr_0x40aeb6_23:
    return edi20;
}

void** fun_40aec0(void** a1, struct s4* a2, void** a3) {
    void** v4;
    void** ebp5;
    void** v6;
    void** edi7;
    void** v8;
    void** esi9;
    void** v10;
    void** ebx11;
    struct s4* ebp12;
    void** esi13;
    uint32_t edi14;
    void** v15;
    void** esi16;
    void** ebx17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** ebx39;
    void** esi40;
    void** v41;
    void** v42;
    void** v43;
    void** v44;
    void** v45;
    void** eax46;
    void** ebx47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    void** v52;
    void** v53;

    v4 = ebp5;
    v6 = edi7;
    v8 = esi9;
    v10 = ebx11;
    ebp12 = a2;
    esi13 = ebp12->f0;
    if (!esi13) {
        edi14 = 0;
        v15 = a1 + 0x74;
        if ((int32_t)0 < (int32_t)ebp12->f8) {
            do {
                esi16 = *(void***)(ebp12->f16 + edi14 * 4);
                ebx17 = *(void***)(a1 + 0xb0);
                if (esi16 && ebx17) {
                    v18 = ebx17;
                    fun_407694(a1, esi16, v18, v19, v10, v8, v6, v4, v20, v21, v22, v15);
                    fun_40aaf8(a1, esi16, ebx17, 0x40af3b, a1, esi16, v18, v23, v10, v8, v6, v4);
                }
                v24 = *(void***)(ebp12->f16 + edi14 * 4);
                fun_4029a0(a1, v24, v18, v25, v10, v8, v6, v4, v26, v27, v28, v15, v29, v30, v31);
                *(void***)(ebp12->f16 + edi14 * 4) = (void**)0;
                ++edi14;
            } while ((int32_t)edi14 < (int32_t)ebp12->f8);
        }
        if (ebp12->f12) {
            v24 = ebp12->f16;
            fun_4029a0(a1, v24, v18, v32, v10, v8, v6, v4, v33, v34, v35, v15, v36, v37, v38);
        }
        ebp12->f16 = (void**)0;
        if ((uint8_t)*(void***)(a1 + 0x84) < (uint8_t)*(void***)(a1 + 0xb0) && ((ebx39 = (void**)((uint8_t)*(void***)(a1 + 0xb0) - (uint8_t)*(void***)(a1 + 0x84)), esi40 = *(void***)(a1 + 0xac), !!esi40) && ebx39)) {
            v18 = ebx39;
            v24 = esi40;
            fun_407694(a1, v24, v18, v41, v10, v8, v6, v4, v42, v43, v44, v15);
            fun_40aaf8(a1, esi40, ebx39, 0x40afc4, a1, v24, v18, v45, v10, v8, v6, v4);
        }
        eax46 = fun_409670(v15, v24, v18);
    } else {
        ebx47 = ebp12->f4;
        if (ebx47) {
            fun_407694(a1, esi13, ebx47, v48, v10, v8, v6, v4, v49, v50, v51, v52);
            eax46 = fun_40aaf8(a1, esi13, ebx47, 0x40aeec, a1, esi13, ebx47, v53, v10, v8, v6, v4);
        }
    }
    return eax46;
}

struct s31 {
    int8_t[1] pad1;
    void** f1;
};

void** fun_40ce3c(void** a1, void** a2, void** a3) {
    void** v4;
    void** ebp5;
    void** v6;
    void** edi7;
    void** v8;
    void** esi9;
    void*** esp10;
    void** v11;
    void** ebx12;
    void** ebx13;
    void** v14;
    void** edi15;
    int32_t ecx16;
    struct s31* ecx17;
    void** edi18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** eax26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** eax32;
    void** esi33;
    void* esi34;
    int8_t* ebx35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** v41;
    void** v42;
    void** ebx43;
    void** v44;
    void** v45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    int32_t edx50;
    void** esi51;
    void** v52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;
    void** v58;
    void** v59;
    void** v60;
    void** v61;
    void** v62;
    void** v63;
    void** v64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** v70;
    void** v71;
    void** v72;
    void** v73;
    void** v74;
    void** v75;
    void** ebp76;
    void** v77;
    void** v78;
    void** v79;
    void** v80;
    void** v81;
    void** v82;
    void** v83;
    void** v84;

    v4 = ebp5;
    v6 = edi7;
    v8 = esi9;
    esp10 = (void***)((int32_t)__zero_stack_offset() - 76 - 4 - 4 - 4 - 4);
    v11 = ebx12;
    ebx13 = a2;
    v14 = (void**)0;
    *(void***)a3 = (void**)0;
    if (!ebx13) {
        addr_0x40ce72_6:
    } else {
        edi15 = ebx13;
        ecx16 = -1;
        do {
            if (!ecx16) 
                break;
            --ecx16;
            ++edi15;
        } while (*(void***)edi15);
        ecx17 = (struct s31*)~ecx16;
        edi18 = (void**)((int32_t)ecx17 + 0xffffffff);
        if (edi18) 
            goto addr_0x40ce90_13; else 
            goto addr_0x40ce72_6;
    }
    fun_40850c(a1, 0x40ccde, v19, v20, v11, v8, v6, v4, v21, v22, v23, 0, v24, v25);
    eax26 = (void**)0;
    addr_0x40d01f_17:
    return eax26;
    addr_0x40ce90_13:
    eax32 = fun_402940(a1, &ecx17->f1, v27, v28, v11, v8, v6, v4, v29, v30, v31, 0);
    *(void***)a3 = eax32;
    esi33 = eax32;
    if (*(void***)ebx13) 
        goto addr_0x40ceb1_20;
    addr_0x40cef9_21:
    *(void***)esi33 = (void**)0;
    esi34 = (void*)((uint8_t)edi18 + (uint8_t)*(void***)a3);
    ebx35 = (int8_t*)((uint32_t)esi34 + 0xffffffff);
    if (*(int8_t*)((uint32_t)esi34 + 0xffffffff) == 32 && (fun_40850c(a1, 0x40cd50, v36, v37, v11, v8, v6, v4, v38, v39, v40, 0, v41, v42), *(int8_t*)((uint32_t)esi34 + 0xffffffff) == 32)) {
        do {
            *ebx35 = 0;
            --ebx35;
            --edi18;
        } while (*ebx35 == 32);
    }
    ebx43 = *(void***)a3;
    if ((int1_t)(*(void***)ebx43 == 32) && (fun_40850c(a1, 0x40cd90, v36, v44, v11, v8, v6, v4, v45, v46, v47, 0, v48, v49), (int1_t)(*(void***)ebx43 == 32))) {
        do {
            ++ebx43;
            --edi18;
        } while (*(void***)ebx43 == 32);
    }
    edx50 = 0;
    esi51 = *(void***)a3;
    if (*(void***)ebx43) {
        do {
            if (!(int1_t)(*(void***)ebx43 == 32)) {
                *(void***)esi51 = *(void***)ebx43;
                ++esi51;
                edx50 = 0;
            } else {
                if (edx50) {
                    --edi18;
                    v14 = (void**)1;
                } else {
                    *(void***)esi51 = (void**)32;
                    ++esi51;
                    edx50 = 1;
                }
            }
            ++ebx43;
        } while (*(void***)ebx43);
    }
    *(void***)esi51 = (void**)0;
    if (v14) {
        fun_40850c(a1, 0x40cdd0, v36, v52, v11, v8, v6, v4, v53, v54, v55, v14, v56, v57);
    }
    if (!edi18) {
        v58 = *(void***)a3;
        fun_4029a0(a1, v58, v36, v59, v11, v8, v6, v4, v60, v61, v62, v14, v63, v64, v65);
        *(void***)a3 = (void**)0;
        fun_40850c(a1, 0x40cdfb, v66, 0x40cfd1, a1, v58, v36, v67, v11, v8, v6, v4, v68, v69);
    }
    if ((uint8_t)edi18 > (uint8_t)79) {
        fun_40850c(a1, 0x40ce10, v36, v70, v11, v8, v6, v4, v71, v72, v73, v14, v74, v75);
        *(int32_t*)(a3 + 0x13c) = 0;
        edi18 = (void**)79;
    }
    eax26 = edi18;
    goto addr_0x40d01f_17;
    addr_0x40ceb1_20:
    ebp76 = (void**)(esp10 - 8 - 4 - 4 - 4 + 4 + 16 + 32);
    esi33 = esi33;
    do {
        if ((int8_t)*(void***)ebx13 <= (int8_t)31 || (int8_t)*(void***)ebx13 > (int8_t)0x7e && (uint8_t)*(void***)ebx13 <= 0xa0) {
            v36 = (void**)static_cast<int32_t>((int8_t)*(void***)ebx13);
            fun_417450(ebp76, 0x40cd10, v36, v77, v11, v8, v6, v4, v78, v79, v80);
            fun_40850c(a1, ebp76, v81, 0x40ced8, ebp76, 0x40cd10, v36, v82, v11, v8, v6, v4, v83, v84);
            *(void***)esi33 = (void**)32;
        } else {
            *(void***)esi33 = *(void***)ebx13;
        }
        ++ebx13;
        ++esi33;
    } while (*(void***)ebx13);
    goto addr_0x40cef9_21;
}

void fun_407670(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8) {
    uint32_t eax9;

    eax9 = fun_402770(0, 0, 0);
    *(uint32_t*)(a1 + 0x110) = eax9;
    return;
}

void fun_403904(void** a1, void** a2, void** a3);

void fun_410a30(void** a1, void** a2) {
    void** v3;
    void** esi4;
    void** v5;
    void** ebx6;
    void** edi7;
    void** v8;
    void** v9;
    void** eax10;
    void** v11;
    void** esi12;
    void** ebx13;
    void** edx14;
    uint32_t eax15;

    v3 = esi4;
    v5 = ebx6;
    edi7 = a1;
    *(void***)(edi7 + 0x74) = a2;
    *(void***)(edi7 + 0x78) = (void**)&(*(struct s13**)(edi7 + 0x104))->f1;
    do {
        v8 = (void**)0;
        eax10 = fun_409780(edi7 + 0x74, 0, v9);
        if (eax10) {
            if (!*(void***)(edi7 + 0x8c)) {
                v8 = (void**)0x40abcc;
            } else {
                v8 = *(void***)(edi7 + 0x8c);
            }
            fun_408404(edi7, v8, v9, v11, v5, v3);
        }
        if (!*(void***)(edi7 + 0x84)) {
            esi12 = *(void***)(edi7 + 0xac);
            ebx13 = *(void***)(edi7 + 0xb0);
            v9 = ebx13;
            v8 = (void**)0x406a5f;
            fun_410b88(edi7, 0x406a5f, v9);
            fun_410bf4(edi7, esi12, ebx13, 0x410aa9, edi7, 0x406a5f, v9);
            fun_410c30(edi7, 0x406a5f, v9);
            *(void***)(edi7 + 0x68) = (void**)((uint8_t)*(void***)(edi7 + 0x68) | 4);
            *(void***)(edi7 + 0x80) = *(void***)(edi7 + 0xac);
            *(void***)(edi7 + 0x84) = *(void***)(edi7 + 0xb0);
        }
    } while (*(void***)(edi7 + 0x78));
    edx14 = *(void***)(edi7 + 0xe8);
    if (edx14) {
        *(void***)(edi7 + 0xe8) = *(void***)(edi7 + 0xec);
        *(void***)(edi7 + 0xec) = edx14;
    }
    fun_40de24(edi7, edi7);
    eax15 = *(uint32_t*)(edi7 + 0x154);
    *(uint32_t*)(edi7 + 0x154) = eax15 + 1;
    if (*(uint32_t*)(edi7 + 0x150) && eax15 + 1 >= *(uint32_t*)(edi7 + 0x150)) {
        fun_403904(edi7, v8, v9);
    }
    return;
}

void fun_4038f8();

void fun_40ab30(void** a1, void** a2, void** a3);

void fun_403904(void** a1, void** a2, void** a3) {
    void** v4;
    void** esi5;
    void** v6;
    void** ebx7;
    void** ebx8;
    void** v9;
    void** v10;
    void** eax11;
    int32_t esi12;
    void** v13;

    v4 = esi5;
    v6 = ebx7;
    ebx8 = a1;
    if ((uint8_t)*(void***)(ebx8 + 0xe4) >= (uint8_t)*(void***)(ebx8 + 0xd0)) {
        addr_0x4039ef_2:
        return;
    } else {
        do {
            v9 = (void**)2;
            eax11 = fun_409780(ebx8 + 0x74, 2, v10);
            esi12 = 0;
            if (eax11) {
                if (!*(void***)(ebx8 + 0x8c)) {
                    v9 = (void**)fun_4038f8;
                } else {
                    v9 = *(void***)(ebx8 + 0x8c);
                }
                fun_408404(ebx8, v9, v10, v13, v6, v4);
            }
            if (!*(void***)(ebx8 + 0x84)) {
                v10 = *(void***)(ebx8 + 0xb0);
                v9 = *(void***)(ebx8 + 0xac);
                fun_410d50(ebx8, v9, v10);
                *(void***)(ebx8 + 0x80) = *(void***)(ebx8 + 0xac);
                *(void***)(ebx8 + 0x84) = *(void***)(ebx8 + 0xb0);
                esi12 = 1;
            }
        } while (esi12 == 1);
        if (*(void***)(ebx8 + 0xb0) != *(void***)(ebx8 + 0x84)) 
            goto addr_0x4039ac_14;
    }
    addr_0x4039d9_15:
    *(uint32_t*)(ebx8 + 0x154) = 0;
    fun_40ab30(ebx8, v9, v10);
    goto addr_0x4039ef_2;
    addr_0x4039ac_14:
    v10 = (void**)((uint8_t)*(void***)(ebx8 + 0xb0) - (uint8_t)*(void***)(ebx8 + 0x84));
    v9 = *(void***)(ebx8 + 0xac);
    fun_410d50(ebx8, v9, v10);
    *(void***)(ebx8 + 0x80) = *(void***)(ebx8 + 0xac);
    *(void***)(ebx8 + 0x84) = *(void***)(ebx8 + 0xb0);
    goto addr_0x4039d9_15;
}

int32_t g41d1d0 = 0x730f14e0;

int8_t* fun_4021cc(int8_t* a1, int8_t* a2, int8_t* a3) {
    goto g41d1d0;
}

void** fun_4032f8(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, int32_t a7, void** a8, void** a9, void** a10);

void** fun_404a3c(void** a1, void** a2, void** a3, int32_t a4) {
    void** v5;
    void** v6;
    void** v7;
    void** eax8;

    eax8 = fun_4032f8(__return_address(), a1, a2, a3, 0, 0, 0, v5, v6, v7);
    return eax8;
}

void** fun_407310(void** a1) {
    void** v2;
    void** v3;
    void** eax4;
    void** eax5;

    if (a1) {
        v2 = *(void***)(a1 + 0x244);
        v3 = *(void***)(a1 + 0x248);
        eax4 = fun_402aac(2, v3, v2);
        if (eax4) {
            fun_40737c((int32_t)__zero_stack_offset() - 28 - 4 - 4 - 4 - 4 - 4 + 4 + 16 - 8 - 4 + 24, 0x120, v2);
        }
        eax5 = eax4;
    } else {
        eax5 = (void**)0;
    }
    return eax5;
}

void fun_4074d8(void** a1, void** a2) {
    *(void***)(a1 + 84) = a2;
    return;
}

void fun_404cd8(void** a1, void** a2, void** a3, void** a4) {
    *(void***)(a1 + 0x6c) = (void**)((uint8_t)*(void***)(a1 + 0x6c) | 2);
    *(void***)(a1 + 0xb4) = a2;
    return;
}

void fun_405240(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12, int32_t a13) {
    void** v14;
    void** v15;
    void** ebx16;
    void** esi17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** edi32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** eax37;
    void** edx38;
    void** eax39;
    int16_t ax40;
    uint32_t edi41;
    void** v42;
    void** v43;

    if (!a5 || !a6) {
        addr_0x405454_4:
        goto a4;
    } else {
        if (!a7) 
            goto addr_0x405275_7;
        if (a8) 
            goto addr_0x405286_9;
    }
    addr_0x405275_7:
    fun_408404(a5, 0x405040, v14, v15, ebx16, esi17);
    addr_0x405286_9:
    if ((int8_t)a7 < (int8_t)0 || (int8_t)a8 < (int8_t)0) {
        fun_408404(a5, 0x405066, v18, v19, ebx16, esi17);
    }
    if ((uint8_t)(a9 + 0xffffffff) > (uint8_t)1 && (a9 != 4 && (a9 != 8 && a9 != 16))) {
        fun_408404(a5, 0x405081, v20, v21, ebx16, esi17);
    }
    if ((int8_t)a10 < (int8_t)0 || (a10 == 1 || (a10 == 5 || (int8_t)a10 > (int8_t)6))) {
        fun_408404(a5, 0x40509b, v22, v23, ebx16, esi17);
    }
    if ((int1_t)(a10 == 3) && (int8_t)a9 > (int8_t)8 || (a10 == 2 || (a10 == 4 || (int1_t)(a10 == 6))) && (int8_t)a9 <= (int8_t)7) {
        fun_408404(a5, 0x4050c0, v24, v25, ebx16, esi17);
    }
    if ((int8_t)a11 > (int8_t)1) {
        fun_408404(a5, 0x405100, v26, v27, ebx16, esi17);
    }
    if (a12) {
        fun_408404(a5, 0x405140, v28, v29, ebx16, esi17);
    }
    if (*(uint8_t*)(a5 + 0x69) & 16 && *(uint8_t*)(a5 + 0x230)) {
        fun_40850c(a5, 0x405180, v30, v31, ebx16, esi17, edi32, __return_address(), a1, a2, a3, a4, a5, a6);
    }
    if (a13) {
        if (!(*(uint8_t*)(a5 + 0x230) & 4) || (a13 != 64 || (*(uint8_t*)(a5 + 0x69) & 16 || a10 != 2 && a10 != 6))) {
            fun_408404(a5, 0x4051b2, v33, v34, ebx16, esi17);
        }
        if (*(uint8_t*)(a5 + 0x69) & 16) {
            fun_40850c(a5, 0x4051d0, v35, v36, ebx16, esi17, edi32, __return_address(), a1, a2, a3, a4, a5, a6);
        }
    }
    *(void***)a6 = a7;
    *(void***)(a6 + 4) = a8;
    eax37 = a9;
    *(void***)(a6 + 24) = eax37;
    edx38 = a10;
    *(uint8_t*)(a6 + 25) = *(uint8_t*)&edx38;
    *(void***)(a6 + 26) = a12;
    *(uint8_t*)(a6 + 27) = *(uint8_t*)&a13;
    *(void***)(a6 + 28) = a11;
    eax39 = a10;
    if (*(uint8_t*)&eax39 == 3 || !(*(uint8_t*)&eax39 & 2)) {
        *(int8_t*)(a6 + 29) = 1;
    } else {
        *(int8_t*)(a6 + 29) = 3;
    }
    if (*(uint8_t*)(a6 + 25) & 4) {
        *(int8_t*)(a6 + 29) = (int8_t)(*(int8_t*)(a6 + 29) + 1);
    }
    ax40 = (int16_t)(*(int8_t*)(a6 + 29) * (int8_t)*(void***)(a6 + 24));
    *(uint8_t*)(a6 + 30) = *(uint8_t*)&ax40;
    edi41 = static_cast<uint32_t>(*(uint8_t*)&ax40);
    if ((uint8_t)a7 <= (uint8_t)(0x7fffffff / (uint32_t)((int32_t)(edi41 + 7) >> 3))) {
        *(void***)(a6 + 12) = (void**)(edi41 * (uint8_t)*(void***)a6 + 7 >> 3);
        goto addr_0x405454_4;
    } else {
        fun_40850c(a5, 0x405200, v42, v43, ebx16, esi17, edi32, __return_address(), a1, a2, a3, a4, a5, a6);
        *(void***)(a6 + 12) = (void**)0;
        goto addr_0x405454_4;
    }
}

int32_t fun_417858(void** a1, void** a2);

int32_t fun_402260(void** a1, void** a2, void** a3) {
    void* ebp4;
    void** v5;
    void** ebx6;
    void** v7;
    void** esi8;
    void** v9;
    void** edi10;
    void** eax11;
    void** v12;
    void** eax13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    int32_t eax18;
    void** v19;
    void** v20;
    void** v21;
    void** ebx22;
    void* ecx23;
    void* edx24;
    void* eax25;
    void** edi26;
    void** v27;
    uint32_t edx28;
    uint32_t edx29;
    uint32_t esi30;
    int32_t eax31;
    int32_t ecx32;
    int32_t eax33;
    void*** ecx34;
    void*** edx35;
    void*** eax36;
    void*** eax37;
    void** v38;
    void*** edi39;
    void* edx40;
    void* edi41;
    void* ecx42;
    void* eax43;
    uint32_t eax44;
    void* eax45;
    void* edi46;
    void** edi47;
    void** v48;
    int32_t v49;
    void** eax50;
    void** v51;
    int32_t ecx52;
    void** esi53;
    uint32_t eax54;
    uint32_t edx55;
    uint32_t eax56;
    uint32_t edx57;
    uint32_t edx58;
    void** eax59;
    void** esi60;
    void** eax61;
    void** ecx62;
    void** v63;
    void** v64;
    void*** ecx65;
    void** ebx66;

    ebp4 = (void*)((int32_t)__zero_stack_offset() - 4);
    v5 = ebx6;
    v7 = esi8;
    v9 = edi10;
    eax11 = fun_404a3c(0x420424, 0, 0, 0);
    v12 = eax11;
    if (!eax11) {
        return 9;
    }
    eax13 = fun_407310(eax11);
    v14 = eax13;
    if (!eax13) {
        fun_404c24((int32_t)ebp4 + 0xfffffffc, 0, v9, v7, v5, v15, v16, v17, v14, v12);
        return 9;
    }
    eax18 = fun_417858(v12, 0);
    if (eax18) {
        fun_404c24((int32_t)ebp4 + 0xfffffffc, (int32_t)ebp4 + 0xfffffff8, v9, v7, v5, v19, v20, v21, v14, v12);
        return 6;
    }
    fun_4074d8(v12, a1);
    fun_404cd8(v12, 9, v12, a1);
    ebx22 = a2;
    ecx23 = (void*)0;
    do {
        if (*(int8_t*)((int32_t)ecx23 + (uint8_t)ebx22 + 0x200)) 
            break;
        ecx23 = (void*)((int32_t)ecx23 + 1);
    } while ((int32_t)ecx23 < 0x9c40);
    edx24 = (void*)(__intrinsic() >> 6);
    eax25 = (void*)0x9c3f;
    edi26 = (void**)((uint32_t)edx24 + ((uint32_t)edx24 >> 31));
    v27 = edi26;
    do {
        if (*(int8_t*)((int32_t)eax25 + (uint8_t)ebx22 + 0x200)) 
            break;
        eax25 = (void*)((int32_t)eax25 - 1);
    } while ((int32_t)eax25 >= 0);
    edx28 = (uint32_t)(__intrinsic() >> 6);
    edx29 = edx28 + (edx28 >> 31);
    esi30 = 0xc8 - edx29;
    asm("cdq");
    eax31 = (int32_t)(0xc8 - esi30 - (uint8_t)edi26 - edx29) >> 1;
    ecx32 = eax31 + eax31 * 4;
    eax33 = eax31 + eax31 * 4 + 5;
    ecx34 = (void***)(ecx32 + ecx32 * 4 << 3);
    edx35 = ecx34;
    eax36 = (void***)(eax33 + eax33 * 4 << 3);
    if ((int32_t)edx35 < (int32_t)eax36) 
        goto addr_0x402387_14;
    addr_0x402396_15:
    eax37 = ecx34 + 0xc7;
    v38 = (void**)((uint32_t)edx35 - (uint32_t)ecx34);
    if ((int32_t)eax37 >= (int32_t)ecx34) {
        do {
            if (*(int8_t*)((uint32_t)eax37 + (uint8_t)ebx22 + 0x200)) 
                break;
            --eax37;
        } while ((int32_t)eax37 >= (int32_t)ecx34);
    }
    edi39 = (void***)(edi26 + (uint8_t)edi26 * 4);
    edx40 = (void*)((uint32_t)ecx34 - (uint32_t)eax37 + 0xc7);
    edi41 = (void*)((uint32_t)(edi39 + (uint32_t)edi39 * 4) << 3);
    while (1) {
        ecx42 = (void*)((uint32_t)edi41 + 0xc8);
        eax43 = edi41;
        if ((int32_t)edi41 < (int32_t)ecx42) {
            do {
                if (*(int8_t*)((uint32_t)eax43 + (uint8_t)ebx22 + 0x200)) 
                    break;
                eax43 = (void*)((uint32_t)eax43 + 1);
            } while ((int32_t)eax43 < (int32_t)ecx42);
        }
        if (v38 == (uint32_t)eax43 - (uint32_t)edi41) 
            break;
        edi41 = (void*)((uint32_t)edi41 + 0xc8);
        ++v27;
    }
    eax44 = esi30 + esi30 * 4;
    eax45 = (void*)(0x9c3f - (eax44 + eax44 * 4 << 3));
    while (1) {
        edi46 = eax45;
        if ((int32_t)eax45 >= (int32_t)0) {
            do {
                if (*(int8_t*)((uint32_t)edi46 + (uint8_t)ebx22 + 0x200)) 
                    break;
                edi46 = (void*)((uint32_t)edi46 - 1);
            } while ((int32_t)edi46 >= (int32_t)0);
        }
        if (edx40 == (uint32_t)eax45 - (uint32_t)edi46) 
            break;
        ++esi30;
        eax45 = (void*)((uint32_t)eax45 - 0xc8);
    }
    edi47 = (void**)(0xc8 - esi30 - (uint8_t)v27);
    v48 = v14;
    fun_405240(v12, v48, 0xc8 - (uint32_t)edx40 - (uint8_t)v38, edi47, 8, 3, 0, 0, 0, v9, v7, v5, v49);
    eax50 = fun_402940(v12, 0x300, v12, v48, 0xc8 - (uint32_t)edx40 - (uint8_t)v38, edi47, 8, 3, 0, 0, 0, v9);
    v51 = eax50;
    if (!eax50) {
        fun_404c24((int32_t)ebp4 + 0xfffffffc, (int32_t)ebp4 + 0xfffffff8, v9, v7, v5, v51, v38, v27, v14, v12);
        return 8;
    }
    ecx52 = 0;
    esi53 = eax50 + 1;
    do {
        eax50 = *(void***)(ebx22 + ecx52 * 2);
        esi53 = esi53 + 3;
        eax54 = (uint8_t)eax50 & 31;
        edx55 = eax54 >> 2;
        *(uint8_t*)(esi53 + 0xfffffffe) = (uint8_t)(*(uint8_t*)&edx55 | (uint8_t)(*(uint8_t*)&eax54 << 3));
        *(void***)&eax54 = *(void***)(ebx22 + ecx52 * 2);
        eax56 = eax54 >> 5 & 31;
        edx57 = eax56 >> 2;
        *(uint8_t*)(esi53 + 0xfffffffd) = (uint8_t)(*(uint8_t*)&edx57 | (uint8_t)(*(uint8_t*)&eax56 << 3));
        *(void***)&eax56 = *(void***)(ebx22 + ecx52 * 2);
        eax50 = (void**)(eax56 >> 10 & 31);
        edx58 = (uint8_t)eax50 >> 2;
        ++ecx52;
        *(uint8_t*)(esi53 + 0xfffffffc) = (uint8_t)(*(uint8_t*)&edx58 | (uint8_t)((uint8_t)eax50 << 3));
    } while (ecx52 < 0x100);
    fun_4065a4(v12, v14, v51, 0x100);
    eax59 = fun_402940(v12, (uint8_t)edi47 * 4, v12, v14, v51, 0x100, v9, v7, v5, v51, v38, v27);
    esi60 = eax59;
    eax61 = (void**)0;
    if (edi47) 
        goto addr_0x402518_35;
    addr_0x40253b_36:
    ecx62 = v12;
    fun_402e04(*(int16_t*)&ecx62, ecx62, v14, v9, v7, v5, v51, v38);
    fun_404bc0(v12, esi60, ecx62, v14);
    v63 = v12;
    fun_4030dc(v63, v14, v12, esi60, ecx62, v14);
    v64 = v12;
    fun_4029a0(v64, v51, v63, v14, v12, esi60, ecx62, v14, v9, v7, v5, v51, v38, v27, v14);
    fun_404c24((int32_t)ebp4 + 0xfffffffc, (int32_t)ebp4 + 0xfffffff8, v64, v51, v63, v14, v12, esi60, ecx62, v14);
    return 0;
    addr_0x402518_35:
    ecx65 = (void***)(v27 + (uint8_t)v27 * 4);
    ebx66 = (void**)((uint32_t)(ebx22 + (uint32_t)(ecx65 + (uint32_t)ecx65 * 4) * 8) + 0x200 + (uint8_t)v38);
    do {
        *(void***)(esi60 + (uint8_t)eax61 * 4) = ebx66;
        ++eax61;
        ebx66 = ebx66 + 0xc8;
    } while ((uint8_t)eax61 < (uint8_t)edi47);
    goto addr_0x40253b_36;
    do {
        addr_0x402387_14:
        if (*(int8_t*)((uint32_t)edx35 + (uint8_t)ebx22 + 0x200)) 
            goto addr_0x402396_15;
        ++edx35;
    } while ((int32_t)edx35 < (int32_t)eax36);
    goto addr_0x402396_15;
}

void fun_417a50();

int32_t cb2_read_chunk_of_size(void* a1, uint32_t a2, void*** a3);

struct s32 {
    int8_t[8] pad8;
    void*** f8;
    uint32_t f12;
};

/* callback1? */
int16_t callback1_(void** a1, uint32_t a2, struct s32* a3);

void fun_41793c(void** a1, void** a2, void** a3, void** a4, void** a5);

uint32_t convert_and_write(void** a1, void** a2) {
    void* esp3;
    void** v4;
    int32_t v5;
    void** eax6;
    void* esp7;
    int32_t eax8;
    void* esp9;
    int32_t eax10;
    void* esp11;
    int32_t eax12;
    void* esp13;
    void** esi14;
    uint32_t eax15;
    void** edi16;
    void** v17;
    int32_t v18;
    int32_t v19;
    int32_t v20;
    int32_t v21;

    fun_417a50();
    esp3 = (void*)((int32_t)__zero_stack_offset() - 4 + 4 - 4 - 4 - 4);
    read_bytes((int32_t)esp3 + 32, 4, 1, v4);
    if (v5 >= 1) {
        eax6 = fun_417992(0x9e40);
        if (eax6) {
            esp7 = (void*)((int32_t)esp3 - 4 - 4 - 4 + 4 + 16 - 4 - 4 + 4 + 4 - 4 - 4);
            eax8 = read_bytes((int32_t)esp7 + 36, 4, 1, v4);
            if (eax8 && ((esp9 = (void*)((int32_t)esp7 - 4 - 4 - 4 + 4 + 16 - 4 - 4), eax10 = read_bytes((int32_t)esp9 + 40, 4, 1, v4), !!eax10) && ((esp11 = (void*)((int32_t)esp9 - 4 - 4 - 4 + 4 + 16 - 4 - 4), eax12 = read_bytes((int32_t)esp11 + 12, 4, 1, v4), esp13 = (void*)((int32_t)esp11 - 4 - 4 - 4 + 4 + 16), !!eax12) && (eax15 = file_processor_(cb2_read_chunk_of_size, callback1_, (int32_t)esp13 + 36, (int32_t)esp13 + 8, esi14, __return_address(), v4, eax6, eax6, 0), !eax15)))) {
                if (!__return_address()) {
                    fun_41793c(v4, edi16, esi14, __return_address(), v4);
                    fun_402260(v17, eax6, v4);
                    fun_4178d3(eax6, v17, eax6, v4);
                    fun_41793c(v17, eax6, v17, eax6, v4);
                    goto v18;
                } else {
                    goto v19;
                }
            }
        } else {
            goto v20;
        }
    }
    goto v21;
}

void** fun_407654(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7);

int32_t fun_409370(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, int32_t a8);

struct s33 {
    int8_t[1] pad1;
    void** f1;
};

void fun_40b1d8(int16_t cx, void** a2, void** a3, void** a4, uint32_t a5, void* a6, uint32_t a7, void** a8, void** a9) {
    int32_t ecx1;
    void*** esp10;
    void** esi11;
    uint32_t ebx12;
    void** edi13;
    void*** esp14;
    void** v15;
    void** v16;
    void** v17;
    void** ebx18;
    void** esi19;
    void** v20;
    void** v21;
    void** edi22;
    void** ebp23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** v41;
    void** v42;
    void** v43;
    void** v44;
    void** v45;
    void** eax46;
    uint32_t eax47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    void** v52;
    struct s33* eax53;
    void** eax54;
    void* edx55;
    void* edx56;
    uint8_t dh57;
    int32_t edx58;
    int32_t edx59;
    int8_t dh60;
    void** v61;
    void** v62;
    void** v63;
    void** v64;

    *(int16_t*)&ecx1 = cx;
    esp10 = (void***)((int32_t)__zero_stack_offset() - 28 - 4 - 4 - 4 - 4);
    esi11 = a2;
    ebx12 = a5;
    edi13 = a8;
    if ((uint32_t)a6 > 6) {
        esp14 = esp10 - 8 - 4;
        v15 = (void**)0x40b110;
    } else {
        goto *(int32_t*)((uint32_t)a6 * 4 + 0x40b208);
    }
    addr_0x40b32c_6:
    fun_408404(esi11, v15, v16, v17, ebx18, esi19);
    esp10 = esp14 - 4 - 4 + 4 + 16;
    addr_0x40b335_7:
    if (a7) {
        fun_40850c(esi11, 0x40b150, v20, v21, ebx18, esi19, edi22, ebp23, v24, v25, v26, v27, v28, v29);
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    if ((!(*(uint8_t*)(esi11 + 0x230) & 4) || (*(uint8_t*)(esi11 + 0x69) & 16 || (a6 != 2 && !(int1_t)(a6 == 6) || edi13 != 64))) && edi13) {
        fun_40850c(esi11, 0x40b173, v30, v31, ebx18, esi19, edi22, ebp23, v32, v33, v34, v35, v36, v37);
        edi13 = (void**)0;
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    if ((uint8_t)a9 > (uint8_t)1) {
        fun_40850c(esi11, 0x40b1b0, v38, v39, ebx18, esi19, edi22, ebp23, v40, v41, v42, v43, v44, v45);
        a9 = (void**)1;
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    *(void**)(esi11 + 0x127) = *(void**)&ebx12;
    *(uint8_t*)(esi11 + 0x126) = *(uint8_t*)&a6;
    *(int8_t*)(esi11 + 0x123) = *(int8_t*)&a9;
    eax46 = edi13;
    *(int8_t*)(esi11 + 0x238) = *(int8_t*)&eax46;
    *(void***)(esi11 + 0xc8) = a3;
    *(void***)(esi11 + 0xcc) = a4;
    eax47 = *(uint8_t*)(esi11 + 0x12a) * ebx12;
    *(uint8_t*)(esi11 + 0x129) = *(uint8_t*)&eax47;
    *(void***)(esi11 + 0xd8) = (void**)(*(uint8_t*)(esi11 + 0x129) * (uint8_t)a3 + 7 >> 3);
    *(void***)(esi11 + 0xd4) = a3;
    *(void**)(esi11 + 0x128) = *(void**)&ebx12;
    *(uint8_t*)(esi11 + 0x12b) = *(uint8_t*)(esi11 + 0x12a);
    fun_410b88(esi11, 0x406a5a, 13, esi11, 0x406a5a, 13);
    fun_410bf4(esi11, esp10 + 16, 13, 0x40b49e, esi11, 0x406a5a, 13, esi11, esp10 + 16, 13, 0x40b49e, esi11, 0x406a5a, 13);
    fun_410c30(esi11, 0x406a5a, 13, esi11, 0x406a5a, 13);
    *(int32_t*)(esi11 + 0x94) = (int32_t)fun_4075f0;
    *(int32_t*)(esi11 + 0x98) = (int32_t)fun_407654;
    *(void***)(esi11 + 0x9c) = esi11;
    if (!*(uint8_t*)(esi11 + 0x125)) {
        if (*(uint8_t*)(esi11 + 0x126) == 3 || (uint8_t)*(void**)(esi11 + 0x127) <= 7) {
            *(uint8_t*)(esi11 + 0x125) = 8;
        } else {
            *(uint8_t*)(esi11 + 0x125) = 0xf8;
        }
    }
    if (!((uint8_t)*(void***)(esi11 + 0x6c) & 1)) {
        if (*(uint8_t*)(esi11 + 0x125) == 8) {
            *(void***)(esi11 + 0xc4) = (void**)0;
        } else {
            *(void***)(esi11 + 0xc4) = (void**)1;
        }
    }
    if (!((uint8_t)*(void***)(esi11 + 0x6c) & 2)) {
        *(void***)(esi11 + 0xb4) = (void**)0xffffffff;
    }
    if (!((uint8_t)*(void***)(esi11 + 0x6c) & 4)) {
        *(void***)(esi11 + 0xc0) = (void**)8;
    }
    if (!((uint8_t)*(void***)(esi11 + 0x6c) & 8)) {
        *(void***)(esi11 + 0xbc) = (void**)15;
    }
    if (!((uint8_t)*(void***)(esi11 + 0x6c) & 16)) {
        *(void***)(esi11 + 0xb8) = (void**)8;
    }
    v48 = *(void***)(esi11 + 0xc4);
    v49 = *(void***)(esi11 + 0xc0);
    v50 = *(void***)(esi11 + 0xbc);
    v51 = *(void***)(esi11 + 0xb8);
    v52 = *(void***)(esi11 + 0xb4);
    fun_409370(esi11 + 0x74, v52, v51, v50, v49, v48, 0x40b1d1, 56);
    *(void***)(esi11 + 0x80) = *(void***)(esi11 + 0xac);
    *(void***)(esi11 + 0x84) = *(void***)(esi11 + 0xb0);
    *(void***)(esi11 + 0x68) = (void**)1;
    return;
    asm("emms");
    eax53 = (struct s33*)((uint32_t)a6 - 1);
    switch (eax53) {
        addr_0x40b2c5_32:
    case 0:
    case 1:
    case 3:
    case 7:
    case 15:
        *(uint8_t*)(esi11 + 0x12a) = 1;
        goto addr_0x40b335_7;
    case 2:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        eax54 = (void**)&eax53->f1;
        *(int8_t*)&ecx1 = (int8_t)(*(int8_t*)&ecx1 + *(int8_t*)((int32_t)&ecx1 + 1));
        *(void***)(edi13 + 4) = eax54;
        esi11 = (void**)((uint32_t)(esi11 + 4) + 4);
        *(void***)eax54 = (void**)((uint8_t)*(void***)eax54 + (uint8_t)*(void**)&eax54);
        *(int8_t*)(a3 + 0xfb830076) = (int8_t)(*(int8_t*)(a3 + 0xfb830076) + *(int8_t*)&ecx1);
    }
    *(uint8_t*)((uint8_t)esi11 + (uint32_t)edx55 - 0x7d) = (uint8_t)(*(uint8_t*)((uint8_t)esi11 + (uint32_t)edx56 - 0x7d) | dh57);
    asm("sti");
    *(uint8_t*)(ecx1 + edx58 - 0x7d) = (uint8_t)static_cast<uint32_t>((uint8_t)(*(int8_t*)(ecx1 + edx59 - 0x7d) + dh60));
    if (ebx12 == 4) 
        goto addr_0x40b2c5_32;
    if ((int32_t)ebx12 > (int32_t)4) {
        if (ebx12 == 8) 
            goto addr_0x40b2c5_32;
    } else {
        if ((int32_t)ebx12 <= (int32_t)2 && (int32_t)ebx12 >= (int32_t)1) {
            goto addr_0x40b2c5_32;
        }
    }
    esp14 = esp10 - 8 - 4;
    v15 = (void**)0x40b050;
    goto addr_0x40b32c_6;
    if (ebx12 != 8 && ebx12 != 16) {
        fun_408404(esi11, 0x40b090, v61, v62, ebx18, esi19);
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    *(uint8_t*)(esi11 + 0x12a) = 2;
    goto addr_0x40b335_7;
    if (ebx12 != 8 && ebx12 != 16) {
        fun_408404(esi11, 0x40b0d0, v63, v64, ebx18, esi19);
        esp10 = esp10 - 8 - 4 - 4 - 4 + 4 + 16;
    }
    *(uint8_t*)(esi11 + 0x12a) = 4;
    goto addr_0x40b335_7;
}

void fun_40b5d0(void* ecx);

void fun_40b648(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7) {
    void** v8;
    void** v9;
    void** esi10;
    void*** esp11;
    void** v12;
    void** ebx13;
    void** edi14;
    void** v15;
    int32_t v16;
    uint32_t v17;
    void** v18;
    void** v19;
    void** v20;
    int32_t eax21;
    int32_t v22;
    uint32_t edx23;
    int32_t v24;
    uint32_t eax25;
    void** v26;
    uint32_t eax27;
    uint32_t eax28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void* esp33;
    uint32_t ebp34;
    void** v35;
    uint32_t v36;
    void** esi37;
    uint32_t eax38;
    uint32_t v39;
    int32_t v40;
    void** v41;
    int32_t v42;
    void** v43;
    int32_t v44;
    uint32_t v45;
    uint32_t edx46;
    uint32_t eax47;
    void** v48;
    uint32_t eax49;
    uint32_t eax50;
    void** v51;
    int32_t v52;
    void** v53;
    int32_t v54;
    void** v55;
    int32_t v56;
    void** v57;
    int32_t v58;
    void** v59;
    int32_t v60;
    void** v61;
    int32_t v62;
    void** v63;
    int32_t v64;
    void** v65;
    int32_t v66;
    void** v67;
    int32_t v68;
    uint32_t v69;
    int32_t v70;
    void** v71;
    int32_t v72;
    void** v73;
    int32_t v74;
    void** v75;
    int32_t v76;
    void** v77;
    int32_t v78;
    void** v79;
    void** v80;

    v8 = (void**)__return_address();
    v9 = esi10;
    esp11 = (void***)((int32_t)__zero_stack_offset() - 4 - 4);
    v12 = ebx13;
    edi14 = v15;
    if (*(uint8_t*)(edi14 + 0x230) & 1 || v16) {
        if (v17 > 0x100) 
            goto addr_0x40b66d_4;
    } else {
        addr_0x40b66d_4:
        if (*(uint8_t*)(edi14 + 0x126) == 3) {
            fun_408404(edi14, fun_40b5d0, v18, v19, v12, v9);
            esp11 = esp11 - 8 - 4 - 4 - 4 + 4 + 16;
        } else {
            v20 = (void**)fun_40b5d0;
            goto addr_0x40b6a2_7;
        }
    }
    if (*(uint8_t*)(edi14 + 0x126) & 2) {
        eax21 = v22;
        *(void***)(edi14 + 0x118) = *(void***)&eax21;
        edx23 = (uint32_t)(v24 + v24 * 2);
        eax25 = edx23 >> 24;
        *(int8_t*)&v26 = *(int8_t*)&eax25;
        eax27 = edx23 >> 16;
        *(int8_t*)(&v26 + 1) = *(int8_t*)&eax27;
        eax28 = edx23 >> 8;
        *(int8_t*)(&v26 + 2) = *(int8_t*)&eax28;
        *(int8_t*)(&v26 + 3) = *(int8_t*)&edx23;
        fun_40aaf8(edi14, esp11 + 28, 4, v29, v12, v9, v8, a1, a2, a3, a4, v26);
        fun_40aaf8(edi14, 0x406a69, 4, 0x40b6ee, edi14, esp11 + 28, 4, v30, v12, v9, v8, a1);
        fun_407670(edi14, esp11 + 28, 4, v31, v12, v9, v8, a1);
        fun_407694(edi14, 0x406a69, 4, 0x40b70a, edi14, esp11 + 28, 4, v32, v12, v9, v8, a1);
        esp33 = (void*)(esp11 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32 - 12 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
        ebp34 = 0;
        v35 = (void**)((int32_t)esp33 + 24);
        if (0 >= v36) 
            goto addr_0x40b8d8_14;
        esi37 = (void**)((int32_t)esp33 + 32);
        eax38 = v39 & 3;
        if (v40 > 0) 
            goto addr_0x40b747_16;
    } else {
        v20 = (void**)0x40b610;
        goto addr_0x40b6a2_7;
    }
    addr_0x40b7c3_18:
    fun_407694(edi14, esi37, 3, v41, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v42, v12, v9, v8, a1, a2, v35, a4, v26);
    fun_40aaf8(edi14, esi37, 3, 0x40b7e3, edi14, esi37, 3, v43, v12, v9, v8, a1, edi14, esi37, 3, 0x40b7e3, edi14, esi37, 3, v44, v12, v9, v8, a1);
    ++ebp34;
    if (ebp34 >= v45) {
        addr_0x40b8d8_14:
        edx46 = *(uint32_t*)(edi14 + 0x110);
        eax47 = edx46 >> 24;
        *(int8_t*)&v48 = *(int8_t*)&eax47;
        eax49 = edx46 >> 16;
        *(int8_t*)(&v48 + 1) = *(int8_t*)&eax49;
        eax50 = edx46 >> 8;
        *(int8_t*)(&v48 + 2) = *(int8_t*)&eax50;
        *(int8_t*)(&v48 + 3) = *(int8_t*)&edx46;
        fun_40aaf8(edi14, v35, 4, v51, v12, v9, v8, a1, a2, v35, v48, v26, edi14, v35, 4, v52, v12, v9, v8, a1, a2, v35, v48, v26);
        *(void***)(edi14 + 0x68) = (void**)((uint8_t)*(void***)(edi14 + 0x68) | 2);
    } else {
        do {
            addr_0x40b800_19:
            fun_407694(edi14, esi37, 3, v53, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v54, v12, v9, v8, a1, a2, v35, a4, v26);
            fun_40aaf8(edi14, esi37, 3, 0x40b820, edi14, esi37, 3, v55, v12, v9, v8, a1, edi14, esi37, 3, 0x40b820, edi14, esi37, 3, v56, v12, v9, v8, a1);
            fun_407694(edi14, esi37, 3, v57, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v58, v12, v9, v8, a1, a2, v35, a4, v26);
            fun_40aaf8(edi14, esi37, 3, 0x40b853, edi14, esi37, 3, v59, v12, v9, v8, a1, edi14, esi37, 3, 0x40b853, edi14, esi37, 3, v60, v12, v9, v8, a1);
            fun_407694(edi14, esi37, 3, v61, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v62, v12, v9, v8, a1, a2, v35, a4, v26);
            fun_40aaf8(edi14, esi37, 3, 0x40b886, edi14, esi37, 3, v63, v12, v9, v8, a1, edi14, esi37, 3, 0x40b886, edi14, esi37, 3, v64, v12, v9, v8, a1);
            fun_407694(edi14, esi37, 3, v65, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v66, v12, v9, v8, a1, a2, v35, a4, v26);
            fun_40aaf8(edi14, esi37, 3, 0x40b8b9, edi14, esi37, 3, v67, v12, v9, v8, a1, edi14, esi37, 3, 0x40b8b9, edi14, esi37, 3, v68, v12, v9, v8, a1);
            ebp34 = ebp34 + 4;
        } while (ebp34 < v69);
        goto addr_0x40b8d8_14;
    }
    addr_0x40b911_20:
    goto v70;
    addr_0x40b747_16:
    if (!eax38) 
        goto addr_0x40b800_19;
    if ((int32_t)eax38 > (int32_t)1) {
        if ((int32_t)eax38 > (int32_t)2) {
            fun_407694(edi14, esi37, 3, v71, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v72, v12, v9, v8, a1, a2, v35, a4, v26);
            fun_40aaf8(edi14, esi37, 3, 0x40b779, edi14, esi37, 3, v73, v12, v9, v8, a1, edi14, esi37, 3, 0x40b779, edi14, esi37, 3, v74, v12, v9, v8, a1);
            ebp34 = 1;
        }
        fun_407694(edi14, esi37, 3, v75, v12, v9, v8, a1, a2, v35, a4, v26, edi14, esi37, 3, v76, v12, v9, v8, a1, a2, v35, a4, v26);
        fun_40aaf8(edi14, esi37, 3, 0x40b7b0, edi14, esi37, 3, v77, v12, v9, v8, a1, edi14, esi37, 3, 0x40b7b0, edi14, esi37, 3, v78, v12, v9, v8, a1);
        ++ebp34;
        goto addr_0x40b7c3_18;
    }
    addr_0x40b6a2_7:
    fun_40850c(edi14, v20, v79, v80, v12, v9, v8, a1, a2, a3, a4, a5, a6, a7);
    goto addr_0x40b911_20;
}

struct s34 {
    int8_t[299] pad299;
    uint8_t f299;
};

struct s35 {
    int8_t[200] pad200;
    int32_t f200;
};

struct s36 {
    int8_t[296] pad296;
    uint8_t f296;
};

struct s37 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
};

struct s38 {
    int8_t[236] pad236;
    void** f236;
};

struct s39 {
    int8_t[293] pad293;
    uint8_t f293;
};

struct s40 {
    int8_t[216] pad216;
    int32_t f216;
};

struct s41 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
};

struct s42 {
    int8_t[240] pad240;
    void** f240;
};

struct s43 {
    int8_t[293] pad293;
    uint8_t f293;
};

struct s44 {
    int8_t[232] pad232;
    void** f232;
};

struct s45 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    int32_t f8;
    void** f12;
};

struct s46 {
    int8_t[293] pad293;
    uint8_t f293;
};

struct s47 {
    int8_t[216] pad216;
    int32_t f216;
};

struct s48 {
    int8_t[244] pad244;
    void** f244;
};

struct s49 {
    int8_t[293] pad293;
    uint8_t f293;
};

struct s50 {
    int8_t[216] pad216;
    int32_t f216;
};

struct s51 {
    int8_t[248] pad248;
    void** f248;
};

struct s52 {
    int8_t[293] pad293;
    int8_t f293;
};

struct s53 {
    int8_t[216] pad216;
    int32_t f216;
};

struct s54 {
    int8_t[252] pad252;
    void** f252;
};

struct s55 {
    int8_t[291] pad291;
    int8_t f291;
};

struct s56 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s57 {
    int8_t[208] pad208;
    int32_t f208;
};

struct s58 {
    int8_t[204] pad204;
    int32_t f204;
};

struct s59 {
    int8_t[200] pad200;
    uint32_t f200;
};

int32_t g406b18 = 8;

int32_t g406afc = 0;

struct s60 {
    int8_t[208] pad208;
    uint32_t f208;
};

struct s61 {
    int8_t[204] pad204;
    int32_t f204;
};

int32_t g406ae0 = 8;

int32_t g406ac4 = 0;

struct s62 {
    int8_t[200] pad200;
    int32_t f200;
};

struct s63 {
    int8_t[212] pad212;
    uint32_t f212;
};

struct s64 {
    int8_t[132] pad132;
    int32_t f132;
};

struct s65 {
    int8_t[176] pad176;
    int32_t f176;
};

struct s66 {
    int8_t[128] pad128;
    int32_t f128;
};

struct s67 {
    int8_t[172] pad172;
    int32_t f172;
};

void fun_40dc98(void** a1, void** a2) {
    uint32_t esi3;
    struct s34* ebx4;
    struct s35* ebx5;
    struct s36* ebx6;
    uint32_t* esp7;
    int32_t* esp8;
    int32_t ebx9;
    struct s37* esp10;
    void** eax11;
    struct s38* ebx12;
    void* esp13;
    struct s39* ebx14;
    uint32_t* esp15;
    struct s40* ebx16;
    int32_t* esp17;
    int32_t ebx18;
    struct s41* esp19;
    void** eax20;
    struct s42* ebx21;
    struct s43* ebx22;
    uint32_t* esp23;
    int32_t* esp24;
    int32_t ebx25;
    struct s41* esp26;
    void** eax27;
    struct s44* ebx28;
    uint32_t* esp29;
    int32_t* esp30;
    void*** esp31;
    struct s45* esp32;
    struct s46* ebx33;
    uint32_t* esp34;
    struct s47* ebx35;
    int32_t* esp36;
    int32_t ebx37;
    struct s41* esp38;
    void** eax39;
    struct s48* ebx40;
    struct s49* ebx41;
    uint32_t* esp42;
    struct s50* ebx43;
    int32_t* esp44;
    int32_t ebx45;
    struct s41* esp46;
    void** eax47;
    struct s51* ebx48;
    struct s52* ebx49;
    uint32_t* esp50;
    struct s53* ebx51;
    int32_t* esp52;
    int32_t ebx53;
    struct s41* esp54;
    void** eax55;
    struct s54* ebx56;
    struct s55* ebx57;
    struct s56* ebx58;
    struct s57* ebx59;
    struct s58* ebx60;
    uint32_t eax61;
    struct s59* ebx62;
    int32_t ecx63;
    int32_t eax64;
    struct s60* ebx65;
    struct s61* ebx66;
    int32_t ecx67;
    int32_t eax68;
    struct s62* ebx69;
    struct s63* ebx70;
    struct s64* ebx71;
    struct s65* ebx72;
    struct s66* ebx73;
    struct s67* ebx74;

    esi3 = (ebx4->f299 * ebx5->f200 * ebx6->f296 + 7 >> 3) + 1;
    esp7 = (uint32_t*)((int32_t)__return_address() + 4 - 8 - 4);
    *esp7 = esi3;
    esp8 = (int32_t*)(esp7 - 1);
    *esp8 = ebx9;
    esp10 = (struct s37*)(esp8 - 1);
    esp10->f0 = 0x40dccc;
    eax11 = fun_402940(esp10->f4, esp10->f8, esp10->f12, esp10->f16, esp10->f20, esp10->f24, esp10->f28, esp10->f32, esp10->f36, esp10->f40, esp10->f44, esp10->f48);
    ebx12->f236 = eax11;
    *(void***)eax11 = (void**)0;
    esp13 = (void*)(&esp10->f4 + 16);
    if (ebx14->f293 & 16) {
        esp15 = (uint32_t*)((int32_t)esp13 - 8 - 4);
        *esp15 = (uint32_t)(ebx16->f216 + 1);
        esp17 = (int32_t*)(esp15 - 1);
        *esp17 = ebx18;
        esp19 = (struct s41*)(esp17 - 1);
        esp19->f0 = 0x40dcf2;
        eax20 = fun_402940(esp19->f4, esp19->f8, esp19->f12, esp19->f16, esp19->f20, esp19->f24, esp19->f28, esp19->f32, esp19->f36, esp19->f40, esp19->f44, esp19->f48);
        ebx21->f240 = eax20;
        *(void***)eax20 = (void**)1;
        esp13 = (void*)(&esp19->f4 + 16);
    }
    if (ebx22->f293 & 0xe0) {
        esp23 = (uint32_t*)((int32_t)esp13 - 8 - 4);
        *esp23 = esi3;
        esp24 = (int32_t*)(esp23 - 1);
        *esp24 = ebx25;
        esp26 = (struct s41*)(esp24 - 1);
        esp26->f0 = 0x40dd15;
        eax27 = fun_402940(esp26->f4, esp26->f8, esp26->f12, esp26->f16, esp26->f20, esp26->f24, esp26->f28, esp26->f32, esp26->f36, esp26->f40, esp26->f44, esp26->f48);
        ebx28->f232 = eax27;
        esp29 = (uint32_t*)(&esp26->f4 - 4 - 4);
        *esp29 = esi3;
        esp30 = (int32_t*)(esp29 - 1);
        *esp30 = 0;
        esp31 = (void***)(esp30 - 1);
        *esp31 = eax27;
        esp32 = (struct s45*)(esp31 - 4);
        esp32->f0 = 0x40dd27;
        fun_417e00(esp32->f4, esp32->f8, esp32->f12);
        esp13 = (void*)(&esp32->f4 + 32);
        if (ebx33->f293 & 32) {
            esp34 = (uint32_t*)((int32_t)esp13 - 8 - 4);
            *esp34 = (uint32_t)(ebx35->f216 + 1);
            esp36 = (int32_t*)(esp34 - 1);
            *esp36 = ebx37;
            esp38 = (struct s41*)(esp36 - 1);
            esp38->f0 = 0x40dd44;
            eax39 = fun_402940(esp38->f4, esp38->f8, esp38->f12, esp38->f16, esp38->f20, esp38->f24, esp38->f28, esp38->f32, esp38->f36, esp38->f40, esp38->f44, esp38->f48);
            ebx40->f244 = eax39;
            *(void***)eax39 = (void**)2;
            esp13 = (void*)(&esp38->f4 + 16);
        }
        if (ebx41->f293 & 64) {
            esp42 = (uint32_t*)((int32_t)esp13 - 8 - 4);
            *esp42 = (uint32_t)(ebx43->f216 + 1);
            esp44 = (int32_t*)(esp42 - 1);
            *esp44 = ebx45;
            esp46 = (struct s41*)(esp44 - 1);
            esp46->f0 = 0x40dd6a;
            eax47 = fun_402940(esp46->f4, esp46->f8, esp46->f12, esp46->f16, esp46->f20, esp46->f24, esp46->f28, esp46->f32, esp46->f36, esp46->f40, esp46->f44, esp46->f48);
            ebx48->f248 = eax47;
            *(void***)eax47 = (void**)3;
            esp13 = (void*)(&esp46->f4 + 16);
        }
        if (ebx49->f293 < 0) {
            esp50 = (uint32_t*)((int32_t)esp13 - 8 - 4);
            *esp50 = (uint32_t)(ebx51->f216 + 1);
            esp52 = (int32_t*)(esp50 - 1);
            *esp52 = ebx53;
            esp54 = (struct s41*)(esp52 - 1);
            esp54->f0 = 0x40dd90;
            eax55 = fun_402940(esp54->f4, esp54->f8, esp54->f12, esp54->f16, esp54->f20, esp54->f24, esp54->f28, esp54->f32, esp54->f36, esp54->f40, esp54->f44, esp54->f48);
            ebx56->f252 = eax55;
            *(void***)eax55 = (void**)4;
            esp13 = (void*)(&esp54->f4 + 16);
        }
    }
    if (!ebx57->f291 || ebx58->f112 & 2) {
        ebx59->f208 = ebx60->f204;
        eax61 = ebx62->f200;
    } else {
        ecx63 = g406b18;
        eax64 = g406afc;
        ebx65->f208 = (ecx63 + ebx66->f204 - (eax64 + 1)) / (uint32_t)ecx63;
        ecx67 = g406ae0;
        eax68 = g406ac4;
        eax61 = (ecx67 + ebx69->f200 - (eax68 + 1)) / (uint32_t)ecx67;
    }
    ebx70->f212 = eax61;
    ebx71->f132 = ebx72->f176;
    ebx73->f128 = ebx74->f172;
    goto *(int32_t*)((int32_t)esp13 + 4 + 4 + 20);
}

void fun_402a34(void** a1, void** a2, void** a3, struct s13* a4) {
    void** v5;
    void** v6;
    void** v7;
    void** v8;

    fun_417ac0(a1, a2, a3, v5, v6, v7, v8, __return_address());
    return;
}

void fun_40e2fc(void** a1, struct s12* a2, void** a3, struct s13* a4) {
    uint8_t v5;
    void* v6;
    void* v7;
    void* v8;
    void** v9;
    void** ebp10;
    void** v11;
    void** v12;
    void* v13;
    void* esi14;
    void* ebp15;
    void** v16;
    void** v17;
    void* esi18;
    void** ecx19;
    void** ebx20;
    void** edx21;
    void** v22;
    uint32_t eax23;
    void* edx24;
    void* ebx25;
    void** ecx26;
    int8_t v27;
    uint32_t eax28;
    void* edi29;
    void** ecx30;
    void** edx31;
    uint32_t eax32;
    void* eax33;
    void* esi34;
    void* eax35;
    void* esi36;
    void* eax37;
    void* esi38;
    void* eax39;
    void* eax40;
    void* eax41;
    void* eax42;
    void** eax43;
    void** v44;
    void* ebp45;
    void* v46;
    void** v47;
    void** v48;
    void** v49;
    void* edi50;
    void** ebp51;
    void** esi52;
    void** edx53;
    void** ecx54;
    uint32_t eax55;
    void* ecx56;
    uint32_t ecx57;
    uint32_t edx58;
    void* esi59;
    void** v60;
    void** edi61;
    uint32_t eax62;
    void* edi63;
    void** eax64;
    void** v65;
    void** ecx66;
    void** edx67;
    void* ebx68;
    uint32_t eax69;
    void* edi70;
    void* v71;
    void** v72;
    void** v73;
    void** v74;
    void* v75;
    void** v76;
    void** v77;
    void** ebp78;
    void* ecx79;
    uint32_t ecx80;
    uint32_t edx81;
    void* esi82;
    void** v83;
    void** v84;
    uint32_t eax85;
    void* v86;
    void** ebp87;
    void** edx88;
    void** v89;
    void** edi90;
    void** v91;
    void** v92;
    uint32_t eax93;
    void* esi94;
    void* v95;
    void** v96;
    void** v97;
    void** v98;
    void* v99;
    void** ebp100;
    void** ebx101;
    void** edi102;
    void* ecx103;
    uint32_t ecx104;
    uint32_t edx105;
    void* edi106;
    void** v107;
    void** ebp108;
    void** v109;
    uint32_t eax110;
    void* ebp111;
    void** ecx112;
    void** edx113;
    void** ebx114;
    void** esi115;
    void** v116;
    uint32_t eax117;
    void* ecx118;
    uint32_t ecx119;
    uint32_t edx120;
    void* esi121;
    void** v122;
    void** edi123;
    uint32_t eax124;
    void* ecx125;
    void* ecx126;
    void* ecx127;
    void* eax128;
    void* eax129;
    void* edi130;
    void* eax131;
    void* edi132;
    void* eax133;
    void* edi134;
    void* eax135;
    void** v136;
    void** v137;
    void* ecx138;
    uint32_t ecx139;
    uint32_t edx140;
    void* esi141;
    void** v142;
    void** edi143;
    uint32_t eax144;
    uint32_t ebx145;
    uint32_t esi146;
    uint32_t edx147;
    uint32_t eax148;
    uint32_t edx149;
    uint32_t ebx150;
    uint32_t ecx151;
    uint32_t edx152;
    uint32_t eax153;
    void* eax154;
    uint32_t ebx155;
    void** ebp156;
    uint32_t esi157;
    uint32_t edx158;
    uint32_t eax159;
    uint32_t edx160;
    uint32_t ebx161;
    uint32_t ecx162;
    uint32_t edx163;
    uint32_t eax164;
    void* eax165;
    uint32_t ecx166;
    uint32_t esi167;
    uint32_t v168;
    uint32_t eax169;
    uint32_t edx170;
    uint32_t ebx171;
    uint32_t ecx172;
    uint32_t edx173;
    uint32_t eax174;
    void* eax175;
    uint32_t eax176;
    void* esi177;
    uint32_t eax178;
    uint32_t edx179;
    uint32_t eax180;
    void* ebp181;
    uint32_t eax182;
    void* ebp183;
    uint32_t eax184;
    void* ebp185;
    uint32_t eax186;
    uint32_t eax187;
    uint32_t eax188;
    uint32_t eax189;
    uint32_t eax190;
    uint32_t edx191;
    uint32_t eax192;
    void* ebp193;
    uint32_t eax194;
    void* ebx195;
    uint32_t ebp196;
    void* eax197;
    uint32_t ebp198;
    uint32_t eax199;
    uint32_t eax200;
    void** v201;
    void** v202;
    uint32_t ebx203;
    uint32_t esi204;
    uint32_t edx205;
    uint32_t eax206;
    uint32_t edx207;
    uint32_t ebx208;
    uint32_t ecx209;
    uint32_t edx210;
    uint32_t eax211;
    uint32_t v212;
    uint32_t esi213;
    uint32_t v214;
    uint32_t eax215;
    uint32_t edx216;
    uint32_t ebx217;
    uint32_t ecx218;
    uint32_t edx219;
    uint32_t eax220;
    uint32_t v221;
    uint32_t esi222;
    uint32_t ebx223;
    uint32_t eax224;
    uint32_t edx225;
    uint32_t ebx226;
    uint32_t ecx227;
    uint32_t edx228;
    uint32_t eax229;
    void* eax230;
    void* eax231;
    void* esi232;
    void* eax233;
    void* esi234;
    void* eax235;
    void* esi236;
    void* eax237;
    void** ecx238;
    uint32_t eax239;
    void* eax240;
    void* ecx241;
    uint32_t ecx242;
    uint32_t edx243;
    void* esi244;
    void** v245;
    void** edi246;
    uint32_t eax247;
    uint32_t eax248;
    void* esi249;
    uint32_t eax250;
    uint32_t edx251;
    uint32_t eax252;
    void* ebp253;
    uint32_t eax254;
    void* ebp255;
    uint32_t eax256;
    void* ebp257;
    uint32_t eax258;
    uint32_t eax259;
    uint32_t eax260;
    uint32_t eax261;
    uint32_t eax262;
    uint32_t edx263;
    uint32_t eax264;
    void* ebp265;
    uint32_t eax266;
    void* ebx267;
    uint32_t ebp268;
    void* eax269;
    uint32_t ebp270;
    uint32_t eax271;
    uint32_t eax272;
    void** edi273;
    uint32_t eax274;
    int32_t eax275;
    int32_t eax276;
    int32_t eax277;
    int32_t eax278;
    int32_t eax279;
    int32_t eax280;
    int32_t eax281;
    uint32_t eax282;
    uint32_t eax283;
    uint32_t edx284;
    uint32_t eax285;
    void* eax286;
    uint32_t eax287;
    void* eax288;
    uint32_t eax289;
    void* eax290;
    uint32_t eax291;
    uint32_t eax292;
    uint32_t eax293;
    void* ecx294;
    uint32_t ecx295;
    uint32_t edx296;
    void* esi297;
    void** v298;
    void** ebx299;
    void** v300;
    uint32_t eax301;
    uint32_t eax302;
    uint32_t eax303;
    uint32_t eax304;
    uint32_t eax305;
    uint32_t edx306;
    uint32_t eax307;
    void* edi308;
    uint32_t eax309;
    void* ebx310;
    uint32_t edi311;
    void* eax312;
    uint32_t ebx313;
    uint32_t eax314;
    void* esi315;
    uint32_t eax316;
    uint32_t edx317;
    uint32_t eax318;
    void* ebx319;
    uint32_t eax320;
    void* ebx321;
    uint32_t eax322;
    void* ebx323;
    uint32_t eax324;
    uint32_t eax325;
    uint32_t eax326;
    void* ecx327;
    uint32_t ecx328;
    uint32_t edx329;
    void* edi330;
    void** v331;
    void** v332;
    uint32_t eax333;
    uint32_t eax334;
    void* ebp335;
    uint32_t eax336;
    void* ebx337;
    uint32_t ebp338;
    void* eax339;
    uint32_t ebp340;
    uint32_t eax341;
    uint32_t eax342;
    uint32_t eax343;
    uint32_t eax344;
    uint32_t edx345;
    void** ebp346;
    uint32_t eax347;
    void* eax348;
    void* ecx349;
    uint32_t ecx350;
    uint32_t edx351;
    void* esi352;
    void** v353;
    void** edi354;
    uint32_t eax355;
    uint32_t eax356;
    uint32_t eax357;
    uint32_t edx358;
    uint32_t eax359;
    void* ebp360;
    uint32_t eax361;
    void* ebp362;
    uint32_t eax363;
    void* ebp364;
    uint32_t eax365;
    uint32_t eax366;
    uint32_t eax367;
    void* eax368;
    void* edx369;
    void* eax370;
    void* edx371;
    void* eax372;
    void* edx373;
    void* eax374;
    void* eax375;
    void* eax376;

    v5 = *(uint8_t*)(a1 + 0x125);
    v6 = a2->f4;
    v7 = (void*)static_cast<uint32_t>(*(uint8_t*)(a1 + 0x1f9));
    v8 = (void*)((int32_t)(a2->f11 + 7) >> 3);
    v9 = *(void***)(a1 + 0xe8);
    ebp10 = *(void***)(a1 + 0xec);
    v11 = ebp10;
    v12 = ebp10;
    v13 = (void*)0x7fffffff;
    if (!(v5 & 8) || v5 == 8) {
        addr_0x40e688_2:
        if (v5 != 16) {
            if (!(v5 & 16)) 
                goto addr_0x40ed66_4;
            esi14 = (void*)0;
            ebp15 = v13;
            v16 = v12 + 1;
            v17 = *(void***)(a1 + 0xf0);
            if (*(int8_t*)(a1 + 0x1f8) == 2) 
                goto addr_0x40e83f_6;
        } else {
            esi18 = (void*)0;
            ecx19 = v12 + 1;
            ebx20 = *(void***)(a1 + 0xf0);
            edx21 = ebx20 + 1;
            v22 = ecx19;
            if (0 >= (uint32_t)v8) 
                goto addr_0x40e738_8;
            eax23 = (uint32_t)v8 & 3;
            if ((int32_t)v8 <= (int32_t)0) 
                goto addr_0x40e6ff_10; else 
                goto addr_0x40e6d4_11;
        }
    } else {
        edx24 = (void*)0;
        ebx25 = (void*)0;
        ecx26 = ebp10 + 1;
        v27 = *(int8_t*)(a1 + 0x1f8);
        if (0 >= (uint32_t)v6) 
            goto addr_0x40e4b5_13;
        eax28 = (uint32_t)v6 & 3;
        if ((int32_t)v6 <= (int32_t)0) 
            goto addr_0x40e424_15; else 
            goto addr_0x40e3e5_16;
    }
    addr_0x40ea1e_17:
    edi29 = (void*)0;
    ecx30 = v16;
    edx31 = v17 + 1;
    if (0 >= (uint32_t)v8) 
        goto addr_0x40eb34_18;
    eax32 = (uint32_t)v8 & 3;
    if ((int32_t)v8 > (int32_t)0) {
        if (!eax32) {
            do {
                addr_0x40eac4_21:
                eax33 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx30);
                *(void***)edx31 = *(void***)&eax33;
                if ((int32_t)eax33 <= (int32_t)0x7f) {
                    esi34 = (void*)((uint32_t)esi14 + (uint32_t)eax33);
                } else {
                    esi34 = (void*)((uint32_t)esi14 + 0x100 - (uint32_t)eax33);
                }
                eax35 = (void*)static_cast<uint32_t>((uint8_t)*(void***)(ecx30 + 1));
                *(void***)(edx31 + 1) = *(void***)&eax35;
                if ((int32_t)eax35 <= (int32_t)0x7f) {
                    esi36 = (void*)((uint32_t)esi34 + (uint32_t)eax35);
                } else {
                    esi36 = (void*)((uint32_t)esi34 + 0x100 - (uint32_t)eax35);
                }
                eax37 = (void*)static_cast<uint32_t>(*(uint8_t*)(ecx30 + 2));
                *(uint8_t*)(edx31 + 2) = *(uint8_t*)&eax37;
                if ((int32_t)eax37 <= (int32_t)0x7f) {
                    esi38 = (void*)((uint32_t)esi36 + (uint32_t)eax37);
                } else {
                    esi38 = (void*)((uint32_t)esi36 + 0x100 - (uint32_t)eax37);
                }
                eax39 = (void*)static_cast<uint32_t>(*(uint8_t*)(ecx30 + 3));
                *(uint8_t*)(edx31 + 3) = *(uint8_t*)&eax39;
                if ((int32_t)eax39 <= (int32_t)0x7f) {
                    esi14 = (void*)((uint32_t)esi38 + (uint32_t)eax39);
                } else {
                    esi14 = (void*)((uint32_t)esi38 + 0x100 - (uint32_t)eax39);
                }
                edi29 = (void*)((uint32_t)edi29 + 4);
                ecx30 = ecx30 + 4;
                edx31 = edx31 + 4;
            } while ((uint32_t)edi29 < (uint32_t)v8);
            goto addr_0x40eb34_18;
        } else {
            if ((int32_t)eax32 > (int32_t)1) {
                if ((int32_t)eax32 > (int32_t)2) {
                    eax40 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx30);
                    *(void***)(v17 + 1) = *(void***)&eax40;
                    if ((int32_t)eax40 <= (int32_t)0x7f) {
                        esi14 = eax40;
                    } else {
                        esi14 = (void*)(0x100 - (uint32_t)eax40);
                    }
                    edi29 = (void*)1;
                    ++ecx30;
                    ++edx31;
                }
                eax41 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx30);
                *(void***)edx31 = *(void***)&eax41;
                if ((int32_t)eax41 <= (int32_t)0x7f) {
                    esi14 = (void*)((uint32_t)esi14 + (uint32_t)eax41);
                } else {
                    esi14 = (void*)((uint32_t)esi14 + 0x100 - (uint32_t)eax41);
                }
                edi29 = (void*)((uint32_t)edi29 + 1);
                ++ecx30;
                ++edx31;
            }
        }
    }
    eax42 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx30);
    *(void***)edx31 = *(void***)&eax42;
    if ((int32_t)eax42 <= (int32_t)0x7f) {
        esi14 = (void*)((uint32_t)esi14 + (uint32_t)eax42);
    } else {
        esi14 = (void*)((uint32_t)esi14 + 0x100 - (uint32_t)eax42);
    }
    edi29 = (void*)((uint32_t)edi29 + 1);
    ++ecx30;
    ++edx31;
    if ((uint32_t)edi29 >= (uint32_t)v8) {
        addr_0x40eb34_18:
        eax43 = v16;
        v44 = eax43;
    } else {
        esi14 = esi14;
        goto addr_0x40eac4_21;
    }
    while ((uint32_t)edi29 < (uint32_t)a2->f4) {
        eax43 = (void**)((uint8_t)*(void***)ecx30 - (uint8_t)*(void***)v44);
        *(void***)edx31 = eax43;
        eax43 = (void**)((uint8_t)eax43 & 0xff);
        if ((int8_t)eax43 <= (int8_t)0x7f) {
            esi14 = (void*)((uint32_t)esi14 + (uint8_t)eax43);
        } else {
            esi14 = (void*)((uint32_t)esi14 + 0x100 - (uint8_t)eax43);
        }
        if ((uint32_t)esi14 > (uint32_t)ebp15) 
            break;
        edi29 = (void*)((uint32_t)edi29 + 1);
        ++ecx30;
        ++v44;
        ++edx31;
    }
    if (*(int8_t*)(a1 + 0x1f8) != 2) {
        addr_0x40ed42_56:
        if ((uint32_t)esi14 >= (uint32_t)v13) {
            addr_0x40ed66_4:
            if (v5 != 32) {
                if (!(v5 & 32)) 
                    goto addr_0x40f2e6_58;
                ebp45 = (void*)0;
                v46 = v13;
                v47 = v12 + 1;
                v48 = *(void***)(a1 + 0xf4);
                v49 = v9 + 1;
                if (*(int8_t*)(a1 + 0x1f8) == 2) 
                    goto addr_0x40eeba_60;
            } else {
                edi50 = (void*)0;
                ebp51 = v12 + 1;
                esi52 = *(void***)(a1 + 0xf4);
                edx53 = esi52 + 1;
                ecx54 = v9 + 1;
                if (0 >= (uint32_t)v6) 
                    goto addr_0x40f2d2_62;
                eax55 = (uint32_t)v6 & 3;
                if ((int32_t)v6 <= (int32_t)0) 
                    goto addr_0x40edf9_64; else 
                    goto addr_0x40edb7_65;
            }
        } else {
            v13 = esi14;
            goto addr_0x40ed52_67;
        }
    } else {
        ecx56 = esi14;
        ecx57 = static_cast<uint32_t>(*(uint16_t*)&ecx56);
        edx58 = (uint32_t)esi14 >> 10 & 0x3fffc0;
        esi59 = (void*)0;
        v60 = *(void***)(a1 + 0x20c);
        if ((int32_t)0 >= (int32_t)v7) 
            goto addr_0x40ed15_69;
        edi61 = *(void***)(a1 + 0x1fc);
        eax62 = (uint32_t)v7 & 3;
        if ((int32_t)v7 <= (int32_t)0) 
            goto addr_0x40ec3c_71; else 
            goto addr_0x40ebe0_72;
    }
    addr_0x40f08d_73:
    edi63 = (void*)0;
    eax64 = v47;
    v65 = eax64;
    ecx66 = v48 + 1;
    edx67 = v49;
    while ((uint32_t)edi63 < (uint32_t)v6) {
        eax64 = (void**)((uint8_t)*(void***)v65 - (uint8_t)*(void***)edx67);
        *(void***)ecx66 = eax64;
        eax64 = (void**)((uint8_t)eax64 & 0xff);
        ++edx67;
        ++v65;
        ++ecx66;
        if ((int8_t)eax64 <= (int8_t)0x7f) {
            ebp45 = (void*)((uint32_t)ebp45 + (uint8_t)eax64);
        } else {
            ebp45 = (void*)((uint32_t)ebp45 + 0x100 - (uint8_t)eax64);
        }
        if ((uint32_t)ebp45 > (uint32_t)v46) 
            break;
        edi63 = (void*)((uint32_t)edi63 + 1);
    }
    if (*(int8_t*)(a1 + 0x1f8) != 2) {
        addr_0x40f2c2_81:
        if ((uint32_t)ebp45 >= (uint32_t)v13) {
            addr_0x40f2e6_58:
            if (v5 != 64) {
                if (!(v5 & 64)) {
                    addr_0x40fbda_83:
                    if (v5 != 0x80) {
                        if ((int8_t)v5 >= (int8_t)0) {
                            addr_0x410913_85:
                            fun_410a30(a1, v11);
                            if (!*(uint8_t*)(a1 + 0x1f9)) {
                                addr_0x410a25_86:
                                return;
                            } else {
                                ebx68 = (void*)1;
                                if ((int32_t)1 >= (int32_t)v7) 
                                    goto addr_0x410a0c_88;
                                eax69 = (uint32_t)v7 - 1 & 3;
                                if ((int32_t)v7 > (int32_t)1) 
                                    goto addr_0x410969_90;
                            }
                        } else {
                            edi70 = (void*)0;
                            v71 = v13;
                            v72 = v12 + 1;
                            v73 = v9 + 1;
                            v74 = *(void***)(a1 + 0xfc);
                            if (*(int8_t*)(a1 + 0x1f8) != 2) {
                                addr_0x4101f8_92:
                                v75 = (void*)0;
                                v76 = v72;
                                v77 = v74 + 1;
                                ebp78 = v73;
                                if (0 >= (uint32_t)v8) 
                                    goto addr_0x41044e_93; else 
                                    goto addr_0x41023b_94;
                            } else {
                                ecx79 = v13;
                                ecx80 = static_cast<uint32_t>(*(uint16_t*)&ecx79);
                                edx81 = (uint32_t)v13 >> 10 & 0x3fffc0;
                                esi82 = (void*)0;
                                v83 = *(void***)(a1 + 0x20c);
                                if ((int32_t)0 >= (int32_t)v7) 
                                    goto addr_0x4101bd_96;
                                v84 = *(void***)(a1 + 0x1fc);
                                eax85 = (uint32_t)v7 & 3;
                                if ((int32_t)v7 <= (int32_t)0) 
                                    goto addr_0x4100ba_98; else 
                                    goto addr_0x410056_99;
                            }
                        }
                    } else {
                        v86 = (void*)0;
                        ebp87 = v12 + 1;
                        edx88 = *(void***)(a1 + 0xfc);
                        v89 = edx88 + 1;
                        edi90 = v9 + 1;
                        v91 = ebp87;
                        v92 = edi90;
                        if (0 >= (uint32_t)v8) 
                            goto addr_0x40fd39_101;
                        eax93 = (uint32_t)v8 & 3;
                        if ((uint1_t)((int32_t)v8 < (int32_t)0) | (uint1_t)(v8 == 0)) 
                            goto addr_0x40fcac_103; else 
                            goto addr_0x40fc45_104;
                    }
                } else {
                    esi94 = (void*)0;
                    v95 = v13;
                    v96 = v12 + 1;
                    v97 = v9 + 1;
                    v98 = *(void***)(a1 + 0xf8);
                    if (*(int8_t*)(a1 + 0x1f8) != 2) {
                        addr_0x40f748_106:
                        v99 = (void*)0;
                        ebp100 = v96;
                        ebx101 = v98 + 1;
                        edi102 = v97;
                        if (0 >= (uint32_t)v8) 
                            goto addr_0x40f982_107; else 
                            goto addr_0x40f77d_108;
                    } else {
                        ecx103 = v13;
                        ecx104 = static_cast<uint32_t>(*(uint16_t*)&ecx103);
                        edx105 = (uint32_t)v13 >> 10 & 0x3fffc0;
                        edi106 = (void*)0;
                        v107 = *(void***)(a1 + 0x20c);
                        if ((int32_t)0 >= (int32_t)v7) 
                            goto addr_0x40f70d_110;
                        ebp108 = *(void***)(a1 + 0x1fc);
                        v109 = ebp108;
                        eax110 = (uint32_t)v7 & 3;
                        if ((int32_t)v7 <= (int32_t)0) 
                            goto addr_0x40f60b_112; else 
                            goto addr_0x40f5aa_113;
                    }
                }
            } else {
                ebp111 = (void*)0;
                ecx112 = v12 + 1;
                edx113 = *(void***)(a1 + 0xf8);
                ebx114 = edx113 + 1;
                esi115 = v9 + 1;
                v116 = ecx112;
                if (0 >= (uint32_t)v8) 
                    goto addr_0x40f3e6_115;
                eax117 = (uint32_t)v8 & 3;
                if ((int32_t)v8 <= (int32_t)0) 
                    goto addr_0x40f387_117; else 
                    goto addr_0x40f33e_118;
            }
        } else {
            v13 = ebp45;
            goto addr_0x40f2d2_62;
        }
    } else {
        ecx118 = ebp45;
        ecx119 = static_cast<uint32_t>(*(uint16_t*)&ecx118);
        edx120 = (uint32_t)ebp45 >> 10 & 0x3fffc0;
        esi121 = (void*)0;
        v122 = *(void***)(a1 + 0x208);
        if ((int32_t)0 >= (int32_t)v7) 
            goto addr_0x40f298_121;
        edi123 = *(void***)(a1 + 0x1fc);
        eax124 = (uint32_t)v7 & 3;
        if ((int32_t)v7 <= (int32_t)0) 
            goto addr_0x40f1a7_123; else 
            goto addr_0x40f14b_124;
    }
    addr_0x41099c_125:
    *(int8_t*)((uint32_t)ebx68 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ebx68 + 0xffffffff);
    ebx68 = (void*)((uint32_t)ebx68 + 1);
    if ((int32_t)ebx68 >= (int32_t)v7) {
        addr_0x410a0c_88:
        *(void***)((uint32_t)ebx68 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(void***)v11;
        goto addr_0x410a25_86;
    } else {
        goto addr_0x4109bc_127;
    }
    addr_0x410969_90:
    if (!eax69) {
        do {
            addr_0x4109bc_127:
            *(int8_t*)((uint32_t)ebx68 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ebx68 + 0xffffffff);
            ecx125 = (void*)((uint32_t)ebx68 + 1);
            *(int8_t*)((uint32_t)ecx125 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ecx125 + 0xffffffff);
            ecx126 = (void*)((uint32_t)ebx68 + 2);
            *(int8_t*)((uint32_t)ecx126 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ecx126 - 1);
            ecx127 = (void*)((uint32_t)ebx68 + 3);
            *(int8_t*)((uint32_t)ecx127 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ecx127 - 1);
            ebx68 = (void*)((uint32_t)ebx68 + 4);
        } while ((int32_t)ebx68 < (int32_t)v7);
        goto addr_0x410a0c_88;
    } else {
        if ((int32_t)eax69 > (int32_t)1) {
            if ((int32_t)eax69 > (int32_t)2) {
                *(void***)(*(void***)(a1 + 0x1fc) + 1) = *(void***)*(void***)(a1 + 0x1fc);
                ebx68 = (void*)2;
            }
            *(int8_t*)((uint32_t)ebx68 + (uint8_t)*(void***)(a1 + 0x1fc)) = *(int8_t*)((uint8_t)*(void***)(a1 + 0x1fc) + (uint32_t)ebx68 + 0xffffffff);
            ebx68 = (void*)((uint32_t)ebx68 + 1);
            goto addr_0x41099c_125;
        }
    }
    addr_0x41023b_94:
    eax128 = (void*)((uint32_t)v8 & 3);
    if ((int32_t)v8 > (int32_t)0) {
        if (!eax128) {
            do {
                addr_0x41034c_133:
                *(void***)&eax128 = (void**)((uint8_t)*(void***)v76 - (uint8_t)*(void***)ebp78);
                *(void***)v77 = *(void***)&eax128;
                eax129 = (void*)((uint32_t)eax128 & 0xff);
                if ((int32_t)eax129 <= (int32_t)0x7f) {
                    edi130 = (void*)((uint32_t)edi70 + (uint32_t)eax129);
                } else {
                    edi130 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax129);
                }
                *(void***)&eax129 = (void**)((uint8_t)*(void***)(v76 + 1) - (uint8_t)*(void***)(ebp78 + 1));
                *(void***)(v77 + 1) = *(void***)&eax129;
                eax131 = (void*)((uint32_t)eax129 & 0xff);
                if ((int32_t)eax131 <= (int32_t)0x7f) {
                    edi132 = (void*)((uint32_t)edi130 + (uint32_t)eax131);
                } else {
                    edi132 = (void*)((uint32_t)edi130 + 0x100 - (uint32_t)eax131);
                }
                *(uint8_t*)&eax131 = (uint8_t)(*(uint8_t*)(v76 + 2) - *(uint8_t*)(ebp78 + 2));
                *(uint8_t*)(v77 + 2) = *(uint8_t*)&eax131;
                eax133 = (void*)((uint32_t)eax131 & 0xff);
                if ((int32_t)eax133 <= (int32_t)0x7f) {
                    edi134 = (void*)((uint32_t)edi132 + (uint32_t)eax133);
                } else {
                    edi134 = (void*)((uint32_t)edi132 + 0x100 - (uint32_t)eax133);
                }
                *(uint8_t*)&eax133 = (uint8_t)(*(uint8_t*)(v76 + 3) - *(uint8_t*)(ebp78 + 3));
                *(uint8_t*)(v77 + 3) = *(uint8_t*)&eax133;
                eax128 = (void*)((uint32_t)eax133 & 0xff);
                ebp78 = ebp78 + 4;
                v76 = v76 + 4;
                v77 = v77 + 4;
                if ((int32_t)eax128 <= (int32_t)0x7f) {
                    edi70 = (void*)((uint32_t)edi134 + (uint32_t)eax128);
                } else {
                    edi70 = (void*)((uint32_t)edi134 + 0x100 - (uint32_t)eax128);
                }
                v75 = (void*)((uint32_t)v75 + 4);
            } while ((uint32_t)v75 < (uint32_t)v8);
            goto addr_0x41044e_93;
        } else {
            if ((int32_t)eax128 > (int32_t)1) {
                if ((int32_t)eax128 > (int32_t)2) {
                    *(void***)&eax128 = (void**)((uint8_t)*(void***)v72 - (uint8_t)*(void***)ebp78);
                    *(void***)(v74 + 1) = *(void***)&eax128;
                    eax128 = (void*)((uint32_t)eax128 & 0xff);
                    ++ebp78;
                    ++v76;
                    v77 = v74 + 2;
                    if ((int32_t)eax128 <= (int32_t)0x7f) {
                        edi70 = eax128;
                    } else {
                        edi70 = (void*)(0x100 - (uint32_t)eax128);
                    }
                    v75 = (void*)1;
                }
                *(void***)&eax128 = (void**)((uint8_t)*(void***)v76 - (uint8_t)*(void***)ebp78);
                *(void***)v77 = *(void***)&eax128;
                eax128 = (void*)((uint32_t)eax128 & 0xff);
                ++ebp78;
                ++v76;
                ++v77;
                if ((int32_t)eax128 <= (int32_t)0x7f) {
                    edi70 = (void*)((uint32_t)edi70 + (uint32_t)eax128);
                } else {
                    edi70 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax128);
                }
                v75 = (void*)((uint32_t)v75 + 1);
            }
        }
    }
    *(void***)&eax128 = (void**)((uint8_t)*(void***)v76 - (uint8_t)*(void***)ebp78);
    *(void***)v77 = *(void***)&eax128;
    eax135 = (void*)((uint32_t)eax128 & 0xff);
    ++ebp78;
    ++v76;
    ++v77;
    if ((int32_t)eax135 <= (int32_t)0x7f) {
        edi70 = (void*)((uint32_t)edi70 + (uint32_t)eax135);
    } else {
        edi70 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax135);
    }
    v75 = (void*)((uint32_t)v75 + 1);
    eax128 = v8;
    if ((uint32_t)v75 >= (uint32_t)eax128) {
        addr_0x41044e_93:
        v136 = v72;
        v137 = v73;
        if ((uint32_t)v75 >= (uint32_t)v6) {
            addr_0x41071a_160:
            if (*(int8_t*)(a1 + 0x1f8) != 2) {
                addr_0x4108f6_161:
                if ((uint32_t)edi70 < (uint32_t)v13) {
                    v11 = *(void***)(a1 + 0xfc);
                    goto addr_0x410913_85;
                }
            } else {
                ecx138 = edi70;
                ecx139 = static_cast<uint32_t>(*(uint16_t*)&ecx138);
                edx140 = (uint32_t)edi70 >> 10 & 0x3fffc0;
                esi141 = (void*)0;
                v142 = *(void***)(a1 + 0x208);
                if ((int32_t)0 >= (int32_t)v7) 
                    goto addr_0x4108cb_164;
                edi143 = *(void***)(a1 + 0x1fc);
                eax144 = (uint32_t)v7 & 3;
                if ((int32_t)v7 > (int32_t)0) 
                    goto addr_0x41077f_166;
            }
        } else {
            if ((int32_t)v75 >= (int32_t)v6 || (uint32_t)v6 - (uint32_t)v75 & 1) {
                ebx145 = static_cast<uint32_t>((uint8_t)*(void***)ebp78);
                ++ebp78;
                esi146 = static_cast<uint32_t>((uint8_t)*(void***)v137);
                ++v137;
                edx147 = static_cast<uint32_t>((uint8_t)*(void***)v136);
                ++v136;
                eax148 = ebx145 - esi146;
                edx149 = edx147 - esi146;
                ebx150 = eax148;
                if ((int32_t)eax148 < (int32_t)0) {
                    ebx150 = -ebx150;
                }
                ecx151 = edx149;
                if ((int32_t)ecx151 < (int32_t)0) {
                    ecx151 = -ecx151;
                }
                edx152 = edx149 + eax148;
                if ((int32_t)edx152 < (int32_t)0) {
                    edx152 = -edx152;
                }
                if ((int32_t)ebx150 > (int32_t)ecx151 || (int32_t)ebx150 > (int32_t)edx152) {
                    eax153 = esi146;
                    if ((int32_t)ecx151 <= (int32_t)edx152) {
                        eax153 = ebx145;
                    }
                } else {
                    eax153 = edx147;
                }
                *(void***)&eax153 = (void**)((uint8_t)*(void***)v76 - (uint8_t)*(void***)&eax153);
                *(void***)v77 = *(void***)&eax153;
                eax154 = (void*)(eax153 & 0xff);
                ++v76;
                ++v77;
                if ((int32_t)eax154 <= (int32_t)0x7f) {
                    edi70 = (void*)((uint32_t)edi70 + (uint32_t)eax154);
                } else {
                    edi70 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax154);
                }
                if ((uint32_t)edi70 > (uint32_t)v71) 
                    goto addr_0x41071a_160;
                v75 = (void*)((uint32_t)v75 + 1);
                if ((uint32_t)v75 >= (uint32_t)v6) 
                    goto addr_0x41071a_160; else 
                    goto addr_0x410576_183;
            } else {
                do {
                    addr_0x410578_184:
                    ebx155 = static_cast<uint32_t>((uint8_t)*(void***)ebp78);
                    ebp156 = ebp78 + 1;
                    esi157 = static_cast<uint32_t>((uint8_t)*(void***)v137);
                    edx158 = static_cast<uint32_t>((uint8_t)*(void***)v136);
                    eax159 = ebx155 - esi157;
                    edx160 = edx158 - esi157;
                    ebx161 = eax159;
                    if ((int32_t)eax159 < (int32_t)0) {
                        ebx161 = -ebx161;
                    }
                    ecx162 = edx160;
                    if ((int32_t)ecx162 < (int32_t)0) {
                        ecx162 = -ecx162;
                    }
                    edx163 = edx160 + eax159;
                    if ((int32_t)edx163 < (int32_t)0) {
                        edx163 = -edx163;
                    }
                    if ((int32_t)ebx161 > (int32_t)ecx162 || (int32_t)ebx161 > (int32_t)edx163) {
                        eax164 = esi157;
                        if ((int32_t)ecx162 <= (int32_t)edx163) {
                            eax164 = ebx155;
                        }
                    } else {
                        eax164 = edx158;
                    }
                    *(void***)&eax164 = (void**)((uint8_t)*(void***)v76 - (uint8_t)*(void***)&eax164);
                    *(void***)v77 = *(void***)&eax164;
                    eax165 = (void*)(eax164 & 0xff);
                    if ((int32_t)eax165 <= (int32_t)0x7f) {
                        edi70 = (void*)((uint32_t)edi70 + (uint32_t)eax165);
                    } else {
                        edi70 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax165);
                    }
                    if ((uint32_t)edi70 > (uint32_t)v71) 
                        goto addr_0x41071a_160;
                    ecx166 = static_cast<uint32_t>((uint8_t)*(void***)ebp156);
                    ebp78 = ebp156 + 1;
                    esi167 = static_cast<uint32_t>((uint8_t)*(void***)(v137 + 1));
                    v137 = v137 + 2;
                    v168 = static_cast<uint32_t>((uint8_t)*(void***)(v136 + 1));
                    v136 = v136 + 2;
                    eax169 = ecx166 - esi167;
                    edx170 = v168 - esi167;
                    ebx171 = eax169;
                    if ((int32_t)eax169 < (int32_t)0) {
                        ebx171 = -ebx171;
                    }
                    ecx172 = edx170;
                    if ((int32_t)ecx172 < (int32_t)0) {
                        ecx172 = -ecx172;
                    }
                    edx173 = edx170 + eax169;
                    if ((int32_t)edx173 < (int32_t)0) {
                        edx173 = -edx173;
                    }
                    if ((int32_t)ebx171 > (int32_t)ecx172 || (int32_t)ebx171 > (int32_t)edx173) {
                        eax174 = esi167;
                        if ((int32_t)ecx172 <= (int32_t)edx173) {
                            eax174 = ecx166;
                        }
                    } else {
                        eax174 = v168;
                    }
                    *(void***)&eax174 = (void**)((uint8_t)*(void***)(v76 + 1) - (uint8_t)*(void***)&eax174);
                    *(void***)(v77 + 1) = *(void***)&eax174;
                    eax175 = (void*)(eax174 & 0xff);
                    v76 = v76 + 1 + 1;
                    v77 = v77 + 1 + 1;
                    if ((int32_t)eax175 <= (int32_t)0x7f) {
                        edi70 = (void*)((uint32_t)edi70 + (uint32_t)eax175);
                    } else {
                        edi70 = (void*)((uint32_t)edi70 + 0x100 - (uint32_t)eax175);
                    }
                } while ((uint32_t)edi70 <= (uint32_t)v71 && (v75 = (void*)((uint32_t)v75 + 1 + 1), (uint32_t)v75 < (uint32_t)v6));
                goto addr_0x41071a_160;
            }
        }
    } else {
        goto addr_0x41034c_133;
    }
    addr_0x4107d4_213:
    if (*(int8_t*)((uint32_t)esi141 + (uint8_t)edi143) == 4) {
        eax176 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi141 * 2));
        ecx139 = ecx139 * eax176 >> 8;
        edx140 = edx140 * eax176 >> 8;
    }
    esi177 = (void*)((uint32_t)esi141 + 1);
    if ((int32_t)esi177 >= (int32_t)v7) {
        addr_0x4108cb_164:
        eax178 = static_cast<uint32_t>((uint16_t)*(void***)(v142 + 8));
        edx179 = edx140 * eax178 >> 3;
        if (edx179 <= 0x3fffc0) {
            edi70 = (void*)((ecx139 * eax178 >> 3) + (edx179 << 10));
            goto addr_0x4108f6_161;
        } else {
            edi70 = (void*)0x7fffffff;
            goto addr_0x4108f6_161;
        }
    } else {
        esi141 = esi177;
        goto addr_0x410808_219;
    }
    addr_0x41077f_166:
    if (!eax144) {
        do {
            addr_0x410808_219:
            if (*(int8_t*)((uint32_t)esi141 + (uint8_t)edi143) == 4) {
                eax180 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi141 * 2));
                ecx139 = ecx139 * eax180 >> 8;
                edx140 = edx140 * eax180 >> 8;
            }
            ebp181 = (void*)((uint32_t)esi141 + 1);
            if (*(int8_t*)((uint32_t)ebp181 + (uint8_t)edi143) == 4) {
                eax182 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp181 * 2));
                ecx139 = ecx139 * eax182 >> 8;
                edx140 = edx140 * eax182 >> 8;
            }
            ebp183 = (void*)((uint32_t)esi141 + 2);
            if (*(int8_t*)((uint32_t)ebp183 + (uint8_t)edi143) == 4) {
                eax184 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp183 * 2));
                ecx139 = ecx139 * eax184 >> 8;
                edx140 = edx140 * eax184 >> 8;
            }
            ebp185 = (void*)((uint32_t)esi141 + 3);
            if (*(int8_t*)((uint32_t)ebp185 + (uint8_t)edi143) == 4) {
                eax186 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp185 * 2));
                ecx139 = ecx139 * eax186 >> 8;
                edx140 = edx140 * eax186 >> 8;
            }
            esi141 = (void*)((uint32_t)esi141 + 4);
        } while ((int32_t)esi141 < (int32_t)v7);
        goto addr_0x4108cb_164;
    } else {
        if ((int32_t)eax144 > (int32_t)1) {
            if ((int32_t)eax144 > (int32_t)2) {
                if ((int1_t)(*(void***)edi143 == 4)) {
                    eax187 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x200));
                    ecx139 = ecx139 * eax187 >> 8;
                    edx140 = edx140 * eax187 >> 8;
                }
                esi141 = (void*)1;
            }
            if (*(int8_t*)((uint32_t)esi141 + (uint8_t)edi143) == 4) {
                eax188 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi141 * 2));
                ecx139 = ecx139 * eax188 >> 8;
                edx140 = edx140 * eax188 >> 8;
            }
            esi141 = (void*)((uint32_t)esi141 + 1);
            goto addr_0x4107d4_213;
        }
    }
    addr_0x410576_183:
    goto addr_0x410578_184;
    addr_0x4100ba_98:
    if (*(int8_t*)((uint32_t)esi82 + (uint8_t)v84) == 4) {
        eax189 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi82 * 2));
        ecx80 = ecx80 * eax189 >> 8;
        edx81 = edx81 * eax189 >> 8;
    }
    esi82 = (void*)((uint32_t)esi82 + 1);
    if ((int32_t)esi82 >= (int32_t)v7) {
        addr_0x4101bd_96:
        eax190 = static_cast<uint32_t>((uint16_t)*(void***)(v83 + 8));
        edx191 = edx81 * eax190 >> 3;
        if (edx191 <= 0x3fffc0) {
            v71 = (void*)((edx191 << 10) + (ecx80 * eax190 >> 3));
            goto addr_0x4101f8_92;
        } else {
            v71 = (void*)0x7fffffff;
            goto addr_0x4101f8_92;
        }
    } else {
        goto addr_0x4100f0_241;
    }
    addr_0x410056_99:
    if (!eax85) {
        do {
            addr_0x4100f0_241:
            if (*(int8_t*)((uint32_t)esi82 + (uint8_t)v84) == 4) {
                eax192 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi82 * 2));
                ecx80 = ecx80 * eax192 >> 8;
                edx81 = edx81 * eax192 >> 8;
            }
            ebp193 = (void*)((uint32_t)esi82 + 1);
            if (*(int8_t*)((uint32_t)ebp193 + (uint8_t)v84) == 4) {
                eax194 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebp193 * 2));
                ecx80 = ecx80 * eax194 >> 8;
                edx81 = edx81 * eax194 >> 8;
            }
            ebx195 = (void*)((uint32_t)esi82 + 2);
            if (*(int8_t*)((uint32_t)ebx195 + (uint8_t)v84) == 4) {
                ebp196 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx195 * 2));
                ecx80 = ecx80 * ebp196 >> 8;
                edx81 = edx81 * ebp196 >> 8;
            }
            eax197 = (void*)((uint32_t)esi82 + 3);
            if (*(int8_t*)((uint32_t)eax197 + (uint8_t)v84) == 4) {
                ebp198 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)eax197 * 2));
                ecx80 = ecx80 * ebp198 >> 8;
                edx81 = edx81 * ebp198 >> 8;
            }
            esi82 = (void*)((uint32_t)esi82 + 4);
        } while ((int32_t)esi82 < (int32_t)v7);
        goto addr_0x4101bd_96;
    } else {
        if ((int32_t)eax85 > (int32_t)1) {
            if ((int32_t)eax85 > (int32_t)2) {
                if ((int1_t)(*(void***)v84 == 4)) {
                    eax199 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x204));
                    ecx80 = ecx80 * eax199 >> 8;
                    edx81 = edx81 * eax199 >> 8;
                }
                esi82 = (void*)1;
            }
            if (*(int8_t*)((uint32_t)esi82 + (uint8_t)v84) == 4) {
                eax200 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi82 * 2));
                ecx80 = ecx80 * eax200 >> 8;
                edx81 = edx81 * eax200 >> 8;
            }
            esi82 = (void*)((uint32_t)esi82 + 1);
            goto addr_0x4100ba_98;
        }
    }
    addr_0x40fcac_103:
    *(void***)v89 = (void**)((uint8_t)*(void***)ebp87 - (uint8_t)*(void***)edi90);
    ++edi90;
    ++ebp87;
    ++v89;
    v86 = (void*)((uint32_t)v86 + 1);
    if ((uint32_t)v86 >= (uint32_t)v8) {
        addr_0x40fd39_101:
        v201 = v91;
        v202 = v92;
        if ((uint32_t)v86 >= (uint32_t)v6) {
            addr_0x40ff8e_258:
            v11 = *(void***)(a1 + 0xfc);
            goto addr_0x410913_85;
        } else {
            if ((int32_t)v86 >= (int32_t)v6 || (uint32_t)v6 - (uint32_t)v86 & 1) {
                ebx203 = static_cast<uint32_t>((uint8_t)*(void***)edi90);
                ++edi90;
                esi204 = static_cast<uint32_t>((uint8_t)*(void***)v92);
                v202 = v92 + 1;
                edx205 = static_cast<uint32_t>((uint8_t)*(void***)v91);
                v201 = v91 + 1;
                eax206 = ebx203 - esi204;
                edx207 = edx205 - esi204;
                ebx208 = eax206;
                if ((int32_t)eax206 < (int32_t)0) {
                    ebx208 = -ebx208;
                }
                ecx209 = edx207;
                if ((int32_t)ecx209 < (int32_t)0) {
                    ecx209 = -ecx209;
                }
                edx210 = edx207 + eax206;
                if ((int32_t)edx210 < (int32_t)0) {
                    edx210 = -edx210;
                }
                if ((int32_t)ebx208 > (int32_t)ecx209 || (int32_t)ebx208 > (int32_t)edx210) {
                    eax211 = esi204;
                    if ((int32_t)ecx209 <= (int32_t)edx210) {
                        eax211 = ebx203;
                    }
                } else {
                    eax211 = edx205;
                }
                *(void***)v89 = (void**)((uint8_t)*(void***)ebp87 - *(uint8_t*)&eax211);
                ++ebp87;
                ++v89;
                v86 = (void*)((uint32_t)v86 + 1);
                if ((uint32_t)v86 >= (uint32_t)v6) 
                    goto addr_0x40ff8e_258;
            } else {
                do {
                    addr_0x40fe2c_271:
                    v212 = static_cast<uint32_t>((uint8_t)*(void***)edi90);
                    esi213 = static_cast<uint32_t>((uint8_t)*(void***)v202);
                    v214 = static_cast<uint32_t>((uint8_t)*(void***)v201);
                    eax215 = v212 - esi213;
                    edx216 = v214 - esi213;
                    ebx217 = eax215;
                    if ((int32_t)eax215 < (int32_t)0) {
                        ebx217 = -ebx217;
                    }
                    ecx218 = edx216;
                    if ((int32_t)ecx218 < (int32_t)0) {
                        ecx218 = -ecx218;
                    }
                    edx219 = edx216 + eax215;
                    if ((int32_t)edx219 < (int32_t)0) {
                        edx219 = -edx219;
                    }
                    if ((int32_t)ebx217 > (int32_t)ecx218 || (int32_t)ebx217 > (int32_t)edx219) {
                        eax220 = esi213;
                        if ((int32_t)ecx218 <= (int32_t)edx219) {
                            eax220 = v212;
                        }
                    } else {
                        eax220 = v214;
                    }
                    *(void***)v89 = (void**)((uint8_t)*(void***)ebp87 - *(uint8_t*)&eax220);
                    v221 = static_cast<uint32_t>((uint8_t)*(void***)(edi90 + 1));
                    edi90 = edi90 + 2;
                    esi222 = static_cast<uint32_t>((uint8_t)*(void***)(v202 + 1));
                    v202 = v202 + 2;
                    ebx223 = static_cast<uint32_t>((uint8_t)*(void***)(v201 + 1));
                    v201 = v201 + 2;
                    eax224 = v221 - esi222;
                    edx225 = ebx223 - esi222;
                    ebx226 = eax224;
                    if ((int32_t)eax224 < (int32_t)0) {
                        ebx226 = -ebx226;
                    }
                    ecx227 = edx225;
                    if ((int32_t)ecx227 < (int32_t)0) {
                        ecx227 = -ecx227;
                    }
                    edx228 = edx225 + eax224;
                    if ((int32_t)edx228 < (int32_t)0) {
                        edx228 = -edx228;
                    }
                    if ((int32_t)ebx226 > (int32_t)ecx227 || (int32_t)ebx226 > (int32_t)edx228) {
                        eax229 = esi222;
                        if ((int32_t)ecx227 <= (int32_t)edx228) {
                            eax229 = v221;
                        }
                    } else {
                        eax229 = ebx223;
                    }
                    *(void***)(v89 + 1) = (void**)((uint8_t)*(void***)(ebp87 + 1) - *(uint8_t*)&eax229);
                    ebp87 = ebp87 + 2;
                    v89 = v89 + 2;
                    v86 = (void*)((uint32_t)v86 + 2);
                } while ((uint32_t)v86 < (uint32_t)v6);
                goto addr_0x40ff8e_258;
            }
        }
    } else {
        goto addr_0x40fce0_293;
    }
    goto addr_0x40fe2c_271;
    addr_0x40fc45_104:
    if (!eax93) {
        do {
            addr_0x40fce0_293:
            *(void***)v89 = (void**)((uint8_t)*(void***)ebp87 - (uint8_t)*(void***)edi90);
            *(void***)(v89 + 1) = (void**)((uint8_t)*(void***)(ebp87 + 1) - (uint8_t)*(void***)(edi90 + 1));
            *(uint8_t*)(v89 + 2) = (uint8_t)(*(uint8_t*)(ebp87 + 2) - *(uint8_t*)(edi90 + 2));
            *(uint8_t*)(v89 + 3) = (uint8_t)(*(uint8_t*)(ebp87 + 3) - *(uint8_t*)(edi90 + 3));
            edi90 = edi90 + 4;
            ebp87 = ebp87 + 4;
            v89 = v89 + 4;
            v86 = (void*)((uint32_t)v86 + 4);
        } while ((uint32_t)v86 < (uint32_t)v8);
        goto addr_0x40fd39_101;
    } else {
        if ((int32_t)eax93 > (int32_t)1) {
            if ((int32_t)eax93 > (int32_t)2) {
                *(void***)(edx88 + 1) = (void**)((uint8_t)*(void***)(v12 + 1) - (uint8_t)*(void***)(v9 + 1));
                edi90 = v9 + 2;
                ebp87 = v12 + 2;
                v89 = edx88 + 2;
                v86 = (void*)1;
            }
            *(void***)v89 = (void**)((uint8_t)*(void***)ebp87 - (uint8_t)*(void***)edi90);
            ++edi90;
            ++ebp87;
            ++v89;
            v86 = (void*)((uint32_t)v86 + 1);
            goto addr_0x40fcac_103;
        }
    }
    addr_0x40f77d_108:
    eax230 = (void*)((uint32_t)v8 & 3);
    if ((int32_t)v8 > (int32_t)0) {
        if (!eax230) {
            do {
                addr_0x40f860_300:
                *(void***)&eax230 = (void**)((uint8_t)*(void***)ebp100 - (uint8_t)((uint8_t)*(void***)edi102 >> 1));
                *(void***)ebx101 = *(void***)&eax230;
                eax231 = (void*)((uint32_t)eax230 & 0xff);
                if ((int32_t)eax231 <= (int32_t)0x7f) {
                    esi232 = (void*)((uint32_t)esi94 + (uint32_t)eax231);
                } else {
                    esi232 = (void*)((uint32_t)esi94 + 0x100 - (uint32_t)eax231);
                }
                *(void***)&eax231 = (void**)((uint8_t)*(void***)(ebp100 + 1) - (uint8_t)((uint8_t)*(void***)(edi102 + 1) >> 1));
                *(void***)(ebx101 + 1) = *(void***)&eax231;
                eax233 = (void*)((uint32_t)eax231 & 0xff);
                if ((int32_t)eax233 <= (int32_t)0x7f) {
                    esi234 = (void*)((uint32_t)esi232 + (uint32_t)eax233);
                } else {
                    esi234 = (void*)((uint32_t)esi232 + 0x100 - (uint32_t)eax233);
                }
                *(uint8_t*)&eax233 = (uint8_t)(*(uint8_t*)(ebp100 + 2) - (uint8_t)(*(uint8_t*)(edi102 + 2) >> 1));
                *(uint8_t*)(ebx101 + 2) = *(uint8_t*)&eax233;
                eax235 = (void*)((uint32_t)eax233 & 0xff);
                if ((int32_t)eax235 <= (int32_t)0x7f) {
                    esi236 = (void*)((uint32_t)esi234 + (uint32_t)eax235);
                } else {
                    esi236 = (void*)((uint32_t)esi234 + 0x100 - (uint32_t)eax235);
                }
                *(uint8_t*)&eax235 = (uint8_t)(*(uint8_t*)(ebp100 + 3) - (uint8_t)(*(uint8_t*)(edi102 + 3) >> 1));
                *(uint8_t*)(ebx101 + 3) = *(uint8_t*)&eax235;
                eax230 = (void*)((uint32_t)eax235 & 0xff);
                edi102 = edi102 + 4;
                ebp100 = ebp100 + 4;
                ebx101 = ebx101 + 4;
                if ((int32_t)eax230 <= (int32_t)0x7f) {
                    esi94 = (void*)((uint32_t)esi236 + (uint32_t)eax230);
                } else {
                    esi94 = (void*)((uint32_t)esi236 + 0x100 - (uint32_t)eax230);
                }
                v99 = (void*)((uint32_t)v99 + 4);
            } while ((uint32_t)v99 < (uint32_t)v8);
            goto addr_0x40f982_107;
        } else {
            if ((int32_t)eax230 > (int32_t)1) {
                if ((int32_t)eax230 > (int32_t)2) {
                    *(void***)&eax230 = (void**)((uint8_t)*(void***)ebp100 - (uint8_t)((uint8_t)*(void***)edi102 >> 1));
                    *(void***)(v98 + 1) = *(void***)&eax230;
                    eax230 = (void*)((uint32_t)eax230 & 0xff);
                    edi102 = v97 + 1;
                    ++ebp100;
                    ebx101 = v98 + 2;
                    if ((int32_t)eax230 <= (int32_t)0x7f) {
                        esi94 = eax230;
                    } else {
                        esi94 = (void*)(0x100 - (uint32_t)eax230);
                    }
                    v99 = (void*)1;
                }
                *(void***)&eax230 = (void**)((uint8_t)*(void***)ebp100 - (uint8_t)((uint8_t)*(void***)edi102 >> 1));
                *(void***)ebx101 = *(void***)&eax230;
                eax230 = (void*)((uint32_t)eax230 & 0xff);
                ++edi102;
                ++ebp100;
                ++ebx101;
                if ((int32_t)eax230 <= (int32_t)0x7f) {
                    esi94 = (void*)((uint32_t)esi94 + (uint32_t)eax230);
                } else {
                    esi94 = (void*)((uint32_t)esi94 + 0x100 - (uint32_t)eax230);
                }
                v99 = (void*)((uint32_t)v99 + 1);
            }
        }
    }
    *(void***)&eax230 = (void**)((uint8_t)*(void***)ebp100 - (uint8_t)((uint8_t)*(void***)edi102 >> 1));
    *(void***)ebx101 = *(void***)&eax230;
    eax237 = (void*)((uint32_t)eax230 & 0xff);
    ++edi102;
    ++ebp100;
    ++ebx101;
    if ((int32_t)eax237 <= (int32_t)0x7f) {
        esi94 = (void*)((uint32_t)esi94 + (uint32_t)eax237);
    } else {
        esi94 = (void*)((uint32_t)esi94 + 0x100 - (uint32_t)eax237);
    }
    v99 = (void*)((uint32_t)v99 + 1);
    eax230 = v8;
    if ((uint32_t)v99 >= (uint32_t)eax230) {
        addr_0x40f982_107:
        ecx238 = v96;
    } else {
        esi94 = esi94;
        goto addr_0x40f860_300;
    }
    while ((uint32_t)v99 < (uint32_t)v6) {
        eax239 = (uint32_t)((int32_t)((uint8_t)*(void***)edi102 + (uint8_t)*(void***)ecx238) >> 1);
        *(void***)&eax239 = (void**)((uint8_t)*(void***)ebp100 - (uint8_t)*(void***)&eax239);
        *(void***)ebx101 = *(void***)&eax239;
        eax240 = (void*)(eax239 & 0xff);
        ++ecx238;
        ++edi102;
        ++ebp100;
        ++ebx101;
        if ((int32_t)eax240 <= (int32_t)0x7f) {
            esi94 = (void*)((uint32_t)esi94 + (uint32_t)eax240);
        } else {
            esi94 = (void*)((uint32_t)esi94 + 0x100 - (uint32_t)eax240);
        }
        if ((uint32_t)esi94 > (uint32_t)v95) 
            break;
        v99 = (void*)((uint32_t)v99 + 1);
    }
    if (*(int8_t*)(a1 + 0x1f8) != 2) {
        addr_0x40fbb6_335:
        if ((uint32_t)esi94 < (uint32_t)v13) {
            v13 = esi94;
            v11 = *(void***)(a1 + 0xf8);
            goto addr_0x40fbda_83;
        }
    } else {
        ecx241 = esi94;
        ecx242 = static_cast<uint32_t>(*(uint16_t*)&ecx241);
        edx243 = (uint32_t)esi94 >> 10 & 0x3fffc0;
        esi244 = (void*)0;
        v245 = *(void***)(a1 + 0x208);
        if ((int32_t)0 >= (int32_t)v7) 
            goto addr_0x40fb8b_338;
        edi246 = *(void***)(a1 + 0x1fc);
        eax247 = (uint32_t)v7 & 3;
        if ((int32_t)v7 > (int32_t)0) 
            goto addr_0x40fa40_340;
    }
    addr_0x40fa95_341:
    if (!*(int8_t*)((uint32_t)esi244 + (uint8_t)edi246)) {
        eax248 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi244 * 2));
        ecx242 = ecx242 * eax248 >> 8;
        edx243 = edx243 * eax248 >> 8;
    }
    esi249 = (void*)((uint32_t)esi244 + 1);
    if ((int32_t)esi249 >= (int32_t)v7) {
        addr_0x40fb8b_338:
        eax250 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(v245 + 6));
        edx251 = edx243 * eax250 >> 3;
        if (edx251 <= 0x3fffc0) {
            esi94 = (void*)((ecx242 * eax250 >> 3) + (edx251 << 10));
            goto addr_0x40fbb6_335;
        } else {
            esi94 = (void*)0x7fffffff;
            goto addr_0x40fbb6_335;
        }
    } else {
        esi244 = esi249;
        goto addr_0x40fac8_347;
    }
    addr_0x40fa40_340:
    if (!eax247) {
        do {
            addr_0x40fac8_347:
            if (!*(int8_t*)((uint32_t)esi244 + (uint8_t)edi246)) {
                eax252 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi244 * 2));
                ecx242 = ecx242 * eax252 >> 8;
                edx243 = edx243 * eax252 >> 8;
            }
            ebp253 = (void*)((uint32_t)esi244 + 1);
            if (!*(int8_t*)((uint32_t)ebp253 + (uint8_t)edi246)) {
                eax254 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp253 * 2));
                ecx242 = ecx242 * eax254 >> 8;
                edx243 = edx243 * eax254 >> 8;
            }
            ebp255 = (void*)((uint32_t)esi244 + 2);
            if (!*(int8_t*)((uint32_t)ebp255 + (uint8_t)edi246)) {
                eax256 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp255 * 2));
                ecx242 = ecx242 * eax256 >> 8;
                edx243 = edx243 * eax256 >> 8;
            }
            ebp257 = (void*)((uint32_t)esi244 + 3);
            if (!*(int8_t*)((uint32_t)ebp257 + (uint8_t)edi246)) {
                eax258 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp257 * 2));
                ecx242 = ecx242 * eax258 >> 8;
                edx243 = edx243 * eax258 >> 8;
            }
            esi244 = (void*)((uint32_t)esi244 + 4);
        } while ((int32_t)esi244 < (int32_t)v7);
        goto addr_0x40fb8b_338;
    } else {
        if ((int32_t)eax247 > (int32_t)1) {
            if ((int32_t)eax247 > (int32_t)2) {
                if (!*(void***)edi246) {
                    eax259 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x200));
                    ecx242 = ecx242 * eax259 >> 8;
                    edx243 = edx243 * eax259 >> 8;
                }
                esi244 = (void*)1;
            }
            if (!*(int8_t*)((uint32_t)esi244 + (uint8_t)edi246)) {
                eax260 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi244 * 2));
                ecx242 = ecx242 * eax260 >> 8;
                edx243 = edx243 * eax260 >> 8;
            }
            esi244 = (void*)((uint32_t)esi244 + 1);
            goto addr_0x40fa95_341;
        }
    }
    addr_0x40f60b_112:
    if (*(int8_t*)((uint32_t)edi106 + (uint8_t)v109) == 3) {
        eax261 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi106 * 2));
        ecx104 = ecx104 * eax261 >> 8;
        edx105 = edx105 * eax261 >> 8;
    }
    edi106 = (void*)((uint32_t)edi106 + 1);
    if ((int32_t)edi106 >= (int32_t)v7) {
        addr_0x40f70d_110:
        eax262 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(v107 + 6));
        edx263 = edx105 * eax262 >> 3;
        if (edx263 <= 0x3fffc0) {
            v95 = (void*)((edx263 << 10) + (ecx104 * eax262 >> 3));
            goto addr_0x40f748_106;
        } else {
            v95 = (void*)0x7fffffff;
            goto addr_0x40f748_106;
        }
    } else {
        do {
            addr_0x40f640_368:
            if (*(int8_t*)((uint32_t)edi106 + (uint8_t)v109) == 3) {
                eax264 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi106 * 2));
                ecx104 = ecx104 * eax264 >> 8;
                edx105 = edx105 * eax264 >> 8;
            }
            ebp265 = (void*)((uint32_t)edi106 + 1);
            if (*(int8_t*)((uint32_t)ebp265 + (uint8_t)v109) == 3) {
                eax266 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebp265 * 2));
                ecx104 = ecx104 * eax266 >> 8;
                edx105 = edx105 * eax266 >> 8;
            }
            ebx267 = (void*)((uint32_t)edi106 + 2);
            if (*(int8_t*)((uint32_t)ebx267 + (uint8_t)v109) == 3) {
                ebp268 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx267 * 2));
                ecx104 = ecx104 * ebp268 >> 8;
                edx105 = edx105 * ebp268 >> 8;
            }
            eax269 = (void*)((uint32_t)edi106 + 3);
            if (*(int8_t*)((uint32_t)eax269 + (uint8_t)v109) == 3) {
                ebp270 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)eax269 * 2));
                ecx104 = ecx104 * ebp270 >> 8;
                edx105 = edx105 * ebp270 >> 8;
            }
            edi106 = (void*)((uint32_t)edi106 + 4);
        } while ((int32_t)edi106 < (int32_t)v7);
        goto addr_0x40f70d_110;
    }
    addr_0x40f5aa_113:
    if (!eax110) 
        goto addr_0x40f640_368;
    if ((int32_t)eax110 > (int32_t)1) {
        if ((int32_t)eax110 > (int32_t)2) {
            if ((int1_t)(*(void***)ebp108 == 3)) {
                eax271 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x204));
                ecx104 = ecx104 * eax271 >> 8;
                edx105 = edx105 * eax271 >> 8;
            }
            edi106 = (void*)1;
        }
        if (*(int8_t*)((uint32_t)edi106 + (uint8_t)v109) == 3) {
            eax272 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi106 * 2));
            ecx104 = ecx104 * eax272 >> 8;
            edx105 = edx105 * eax272 >> 8;
        }
        edi106 = (void*)((uint32_t)edi106 + 1);
        goto addr_0x40f60b_112;
    }
    addr_0x40f387_117:
    *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - (uint8_t)((uint8_t)*(void***)esi115 >> 1));
    ++esi115;
    ++ecx112;
    ++ebx114;
    ebp111 = (void*)((uint32_t)ebp111 + 1);
    if ((uint32_t)ebp111 >= (uint32_t)v8) {
        addr_0x40f3e6_115:
        edi273 = v116;
        if ((uint32_t)ebp111 >= (uint32_t)v6) 
            goto addr_0x40f4d0_385;
    } else {
        esi115 = esi115;
        goto addr_0x40f3a0_387;
    }
    eax274 = (uint32_t)v6 - (uint32_t)ebp111 & 3;
    if ((int32_t)ebp111 < (int32_t)v6) {
        if (!eax274) 
            goto addr_0x40f46c_390;
        if ((int32_t)eax274 > (int32_t)1) {
            if ((int32_t)eax274 > (int32_t)2) {
                eax275 = (int32_t)((uint8_t)*(void***)esi115 + (uint8_t)*(void***)edi273) >> 1;
                *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - *(uint8_t*)&eax275);
                edi273 = v116 + 1;
                ++esi115;
                ++ecx112;
                ++ebx114;
                ebp111 = (void*)((uint32_t)ebp111 + 1);
            }
            eax276 = (int32_t)((uint8_t)*(void***)esi115 + (uint8_t)*(void***)edi273) >> 1;
            *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - *(uint8_t*)&eax276);
            ++edi273;
            ++esi115;
            ++ecx112;
            ++ebx114;
            ebp111 = (void*)((uint32_t)ebp111 + 1);
        }
    }
    eax277 = (int32_t)((uint8_t)*(void***)esi115 + (uint8_t)*(void***)edi273) >> 1;
    *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - *(uint8_t*)&eax277);
    ++edi273;
    ++esi115;
    ++ecx112;
    ++ebx114;
    ebp111 = (void*)((uint32_t)ebp111 + 1);
    if ((uint32_t)ebp111 >= (uint32_t)v6) {
        addr_0x40f4d0_385:
        v11 = *(void***)(a1 + 0xf8);
        goto addr_0x40fbda_83;
    } else {
        do {
            addr_0x40f46c_390:
            eax278 = (int32_t)((uint8_t)*(void***)esi115 + (uint8_t)*(void***)edi273) >> 1;
            *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - *(uint8_t*)&eax278);
            eax279 = (int32_t)((uint8_t)*(void***)(esi115 + 1) + (uint8_t)*(void***)(edi273 + 1)) >> 1;
            *(void***)(ebx114 + 1) = (void**)((uint8_t)*(void***)(ecx112 + 1) - *(uint8_t*)&eax279);
            eax280 = (int32_t)(*(uint8_t*)(esi115 + 2) + *(uint8_t*)(edi273 + 2)) >> 1;
            *(uint8_t*)(ebx114 + 2) = (uint8_t)(*(uint8_t*)(ecx112 + 2) - *(int8_t*)&eax280);
            eax281 = (int32_t)(*(uint8_t*)(esi115 + 3) + *(uint8_t*)(edi273 + 3)) >> 1;
            *(uint8_t*)(ebx114 + 3) = (uint8_t)(*(uint8_t*)(ecx112 + 3) - *(int8_t*)&eax281);
            edi273 = edi273 + 4;
            esi115 = esi115 + 4;
            ecx112 = ecx112 + 4;
            ebx114 = ebx114 + 4;
            ebp111 = (void*)((uint32_t)ebp111 + 4);
        } while ((uint32_t)ebp111 < (uint32_t)v6);
        goto addr_0x40f4d0_385;
    }
    addr_0x40f33e_118:
    if (!eax117) {
        do {
            addr_0x40f3a0_387:
            *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - (uint8_t)((uint8_t)*(void***)esi115 >> 1));
            *(void***)(ebx114 + 1) = (void**)((uint8_t)*(void***)(ecx112 + 1) - (uint8_t)((uint8_t)*(void***)(esi115 + 1) >> 1));
            *(uint8_t*)(ebx114 + 2) = (uint8_t)(*(uint8_t*)(ecx112 + 2) - (uint8_t)(*(uint8_t*)(esi115 + 2) >> 1));
            *(uint8_t*)(ebx114 + 3) = (uint8_t)(*(uint8_t*)(ecx112 + 3) - (uint8_t)(*(uint8_t*)(esi115 + 3) >> 1));
            esi115 = esi115 + 4;
            ecx112 = ecx112 + 4;
            ebx114 = ebx114 + 4;
            ebp111 = (void*)((uint32_t)ebp111 + 4);
        } while ((uint32_t)ebp111 < (uint32_t)v8);
        goto addr_0x40f3e6_115;
    } else {
        if ((int32_t)eax117 > (int32_t)1) {
            if ((int32_t)eax117 > (int32_t)2) {
                *(void***)(edx113 + 1) = (void**)((uint8_t)*(void***)(v12 + 1) - (uint8_t)((uint8_t)*(void***)(v9 + 1) >> 1));
                esi115 = v9 + 2;
                ecx112 = v12 + 2;
                ebx114 = edx113 + 2;
                ebp111 = (void*)1;
            }
            *(void***)ebx114 = (void**)((uint8_t)*(void***)ecx112 - (uint8_t)((uint8_t)*(void***)esi115 >> 1));
            ++esi115;
            ++ecx112;
            ++ebx114;
            ebp111 = (void*)((uint32_t)ebp111 + 1);
            goto addr_0x40f387_117;
        }
    }
    addr_0x40f1a7_123:
    if (*(int8_t*)((uint32_t)esi121 + (uint8_t)edi123) == 2) {
        eax282 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi121 * 2));
        ecx119 = ecx119 * eax282 >> 8;
        edx120 = edx120 * eax282 >> 8;
    }
    esi121 = (void*)((uint32_t)esi121 + 1);
    if ((int32_t)esi121 >= (int32_t)v7) {
        addr_0x40f298_121:
        eax283 = static_cast<uint32_t>((uint16_t)*(void***)(v122 + 4));
        edx284 = edx120 * eax283 >> 3;
        if (edx284 <= 0x3fffc0) {
            ebp45 = (void*)((ecx119 * eax283 >> 3) + (edx284 << 10));
            goto addr_0x40f2c2_81;
        } else {
            ebp45 = (void*)0x7fffffff;
            goto addr_0x40f2c2_81;
        }
    } else {
        do {
            addr_0x40f1d8_404:
            if (*(int8_t*)((uint32_t)esi121 + (uint8_t)edi123) == 2) {
                eax285 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi121 * 2));
                ecx119 = ecx119 * eax285 >> 8;
                edx120 = edx120 * eax285 >> 8;
            }
            eax286 = (void*)((uint32_t)esi121 + 1);
            if (*(int8_t*)((uint32_t)eax286 + (uint8_t)edi123) == 2) {
                eax287 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)eax286 * 2));
                ecx119 = ecx119 * eax287 >> 8;
                edx120 = edx120 * eax287 >> 8;
            }
            eax288 = (void*)((uint32_t)esi121 + 2);
            if (*(int8_t*)((uint32_t)eax288 + (uint8_t)edi123) == 2) {
                eax289 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)eax288 * 2));
                ecx119 = ecx119 * eax289 >> 8;
                edx120 = edx120 * eax289 >> 8;
            }
            eax290 = (void*)((uint32_t)esi121 + 3);
            if (*(int8_t*)((uint32_t)eax290 + (uint8_t)edi123) == 2) {
                eax291 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)eax290 * 2));
                ecx119 = ecx119 * eax291 >> 8;
                edx120 = edx120 * eax291 >> 8;
            }
            esi121 = (void*)((uint32_t)esi121 + 4);
        } while ((int32_t)esi121 < (int32_t)v7);
        goto addr_0x40f298_121;
    }
    addr_0x40f14b_124:
    if (!eax124) 
        goto addr_0x40f1d8_404;
    if ((int32_t)eax124 > (int32_t)1) {
        if ((int32_t)eax124 > (int32_t)2) {
            if ((int1_t)(*(void***)edi123 == 2)) {
                eax292 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x200));
                ecx119 = ecx119 * eax292 >> 8;
                edx120 = edx120 * eax292 >> 8;
            }
            esi121 = (void*)1;
        }
        if (*(int8_t*)((uint32_t)esi121 + (uint8_t)edi123) == 2) {
            eax293 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi121 * 2));
            ecx119 = ecx119 * eax293 >> 8;
            edx120 = edx120 * eax293 >> 8;
        }
        esi121 = (void*)((uint32_t)esi121 + 1);
        goto addr_0x40f1a7_123;
    }
    addr_0x40eeba_60:
    ecx294 = v13;
    ecx295 = static_cast<uint32_t>(*(uint16_t*)&ecx294);
    edx296 = (uint32_t)v13 >> 10 & 0x3fffc0;
    esi297 = (void*)0;
    v298 = *(void***)(a1 + 0x20c);
    if ((int32_t)0 >= (int32_t)v7) 
        goto addr_0x40f05a_421;
    ebx299 = *(void***)(a1 + 0x1fc);
    v300 = ebx299;
    eax301 = (uint32_t)v7 & 3;
    if ((int32_t)v7 > (int32_t)0) {
        if (!eax301) 
            goto addr_0x40ef90_424;
        if ((int32_t)eax301 > (int32_t)1) {
            if ((int32_t)eax301 > (int32_t)2) {
                if ((int1_t)(*(void***)ebx299 == 2)) {
                    eax302 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x204));
                    ecx295 = ecx295 * eax302 >> 8;
                    edx296 = edx296 * eax302 >> 8;
                }
                esi297 = (void*)1;
            }
            if (*(int8_t*)((uint32_t)esi297 + (uint8_t)v300) == 2) {
                eax303 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi297 * 2));
                ecx295 = ecx295 * eax303 >> 8;
                edx296 = edx296 * eax303 >> 8;
            }
            esi297 = (void*)((uint32_t)esi297 + 1);
        }
    }
    if (*(int8_t*)((uint32_t)esi297 + (uint8_t)v300) == 2) {
        eax304 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi297 * 2));
        ecx295 = ecx295 * eax304 >> 8;
        edx296 = edx296 * eax304 >> 8;
    }
    esi297 = (void*)((uint32_t)esi297 + 1);
    if ((int32_t)esi297 >= (int32_t)v7) {
        addr_0x40f05a_421:
        eax305 = static_cast<uint32_t>((uint16_t)*(void***)(v298 + 4));
        edx306 = edx296 * eax305 >> 3;
        if (edx306 <= 0x3fffc0) {
            v46 = (void*)((edx306 << 10) + (ecx295 * eax305 >> 3));
            goto addr_0x40f08d_73;
        } else {
            v46 = (void*)0x7fffffff;
            goto addr_0x40f08d_73;
        }
    } else {
        do {
            addr_0x40ef90_424:
            if (*(int8_t*)((uint32_t)esi297 + (uint8_t)v300) == 2) {
                eax307 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi297 * 2));
                ecx295 = ecx295 * eax307 >> 8;
                edx296 = edx296 * eax307 >> 8;
            }
            edi308 = (void*)((uint32_t)esi297 + 1);
            if (*(int8_t*)((uint32_t)edi308 + (uint8_t)v300) == 2) {
                eax309 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi308 * 2));
                ecx295 = ecx295 * eax309 >> 8;
                edx296 = edx296 * eax309 >> 8;
            }
            ebx310 = (void*)((uint32_t)esi297 + 2);
            if (*(int8_t*)((uint32_t)ebx310 + (uint8_t)v300) == 2) {
                edi311 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx310 * 2));
                ecx295 = ecx295 * edi311 >> 8;
                edx296 = edx296 * edi311 >> 8;
            }
            eax312 = (void*)((uint32_t)esi297 + 3);
            if (*(int8_t*)((uint32_t)eax312 + (uint8_t)v300) == 2) {
                ebx313 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)eax312 * 2));
                ecx295 = ecx295 * ebx313 >> 8;
                edx296 = edx296 * ebx313 >> 8;
            }
            esi297 = (void*)((uint32_t)esi297 + 4);
        } while ((int32_t)esi297 < (int32_t)v7);
        goto addr_0x40f05a_421;
    }
    addr_0x40edf9_64:
    *(void***)edx53 = (void**)((uint8_t)*(void***)ebp51 - (uint8_t)*(void***)ecx54);
    edi50 = (void*)((uint32_t)edi50 + 1);
    ++ebp51;
    ++ecx54;
    ++edx53;
    if ((uint32_t)edi50 >= (uint32_t)v6) {
        addr_0x40f2d2_62:
        v11 = *(void***)(a1 + 0xf4);
        goto addr_0x40f2e6_58;
    } else {
        goto addr_0x40ee14_447;
    }
    addr_0x40edb7_65:
    if (!eax55) {
        do {
            addr_0x40ee14_447:
            *(void***)edx53 = (void**)((uint8_t)*(void***)ebp51 - (uint8_t)*(void***)ecx54);
            *(void***)(edx53 + 1) = (void**)((uint8_t)*(void***)(ebp51 + 1) - (uint8_t)*(void***)(ecx54 + 1));
            *(uint8_t*)(edx53 + 2) = (uint8_t)(*(uint8_t*)(ebp51 + 2) - *(uint8_t*)(ecx54 + 2));
            *(uint8_t*)(edx53 + 3) = (uint8_t)(*(uint8_t*)(ebp51 + 3) - *(uint8_t*)(ecx54 + 3));
            edi50 = (void*)((uint32_t)edi50 + 4);
            ebp51 = ebp51 + 4;
            ecx54 = ecx54 + 4;
            edx53 = edx53 + 4;
        } while ((uint32_t)edi50 < (uint32_t)v6);
    } else {
        if ((int32_t)eax55 > (int32_t)1) {
            if ((int32_t)eax55 > (int32_t)2) {
                *(void***)(esi52 + 1) = (void**)((uint8_t)*(void***)(v12 + 1) - (uint8_t)*(void***)(v9 + 1));
                edi50 = (void*)1;
                ebp51 = v12 + 2;
                ecx54 = v9 + 2;
                edx53 = esi52 + 2;
            }
            *(void***)edx53 = (void**)((uint8_t)*(void***)ebp51 - (uint8_t)*(void***)ecx54);
            edi50 = (void*)((uint32_t)edi50 + 1);
            ++ebp51;
            ++ecx54;
            ++edx53;
            goto addr_0x40edf9_64;
        }
    }
    goto addr_0x40f2d2_62;
    addr_0x40ec3c_71:
    if (*(int8_t*)((uint32_t)esi59 + (uint8_t)edi61) == 1) {
        eax314 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi59 * 2));
        ecx57 = ecx57 * eax314 >> 8;
        edx58 = edx58 * eax314 >> 8;
    }
    esi315 = (void*)((uint32_t)esi59 + 1);
    if ((int32_t)esi315 >= (int32_t)v7) {
        addr_0x40ed15_69:
        eax316 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(v60 + 2));
        edx317 = edx58 * eax316 >> 3;
        if (edx317 <= 0x3fffc0) {
            esi14 = (void*)((ecx57 * eax316 >> 3) + (edx317 << 10));
            goto addr_0x40ed42_56;
        } else {
            esi14 = (void*)0x7fffffff;
            goto addr_0x40ed42_56;
        }
    } else {
        esi59 = esi315;
        goto addr_0x40ec70_458;
    }
    addr_0x40ebe0_72:
    if (!eax62) {
        do {
            addr_0x40ec70_458:
            if (*(int8_t*)((uint32_t)esi59 + (uint8_t)edi61) == 1) {
                eax318 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi59 * 2));
                ecx57 = ecx57 * eax318 >> 8;
                edx58 = edx58 * eax318 >> 8;
            }
            ebx319 = (void*)((uint32_t)esi59 + 1);
            if (*(int8_t*)((uint32_t)ebx319 + (uint8_t)edi61) == 1) {
                eax320 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx319 * 2));
                ecx57 = ecx57 * eax320 >> 8;
                edx58 = edx58 * eax320 >> 8;
            }
            ebx321 = (void*)((uint32_t)esi59 + 2);
            if (*(int8_t*)((uint32_t)ebx321 + (uint8_t)edi61) == 1) {
                eax322 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx321 * 2));
                ecx57 = ecx57 * eax322 >> 8;
                edx58 = edx58 * eax322 >> 8;
            }
            ebx323 = (void*)((uint32_t)esi59 + 3);
            if (*(int8_t*)((uint32_t)ebx323 + (uint8_t)edi61) == 1) {
                eax324 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx323 * 2));
                ecx57 = ecx57 * eax324 >> 8;
                edx58 = edx58 * eax324 >> 8;
            }
            esi59 = (void*)((uint32_t)esi59 + 4);
        } while ((int32_t)esi59 < (int32_t)v7);
        goto addr_0x40ed15_69;
    } else {
        if ((int32_t)eax62 > (int32_t)1) {
            if ((int32_t)eax62 > (int32_t)2) {
                if ((int1_t)(*(void***)edi61 == 1)) {
                    eax325 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x204));
                    ecx57 = ecx57 * eax325 >> 8;
                    edx58 = edx58 * eax325 >> 8;
                }
                esi59 = (void*)1;
            }
            if (*(int8_t*)((uint32_t)esi59 + (uint8_t)edi61) == 1) {
                eax326 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)esi59 * 2));
                ecx57 = ecx57 * eax326 >> 8;
                edx58 = edx58 * eax326 >> 8;
            }
            esi59 = (void*)((uint32_t)esi59 + 1);
            goto addr_0x40ec3c_71;
        }
    }
    addr_0x40e83f_6:
    ecx327 = ebp15;
    ecx328 = static_cast<uint32_t>(*(uint16_t*)&ecx327);
    edx329 = (uint32_t)ebp15 >> 10 & 0x3fffc0;
    edi330 = (void*)0;
    v331 = *(void***)(a1 + 0x20c);
    if ((int32_t)0 >= (int32_t)v7) 
        goto addr_0x40e9f1_475;
    v332 = *(void***)(a1 + 0x1fc);
    eax333 = (uint32_t)v7 & 3;
    if ((int32_t)v7 > (int32_t)0) {
        if (!eax333) {
            do {
                addr_0x40e924_478:
                if (*(int8_t*)((uint32_t)edi330 + (uint8_t)v332) == 1) {
                    eax334 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi330 * 2));
                    ecx328 = ecx328 * eax334 >> 8;
                    edx329 = edx329 * eax334 >> 8;
                }
                ebp335 = (void*)((uint32_t)edi330 + 1);
                if (*(int8_t*)((uint32_t)ebp335 + (uint8_t)v332) == 1) {
                    eax336 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebp335 * 2));
                    ecx328 = ecx328 * eax336 >> 8;
                    edx329 = edx329 * eax336 >> 8;
                }
                ebx337 = (void*)((uint32_t)edi330 + 2);
                if (*(int8_t*)((uint32_t)ebx337 + (uint8_t)v332) == 1) {
                    ebp338 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)ebx337 * 2));
                    ecx328 = ecx328 * ebp338 >> 8;
                    edx329 = edx329 * ebp338 >> 8;
                }
                eax339 = (void*)((uint32_t)edi330 + 3);
                if (*(int8_t*)((uint32_t)eax339 + (uint8_t)v332) == 1) {
                    ebp340 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)eax339 * 2));
                    ecx328 = ecx328 * ebp340 >> 8;
                    edx329 = edx329 * ebp340 >> 8;
                }
                edi330 = (void*)((uint32_t)edi330 + 4);
            } while ((int32_t)edi330 < (int32_t)v7);
            goto addr_0x40e9f1_475;
        } else {
            if ((int32_t)eax333 > (int32_t)1) {
                if ((int32_t)eax333 > (int32_t)2) {
                    if ((int1_t)(*(void***)v332 == 1)) {
                        eax341 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x204));
                        ecx328 = ecx328 * eax341 >> 8;
                        edx329 = edx329 * eax341 >> 8;
                    }
                    edi330 = (void*)1;
                }
                if (*(int8_t*)((uint32_t)edi330 + (uint8_t)v332) == 1) {
                    eax342 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi330 * 2));
                    ecx328 = ecx328 * eax342 >> 8;
                    edx329 = edx329 * eax342 >> 8;
                }
                edi330 = (void*)((uint32_t)edi330 + 1);
            }
        }
    }
    if (*(int8_t*)((uint32_t)edi330 + (uint8_t)v332) == 1) {
        eax343 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x204) + (uint32_t)edi330 * 2));
        ecx328 = ecx328 * eax343 >> 8;
        edx329 = edx329 * eax343 >> 8;
    }
    edi330 = (void*)((uint32_t)edi330 + 1);
    if ((int32_t)edi330 >= (int32_t)v7) {
        addr_0x40e9f1_475:
        eax344 = static_cast<uint32_t>((uint16_t)*(uint8_t*)(v331 + 2));
        edx345 = edx329 * eax344 >> 3;
        if (edx345 <= 0x3fffc0) {
            ebp15 = (void*)((ecx328 * eax344 >> 3) + (edx345 << 10));
            goto addr_0x40ea1e_17;
        } else {
            ebp15 = (void*)0x7fffffff;
            goto addr_0x40ea1e_17;
        }
    } else {
        esi14 = (void*)0;
        goto addr_0x40e924_478;
    }
    addr_0x40e6ff_10:
    *(void***)edx21 = *(void***)ecx19;
    esi18 = (void*)((uint32_t)esi18 + 1);
    ++ecx19;
    ++edx21;
    if ((uint32_t)esi18 >= (uint32_t)v8) {
        addr_0x40e738_8:
        ebp346 = v22;
        if ((uint32_t)esi18 >= (uint32_t)v6) 
            goto addr_0x40ed52_67;
    } else {
        goto addr_0x40e710_502;
    }
    eax347 = (uint32_t)v6 - (uint32_t)esi18 & 3;
    if ((int32_t)esi18 >= (int32_t)v6) {
        addr_0x40e791_504:
        *(void***)edx21 = (void**)((uint8_t)*(void***)ecx19 - (uint8_t)*(void***)ebp346);
        esi18 = (void*)((uint32_t)esi18 + 1);
        ++ecx19;
        ++ebp346;
        ++edx21;
        if ((uint32_t)esi18 >= (uint32_t)v6) {
            addr_0x40ed52_67:
            v11 = *(void***)(a1 + 0xf0);
            goto addr_0x40ed66_4;
        } else {
            goto addr_0x40e7ac_506;
        }
    } else {
        if (!eax347) {
            do {
                addr_0x40e7ac_506:
                *(void***)edx21 = (void**)((uint8_t)*(void***)ecx19 - (uint8_t)*(void***)ebp346);
                *(void***)(edx21 + 1) = (void**)((uint8_t)*(void***)(ecx19 + 1) - (uint8_t)*(void***)(ebp346 + 1));
                *(uint8_t*)(edx21 + 2) = (uint8_t)(*(uint8_t*)(ecx19 + 2) - *(uint8_t*)(ebp346 + 2));
                *(uint8_t*)(edx21 + 3) = (uint8_t)(*(uint8_t*)(ecx19 + 3) - *(uint8_t*)(ebp346 + 3));
                esi18 = (void*)((uint32_t)esi18 + 4);
                ecx19 = ecx19 + 4;
                ebp346 = ebp346 + 4;
                edx21 = edx21 + 4;
            } while ((uint32_t)esi18 < (uint32_t)v6);
        } else {
            if ((int32_t)eax347 > (int32_t)1) {
                if ((int32_t)eax347 > (int32_t)2) {
                    *(void***)edx21 = (void**)((uint8_t)*(void***)ecx19 - (uint8_t)*(void***)ebp346);
                    esi18 = (void*)((uint32_t)esi18 + 1);
                    ++ecx19;
                    ebp346 = v22 + 1;
                    ++edx21;
                }
                *(void***)edx21 = (void**)((uint8_t)*(void***)ecx19 - (uint8_t)*(void***)ebp346);
                esi18 = (void*)((uint32_t)esi18 + 1);
                ++ecx19;
                ++ebp346;
                ++edx21;
                goto addr_0x40e791_504;
            }
        }
    }
    goto addr_0x40ed52_67;
    addr_0x40e6d4_11:
    if (!eax23) {
        do {
            addr_0x40e710_502:
            *(void***)edx21 = *(void***)ecx19;
            *(void***)(edx21 + 1) = *(void***)(ecx19 + 1);
            *(uint8_t*)(edx21 + 2) = *(uint8_t*)(ecx19 + 2);
            *(uint8_t*)(edx21 + 3) = *(uint8_t*)(ecx19 + 3);
            esi18 = (void*)((uint32_t)esi18 + 4);
            ecx19 = ecx19 + 4;
            edx21 = edx21 + 4;
        } while ((uint32_t)esi18 < (uint32_t)v8);
        goto addr_0x40e738_8;
    } else {
        if ((int32_t)eax23 > (int32_t)1) {
            if ((int32_t)eax23 > (int32_t)2) {
                *(void***)(ebx20 + 1) = *(void***)(v12 + 1);
                esi18 = (void*)1;
                ecx19 = v12 + 2;
                edx21 = ebx20 + 2;
            }
            *(void***)edx21 = *(void***)ecx19;
            esi18 = (void*)((uint32_t)esi18 + 1);
            ++ecx19;
            ++edx21;
            goto addr_0x40e6ff_10;
        }
    }
    addr_0x40e424_15:
    eax348 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx26);
    if ((int32_t)eax348 <= (int32_t)0x7f) {
        edx24 = (void*)((uint32_t)edx24 + (uint32_t)eax348);
    } else {
        edx24 = (void*)((uint32_t)edx24 + 0x100 - (uint32_t)eax348);
    }
    ebx25 = (void*)((uint32_t)ebx25 + 1);
    ++ecx26;
    if ((uint32_t)ebx25 >= (uint32_t)v6) {
        addr_0x40e4b5_13:
        if (v27 != 2) {
            addr_0x40e681_520:
            v13 = edx24;
            goto addr_0x40e688_2;
        } else {
            ecx349 = edx24;
            ecx350 = static_cast<uint32_t>(*(uint16_t*)&ecx349);
            edx351 = (uint32_t)edx24 >> 10 & 0x3fffc0;
            esi352 = (void*)0;
            v353 = *(void***)(a1 + 0x208);
            if ((int32_t)0 >= (int32_t)v7) 
                goto addr_0x40e657_522;
            edi354 = *(void***)(a1 + 0x1fc);
            eax355 = (uint32_t)v7 & 3;
            if ((int32_t)v7 > (int32_t)0) 
                goto addr_0x40e512_524;
        }
    } else {
        goto addr_0x40e448_526;
    }
    addr_0x40e563_527:
    if (!*(int8_t*)((uint32_t)esi352 + (uint8_t)edi354)) {
        eax356 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi352 * 2));
        ecx350 = ecx350 * eax356 >> 8;
        edx351 = edx351 * eax356 >> 8;
    }
    esi352 = (void*)((uint32_t)esi352 + 1);
    if ((int32_t)esi352 >= (int32_t)v7) {
        addr_0x40e657_522:
        eax357 = static_cast<uint32_t>((uint16_t)*(void***)v353);
        edx358 = edx351 * eax357 >> 3;
        if (edx358 <= 0x3fffc0) {
            edx24 = (void*)((edx358 << 10) + (ecx350 * eax357 >> 3));
            goto addr_0x40e681_520;
        } else {
            edx24 = (void*)0x7fffffff;
            goto addr_0x40e681_520;
        }
    } else {
        do {
            addr_0x40e594_532:
            if (!*(int8_t*)((uint32_t)esi352 + (uint8_t)edi354)) {
                eax359 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi352 * 2));
                ecx350 = ecx350 * eax359 >> 8;
                edx351 = edx351 * eax359 >> 8;
            }
            ebp360 = (void*)((uint32_t)esi352 + 1);
            if (!*(int8_t*)((uint32_t)ebp360 + (uint8_t)edi354)) {
                eax361 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp360 * 2));
                ecx350 = ecx350 * eax361 >> 8;
                edx351 = edx351 * eax361 >> 8;
            }
            ebp362 = (void*)((uint32_t)esi352 + 2);
            if (!*(int8_t*)((uint32_t)ebp362 + (uint8_t)edi354)) {
                eax363 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp362 * 2));
                ecx350 = ecx350 * eax363 >> 8;
                edx351 = edx351 * eax363 >> 8;
            }
            ebp364 = (void*)((uint32_t)esi352 + 3);
            if (!*(int8_t*)((uint32_t)ebp364 + (uint8_t)edi354)) {
                eax365 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)ebp364 * 2));
                ecx350 = ecx350 * eax365 >> 8;
                edx351 = edx351 * eax365 >> 8;
            }
            esi352 = (void*)((uint32_t)esi352 + 4);
        } while ((int32_t)esi352 < (int32_t)v7);
        goto addr_0x40e657_522;
    }
    addr_0x40e512_524:
    if (!eax355) 
        goto addr_0x40e594_532;
    if ((int32_t)eax355 > (int32_t)1) {
        if ((int32_t)eax355 > (int32_t)2) {
            if (!*(void***)edi354) {
                eax366 = static_cast<uint32_t>((uint16_t)*(void***)*(void***)(a1 + 0x200));
                ecx350 = ecx350 * eax366 >> 8;
                edx351 = edx351 * eax366 >> 8;
            }
            esi352 = (void*)1;
        }
        if (!*(int8_t*)((uint32_t)esi352 + (uint8_t)edi354)) {
            eax367 = static_cast<uint32_t>((uint16_t)*(void***)(*(void***)(a1 + 0x200) + (uint32_t)esi352 * 2));
            ecx350 = ecx350 * eax367 >> 8;
            edx351 = edx351 * eax367 >> 8;
        }
        esi352 = (void*)((uint32_t)esi352 + 1);
        goto addr_0x40e563_527;
    }
    addr_0x40e3e5_16:
    if (!eax28) {
        do {
            addr_0x40e448_526:
            eax368 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx26);
            if ((int32_t)eax368 <= (int32_t)0x7f) {
                edx369 = (void*)((uint32_t)edx24 + (uint32_t)eax368);
            } else {
                edx369 = (void*)((uint32_t)edx24 + 0x100 - (uint32_t)eax368);
            }
            eax370 = (void*)static_cast<uint32_t>((uint8_t)*(void***)(ecx26 + 1));
            if ((int32_t)eax370 <= (int32_t)0x7f) {
                edx371 = (void*)((uint32_t)edx369 + (uint32_t)eax370);
            } else {
                edx371 = (void*)((uint32_t)edx369 + 0x100 - (uint32_t)eax370);
            }
            eax372 = (void*)static_cast<uint32_t>(*(uint8_t*)(ecx26 + 2));
            if ((int32_t)eax372 <= (int32_t)0x7f) {
                edx373 = (void*)((uint32_t)edx371 + (uint32_t)eax372);
            } else {
                edx373 = (void*)((uint32_t)edx371 + 0x100 - (uint32_t)eax372);
            }
            eax374 = (void*)static_cast<uint32_t>(*(uint8_t*)(ecx26 + 3));
            if ((int32_t)eax374 <= (int32_t)0x7f) {
                edx24 = (void*)((uint32_t)edx373 + (uint32_t)eax374);
            } else {
                edx24 = (void*)((uint32_t)edx373 + 0x100 - (uint32_t)eax374);
            }
            ebx25 = (void*)((uint32_t)ebx25 + 4);
            ecx26 = ecx26 + 4;
        } while ((uint32_t)ebx25 < (uint32_t)v6);
        goto addr_0x40e4b5_13;
    } else {
        if ((int32_t)eax28 > (int32_t)1) {
            if ((int32_t)eax28 > (int32_t)2) {
                eax375 = (void*)static_cast<uint32_t>((uint8_t)*(void***)(ebp10 + 1));
                if ((int32_t)eax375 <= (int32_t)0x7f) {
                    edx24 = eax375;
                } else {
                    edx24 = (void*)(0x100 - (uint32_t)eax375);
                }
                ebx25 = (void*)1;
                ++ecx26;
            }
            eax376 = (void*)static_cast<uint32_t>((uint8_t)*(void***)ecx26);
            if ((int32_t)eax376 <= (int32_t)0x7f) {
                edx24 = (void*)((uint32_t)edx24 + (uint32_t)eax376);
            } else {
                edx24 = (void*)((uint32_t)edx24 + 0x100 - (uint32_t)eax376);
            }
            ebx25 = (void*)((uint32_t)ebx25 + 1);
            ++ecx26;
            goto addr_0x40e424_15;
        }
    }
}

void fun_40ab30(void** a1, void** a2, void** a3) {
    int32_t eax4;

    eax4 = *(int32_t*)(a1 + 0x14c);
    if (eax4) {
        eax4(a1);
    }
    return;
}

uint32_t fun_409bc0(void** a1) {
    void** edi2;
    void** v3;
    void** v4;
    void** edx5;
    void** v6;
    void** ecx7;
    void** v8;
    void** v9;
    void** v10;
    void** edx11;
    void** v12;
    int32_t eax13;

    if (!a1 || (!*(void***)(a1 + 28) || (edi2 = *(void***)(*(void***)(a1 + 28) + 4), edi2 != 42) && (edi2 != 0x71 && !(int1_t)(edi2 == 0x29a)))) {
        return 0xfffffffe;
    } else {
        if (*(void***)(*(void***)(a1 + 28) + 8)) {
            v3 = *(void***)(*(void***)(a1 + 28) + 8);
            v4 = *(void***)(a1 + 40);
            *(void***)(a1 + 36)(v4, v3);
        }
        if (*(void***)(*(void***)(a1 + 28) + 60)) {
            edx5 = *(void***)(a1 + 40);
            v6 = *(void***)(*(void***)(a1 + 28) + 60);
            *(void***)(a1 + 36)(edx5, v6);
        }
        if (*(void***)(*(void***)(a1 + 28) + 56)) {
            ecx7 = *(void***)(a1 + 40);
            v8 = *(void***)(*(void***)(a1 + 28) + 56);
            *(void***)(a1 + 36)(ecx7, v8);
        }
        if (*(void***)(*(void***)(a1 + 28) + 48)) {
            v9 = *(void***)(*(void***)(a1 + 28) + 48);
            v10 = *(void***)(a1 + 40);
            *(void***)(a1 + 36)(v10, v9);
        }
        edx11 = *(void***)(a1 + 40);
        v12 = *(void***)(a1 + 28);
        *(void***)(a1 + 36)(edx11, v12);
        eax13 = 0;
        *(uint8_t*)&eax13 = static_cast<uint8_t>((uint1_t)!(int1_t)(edi2 == 0x71));
        *(void***)(a1 + 28) = (void**)0;
        return (uint32_t)(eax13 - 1) & 0xfffffffd;
    }
}

struct s68 {
    int8_t[4221504] pad4221504;
    int8_t f4221504;
};

void fun_404de4(void*** a1, void** a2, uint32_t a3) {
    void** v4;
    void** ebp5;
    void** v6;
    void** edi7;
    void** v8;
    void** esi9;
    void** v10;
    void** ebx11;
    void*** ebp12;
    void** v13;
    struct s68* edx14;
    void** esi15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    int32_t ecx23;
    void** eax24;
    void** edi25;
    int32_t ecx26;
    void** v27;
    void** v28;
    void** edi29;
    int32_t ecx30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void** v37;
    void** v38;
    void** eax39;
    void** v40;
    void** v41;

    v4 = ebp5;
    v6 = edi7;
    v8 = esi9;
    v10 = ebx11;
    ebp12 = a1;
    v13 = *ebp12;
    edx14 = (struct s68*)0;
    esi15 = a2;
    do {
        if (*(int8_t*)((int32_t)edx14 + (uint8_t)esi15) != *(int8_t*)((int32_t)edx14 + (int32_t)"1.2.1")) 
            break;
        edx14 = (struct s68*)((int32_t)edx14 + 1);
    } while (*(int8_t*)((int32_t)edx14 + (uint8_t)esi15));
    goto addr_0x404e35_4;
    *(void**)(v13 + 68) = (void*)0;
    fun_40850c(v13, 0x4035e0, v16, v17, v10, v8, v6, v4, v18, v19, v20, v13, v21, v22);
    addr_0x404e35_4:
    ecx23 = 16;
    while (ecx23) {
        --ecx23;
    }
    if (a3 <= 0x253) {
        fun_402a90(v13, 0x4035e0);
        eax24 = fun_402a74(1);
        v13 = eax24;
        *ebp12 = eax24;
    }
    edi25 = v13;
    ecx26 = 0x95;
    while (ecx26) {
        --ecx26;
        *(void***)edi25 = (void**)0;
        edi25 = edi25 + 4;
    }
    v27 = v13;
    fun_407808(v27, 0x4035e0, v28);
    edi29 = v13;
    ecx30 = 16;
    while (ecx30) {
        --ecx30;
        *(void***)edi29 = v31;
        edi29 = edi29 + 4;
    }
    fun_40aa88(v13, 0, 0, 0, v27, 0x4035e0, v32, v33);
    *(void***)(v13 + 0xb0) = (void**)0x2000;
    eax39 = fun_402940(v13, 0x2000, v34, v35, v10, v8, v6, v4, v36, v37, v38, v13);
    *(void***)(v13 + 0xac) = eax39;
    fun_403eb8(v13, 0, 1, 0, 0, 0, 0, 0x404ece, v13, 0x2000, v40, v41, v10);
    return;
}

uint32_t translate_byte_v1(void** a1) {
    uint8_t al2;
    uint32_t eax3;
    void* eax4;
    uint32_t ecx5;
    uint32_t edx6;
    uint32_t edi7;
    void* ebp8;
    uint32_t eax9;
    uint32_t ecx10;
    uint32_t eax11;
    uint32_t ebx12;
    int32_t edi13;
    uint32_t edi14;
    uint32_t eax15;
    uint32_t eax16;
    uint32_t eax17;
    void* ecx18;
    uint32_t edx19;
    uint32_t edi20;
    uint32_t edx21;
    uint32_t eax22;
    uint32_t eax23;
    uint32_t eax24;
    void* eax25;
    uint32_t ecx26;
    uint32_t ecx27;
    uint32_t eax28;
    int1_t zf29;
    uint32_t edx30;

    al2 = *(uint8_t*)(a1 + 10);
    if (1 & al2) {
        eax3 = fun_407d40(a1, 1);
        if (!*(int16_t*)&eax3) {
            eax4 = (void*)0;
            ecx5 = 0;
            *(uint8_t*)&eax4 = *(uint8_t*)(a1 + 10);
            edx6 = 0;
            *(int8_t*)&ecx5 = *(int8_t*)((int32_t)eax4 + (uint8_t)a1 + 0x2b22);
            edi7 = ecx5;
            ebp8 = (void*)(edi7 & 0xffff);
            *(int8_t*)&edx6 = *(int8_t*)((uint8_t)a1 + (uint32_t)ebp8 + 0x30e2);
            eax9 = fun_407d40(a1, edx6);
            if (!*(int16_t*)&eax9) {
                ecx10 = 0;
                *(uint8_t*)&ecx10 = *(uint8_t*)((uint8_t)a1 + (uint32_t)ebp8 + 0x30f2);
                if (ecx10) {
                    eax11 = 0;
                    *(uint8_t*)&eax11 = *(uint8_t*)(a1 + 10);
                    ebx12 = (uint32_t)((1 << *(uint8_t*)&ecx10) - 1) & eax11;
                    eax9 = fun_407d40(a1, ecx10);
                    if (!*(int16_t*)&eax9 || (ebx12 & 0xffff) + (uint32_t)ebp8 == 0x10e) {
                        edi13 = 0;
                        *(int16_t*)&edi13 = *(int16_t*)((uint32_t)(a1 + (uint32_t)ebp8 * 2) + 0x3102);
                        edi7 = edi13 + ebx12;
                    } else {
                        *(int16_t*)&eax9 = 0x306;
                        return eax9;
                    }
                }
                edi14 = edi7 + 0x100;
                *(int16_t*)&eax9 = *(int16_t*)&edi14;
                return eax9;
            } else {
                *(int16_t*)&eax9 = 0x306;
                return eax9;
            }
        } else {
            *(int16_t*)&eax3 = 0x306;
            return eax3;
        }
    }
    eax15 = fun_407d40(a1, 1);
    if (*(int16_t*)&eax15) {
        *(int16_t*)&eax15 = 0x306;
        return eax15;
    }
    if (!*(uint8_t*)(a1 + 2)) 
        goto addr_0x407bb2_14;
    eax16 = 0;
    *(uint8_t*)&eax16 = *(uint8_t*)(a1 + 10);
    if (!*(uint8_t*)&eax16) {
        eax17 = fun_407d40(a1, 8);
        if (!*(int16_t*)&eax17) {
            ecx18 = (void*)0;
            edx19 = 0;
            *(uint8_t*)&ecx18 = *(uint8_t*)(a1 + 10);
            *(int8_t*)&edx19 = *(int8_t*)((int32_t)ecx18 + (uint8_t)a1 + 0x2ea2);
            edi20 = edx19;
        } else {
            *(int16_t*)&eax17 = 0x306;
            return eax17;
        }
    } else {
        edx21 = 0;
        *(uint8_t*)&edx21 = *(uint8_t*)((eax16 & 0xff) + (uint8_t)a1 + 0x2c22);
        edi20 = edx21;
        if (*(int16_t*)&edi20 == 0xff) {
            if (!(*(uint8_t*)&eax16 & 63)) {
                eax22 = fun_407d40(a1, 6);
                if (!*(int16_t*)&eax22) {
                    *(uint8_t*)&edx21 = *(uint8_t*)(a1 + 10);
                    eax23 = 0;
                    *(int8_t*)&eax23 = *(int8_t*)((edx21 & 0x7f) + (uint8_t)a1 + 0x2e22);
                    edi20 = eax23;
                } else {
                    *(int16_t*)&eax22 = 0x306;
                    return eax22;
                }
            } else {
                eax24 = fun_407d40(a1, 4);
                if (!*(int16_t*)&eax24) {
                    eax25 = (void*)0;
                    ecx26 = 0;
                    *(uint8_t*)&eax25 = *(uint8_t*)(a1 + 10);
                    *(int8_t*)&ecx26 = *(int8_t*)((int32_t)eax25 + (uint8_t)a1 + 0x2d22);
                    edi20 = ecx26;
                } else {
                    *(int16_t*)&eax24 = 0x306;
                    return eax24;
                }
            }
        }
    }
    ecx27 = 0;
    *(int8_t*)&ecx27 = *(int8_t*)((edi20 & 0xffff) + (uint8_t)a1 + 0x2fa2);
    eax28 = fun_407d40(a1, ecx27);
    zf29 = *(int16_t*)&eax28 == 0;
    *(int16_t*)&eax28 = 0x306;
    if (zf29) 
        goto addr_0x407ca7_28;
    addr_0x407caa_29:
    return eax28;
    addr_0x407ca7_28:
    *(int16_t*)&eax28 = *(int16_t*)&edi20;
    goto addr_0x407caa_29;
    addr_0x407bb2_14:
    edx30 = 0;
    *(uint8_t*)&edx30 = *(uint8_t*)(a1 + 10);
    edi20 = edx30;
    eax28 = fun_407d40(a1, 8);
    if (*(int16_t*)&eax28) {
        *(int16_t*)&eax28 = 0x306;
        return eax28;
    }
}

uint32_t fun_407cb0(void** a1, int16_t a2) {
    void* eax3;
    uint32_t ebx4;
    uint32_t edx5;
    uint32_t eax6;
    uint32_t ecx7;
    uint32_t edi8;
    uint32_t edx9;
    uint32_t v10;
    uint32_t edi11;

    eax3 = (void*)0;
    ebx4 = 0;
    edx5 = 0;
    *(uint8_t*)&eax3 = *(uint8_t*)(a1 + 10);
    *(int8_t*)&ebx4 = *(int8_t*)((int32_t)eax3 + (uint8_t)a1 + 0x2a22);
    *(int8_t*)&edx5 = *(int8_t*)((ebx4 & 0xffff) + (uint8_t)a1 + 0x30a2);
    eax6 = fun_407d40(a1, edx5);
    if (!*(int16_t*)&eax6) {
        if (a2 != 2) {
            ecx7 = 0;
            edi8 = 0;
            *(uint8_t*)&ecx7 = *(uint8_t*)(a1 + 6);
            *(void***)&edi8 = *(void***)(a1 + 8);
            edx9 = 0;
            v10 = ecx7;
            *(uint8_t*)&edx9 = *(uint8_t*)(a1 + 10);
            edi11 = edi8 & edx9 | ebx4 << *(uint8_t*)&ecx7;
        } else {
            *(uint8_t*)&eax6 = *(uint8_t*)(a1 + 10);
            v10 = 2;
            edi11 = eax6 & 3 | ebx4 * 4;
        }
        eax6 = fun_407d40(a1, v10);
        if (!*(int16_t*)&eax6) {
            return edi11 + 1;
        }
    }
    *(int16_t*)&eax6 = 0;
    return eax6;
}

void** fun_4085f8(void** a1, void** a2) {
    void*** esp3;
    void** v4;
    void** ebx5;
    void** ecx6;
    void** v7;
    int32_t v8;
    void* edx9;
    void* ebx10;
    struct s0* eax11;
    void* v12;
    int32_t v13;
    int32_t v14;
    void** eax15;
    void** eax16;

    esp3 = (void***)((int32_t)__zero_stack_offset() - 40 - 4);
    v4 = ebx5;
    ecx6 = a2;
    if (!(int1_t)(*(void***)ecx6 == 35)) {
        addr_0x408644_2:
        v7 = ecx6;
        v8 = (int32_t)"libpng warning: %s\n";
    } else {
        edx9 = (void*)0;
        ebx10 = (void*)(esp3 + 16);
        do {
            edx9 = (void*)((uint32_t)edx9 + 1);
            if ((int32_t)edx9 > (int32_t)14) 
                break;
            *(int8_t*)((uint32_t)edx9 + (uint32_t)ebx10) = *(int8_t*)((uint32_t)edx9 + (uint8_t)ecx6 + 1);
        } while (*(int8_t*)((uint32_t)edx9 + (uint8_t)ecx6) != 32);
        if ((uint32_t)edx9 + 0xfffffffe > 12) 
            goto addr_0x408644_2; else 
            goto addr_0x40862f_7;
    }
    addr_0x40864d_8:
    eax11 = g41ebe4;
    eax15 = fun_4180f9((uint32_t)eax11 + 64, v8, v7, v12, v4, v13, (uint32_t)eax11 + 64, v8, v7, v12, v4, v14);
    return eax15;
    addr_0x40862f_7:
    eax16 = (void**)(esp3 + 16);
    *(int8_t*)((uint8_t)eax16 + (uint32_t)edx9 + 0xffffffff) = 0;
    v12 = (void*)((uint32_t)edx9 + (uint8_t)ecx6);
    v7 = eax16;
    v8 = (int32_t)"libpng warning no. %s: %s\n";
    goto addr_0x40864d_8;
}

void fun_415810(void** a1);

void fun_415809();

void** fun_409670(void** a1, void** a2, void** a3) {
    void** esi4;
    int1_t less5;
    uint32_t edx6;
    void** edx7;
    void* ecx8;
    void** edx9;
    void** edi10;
    void* ecx11;
    void* edx12;
    uint32_t ecx13;
    uint32_t ecx14;
    void** ecx15;
    uint32_t eax16;
    void** edx17;
    int32_t ecx18;
    void** edx19;

    if (!a1 || ((esi4 = *(void***)(a1 + 28), esi4 == 0) || (!*(void***)(a1 + 32) || !*(void***)(a1 + 36)))) {
        return 0xfffffffe;
    } else {
        *(void***)(a1 + 20) = (void**)0;
        *(void***)(a1 + 8) = (void**)0;
        *(void***)(a1 + 24) = (void**)0;
        *(void***)(a1 + 44) = (void**)2;
        *(void***)(esi4 + 16) = *(void***)(esi4 + 8);
        less5 = (int8_t)*(void***)(esi4 + 24) < (int8_t)0;
        *(void***)(esi4 + 20) = (void**)0;
        if (less5) {
            *(void***)(esi4 + 24) = (void**)0;
        }
        edx6 = (uint32_t)-(uint8_t)*(void***)(esi4 + 24);
        edx7 = (void**)((edx6 - (edx6 + (uint1_t)(edx6 < edx6 + (uint1_t)!!*(void***)(esi4 + 24))) & 71) + 42);
        *(void***)(esi4 + 4) = edx7;
        *(void***)(a1 + 48) = (void**)1;
        *(void***)(esi4 + 32) = (void**)0;
        fun_415810(esi4);
        ecx8 = *(void**)(esi4 + 68);
        edx9 = *(void***)(esi4 + 60);
        *(uint32_t*)(esi4 + 52) = (uint8_t)*(void***)(esi4 + 36) << 1;
        *(int16_t*)((uint32_t)(edx9 + (uint8_t)ecx8 * 2) - 2) = 0;
        edi10 = *(void***)(esi4 + 60);
        ecx11 = (void*)((uint8_t)*(void**)(esi4 + 68) + (uint8_t)*(void**)(esi4 + 68) + 0xfffffffe);
        edx12 = ecx11;
        ecx13 = (uint32_t)ecx11 >> 2;
        while (ecx13) {
            --ecx13;
            *(void***)edi10 = (void**)0;
            edi10 = edi10 + 4;
            esi4 = esi4 + 4;
        }
        ecx14 = (uint32_t)edx12 & 3;
        while (ecx14) {
            --ecx14;
            *(void***)edi10 = (void**)0;
            ++edi10;
            ++esi4;
        }
        ecx15 = (void**)0;
        eax16 = (uint32_t)(*(void***)(esi4 + 0x7c) + (uint8_t)*(void***)(esi4 + 0x7c) * 2) << 2;
        *(int16_t*)&ecx15 = *(int16_t*)(eax16 + 0x41d612);
        edx17 = (void**)0;
        *(void***)(esi4 + 0x78) = ecx15;
        *(int16_t*)&edx17 = *(int16_t*)(eax16 + 0x41d610);
        ecx18 = 0;
        *(void***)(esi4 + 0x84) = edx17;
        *(int16_t*)&ecx18 = *(int16_t*)(eax16 + 0x41d614);
        edx19 = (void**)0;
        *(int32_t*)(esi4 + 0x88) = ecx18;
        *(int16_t*)&edx19 = *(int16_t*)(eax16 + 0x41d616);
        *(void***)(esi4 + 100) = (void**)0;
        *(void***)(esi4 + 84) = (void**)0;
        *(void***)(esi4 + 0x6c) = (void**)0;
        *(void***)(esi4 + 0x70) = (void**)2;
        *(void***)(esi4 + 88) = (void**)2;
        *(void***)(esi4 + 96) = (void**)0;
        *(void***)(esi4 + 0x74) = edx19;
        *(void***)(esi4 + 64) = (void**)0;
        fun_415809();
        return 0;
    }
}

void*** g420740 = (void***)0x420744;

void** g420820 = (void**)88;

int32_t fun_409370(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, int32_t a8) {
    void** ebp9;
    void*** ecx10;
    int1_t zf11;
    void** ecx12;
    void** ebx13;
    void** edx14;
    void** eax15;
    void** ecx16;
    void** ebp17;
    uint32_t ecx18;
    void* eax19;
    void** ecx20;
    void** eax21;
    void** edx22;
    void** eax23;
    void** eax24;
    void* ecx25;
    void** edx26;
    void** eax27;
    uint8_t* ecx28;
    void* eax29;
    void** v30;
    void** eax31;
    void* ecx32;
    int1_t zf33;
    void** eax34;
    void** esi35;
    int1_t less36;
    uint32_t ecx37;
    void* eax38;
    void** ecx39;
    void** edi40;
    void* ecx41;
    void* edx42;
    uint32_t ecx43;
    uint32_t ecx44;
    void** ecx45;
    uint32_t eax46;
    void** edx47;
    int32_t ecx48;
    void** edx49;

    ebp9 = (void**)0;
    if (!a7 || ((ecx10 = g420740, *(void***)a7 != *ecx10) || a8 != 56)) {
        return -6;
    } else {
        if (a1) {
            zf11 = *(void***)(a1 + 32) == 0;
            *(void***)(a1 + 24) = (void**)0;
            if (zf11) {
                *(void***)(a1 + 32) = (void**)0x415630;
                *(void***)(a1 + 40) = (void**)0;
            }
            if (!*(void***)(a1 + 36)) {
                *(void***)(a1 + 36) = (void**)0x415650;
            }
            ecx12 = a2;
            if ((int1_t)(ecx12 == 0xffffffff)) {
                a2 = (void**)6;
                ecx12 = (void**)6;
            }
            ebx13 = a4;
            if ((int8_t)ebx13 < (int8_t)0) {
                ebp9 = (void**)1;
                ebx13 = (void**)-(uint8_t)ebx13;
            }
            if ((int8_t)a5 >= (int8_t)1 && ((int8_t)a5 <= (int8_t)9 && ((int1_t)(a3 == 8) && ((int8_t)ebx13 >= (int8_t)8 && ((int8_t)ebx13 <= (int8_t)15 && ((int8_t)ecx12 >= (int8_t)0 && ((int8_t)ecx12 <= (int8_t)9 && ((int8_t)a6 >= (int8_t)0 && (int8_t)a6 <= (int8_t)2)))))))) {
                edx14 = *(void***)(a1 + 40);
                eax15 = (void**)*(void***)(a1 + 32)(edx14, 1, 0x16b8);
                if (eax15) {
                    *(void***)(a1 + 28) = eax15;
                    *(void***)(eax15 + 24) = ebp9;
                    ecx16 = ebx13;
                    ebp17 = (void**)(1 << *(uint8_t*)&ecx16);
                    *(void***)(eax15 + 40) = ebx13;
                    ecx18 = (uint32_t)(a5 + 7);
                    *(void***)(eax15 + 44) = ebp17 + 0xffffffff;
                    eax19 = (void*)(1 << *(uint8_t*)&ecx18);
                    *(uint32_t*)(eax15 + 72) = ecx18;
                    *(void**)(eax15 + 68) = eax19;
                    *(void***)(eax15 + 76) = (void**)((uint8_t)eax19 - 1);
                    *(void***)eax15 = a1;
                    *(void***)(eax15 + 36) = ebp17;
                    *(uint32_t*)(eax15 + 80) = __intrinsic() >> 1;
                    ecx20 = *(void***)(a1 + 40);
                    eax21 = (void**)*(void***)(a1 + 32)(ecx20, ebp17, 2);
                    edx22 = *(void***)(eax15 + 36);
                    *(void***)(eax15 + 48) = eax21;
                    eax23 = *(void***)(a1 + 40);
                    eax24 = (void**)*(void***)(a1 + 32)(eax23, edx22, 2, ecx20, ebp17, 2);
                    ecx25 = *(void**)(eax15 + 68);
                    *(void***)(eax15 + 56) = eax24;
                    edx26 = *(void***)(a1 + 40);
                    eax27 = (void**)*(void***)(a1 + 32)(edx26, ecx25, 2, eax23, edx22, 2, ecx20, ebp17, 2);
                    *(void***)(eax15 + 60) = eax27;
                    ecx28 = (uint8_t*)(a5 + 6);
                    eax29 = (void*)(1 << *(uint8_t*)&ecx28);
                    *(void**)(eax15 + 0x1694) = eax29;
                    v30 = *(void***)(a1 + 40);
                    eax31 = (void**)*(void***)(a1 + 32)(v30, eax29, 4, edx26, ecx25, 2, eax23, edx22, 2, ecx20, ebp17, 2);
                    ecx32 = *(void**)(eax15 + 0x1694);
                    *(void***)(eax15 + 12) = (void**)((uint32_t)ecx32 * 4);
                    zf33 = *(void***)(eax15 + 48) == 0;
                    *(void***)(eax15 + 8) = eax31;
                    if (zf33 || (!*(void***)(eax15 + 56) || (!*(void***)(eax15 + 60) || !eax31))) {
                        eax34 = g420820;
                        *(void***)(a1 + 24) = eax34;
                        fun_409bc0(a1);
                        return -4;
                    } else {
                        *(void****)(eax15 + 0x169c) = (void***)(eax31 + ((uint32_t)ecx32 >> 1) * 2);
                        *(void**)(eax15 + 0x1690) = (void*)((uint32_t)ecx32 + (uint32_t)(eax31 + (uint32_t)ecx32 * 2));
                        *(void***)(eax15 + 0x7c) = a2;
                        *(void***)(eax15 + 0x80) = a6;
                        *(int8_t*)(eax15 + 29) = 8;
                        esi35 = *(void***)(a1 + 28);
                        if (!esi35 || (!*(void***)(a1 + 32) || !*(void***)(a1 + 36))) {
                            return -2;
                        } else {
                            *(void***)(a1 + 20) = (void**)0;
                            *(void***)(a1 + 8) = (void**)0;
                            *(void***)(a1 + 24) = (void**)0;
                            *(void***)(a1 + 44) = (void**)2;
                            *(void***)(esi35 + 16) = *(void***)(esi35 + 8);
                            less36 = (int8_t)*(void***)(esi35 + 24) < (int8_t)0;
                            *(void***)(esi35 + 20) = (void**)0;
                            if (less36) {
                                *(void***)(esi35 + 24) = (void**)0;
                            }
                            ecx37 = (uint32_t)-(uint8_t)*(void***)(esi35 + 24);
                            *(void***)(esi35 + 4) = (void**)((ecx37 - (ecx37 + (uint1_t)(ecx37 < ecx37 + (uint1_t)!!*(void***)(esi35 + 24))) & 71) + 42);
                            *(void***)(a1 + 48) = (void**)1;
                            *(void***)(esi35 + 32) = (void**)0;
                            fun_415810(esi35);
                            eax38 = *(void**)(esi35 + 68);
                            ecx39 = *(void***)(esi35 + 60);
                            *(uint32_t*)(esi35 + 52) = (uint8_t)*(void***)(esi35 + 36) << 1;
                            *(int16_t*)((uint32_t)(ecx39 + (uint8_t)eax38 * 2) - 2) = 0;
                            edi40 = *(void***)(esi35 + 60);
                            ecx41 = (void*)((uint8_t)*(void**)(esi35 + 68) + (uint8_t)*(void**)(esi35 + 68) + 0xfffffffe);
                            edx42 = ecx41;
                            ecx43 = (uint32_t)ecx41 >> 2;
                            while (ecx43) {
                                --ecx43;
                                *(void***)edi40 = (void**)0;
                                edi40 = edi40 + 4;
                                esi35 = esi35 + 4;
                            }
                            ecx44 = (uint32_t)edx42 & 3;
                            while (ecx44) {
                                --ecx44;
                                *(void***)edi40 = (void**)0;
                                ++edi40;
                                ++esi35;
                            }
                            ecx45 = (void**)0;
                            eax46 = (uint32_t)(*(void***)(esi35 + 0x7c) + (uint8_t)*(void***)(esi35 + 0x7c) * 2) << 2;
                            *(int16_t*)&ecx45 = *(int16_t*)(eax46 + 0x41d612);
                            edx47 = (void**)0;
                            *(void***)(esi35 + 0x78) = ecx45;
                            *(int16_t*)&edx47 = *(int16_t*)(eax46 + 0x41d610);
                            ecx48 = 0;
                            *(void***)(esi35 + 0x84) = edx47;
                            *(int16_t*)&ecx48 = *(int16_t*)(eax46 + 0x41d614);
                            edx49 = (void**)0;
                            *(int32_t*)(esi35 + 0x88) = ecx48;
                            *(int16_t*)&edx49 = *(int16_t*)(eax46 + 0x41d616);
                            *(void***)(esi35 + 100) = (void**)0;
                            *(void***)(esi35 + 84) = (void**)0;
                            *(void***)(esi35 + 0x6c) = (void**)0;
                            *(void***)(esi35 + 0x70) = (void**)2;
                            *(void***)(esi35 + 88) = (void**)2;
                            *(void***)(esi35 + 96) = (void**)0;
                            *(void***)(esi35 + 0x74) = edx49;
                            *(void***)(esi35 + 64) = (void**)0;
                            fun_415809();
                            return 0;
                        }
                    }
                } else {
                    return -4;
                }
            }
        }
        return -2;
    }
}

int32_t fun_417e58(void** a1);

void fun_40290c(void** a1, int32_t a2, void** a3, void** a4);

void fun_4083e0(void** a1, uint32_t a2, void** a3, void* a4, void** a5, int32_t a6, void** a7, void** a8);

struct s69 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

int8_t g406a40 = 49;

int8_t g406a42 = 50;

struct s70 {
    int8_t[2] pad2;
    int8_t f2;
};

void** fun_4032f8(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, int32_t a7, void** a8, void** a9, void** a10) {
    void** v11;
    void** v12;
    void** v13;
    void** eax14;
    void** v15;
    int32_t eax16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    int32_t v21;
    void** v22;
    void** v23;
    uint32_t v24;
    void* v25;
    int32_t edx26;
    void* esp27;
    int8_t al28;
    void* v29;
    int32_t v30;
    void** ebx31;
    int1_t zf32;
    struct s69* v33;
    int8_t al34;
    struct s70* v35;
    int32_t v36;
    void* esp37;
    void** ebx38;
    void** v39;
    void** eax40;
    int32_t v41;
    void** v42;
    void** v43;
    void** v44;

    v11 = (void**)__return_address();
    eax14 = fun_402aac(1, v12, v13);
    v15 = eax14;
    if (eax14) {
        fun_407808(v15, v12, v13);
        eax16 = fun_417e58(v15);
        if (eax16) 
            goto addr_0x403349_6;
    } else {
        goto addr_0x4034f4_8;
    }
    v17 = v18;
    v19 = v20;
    fun_40290c(v15, v21, v19, v17);
    v22 = v23;
    fun_4083e0(v15, v24, v22, v25, v15, v21, v19, v17);
    edx26 = 0;
    esp27 = (void*)((int32_t)__zero_stack_offset() - 4 - 4 - 4 - 4 - 4 + 4 + 16 - 12 - 4 - 4 + 4 - 12 - 4 - 4 + 4 + 32 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 + 32);
    do {
        al28 = *(int8_t*)(edx26 + (int32_t)"1.2.1");
        if (*(int8_t*)(edx26 + (int32_t)v29) != al28) {
            *(uint8_t*)(v15 + 0x6e) = (uint8_t)(*(uint8_t*)(v15 + 0x6e) | 2);
        }
        ++edx26;
    } while (al28);
    if (!(*(uint8_t*)(v15 + 0x6e) & 2)) 
        goto addr_0x4034a3_14;
    if (!v30) {
        addr_0x40345f_16:
        v19 = (void**)0x406a40;
        ebx31 = (void**)((int32_t)esp27 - 4 - 4 - 4 + 44);
        fun_417450(ebx31, 0x403280, 0x406a40, v17, v11, a1, a2, a3, a4, a5, a6);
        fun_40850c(v15, ebx31, v22, 0x403476, ebx31, 0x403280, 0x406a40, v17, v11, a1, a2, a3, a4, a5);
        *(void***)(v15 + 0x6c) = (void**)0;
        fun_408404(v15, 0x4032c0, 0x406a40, v17, v11, a1);
        goto addr_0x4034a3_14;
    } else {
        zf32 = v33->f0 == g406a40;
        if (!zf32 || (v33->f0 == 49 && (al34 = g406a42, v33->f2 != al34) || v33->f0 == 48 && v35->f2 <= 56)) {
            if (v36) {
                esp37 = (void*)((int32_t)esp27 - 4 - 4 - 4);
                ebx38 = (void**)((int32_t)esp37 + 44);
                fun_417450(ebx38, fun_403240, v39, v17, v11, a1, a2, a3, a4, a5, a6);
                fun_40850c(v15, ebx38, v22, 0x40344e, ebx38, fun_403240, v39, v17, v11, a1, a2, a3, a4, a5);
                esp27 = (void*)((int32_t)esp37 - 4 - 4 + 4 - 8 - 4 - 4 - 4 + 4 + 32);
                goto addr_0x40345f_16;
            }
        } else {
            addr_0x4034a3_14:
            *(void***)(v15 + 0xb0) = (void**)0x2000;
            eax40 = fun_402940(v15, 0x2000, v19, v17, v11, a1, a2, a3, a4, a5, a6, v15);
            *(void***)(v15 + 0xac) = eax40;
            fun_40aa88(v15, 0, 0, 0, v15, 0x2000, v19, v17);
            fun_403eb8(v15, 0, 1, 0, 0, 0x2000, v19, v17, v11, a1, a2, a3, a4);
        }
    }
    addr_0x4034f1_20:
    addr_0x4034f4_8:
    goto v41;
    addr_0x403349_6:
    v42 = *(void***)(v15 + 0xac);
    fun_4029a0(v15, v42, v13, v43, v11, a1, a2, a3, a4, a5, a6, v15, a8, a9, a10);
    *(void***)(v15 + 0xac) = (void**)0;
    fun_402a90(v15, v44);
    goto addr_0x4034f1_20;
}

void** fun_4029dc(void** a1, void** a2) {
    void** eax3;
    void** v4;
    void** v5;
    void** ebx6;
    void** v7;

    eax3 = fun_417992(a1);
    if (!eax3) {
        fun_408404(__return_address(), 0x4028bf, v4, v5, ebx6, v7);
    }
    return eax3;
}

struct s71 {
    int8_t[32] pad32;
    uint8_t f32;
    int8_t[77] pad110;
    uint8_t f110;
    int8_t[5] pad116;
    uint8_t f116;
};

void fun_402b80(struct s71* ecx);

void fun_402bb4(int16_t cx, void** a2, void** a3) {
    void** edi4;
    void** esi5;
    void** v6;
    void** v7;
    void** ebx8;
    void** esi9;
    void** edi10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    uint32_t v20;
    void* v21;
    uint32_t v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** ebx28;
    uint32_t eax29;

    edi4 = a2;
    esi5 = a3;
    if (!(*(uint8_t*)(edi4 + 0x69) & 4)) {
        fun_410cd0(edi4);
        if (*(uint8_t*)(edi4 + 0x69) & 16 && *(uint8_t*)(edi4 + 0x230)) {
            fun_40850c(edi4, fun_402b80, v6, v7, ebx8, esi9, edi10, v11, v12, v13, v14, v15, v16, v17);
            *(uint8_t*)(edi4 + 0x230) = (uint8_t)0;
        }
        v18 = (void**)static_cast<uint32_t>((uint8_t)*(void***)(esi5 + 28));
        v19 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi5 + 27));
        v20 = static_cast<uint32_t>((uint8_t)*(void***)(esi5 + 26));
        v21 = (void*)static_cast<uint32_t>(*(uint8_t*)(esi5 + 25));
        v22 = static_cast<uint32_t>((uint8_t)*(void***)(esi5 + 24));
        v23 = *(void***)(esi5 + 4);
        v24 = *(void***)esi5;
        fun_40b1d8(cx, edi4, v24, v23, v22, v21, v20, v19, v18);
        if ((uint8_t)*(void***)(esi5 + 8) & 1) {
            asm("fld dword [esi+0x28]");
            asm("fstp qword [esp]");
            fun_410de8(edi4, v20, v19, v18);
        }
        if ((uint8_t)*(void***)(esi5 + 9) & 8) {
            v20 = static_cast<uint32_t>((uint8_t)*(void***)(esi5 + 44));
            fun_410edc(edi4, v20, v19, v18);
        }
        if ((uint8_t)*(void***)(esi5 + 9) & 16) {
            v25 = *(void***)(esi5 + 0xcc);
            v26 = *(void***)(esi5 + 0xc8);
            v27 = *(void***)(esi5 + 0xc4);
            fun_40b9b8(edi4, v27, 0, v26, v25, v20, v19, v18);
        }
        if ((uint8_t)*(void***)(esi5 + 8) & 2) {
            v19 = (void**)static_cast<uint32_t>(*(uint8_t*)(esi5 + 25));
            fun_40bdb0(edi4, esi5 + 68, v19, v18);
        }
        if ((uint8_t)*(void***)(esi5 + 8) & 4) {
            asm("fld dword [esi+0x9c]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x98]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x94]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x90]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x8c]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x88]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x84]");
            asm("fstp qword [esp]");
            asm("fld dword [esi+0x80]");
            asm("fstp qword [esp]");
            fun_40bfd0(edi4);
        }
        if (*(void***)(esi5 + 0xc0) && (ebx28 = *(void***)(esi5 + 0xbc), (uint8_t)ebx28 < (uint8_t)(ebx28 + (uint32_t)(*(void***)(esi5 + 0xc0) + (uint8_t)*(void***)(esi5 + 0xc0) * 4) * 4))) {
            do {
                eax29 = fun_4076f4(edi4, ebx28, v19, v18);
                if (eax29 != 1 && (*(void***)(ebx28 + 16) && (!((uint8_t)*(void***)(ebx28 + 16) & 2) && (*(uint8_t*)(ebx28 + 3) & 32 || (eax29 == 3 || *(uint8_t*)(edi4 + 0x6e) & 1))))) {
                    v18 = *(void***)(ebx28 + 12);
                    v19 = *(void***)(ebx28 + 8);
                    fun_410b44(edi4, ebx28, v19, v18);
                }
                ebx28 = ebx28 + 20;
            } while ((uint8_t)ebx28 < (uint8_t)(*(void***)(esi5 + 0xbc) + (uint32_t)(*(void***)(esi5 + 0xc0) + (uint8_t)*(void***)(esi5 + 0xc0) * 4) * 4));
        }
        *(uint8_t*)(edi4 + 0x69) = (uint8_t)(*(uint8_t*)(edi4 + 0x69) | 4);
    }
    return;
}

struct s72 {
    int8_t[580] pad580;
    int32_t f580;
    int32_t f584;
    int32_t f588;
};

void fun_40290c(void** a1, int32_t a2, void** a3, void** a4) {
    uint96_t v1;
    uint72_t v2;
    struct s72* eax3;
    uint8_t al4;
    int32_t v5;

    *(void***)((int32_t)&v1 + 4) = a1;
    *(int32_t*)((int32_t)&v1 + 8) = a2;
    *(void***)&v2 = a3;
    *(void***)((int32_t)&v2 + 4) = a4;
    *(uint8_t*)&eax3 = (uint8_t)(al4 & 8);
    eax3->f580 = *(int32_t*)((int32_t)&v2 + 1);
    eax3->f584 = *(int32_t*)((int32_t)&v2 + 5);
    eax3->f588 = v5;
    goto *(int32_t*)((int32_t)&v1 + 5);
}

void fun_4083e0(void** a1, uint32_t a2, void** a3, void* a4, void** a5, int32_t a6, void** a7, void** a8) {
    *(uint32_t*)(a1 + 72) = a2;
    *(void***)(a1 + 64) = a3;
    *(void**)(a1 + 68) = a4;
    return;
}

int32_t g420030 = 0x420034;

int32_t g41d1b4 = 0x754a4bb0;

int32_t g41d17c = 0x754aaeb0;

int32_t g41d134 = 0x754a53d0;

int8_t* g42454c = (int8_t*)0x400000;

int32_t g41d180 = 0x754b2dc0;

int32_t g41d12c = 0x754ad910;

int32_t g41d1bc = 0x754bd410;

int32_t g41d150 = 0x7549ef90;

int32_t g41d148 = 0x754a9bd0;

int32_t g41d144 = 0x754a8c90;

int32_t g41d140 = 0x754a8a70;

int32_t g41d13c = 0x754ba780;

int32_t g41d138 = 0x754acdc0;

int32_t g41d1b8 = 0x754a3a80;

int32_t g41d1c0 = 0x754af3a0;

void fun_401000() {
    int32_t eax1;
    int32_t edi2;
    int32_t esi3;
    int32_t eax4;
    void* esp5;
    int16_t ax6;
    int8_t* v7;
    int8_t* v8;
    int32_t esi9;
    int32_t eax10;
    int32_t eax11;
    int32_t v12;
    int32_t eax13;
    int32_t edi14;
    int32_t esi15;
    int32_t eax16;
    int32_t v17;
    int32_t ebx18;
    int32_t ebx19;
    int32_t* esp20;
    int32_t v21;
    int32_t ebp22;
    int32_t ebp23;
    int32_t eax24;
    void* esp25;
    void* esp26;
    int32_t eax27;
    int32_t v28;
    int32_t eax29;
    int32_t v30;

    eax1 = g420030;
    eax4 = (int32_t)g41d1b4(eax1, 0, edi2, esi3);
    if (!eax4) {
        g41d17c();
        esp5 = (void*)((int32_t)__zero_stack_offset() - 76 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4);
        ax6 = (int16_t)g41d134();
        if (ax6) {
            v7 = v8;
            g42454c = v8;
            esi9 = g41d180;
            eax10 = (int32_t)esi9(1, 0x6b, 73, 0, 0);
            asm("cdq");
            esi9(0, (eax10 - 72 - ((int32_t)esp5 + 36) >> 1) + 72, 1, 0x6b, 73, 0, 0);
            asm("cdq");
            eax11 = (int32_t)g41d12c();
            if (eax11) {
                g41d1bc(eax11, v12);
                g41d150(eax11, eax11, v12);
                eax13 = (int32_t)g41d148();
                edi14 = g41d144;
                esi15 = eax13;
                eax16 = (int32_t)edi14();
                if (eax16) {
                    v17 = ebx18;
                    ebx19 = g41d140;
                    esp20 = (int32_t*)((int32_t)esp5 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4);
                    v21 = ebp22;
                    ebp23 = g41d13c;
                    do {
                        eax24 = (int32_t)ebx19(0, esi15, esp20 + 4, v21, v17);
                        esp25 = (void*)(esp20 - 1 - 1 - 1 - 1 + 1);
                        if (!eax24) {
                            ebp23((int32_t)esp25 + 16, 0, esi15, esp20 + 4, v21, v17);
                            esp26 = (void*)((int32_t)esp25 - 4 - 4 + 4);
                            g41d138((int32_t)esp26 + 16, (int32_t)esp25 + 16, 0, esi15, esp20 + 4, v21, v17);
                            esp25 = (void*)((int32_t)esp26 - 4 - 4 + 4);
                        }
                        eax27 = (int32_t)edi14();
                        esp20 = (int32_t*)((int32_t)esp25 - 4 - 4 - 4 - 4 - 4 + 4);
                    } while (eax27);
                }
                goto v7;
            } else {
                goto v28;
            }
        } else {
            goto 0;
        }
    } else {
        eax29 = (int32_t)g41d1b8();
        if (eax29) {
            g41d1bc(eax4, 9);
        }
        g41d1c0();
        goto v30;
    }
}

int8_t ga872b03e;

int8_t fun_40545d() {
    int8_t al1;

    al1 = ga872b03e;
    return al1;
}

struct s73 {
    int8_t[298] pad298;
    int8_t f298;
};

void fun_40b290(void** a1, void** a2, void** a3) {
    void** esi4;
    struct s73* esi5;

    asm("clc");
    fun_408404(esi4, 0x40b030, __return_address(), a1, a2, a3);
    esi5->f298 = 3;
    goto 0x40b335;
}

void fun_41c000() {
}

int32_t g424550 = 0xaf050b;

int32_t g41d1b0 = 0x754f5e00;

int32_t g41d1ac = 0x754bc540;

int32_t g41d190 = 0x754db190;

int32_t g41d1a0 = 0x7550b380;

int32_t g41d1a4 = 0x754b5e30;

int32_t g41d1a8 = 0x754bd3b0;

int32_t g41d188 = 0x7550b690;

int32_t g42434c = 0;

int32_t g41d120 = 0x73c94fd0;

int32_t g41d198 = 0x754f7e60;

struct s74 {
    int8_t[1] pad1;
    void** f1;
};

struct s74* fun_4174b0(void** a1, void** a2);

int32_t fun_41cd80(struct s74* a1, int32_t a2);

int32_t g41d19c = 0x755056b0;

int32_t g41d11c = 0x73c94fc0;

struct s75 {
    int8_t[4200580] pad4200580;
    int8_t f4200580;
};

int32_t g41d010 = 0x722fe7f0;

int32_t g41d178 = 0x754aff50;

int32_t g41d128 = 0x7550b290;

int32_t g41d130 = 0x754af990;

int32_t g424548 = 0xf7050ea9;

int32_t g41d18c = 0x754af6c0;

int32_t g41d184 = 0x754bc370;

int32_t g41d01c = 0x751a6a80;

int32_t g41d02c = 0x751a6940;

int32_t g41d028 = 0x751a5ba0;

int32_t g41d024 = 0x751a4330;

int32_t g41d018 = 0x751a69b0;

int32_t g41d020 = 0x751a5fd0;

int32_t g41d14c = 0x754bc6e0;

int32_t g41d194 = 0x771ee630;

int16_t process_event(int32_t a1, void* a2, uint32_t a3, uint32_t a4) {
    void*** esp5;
    void** v6;
    void** edi7;
    void* ecx8;
    int32_t edx9;
    void* ecx10;
    int32_t v11;
    int32_t v12;
    int32_t ecx13;
    int32_t ecx14;
    int32_t v15;
    uint32_t eax16;
    uint32_t v17;
    int32_t v18;
    int32_t ecx19;
    int32_t ecx20;
    int32_t v21;
    int32_t eax22;
    int32_t v23;
    void** ecx24;
    void** v25;
    void** eax26;
    void** ecx27;
    int32_t ebx28;
    void** v29;
    void** ebp30;
    int32_t ebp31;
    int32_t v32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    void* esp37;
    struct s74* eax38;
    void* esp39;
    int32_t eax40;
    void* eax41;
    void* ecx42;
    void* edx43;
    uint32_t ecx44;
    void* edx45;
    uint32_t ecx46;
    int32_t eax47;
    uint32_t eax48;
    struct s74* eax49;
    void* esp50;
    void* esp51;
    struct s74* eax52;
    void*** esp53;
    void* esp54;
    struct s74* eax55;
    void*** esp56;
    void* esp57;
    struct s74* eax58;
    void*** esp59;
    void* esp60;
    struct s74* eax61;
    void*** esp62;
    void* esp63;
    struct s74* eax64;
    void*** esp65;
    void* esp66;
    struct s74* eax67;
    void*** esp68;
    void* esp69;
    struct s74* eax70;
    void*** esp71;
    void* esp72;
    void* esp73;
    int32_t v74;
    int32_t v75;
    struct s75* ecx76;
    int32_t edx77;
    int32_t eax78;
    int32_t esi79;
    int32_t eax80;
    int32_t ecx81;
    int32_t eax82;
    int32_t v83;
    int32_t v84;
    int32_t eax85;
    int32_t eax86;
    int32_t edx87;
    int32_t eax88;
    int32_t ecx89;
    int32_t v90;
    int32_t v91;

    esp5 = (void***)((int32_t)__zero_stack_offset() - 0x474 - 4 - 4 - 4);
    v6 = edi7;
    if ((uint32_t)a2 > 0xa3) {
        ecx8 = (void*)((uint32_t)a2 - 0xa4);
        if (!ecx8) {
            edx9 = g424550;
            g41d1b0(edx9, 6, a4 & 0xffff, a4 >> 16, 0, a1, 0);
            goto addr_0x401862_4;
        } else {
            ecx10 = (void*)((uint32_t)ecx8 - 0x6d);
            if (!ecx10) {
                switch ((a3 & 0xffff) - 100) {
                    addr_0x401862_4:
                default:
                    return 0;
                case 0:
                    g41d1ac();
                    goto v11;
                case 1:
                    g41d190();
                    goto v12;
                case 2:
                    ecx13 = 12;
                    while (ecx13) {
                        --ecx13;
                    }
                    ecx14 = g424550;
                    g41d1a0(ecx14, 0, 1);
                    g41d1a4(v15, esp5 - 4 - 4 - 4 - 4 - 4 + 4 + 20, ecx14, 0, 1);
                    eax16 = v17 & 8;
                    if (*(int8_t*)&eax16 != 8) {
                        g41d1a8(v15, 0xff, esp5 + 44, v6, 0, 0, 1, v15, esp5 - 4 - 4 - 4 - 4 - 4 + 4 + 20, ecx14, 0, 1);
                    } else {
                        g41d1a8(v15, 0xfe, esp5 + 44, v6, 0, 0, 1, v15, esp5 - 4 - 4 - 4 - 4 - 4 + 4 + 20, ecx14, 0, 1);
                    }
                    g41d188();
                    goto v18;
                case 3:
                    ecx19 = 12;
                    while (ecx19) {
                        --ecx19;
                    }
                    ecx20 = g424550;
                    g41d1a0(ecx20, 1, 1, esp5 + 44);
                    g41d1a4(v21, esp5 - 4 - 4 - 4 - 4 - 4 + 4 + 20, ecx20, 1, 1, esp5 + 44);
                    eax22 = g42434c;
                    if (!eax22) {
                        g42434c = 1;
                    } else {
                        g42434c = 0;
                    }
                    g41d188();
                    goto v23;
                }
            } else {
                ecx24 = (void**)((uint32_t)ecx10 - 0x122);
                if (!ecx24) {
                    v25 = ecx24;
                    eax26 = (void**)g41d120();
                    ecx27 = (void**)0;
                    v6 = eax26;
                    if (eax26) {
                        ebx28 = g41d198;
                        esp5 = esp5 - 4 - 4 - 4 - 4 - 4 + 4 - 4;
                        v29 = ebp30;
                        ebp31 = v32;
                        do {
                            v33 = (void**)(esp5 + 0x37c);
                            v34 = ecx27;
                            v35 = v36;
                            g41d120();
                            esp37 = (void*)(esp5 - 4 - 4 - 4 - 4 - 4 + 4);
                            eax38 = fun_4174b0((int32_t)esp37 + 0x37c, 46);
                            esp39 = (void*)((int32_t)esp37 - 4 - 4 - 4 + 4 + 8);
                            if (!eax38 || (eax40 = fun_41cd80(eax38, ".MAP"), esp39 = (void*)((int32_t)esp39 - 4 - 4 - 4 + 4 + 8), !!eax40)) {
                                g41d19c(0);
                                esp5 = (void***)((int32_t)esp39 - 4 - 4 + 4);
                                continue;
                            } else {
                                eax41 = (void*)((int32_t)eax38 - ((int32_t)esp39 + 0x37c));
                                ecx42 = (void*)((int32_t)eax41 + 1);
                                edx43 = ecx42;
                                ecx44 = (uint32_t)ecx42 >> 2;
                                while (ecx44) {
                                    --ecx44;
                                }
                                edx45 = (void*)((int32_t)esp39 + 0x37c);
                                ecx46 = (uint32_t)edx43 & 3;
                                while (ecx46) {
                                    --ecx46;
                                }
                                *(int8_t*)((int32_t)esp39 + (int32_t)eax41 + 0x71) = 0x70;
                                *(int8_t*)((int32_t)esp39 + (int32_t)eax41 + 0x72) = 0x6e;
                                *(int8_t*)((int32_t)esp39 + (int32_t)eax41 + 0x73) = 0x67;
                                *(int8_t*)((int32_t)esp39 + (int32_t)eax41 + 0x74) = 0;
                                eax47 = g42434c;
                                eax48 = convert_file(edx45, (int32_t)esp39 + 0x70, eax47);
                                esp5 = (void***)((int32_t)esp39 - 4 - 4 - 4 - 4 + 4 + 12);
                                if (eax48 > 9) 
                                    continue;
                            }
                            switch (eax48) {
                            case 0:
                                eax49 = fun_4174b0(esp5 + 0x70, 92);
                                esp50 = (void*)(esp5 - 4 - 4 - 4 + 4);
                                fun_417450((int32_t)esp50 + 0x180, 0x4201b0, &eax49->f1, esp5 + 0x70, 92, v35, v34, v33, 0x105, v29, v25);
                                esp51 = (void*)((int32_t)esp50 - 4 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp51 + 0x178, "Success!", 64);
                                esp5 = (void***)((int32_t)esp51 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 1:
                                eax52 = fun_4174b0(esp5 + 0x37c, 92);
                                esp53 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp53 + 0x184, 0x420164, &eax52->f1, esp5 + 0x37c, 92, v35, v34, v33, 0x105, v29, v25);
                                esp54 = (void*)(esp53 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp54 + 0x178, "Error", 16);
                                esp5 = (void***)((int32_t)esp54 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 2:
                                eax55 = fun_4174b0(esp5 + 0x70, 92);
                                esp56 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp56 + 0x184, 0x420138, &eax55->f1, esp5 + 0x70, 92, v35, v34, v33, 0x105, v29, v25);
                                esp57 = (void*)(esp56 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp57 + 0x178, "Error", 16);
                                esp5 = (void***)((int32_t)esp57 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 3:
                                eax58 = fun_4174b0(esp5 + 0x70, 92);
                                esp59 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp59 + 0x184, 0x420120, &eax58->f1, esp5 + 0x70, 92, v35, v34, v33, 0x105, v29, v25);
                                esp60 = (void*)(esp59 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp60 + 0x178, "File Exists", 48);
                                esp5 = (void***)((int32_t)esp60 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 4:
                            case 5:
                                eax61 = fun_4174b0(esp5 + 0x37c, 92);
                                esp62 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp62 + 0x184, 0x4200f0, &eax61->f1, esp5 + 0x37c, 92, v35, v34, v33, 0x105, v29, v25);
                                esp63 = (void*)(esp62 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp63 + 0x178, "Error", 48);
                                esp5 = (void***)((int32_t)esp63 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 6:
                                eax64 = fun_4174b0(esp5 + 0x70, 92);
                                esp65 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp65 + 0x184, 0x4200a8, &eax64->f1, esp5 + 0x70, 92, v35, v34, v33, 0x105, v29, v25);
                                esp66 = (void*)(esp65 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp66 + 0x178, "Error", 16);
                                esp5 = (void***)((int32_t)esp66 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 7:
                                eax67 = fun_4174b0(esp5 + 0x37c, 92);
                                esp68 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp68 + 0x184, 0x420058, &eax67->f1, esp5 + 0x37c, 92, v35, v34, v33, 0x105, v29, v25);
                                esp69 = (void*)(esp68 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp69 + 0x178, "Bad CRC", 16);
                                esp5 = (void***)((int32_t)esp69 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 8:
                                eax70 = fun_4174b0(esp5 + 0x70, 92);
                                esp71 = esp5 - 4 - 4 - 4 + 4 - 4;
                                fun_417450(esp71 + 0x184, 0x420088, &eax70->f1, esp5 + 0x70, 92, v35, v34, v33, 0x105, v29, v25);
                                esp72 = (void*)(esp71 - 4 - 4 - 4 + 4 + 20);
                                ebx28(ebp31, (int32_t)esp72 + 0x178, "Out Of Memory!", 16);
                                esp5 = (void***)((int32_t)esp72 - 4 - 4 - 4 - 4 - 4 + 4);
                                break;
                            case 9:
                                fun_417450(esp5 + 0x178, 0x420188, v35, v34, v33, 0x105, v29, v25, 0xff, 0, 0);
                                esp73 = (void*)(esp5 - 4 - 4 - 4 + 4 + 8);
                                ebx28(ebp31, (int32_t)esp73 + 0x178, "Uknown error.", 16);
                                esp5 = (void***)((int32_t)esp73 - 4 - 4 - 4 - 4 - 4 + 4);
                            case 13:
                                goto 0x4016da;
                            case 11:
                                goto 0x4016ab;
                            case 12:
                                goto 0x401768;
                            case 10:
                                goto 0x401818;
                            }
                            ecx27 = v29 + 1;
                            v29 = ecx27;
                        } while ((uint8_t)ecx27 < (uint8_t)v25);
                    }
                    g41d11c();
                    goto v74;
                }
            }
        }
    } else {
        if (a2 == 0xa3) {
            g41d190();
            goto v75;
        }
        ecx76 = (struct s75*)((uint32_t)a2 + 0xffffffff);
        if ((uint32_t)ecx76 > 0x83) 
            goto addr_0x401343_52;
        edx77 = 0;
        *(int8_t*)&edx77 = ecx76->f4200580;
        switch (edx77) {
        case 0:
            g41d010();
            eax78 = (int32_t)g41d178();
            esi79 = g41d128;
            g424550 = eax78;
            esi79(eax78, 8, 0x66, "&Always on top");
            eax80 = g424550;
            esi79(eax80, 0, 0x67, "&Overwrite existing files", eax78, 8, 0x66, "&Always on top");
            ecx81 = g424550;
            esi79(ecx81, 0x800, 0, 0, eax80, 0, 0x67, "&Overwrite existing files", eax78, 8, 0x66, "&Always on top");
            esi79();
            eax82 = (int32_t)g41d130();
            g424548 = eax82;
            goto v83;
        case 1:
            g41d18c();
            goto v84;
        case 2:
            eax85 = (int32_t)g41d184();
            eax86 = (int32_t)g41d01c();
            edx87 = g424548;
            eax88 = (int32_t)g41d02c(eax86, edx87);
            g41d028(eax88, eax86, edx87);
            ecx89 = g424548;
            g41d024(ecx89, 24, esp5 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 + 20, eax88, eax86, edx87);
            g41d018(eax85, 0, 0, eax85, a1, eax86, 0, 0, 0xcc0020, ecx89, 24, esp5 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 + 20, eax88, eax86, edx87);
            g41d020();
            g41d14c();
            goto v90;
        case 3:
            return 2;
            addr_0x401343_52:
        case 4:
            g41d194();
            goto v91;
        }
    }
}

struct s76 {
    int8_t[102] pad102;
    uint8_t f102;
};

struct s77 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s78 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s79 {
    int8_t[102] pad102;
    uint8_t f102;
    int8_t[15] pad118;
    uint8_t f118;
};

struct s80 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s81 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s82 {
    int8_t[580] pad580;
    int32_t f580;
};

struct s83 {
    int8_t[32] pad32;
    int32_t f32;
};

int32_t fun_4028b0(int16_t cx) {
    struct s76* edi2;
    void* edi3;
    struct s77* ebp4;
    struct s78* ebp5;
    uint32_t* eax6;
    uint32_t* eax7;
    uint32_t eax8;
    struct s79* edi9;
    struct s80* ebp10;
    struct s81* ebp11;
    uint1_t cf12;
    uint1_t zf13;
    struct s82* eax14;
    int32_t ebp15;
    struct s83* esi16;

    edi2 = (struct s76*)((int32_t)edi3 - 1);
    if (edi2) 
        goto 0x402927;
    edi2->f102 = 0;
    ebp4->f101 = (uint8_t)(ebp5->f101 & *(uint8_t*)&cx);
    asm("insd");
    asm("outsd");
    if (!static_cast<int1_t>(*eax6 = *eax7 & eax8, edi9 = (struct s79*)((int32_t)edi2 - 1), !!edi9)) {
        edi9->f102 = 0;
        ebp10->f101 = (uint8_t)(ebp11->f101 & *(uint8_t*)&cx);
        asm("insd");
        asm("outsd");
        if (0) 
            goto 0x402945;
        edi9->f118 = (uint8_t)(edi9->f118 + *(uint8_t*)&cx);
        cf12 = __intrinsic();
        zf13 = (uint1_t)(edi9->f118 == 0);
        if (!cf12) 
            goto addr_0x4028d2_6;
    }
    return eax14->f580;
    addr_0x4028d2_6:
    asm("insb");
    asm("outsd");
    if ((uint1_t)(cf12 | zf13)) {
        asm("insd");
        asm("insd");
        asm("arpl [eax+0x79], si");
        asm("arpl [eax+0x65], bp");
        asm("arpl [ebx+0x2e], bp");
        *(uint8_t*)((int32_t)__return_address() + 0x76) = (uint8_t)(*(uint8_t*)((int32_t)__return_address() + 0x76) + *(uint8_t*)&cx);
        if (__intrinsic()) 
            goto 0x402956;
        asm("insb");
        asm("outsd");
        if (!(uint1_t)(__intrinsic() | (uint1_t)(*(uint8_t*)((int32_t)__return_address() + 0x76) == 0))) 
            goto 0x402914;
        ebp15 = esi16->f32 * 0x5f676e70;
        cf12 = __intrinsic();
        zf13 = __undefined();
    }
    asm("insd");
    asm("insd");
    if (cf12) {
        if (zf13) 
            goto 0x402961;
        asm("arpl [eax+0x65], bp");
        asm("arpl [ebx+0x2e], bp");
        *(uint8_t*)(ebp15 - 0x74acff8a) = (uint8_t)(*(uint8_t*)(ebp15 - 0x74acff8a) + *(uint8_t*)&cx);
    }
}

void fun_4029c6() {
}

void fun_402ace() {
}

void fun_402ad9() {
}

struct s84 {
    int8_t[112] pad112;
    int32_t f112;
};

struct s85 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s86 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s87 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s88 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s89 {
    int8_t[120] pad120;
    uint8_t f120;
};

struct s90 {
    int8_t[120] pad120;
    uint8_t f120;
};

struct s91 {
    int8_t[120] pad120;
    int8_t f120;
};

void fun_402da0(struct s1* ecx) {
    void* esp2;
    struct s84* eax3;
    struct s85* edx4;
    struct s86* edx5;
    uint8_t dh6;
    int1_t zf7;
    int32_t ebp8;
    struct s87* edi9;
    struct s88* edi10;
    uint8_t dh11;
    struct s89* ebp12;
    struct s90* ebp13;
    uint8_t dh14;
    struct s91* ebp15;
    int32_t ebx16;
    int32_t ebx17;
    int8_t al18;
    int32_t eax19;
    int32_t eax20;
    int8_t dl21;
    int32_t eax22;

    asm("popad");
    asm("insb");
    esp2 = (void*)(eax3->f112 * 0x74656c61);
    if (__undefined()) 
        goto 0x402e12;
    edx4->f101 = (uint8_t)(edx5->f101 & dh6);
    if (1) 
        goto 0x402e27;
    zf7 = __undefined();
    if (__intrinsic()) {
        addr_0x402ddb_4:
        *(int32_t*)((int32_t)esp2 - 4) = ebp8;
        asm("outsb");
        asm("popad");
        if (!zf7) {
            edi9->f114 = (uint8_t)(edi10->f114 & dh11);
            if (__intrinsic()) 
                goto 0x402e64;
            asm("popad");
            if (__undefined()) 
                goto 0x402e62;
            asm("outsd");
            asm("outsb");
            asm("popad");
            asm("insb");
            ebp12->f120 = (uint8_t)(ebp13->f120 & dh14);
            if (!ebp15->f120) 
                goto 0x402e0d;
            *(int8_t*)(ebx16 + 0x57550cec) = (int8_t)(*(int8_t*)(ebx17 + 0x57550cec) + al18);
        }
    } else {
        if (__intrinsic()) 
            goto 0x402e1e;
        asm("insb");
        if (zf7) 
            goto 0x402e35;
        ecx->f109 = 0;
        zf7 = ecx->f109 == 0;
        asm("popad");
        if (!1) 
            goto addr_0x402dcb_13;
    }
    addr_0x402dd5_14:
    goto addr_0x402ddb_4;
    addr_0x402dcb_13:
    *(int8_t*)(eax19 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax20 - 0x6f6f6f70) + dl21);
    zf7 = *(int8_t*)(eax22 - 0x6f6f6f70) == 0;
    goto addr_0x402dd5_14;
}

void fun_402fea() {
}

struct s92 {
    int8_t[216826870] pad216826870;
    int8_t f216826870;
};

void fun_4030bf(struct s2* ecx) {
    struct s92* ecx2;
    int32_t esi3;
    int32_t esi4;
    uint8_t ah5;

    asm("outsd");
    ecx->f68 = (uint8_t)(ecx->f68 & *(uint8_t*)&ecx);
    ecx2 = (struct s92*)((int32_t)ecx + 1);
    if (1) 
        goto 0x4030e8;
    if (!(uint1_t)static_cast<uint32_t>((uint1_t)(ecx2 == 0))) 
        goto 0x40313c;
    esi3 = *(int32_t*)((int32_t)__zero_stack_offset() - 4 + (esi4 - 1) * 2 + 0x65) * 0x6e69206e;
    if (__undefined()) 
        goto 0x403143;
    *(uint8_t*)(esi3 + 0x69) = (uint8_t)(*(uint8_t*)(esi3 + 0x69) & ah5);
    asm("insb");
    ecx2->f216826870 = (int8_t)(ecx2->f216826870 + *(int8_t*)&ecx2);
}

struct s93 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s94 {
    int8_t[97] pad97;
    int32_t f97;
};

struct s95 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s96 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s97 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s98 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s99 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s100 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s101 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s102 {
    uint8_t f0;
    int8_t[1400433794] pad1400433795;
    int8_t f1400433795;
};

struct s103 {
    int8_t[110] pad110;
    int32_t f110;
};

struct s104 {
    int8_t[97] pad97;
    int32_t f97;
};

struct s105 {
    int8_t[32] pad32;
    int32_t f32;
};

void fun_403240(void* ecx) {
    struct s93* ecx2;
    int1_t cf3;
    void* esp4;
    struct s94* ebx5;
    struct s95* edi6;
    struct s96* edi7;
    uint8_t dh8;
    int1_t zf9;
    int1_t of10;
    struct s97* edi11;
    struct s98* edi12;
    uint8_t dh13;
    struct s99* edi14;
    struct s100* eax15;
    struct s101* eax16;
    uint8_t dh17;
    int32_t ebp18;
    int1_t of19;
    uint32_t eax20;
    struct s102* eax21;
    void* eax22;
    struct s103* edi23;
    struct s103* edi24;
    struct s103* edi25;
    void* esp26;
    struct s104* ebx27;
    int32_t ebp28;
    struct s105* ebx29;
    int8_t dl30;
    int32_t ebp31;

    ecx2 = (struct s93*)((int32_t)ecx + 1);
    if (__intrinsic()) {
        addr_0x4032b3_2:
    } else {
        asm("insb");
        esp4 = (void*)(ebx5->f97 * 0x6e6f6974);
        edi6->f97 = (uint8_t)(edi7->f97 & dh8);
        cf3 = 0;
        if (1) {
            addr_0x403270_4:
            if (!cf3) 
                goto addr_0x403276_5; else 
                goto addr_0x403276_5;
        } else {
            asm("arpl [edi+0x6d], bp");
            if (0) {
                addr_0x4032be_7:
                ecx2 = (struct s93*)((int32_t)ecx2 - 1);
                zf9 = ecx2 == 0;
                of10 = __intrinsic();
                asm("outsb");
                asm("arpl [edi+0x6d], bp");
                goto addr_0x4032c5_8;
            } else {
                asm("insb");
                edi11->f105 = (uint8_t)(edi12->f105 & dh13);
                zf9 = edi14->f105 == 0;
                of10 = 0;
                if (zf9) {
                    addr_0x4032c5_8:
                    if (of10) 
                        goto 0x403328; else 
                        goto addr_0x4032c7_10;
                } else {
                    eax15->f110 = (uint8_t)(eax16->f110 & dh17);
                    *(int32_t*)((int32_t)esp4 - 4) = 0x6f726620;
                    asm("insd");
                    *(uint8_t*)((int32_t)ecx2 + ebp18 * 2 + 98) = 0;
                    of19 = 0;
                    if (0) {
                        addr_0x4032dc_12:
                        asm("popad");
                        if (of19) 
                            goto 0x403352; else 
                            goto addr_0x4032e2_13;
                    } else {
                        cf3 = eax20 < 0x30322e25;
                        eax21 = (struct s102*)((int32_t)eax22 - 0x30322e25);
                        goto addr_0x403270_4;
                    }
                }
            }
        }
    }
    edi23 = edi24;
    goto addr_0x4032be_7;
    addr_0x403276_5:
    edi24 = edi25;
    ecx2 = (struct s93*)((int32_t)ecx2 + 1);
    if (!__intrinsic()) {
        asm("insb");
        esp26 = (void*)(ebx27->f97 * 0x6e6f6974);
        *(uint8_t*)eax21 = 0;
        asm("outsb");
        ebp28 = *(int32_t*)(ebx29->f32 * 0x6e757220 + 0x67) * 0x74697720;
        *(int32_t*)((int32_t)esp26 - 4) = 0x676e7020;
        asm("arpl [cs:eax], sp");
        if (__intrinsic()) 
            goto 0x403316;
        asm("insd");
        *(uint8_t*)((int32_t)ecx2 + ebp28 * 2 + 98) = 0;
        if (0) 
            goto 0x40331c;
        cf3 = (uint32_t)eax21 < 0x30322e25;
        eax21 = (struct s102*)((uint32_t)eax21 - 0x30322e25);
        goto addr_0x4032b3_2;
    }
    addr_0x4032f4_20:
    if (!cf3) {
        *(int8_t*)((uint32_t)eax21 + 0x5378ec83) = (int8_t)(*(int8_t*)((uint32_t)eax21 + 0x5378ec83) + dl30);
    }
    addr_0x4032c7_10:
    if (zf9) 
        goto "D";
    asm("insb");
    if (__intrinsic()) 
        goto 0x40334b;
    ebp31 = edi23->f110 * 0x206e6920;
    of19 = __intrinsic();
    goto addr_0x4032dc_12;
    addr_0x4032e2_13:
    asm("insb");
    ecx2->f110 = 0;
    *(uint8_t*)((int32_t)ecx2 + ebp31 * 2 + 98) = 0;
    cf3 = 0;
    if (0) 
        goto 0x403355; else 
        goto addr_0x4032f4_20;
}

void fun_40388a() {
}

struct s106 {
    int8_t[118] pad118;
    uint8_t f118;
};

struct s107 {
    int8_t[111] pad111;
    int32_t f111;
};

struct s108 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s109 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s110 {
    int8_t[111] pad111;
    int8_t f111;
};

struct s111 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s112 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s113 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s114 {
    int8_t[1] pad1;
    void** f1;
};

struct s115 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s116 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s117 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s118 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s119 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s120 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s121 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s122 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s123 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s124 {
    int8_t[103] pad103;
    int32_t f103;
};

struct s125 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s126 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s127 {
    int8_t[97] pad97;
    int8_t f97;
};

void fun_403b80(struct s106* ecx, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10, void** a11, void** a12) {
    int32_t ebp13;
    struct s107* esi14;
    struct s108* edx15;
    struct s109* edx16;
    uint8_t dh17;
    struct s110* edx18;
    struct s111* esi19;
    struct s112* esi20;
    uint8_t ah21;
    uint1_t cf22;
    int1_t zf23;
    struct s113* esi24;
    void** ebx25;
    struct s114* ebx26;
    uint8_t al27;
    struct s115* esi28;
    struct s116* esi29;
    uint8_t ah30;
    struct s117* esi31;
    uint8_t ah32;
    void** eax33;
    void** edx34;
    uint1_t zf35;
    uint1_t below_or_equal36;
    void* eax37;
    int8_t al38;
    uint8_t ah39;
    struct s118* eax40;
    struct s119* eax41;
    uint8_t dl42;
    struct s120* eax43;
    struct s121* esi44;
    struct s122* esi45;
    uint8_t ah46;
    struct s123* esi47;
    void** v48;
    void** v49;
    void** ebp50;
    struct s124* esi51;
    int32_t esi52;
    uint8_t* eax53;
    uint8_t* eax54;
    uint8_t dh55;
    struct s125* ebx56;
    struct s126* ebx57;
    int8_t al58;
    struct s127* ebx59;
    void** v60;
    void** eax61;
    void** v62;
    void** eax63;
    void** v64;
    void** eax65;
    void** v66;
    void** eax67;
    int32_t* eax68;
    int32_t eax69;
    int32_t* eax70;
    int32_t eax71;
    int8_t* eax72;
    int8_t al73;
    int8_t ah74;
    int8_t dh75;
    int32_t eax76;
    int32_t eax77;
    int8_t dl78;
    uint8_t dl79;

    asm("outsb");
    ebp13 = esi14->f111 * 0x77;
    asm("outsb");
    edx15->f111 = (uint8_t)(edx16->f111 & dh17);
    if (!(uint1_t)static_cast<uint32_t>((uint1_t)(edx18->f111 == 0))) {
        addr_0x403bac_2:
        esi19->f105 = (uint8_t)(esi20->f105 & ah21);
        cf22 = 0;
        zf23 = esi24->f105 == 0;
        asm("insb");
        if (zf23) {
            addr_0x403c17_3:
            goto addr_0x403c19_4;
        } else {
            if (0) {
                addr_0x403bd4_6:
                goto addr_0x403bda_7;
            } else {
                asm("popad");
                if (zf23) {
                    addr_0x403c1d_9:
                    goto addr_0x403c1f_10;
                } else {
                    addr_0x403bb8_11:
                    if (cf22) {
                        addr_0x403bda_7:
                        ebx25 = (void**)&ebx26->f1;
                        asm("popad");
                        asm("outsb");
                        asm("daa");
                        if (!ebx25) {
                            addr_0x403c06_12:
                            goto addr_0x403c17_3;
                        } else {
                            asm("popad");
                            ecx->f118 = (uint8_t)(ecx->f118 & al27);
                            if (0) {
                                addr_0x403c50_14:
                                if (1) {
                                    addr_0x403cc6_15:
                                    goto addr_0x403cc8_16;
                                } else {
                                    asm("outsd");
                                    asm("insd");
                                    esi28->f105 = (uint8_t)(esi29->f105 & ah30);
                                    cf22 = 0;
                                    zf23 = esi31->f105 == 0;
                                    goto addr_0x403c57_18;
                                }
                            } else {
                                *(uint8_t*)(*(int16_t*)&ebp13 + 0x69) = (uint8_t)(*(uint8_t*)(*(int16_t*)&ebp13 + 0x69) & ah32);
                                cf22 = 0;
                                zf23 = *(uint8_t*)(*(int16_t*)&ebp13 + 0x69) == 0;
                                asm("insb");
                                if (zf23) {
                                    asm("insd");
                                    goto addr_0x403c5d_21;
                                } else {
                                    if (0) {
                                        addr_0x403c19_4:
                                        goto addr_0x403c1d_9;
                                    } else {
                                        asm("popad");
                                        if (zf23) {
                                            addr_0x403c62_24:
                                            ebx25 = a8;
                                            eax33 = a9;
                                            edx34 = a10;
                                            zf23 = (*(uint8_t*)(ebx25 + 0x230) & 4) == 0;
                                            goto addr_0x403c75_25;
                                        } else {
                                            if (0) {
                                                addr_0x403c1f_10:
                                                ++ebx25;
                                                zf35 = (uint1_t)(ebx25 == 0);
                                                below_or_equal36 = (uint1_t)(cf22 | zf35);
                                                asm("popad");
                                                asm("outsb");
                                                asm("daa");
                                                if (zf35) {
                                                    addr_0x403c46_27:
                                                    asm("outsb");
                                                    asm("outsd");
                                                    if (!below_or_equal36) {
                                                        addr_0x403cbb_28:
                                                        *(int8_t*)&eax37 = (int8_t)(al38 + al38);
                                                        goto addr_0x403cbf_29;
                                                    } else {
                                                        *(uint8_t*)(ebx25 + 0x75) = (uint8_t)(*(uint8_t*)(ebx25 + 0x75) & ah39);
                                                        goto addr_0x403c50_14;
                                                    }
                                                } else {
                                                    asm("popad");
                                                    eax40->f97 = (uint8_t)(eax41->f97 & dl42);
                                                    if (!eax43->f97) {
                                                        goto addr_0x403c98_33;
                                                    } else {
                                                        esi44->f105 = (uint8_t)(esi45->f105 & ah46);
                                                        cf22 = 0;
                                                        zf23 = esi47->f105 == 0;
                                                        goto addr_0x403c30_35;
                                                    }
                                                }
                                            } else {
                                                if (1) {
                                                    addr_0x403c75_25:
                                                    goto addr_0x403c78_37;
                                                } else {
                                                    asm("popad");
                                                    if (0) {
                                                        addr_0x403c78_37:
                                                        if (zf23) {
                                                            addr_0x403c84_39:
                                                            if (eax33) {
                                                                fun_408404(ebx25, 0x403c46, v48, v49, ebp50, __return_address());
                                                            } else {
                                                                eax37 = (void*)((uint8_t)edx34 & 0xff);
                                                                if ((uint32_t)eax37 > 7) {
                                                                    *(uint8_t*)(ebx25 + 0x125) = *(uint8_t*)&edx34;
                                                                    goto addr_0x403d12_43;
                                                                } else {
                                                                    addr_0x403c98_33:
                                                                    switch (eax37) {
                                                                        addr_0x403cd1_44:
                                                                    case 0:
                                                                        *(uint8_t*)(ebx25 + 0x125) = 8;
                                                                        goto addr_0x403d12_43;
                                                                    case 1:
                                                                        *(uint8_t*)(ebx25 + 0x125) = 16;
                                                                        goto addr_0x403d12_43;
                                                                    case 2:
                                                                        *(uint8_t*)(ebx25 + 0x125) = 32;
                                                                        goto addr_0x403d12_43;
                                                                    case 3:
                                                                        *(uint8_t*)(ebx25 + 0x125) = 64;
                                                                        goto addr_0x403d12_43;
                                                                    case 4:
                                                                        *(uint8_t*)(ebx25 + 0x125) = 0x80;
                                                                        goto addr_0x403d12_43;
                                                                        addr_0x403cc0_49:
                                                                    case 5:
                                                                    case 6:
                                                                    case 7:
                                                                        goto addr_0x403cc6_15;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            addr_0x403c7d_50:
                                                            if ((int1_t)(eax33 == 64)) {
                                                                eax33 = (void**)0;
                                                                goto addr_0x403c84_39;
                                                            }
                                                        }
                                                    } else {
                                                        addr_0x403c04_52:
                                                        cf22 = __intrinsic();
                                                        goto addr_0x403c06_12;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (!cf22) {
                            addr_0x403c30_35:
                            asm("insb");
                            goto addr_0x403c33_54;
                        } else {
                            asm("popad");
                            if (cf22) {
                                addr_0x403c33_54:
                                if (zf23) {
                                    goto addr_0x403ca0_58;
                                }
                            } else {
                                ebp13 = esi51->f103 * 0x90909000;
                                cf22 = __intrinsic();
                                goto addr_0x403bc6_60;
                            }
                        }
                    }
                }
            }
        }
    } else {
        *(int16_t*)&ebp13 = (int16_t)(*(int16_t*)((int32_t)__zero_stack_offset() - 4 + esi52 * 2 + 0x65) * 0x2072);
        cf22 = __intrinsic();
        zf23 = __undefined();
        asm("outsw");
        if (cf22) {
            goto addr_0x403bb8_11;
        }
        asm("insd");
        if (zf23) {
            goto addr_0x403c04_52;
        }
        asm("outsd");
        *eax53 = (uint8_t)(*eax54 & dh55);
        ebx56->f97 = (int8_t)(ebx57->f97 + al58);
        cf22 = __intrinsic();
        asm("outsb");
        asm("daa");
        if (!ebx59->f97) 
            goto addr_0x403bc6_60; else 
            goto addr_0x403ba6_66;
    }
    addr_0x403e61_67:
    goto a10;
    addr_0x403d12_43:
    if (*(void***)(ebx25 + 0xec)) {
        if (*(uint8_t*)(ebx25 + 0x125) & 16 && !*(void***)(ebx25 + 0xf0)) {
            v60 = *(void***)(ebx25 + 0xd8) + 1;
            eax61 = fun_402940(ebx25, v60, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
            *(void***)(ebx25 + 0xf0) = eax61;
            *(void***)eax61 = (void**)1;
        }
        if (*(uint8_t*)(ebx25 + 0x125) & 32 && !*(void***)(ebx25 + 0xf4)) {
            if (*(void***)(ebx25 + 0xe8)) {
                v62 = *(void***)(ebx25 + 0xd8) + 1;
                eax63 = fun_402940(ebx25, v62, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
                *(void***)(ebx25 + 0xf4) = eax63;
                *(void***)eax63 = (void**)2;
            } else {
                fun_40850c(ebx25, 0x403ba0, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
                *(uint8_t*)(ebx25 + 0x125) = (uint8_t)(*(uint8_t*)(ebx25 + 0x125) & 0xdf);
            }
        }
        if (*(uint8_t*)(ebx25 + 0x125) & 64 && !*(void***)(ebx25 + 0xf8)) {
            if (*(void***)(ebx25 + 0xe8)) {
                v64 = *(void***)(ebx25 + 0xd8) + 1;
                eax65 = fun_402940(ebx25, v64, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
                *(void***)(ebx25 + 0xf8) = eax65;
                *(void***)eax65 = (void**)3;
            } else {
                fun_40850c(ebx25, 0x403be0, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
                *(uint8_t*)(ebx25 + 0x125) = (uint8_t)(*(uint8_t*)(ebx25 + 0x125) & 0xbf);
            }
        }
        if ((int8_t)*(uint8_t*)(ebx25 + 0x125) < (int8_t)0 && !*(void***)(ebx25 + 0xfc)) {
            if (*(void***)(ebx25 + 0xe8)) {
                v66 = *(void***)(ebx25 + 0xd8) + 1;
                eax67 = fun_402940(ebx25, v66, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
                *(void***)(ebx25 + 0xfc) = eax67;
                *(void***)eax67 = (void**)4;
            } else {
                fun_40850c(ebx25, 0x403c20, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
                *(uint8_t*)(ebx25 + 0x125) = (uint8_t)(*(uint8_t*)(ebx25 + 0x125) & 0x7f);
            }
        }
        if (!*(uint8_t*)(ebx25 + 0x125)) {
            *(uint8_t*)(ebx25 + 0x125) = 8;
            goto addr_0x403e61_67;
        }
    }
    if (cf22) {
        addr_0x403c57_18:
        asm("insb");
        if (zf23) {
            addr_0x403cbf_29:
            *(int8_t*)(ebx25 + 0x8068f8c4) = (int8_t)(*(int8_t*)(ebx25 + 0x8068f8c4) + *(int8_t*)&eax37);
            goto addr_0x403cc0_49;
        } else {
            if (cf22) {
                goto addr_0x403c7d_50;
            }
        }
    } else {
        asm("popad");
        if (zf23) {
            addr_0x403ca0_58:
            *(int32_t*)((int32_t)eax68 + eax69 * 2) = *(int32_t*)((int32_t)eax70 + eax71 * 2) >> 1;
            *(int8_t*)&eax72 = (int8_t)(al73 + *(int8_t*)((int32_t)&ecx + 1));
            *(int8_t*)((int32_t)&eax72 + 1) = (int8_t)((int8_t)(ah74 + *(int8_t*)&ebx25) + dh75);
            *eax72 = (int8_t)(*eax72 + *(int8_t*)&eax72);
            goto addr_0x403cb3_91;
        } else {
            if (cf22) {
                addr_0x403c5d_21:
                if (zf23) {
                    addr_0x403cc8_16:
                    fun_40850c(ebx25, ebp50, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
                    goto addr_0x403cd1_44;
                } else {
                    asm("outsd");
                    *(int8_t*)(eax76 + 0x5318ec83) = (int8_t)(*(int8_t*)(eax77 + 0x5318ec83) + dl78);
                    goto addr_0x403c62_24;
                }
            } else {
                if (!cf22) {
                    addr_0x403cb3_91:
                    goto addr_0x403cb6_95;
                } else {
                    asm("popad");
                    if (cf22) {
                        addr_0x403cb6_95:
                        eax37 = (void*)(eax72 + 1);
                        al38 = (int8_t)(*(int8_t*)&eax37 + *(int8_t*)&eax37);
                        goto addr_0x403cbb_28;
                    } else {
                        below_or_equal36 = (uint1_t)(__intrinsic() | __undefined());
                        goto addr_0x403c46_27;
                    }
                }
            }
        }
    }
    addr_0x403bc6_60:
    goto addr_0x403bd4_6;
    addr_0x403ba6_66:
    asm("popad");
    *(uint8_t*)(ebp13 + 0x70) = (uint8_t)(*(uint8_t*)(ebp13 + 0x70) & dl79);
    goto addr_0x403bac_2;
}

void fun_403eea() {
}

void fun_404369() {
}

void fun_404401() {
}

void fun_404499() {
}

void fun_404769() {
}

struct s128 {
    void** f0;
    int8_t[3] pad4;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
};

void fun_404af9(void** a1, struct s128* a2, uint32_t a3) {
    void** edi4;
    uint32_t ebp5;
    uint32_t esi6;
    struct s128* ebx7;
    uint32_t eax8;
    void** v9;
    void** v10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;
    uint32_t esi23;

    edi4 = a1;
    ebp5 = a3;
    esi6 = 0;
    ebx7 = a2;
    if (0 >= ebp5) 
        goto addr_0x404bb5_2;
    eax8 = ebp5 & 3;
    if (!((uint1_t)((int32_t)ebp5 < (int32_t)0) | (uint1_t)(ebp5 == 0))) {
        if (!eax8) {
            do {
                addr_0x404b70_5:
                v9 = ebx7->f0;
                fun_403678(edi4, v9, v10);
                v11 = ebx7->f4;
                fun_403678(edi4, v11, v12);
                v13 = ebx7->f8;
                fun_403678(edi4, v13, v14);
                v15 = ebx7->f12;
                fun_403678(edi4, v15, v16);
                esi6 = esi6 + 4;
                ebx7 = (struct s128*)((int32_t)ebx7 + 16);
            } while (esi6 < ebp5);
            goto addr_0x404bb5_2;
        } else {
            if ((int32_t)eax8 > (int32_t)1) {
                if ((int32_t)eax8 > (int32_t)2) {
                    v17 = ebx7->f0;
                    fun_403678(edi4, v17, v18);
                    esi6 = 1;
                    ebx7 = (struct s128*)&ebx7->f4;
                }
                v19 = ebx7->f0;
                fun_403678(edi4, v19, v20);
                ++esi6;
                ebx7 = (struct s128*)&ebx7->f4;
            }
        }
    }
    v21 = ebx7->f0;
    fun_403678(edi4, v21, v22);
    esi23 = esi6 + 1;
    ebx7 = (struct s128*)&ebx7->f4;
    if (esi23 >= ebp5) {
        addr_0x404bb5_2:
        return;
    } else {
        esi6 = esi23;
        goto addr_0x404b70_5;
    }
}

void fun_404bbd() {
}

void fun_404c22() {
}

void fun_404cd5() {
}

void** fun_404d71(void** a1, void** a2) {
    void** v3;
    void** v4;
    void** ebx5;
    void** esi6;
    void** v7;
    void** v8;
    void** v9;
    void** v10;
    void** v11;
    void** eax12;

    if (a2 != 8) {
        eax12 = fun_40850c(a1, 0x4048c0, v3, v4, ebx5, esi6, v7, v8, v9, v10, v11, __return_address(), a1, a2);
    }
    *(void***)(a1 + 0x6c) = (void**)((uint8_t)*(void***)(a1 + 0x6c) | 16);
    *(void***)(a1 + 0xb8) = a2;
    return eax12;
}

struct s129 {
    int8_t[412] pad412;
    int32_t f412;
};

void fun_404da8(struct s129* a1, int32_t a2) {
    a1->f412 = a2;
    return;
}

void fun_404e2e() {
}

void fun_9a403329(int32_t a1);

int32_t fun_8f4575b9(int32_t a1);

struct s130 {
    int8_t[44] pad44;
    int8_t f44;
};

struct s131 {
    int8_t[8] pad8;
    int32_t f8;
};

struct s132 {
    int8_t[252] pad252;
    int32_t f252;
};

struct s133 {
    int8_t[256] pad256;
    int32_t f256;
};

struct s134 {
    int8_t[260] pad260;
    int32_t f260;
};

struct s135 {
    int8_t[264] pad264;
    int32_t f264;
};

struct s136 {
    int8_t[268] pad268;
    int32_t f268;
};

struct s137 {
    int8_t[272] pad272;
    int32_t f272;
};

struct s138 {
    int8_t[276] pad276;
    int32_t f276;
};

struct s139 {
    int8_t[280] pad280;
    int32_t f280;
};

struct s140 {
    int8_t[284] pad284;
    int32_t f284;
};

struct s141 {
    int8_t[8] pad8;
    int32_t f8;
};

void fun_40546d() {
    int32_t v1;
    int32_t edx2;
    int32_t eax3;
    int32_t v4;
    struct s130* edx5;
    int32_t eax6;
    struct s131* edx7;
    struct s132* edx8;
    struct s133* edx9;
    struct s134* edx10;
    struct s135* edx11;
    struct s136* edx12;
    struct s137* edx13;
    struct s138* edx14;
    struct s139* edx15;
    struct s140* edx16;
    struct s141* edx17;
    int32_t v18;

    asm("cmc");
    fun_9a403329(__return_address());
    asm("aas");
    fun_8f4575b9(__return_address());
    if (v1 && edx2) {
        eax3 = v4;
        edx5->f44 = *(int8_t*)&eax3;
        eax6 = edx7->f8;
        *(uint8_t*)((int32_t)&eax6 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&eax6 + 1) | 8);
        edx8->f252 = 0xb18f;
        edx9->f256 = 0x7a26;
        edx10->f260 = 0x8084;
        edx11->f264 = 0xfa00;
        edx12->f268 = 0x80e8;
        edx13->f272 = 0x7530;
        edx14->f276 = 0xea60;
        edx15->f280 = 0x3a98;
        edx16->f284 = 0x1770;
        *(uint8_t*)&eax6 = (uint8_t)(*(uint8_t*)&eax6 | 5);
        edx17->f8 = eax6;
        asm("fld dword [0x40545c]");
        asm("fstp dword [edx+0x28]");
        asm("fld dword [0x405460]");
        asm("fld dword [0x405464]");
        asm("fld dword [0x405468]");
        asm("fld dword [0x40546c]");
        asm("fld dword [0x405470]");
        asm("fld dword [0x405474]");
        asm("fld dword [0x405478]");
        asm("fld dword [0x40547c]");
        asm("fxch st0, st7");
        asm("fstp dword [edx+0x80]");
        asm("fxch st0, st5");
        asm("fstp dword [edx+0x84]");
        asm("fxch st0, st3");
        asm("fstp dword [edx+0x88]");
        asm("fxch st0, st1");
        asm("fstp dword [edx+0x8c]");
        asm("fstp dword [edx+0x90]");
        asm("fstp dword [edx+0x94]");
        asm("fstp dword [edx+0x98]");
        asm("fstp dword [edx+0x9c]");
    }
    goto v18;
}

struct s142 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
};

struct s143 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
};

struct s144 {
    int8_t[48] pad48;
    int32_t f48;
    int8_t[4] pad56;
    int32_t* f56;
};

struct s145 {
    int8_t[48] pad48;
    int32_t f48;
};

struct s146 {
    int8_t[48] pad48;
    int32_t f48;
    int8_t[4] pad56;
    int32_t* f56;
};

void fun_40557b(int8_t cl);

void fun_4056ba(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6) {
    void** v7;
    void** esi8;
    void** esi9;
    int32_t ecx10;
    void** edi11;
    void** edi12;
    struct s142* ebx13;
    int32_t edx14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** eax19;
    void** v20;
    struct s143* ebp21;
    void** v22;
    void** eax23;
    void** v24;
    void** v25;
    int32_t* ecx26;
    struct s144* v27;
    int32_t edx28;
    struct s145* v29;
    struct s146* v30;
    void** edi31;
    int32_t ecx32;
    void** v33;
    void** v34;
    void** v35;
    void** v36;
    int32_t v37;

    v7 = (void**)__return_address();
    esi8 = esi9;
    while (1) {
        ecx10 = -1;
        do {
            if (!ecx10) 
                break;
            --ecx10;
            ++edi11;
            ++esi8;
        } while (*(void***)edi11);
        edi12 = (void**)(~ecx10 + 0xffffffff);
        ebx13->f0 = edx14;
        while (1) {
            eax19 = fun_402940(v15, (uint8_t)edi12 + (uint8_t)esi8 + 4, v16, v17, v7, a1, a2, a3, a4, a5, a6, v18);
            ebx13->f4 = eax19;
            v20 = ebp21->f4;
            fun_417ac0(eax19, v20, esi8, 0x4056df, v15, (uint8_t)edi12 + (uint8_t)esi8 + 4, v16, v22);
            *(int8_t*)((uint8_t)esi8 + (uint8_t)ebx13->f4) = 0;
            esi8 = (void**)((uint8_t)esi8 + (uint8_t)ebx13->f4);
            eax23 = esi8 + 1;
            ebx13->f8 = eax23;
            if (edi12) {
                v16 = edi12;
                v24 = ebp21->f8;
                fun_417ac0(eax23, v24, v16, v25, v7, a1, a2, a3);
            }
            *(int8_t*)((uint8_t)edi12 + (uint8_t)ebx13->f8) = 0;
            ebx13->f12 = edi12;
            ecx26 = v27->f56;
            edx28 = v27->f48 << 4;
            *(int32_t*)((int32_t)ecx26 + edx28) = ebx13->f0;
            *(void***)((int32_t)ecx26 + edx28 + 4) = ebx13->f4;
            *(void***)((int32_t)ecx26 + edx28 + 8) = ebx13->f8;
            *(void***)((int32_t)ecx26 + edx28 + 12) = ebx13->f12;
            v29->f48 = v29->f48 + 1;
            while (ebp21 = (struct s143*)((int32_t)ebp21 + 16), --v18, !!v18) {
                ebx13 = (struct s142*)((v30->f48 << 4) + (int32_t)v30->f56);
                edi31 = ebp21->f4;
                if (!edi31) 
                    continue;
                ecx32 = -1;
                do {
                    if (!ecx32) 
                        break;
                    --ecx32;
                    ++edi31;
                } while (*(void***)edi31);
                esi8 = (void**)(~ecx32 + 0xffffffff);
                edx14 = ebp21->f0;
                if ((uint1_t)(edx14 < 0) | (uint1_t)(edx14 == 0)) 
                    goto addr_0x4056a4_15;
                fun_40850c(v33, fun_40557b, v16, v34, v7, a1, a2, a3, a4, a5, a6, v18, v35, v36);
            }
            goto addr_0x40575b_17;
            addr_0x4056a4_15:
            edi11 = ebp21->f8;
            if (!edi11) 
                goto addr_0x4056b0_18;
            if (*(void***)edi11) 
                break;
            addr_0x4056b0_18:
            edi12 = (void**)0;
            ebx13->f0 = -1;
        }
    }
    addr_0x40575b_17:
    goto v37;
}

struct s147 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[174] pad184;
    uint8_t f184;
    int8_t[27] pad212;
    void** f212;
    int8_t[3] pad216;
    void* f216;
};

struct s148 {
    void** f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    uint32_t f12;
    void** f16;
};

struct s149 {
    void** f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    uint32_t f12;
};

void fun_417f90(void** a1, void** a2, void** a3, int32_t a4, void** a5, void** a6);

struct s150 {
    void** f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    uint32_t f12;
};

struct s151 {
    void** f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    uint32_t f12;
};

struct s152 {
    void** f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    uint32_t f12;
};

void fun_405764(void** a1, struct s147* a2, struct s148* a3, void** a4) {
    void** v5;
    void** ebp6;
    void** v7;
    void** edi8;
    void** v9;
    void** esi10;
    void** v11;
    void** ebx12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** eax20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    struct s148* esi35;
    void** v36;
    void** eax37;
    void** v38;
    struct s149* ebp39;
    void** edi40;
    int32_t ecx41;
    void** v42;
    void** v43;
    void** v44;
    void** eax45;
    void** v46;
    void** v47;
    void** v48;
    void** v49;
    void** v50;
    void** v51;
    void** eax52;
    void** v53;
    void** v54;
    void** v55;
    void** v56;
    struct s150* ebx57;
    struct s151* ebp58;
    void** edi59;
    int32_t ecx60;
    void** v61;
    void** v62;
    void** v63;
    void** eax64;
    void** v65;
    void** v66;
    void** v67;
    void** v68;
    void** v69;
    void** v70;
    void** eax71;
    void** v72;
    void** v73;
    void** v74;
    struct s152* ebp75;
    void** edi76;
    int32_t ecx77;
    void** v78;
    void** v79;
    void** v80;
    void** eax81;
    void** v82;
    void** v83;
    void** v84;
    void** v85;
    void** v86;
    void** v87;
    void** eax88;
    void** v89;
    void** v90;
    void** v91;
    void** edx92;

    v5 = ebp6;
    v7 = edi8;
    v9 = esi10;
    v11 = ebx12;
    v13 = (void**)((uint8_t)a4 + (uint32_t)a2->f216 << 4);
    eax20 = fun_402940(a1, v13, v14, v15, v11, v9, v7, v5, v16, v17, v18, v19);
    v21 = eax20;
    v22 = (void**)((uint32_t)a2->f216 << 4);
    v23 = a2->f212;
    fun_417ac0(v21, v23, v22, 0x40578a, a1, v13, v24, v25);
    v26 = a2->f212;
    fun_4029a0(a1, v26, v27, v28, v11, v9, v7, v5, v29, v30, v31, v21, v32, v33, v34);
    a2->f212 = (void**)0;
    if ((int8_t)a4 <= (int8_t)0) {
        addr_0x4059ad_2:
        a2->f212 = v21;
        a2->f216 = (void*)((uint32_t)a2->f216 + (uint8_t)a4);
        a2->f9 = (uint8_t)(a2->f9 | 32);
        a2->f184 = (uint8_t)(a2->f184 | 32);
        return;
    } else {
        esi35 = a3;
        v36 = (void**)0;
        eax37 = a4;
        v38 = eax37;
        if (!(*(uint8_t*)&eax37 & 1)) {
            do {
                addr_0x405894_4:
                ebp39 = (struct s149*)((uint8_t)v36 + (((uint32_t)a2->f216 << 4) + (uint8_t)v21));
                edi40 = esi35->f0;
                ecx41 = -1;
                do {
                    if (!ecx41) 
                        break;
                    --ecx41;
                    ++edi40;
                    esi35 = (struct s148*)&esi35->pad4;
                } while (*(void***)edi40);
                eax45 = fun_402940(a1, ~ecx41, v42, v43, v11, v9, v7, v5, v44, v36, v38, v21);
                ebp39->f0 = eax45;
                v46 = esi35->f0;
                v47 = ebp39->f0;
                fun_417f90(v47, v46, v22, 0x4058c8, a1, ~ecx41);
                v48 = (void**)(esi35->f12 << 4);
                eax52 = fun_402940(a1, v48, v49, v50, v11, v9, v7, v5, v51, v36, v38, v21);
                ebp39->f8 = eax52;
                v53 = (void**)(esi35->f12 << 4);
                v54 = esi35->f8;
                fun_417ac0(eax52, v54, v53, 0x4058ef, a1, v48, v55, v56);
                ebp39->f12 = esi35->f12;
                ebp39->f4 = esi35->f4;
                ebx57 = (struct s150*)&esi35->f16;
                ebp58 = (struct s151*)(((uint32_t)a2->f216 << 4) + (uint8_t)v21 + (uint8_t)v36 + 16);
                edi59 = esi35->f16;
                ecx60 = -1;
                do {
                    if (!ecx60) 
                        break;
                    --ecx60;
                    ++edi59;
                    esi35 = (struct s148*)&esi35->pad4;
                } while (*(void***)edi59);
                eax64 = fun_402940(a1, ~ecx60, v61, v62, v11, v9, v7, v5, v63, v36, v38, v21);
                ebp58->f0 = eax64;
                v65 = esi35->f16;
                v66 = ebp58->f0;
                fun_417f90(v66, v65, v53, 0x40594d, a1, ~ecx60);
                v67 = (void**)(ebx57->f12 << 4);
                eax71 = fun_402940(a1, v67, v68, v69, v11, v9, v7, v5, v70, v36, v38, v21);
                ebp58->f8 = eax71;
                v22 = (void**)(ebx57->f12 << 4);
                v72 = ebx57->f8;
                fun_417ac0(eax71, v72, v22, 0x405975, a1, v67, v73, v74);
                ebp58->f12 = ebx57->f12;
                ebp58->f4 = ebx57->f4;
                esi35 = (struct s148*)((uint32_t)esi35 + 32);
                v36 = v36 + 32;
                v38 = v38 + 0xfffffffe;
            } while (v38);
            goto addr_0x4059ad_2;
        } else {
            ebp75 = (struct s152*)((uint8_t)v21 + ((uint32_t)a2->f216 << 4));
            edi76 = esi35->f0;
            ecx77 = -1;
            do {
                if (!ecx77) 
                    break;
                --ecx77;
                ++edi76;
                esi35 = (struct s148*)&esi35->pad4;
            } while (*(void***)edi76);
            eax81 = fun_402940(a1, ~ecx77, v78, v79, v11, v9, v7, v5, v80, 0, v38, v21);
            ebp75->f0 = eax81;
            v82 = esi35->f0;
            v83 = ebp75->f0;
            fun_417f90(v83, v82, v22, 0x40582c, a1, ~ecx77);
            v84 = (void**)(esi35->f12 << 4);
            eax88 = fun_402940(a1, v84, v85, v86, v11, v9, v7, v5, v87, 0, v38, v21);
            ebp75->f8 = eax88;
            v22 = (void**)(esi35->f12 << 4);
            v89 = esi35->f8;
            fun_417ac0(eax88, v89, v22, 0x405853, a1, v84, v90, v91);
            ebp75->f12 = esi35->f12;
            ebp75->f4 = esi35->f4;
            v36 = (void**)16;
            edx92 = a4 - 1;
            v38 = edx92;
            if (!edx92) 
                goto addr_0x4059ad_2;
        }
    }
    esi35 = (struct s148*)&esi35->f16;
    goto addr_0x405894_4;
}

struct s153 {
    int8_t[185] pad185;
    uint8_t f185;
    int8_t[2] pad188;
    void** f188;
    int8_t[3] pad192;
    int32_t f192;
};

void fun_4059d8(void** a1, struct s153* a2, void** a3, int32_t a4) {
    void** v5;
    void** ebp6;
    void** v7;
    void** edi8;
    void** v9;
    void** esi10;
    void** v11;
    void** ebx12;
    int32_t eax13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** eax20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** v33;
    void** v34;
    void** edi35;
    void* v36;
    int32_t ebp37;
    int32_t eax38;
    void** esi39;
    void** v40;
    int32_t v41;
    void** v42;
    void** v43;
    void** eax44;
    void** v45;
    void** v46;
    void** v47;
    void** ebx48;
    void** esi49;
    int32_t v50;
    void** v51;
    void** v52;
    void** eax53;
    void** v54;
    void** v55;
    void** esi56;
    void** v57;
    int32_t v58;
    void** v59;
    void** v60;
    void** v61;
    void** eax62;
    void** v63;
    void** v64;

    v5 = ebp6;
    v7 = edi8;
    v9 = esi10;
    v11 = ebx12;
    if (!a1 || (!a2 || !a4)) {
        addr_0x405bee_2:
        return;
    } else {
        eax13 = a4 + a2->f192;
        eax20 = fun_402940(a1, eax13 + eax13 * 4 << 2, v14, v15, v11, v9, v7, v5, v16, v17, v18, v19);
        v21 = eax20;
        v22 = (void**)(a2->f192 + a2->f192 * 4 << 2);
        v23 = a2->f188;
        fun_417ac0(v21, v23, v22, 0x405a22, a1, eax13 + eax13 * 4 << 2, v24, v25);
        v26 = a2->f188;
        fun_4029a0(a1, v26, v27, v28, v11, v9, v7, v5, v29, v30, v31, v21, v32, v33, v34);
        a2->f188 = (void**)0;
        if (a4 <= 0) 
            goto addr_0x405bcf_4;
        edi35 = a3;
        v36 = (void*)0;
        ebp37 = a4;
        eax38 = ebp37;
        if (*(uint8_t*)&eax38 & 1) 
            goto addr_0x405a96_6;
    }
    do {
        addr_0x405b00_7:
        esi39 = (void**)((uint32_t)v36 + (uint32_t)(v21 + (a2->f192 + a2->f192 * 4) * 4));
        fun_417f90(esi39, edi35, v40, v41, v11, v9);
        v42 = *(void***)(edi35 + 12);
        eax44 = fun_402940(a1, v42, v22, 0x405b25, esi39, edi35, v40, v43, v11, v9, v7, v5);
        *(void***)(esi39 + 8) = eax44;
        v45 = *(void***)(edi35 + 12);
        v46 = *(void***)(edi35 + 8);
        fun_417ac0(eax44, v46, v45, v47, v11, v9, v7, v5);
        *(void***)(esi39 + 12) = *(void***)(edi35 + 12);
        *(void***)(esi39 + 16) = *(void***)(a1 + 0x68);
        ebx48 = edi35 + 20;
        esi49 = (void**)((uint32_t)(v21 + (a2->f192 + a2->f192 * 4) * 4) + (uint32_t)v36 + 20);
        fun_417f90(esi49, ebx48, v45, v50, v11, v9);
        v51 = *(void***)(ebx48 + 12);
        eax53 = fun_402940(a1, v51, v22, 0x405b86, esi49, ebx48, v45, v52, v11, v9, v7, v5);
        *(void***)(esi49 + 8) = eax53;
        v40 = *(void***)(ebx48 + 12);
        v54 = *(void***)(ebx48 + 8);
        fun_417ac0(eax53, v54, v40, v55, v11, v9, v7, v5);
        *(void***)(esi49 + 12) = *(void***)(ebx48 + 12);
        *(void***)(esi49 + 16) = *(void***)(a1 + 0x68);
        edi35 = edi35 + 40;
        v36 = (void*)((uint32_t)v36 + 40);
        ebp37 = ebp37 - 2;
    } while (ebp37);
    goto addr_0x405bcf_4;
    addr_0x405a96_6:
    esi56 = v21 + (a2->f192 + a2->f192 * 4) * 4;
    fun_417f90(esi56, edi35, v57, v58, v11, v9);
    v59 = *(void***)(edi35 + 12);
    eax62 = fun_402940(a1, v59, v22, 0x405ab0, esi56, edi35, v60, v61, v11, v9, v7, v5);
    *(void***)(esi56 + 8) = eax62;
    v40 = *(void***)(edi35 + 12);
    v63 = *(void***)(edi35 + 8);
    fun_417ac0(eax62, v63, v40, v64, v11, v9, v7, v5);
    *(void***)(esi56 + 12) = *(void***)(edi35 + 12);
    *(void***)(esi56 + 16) = *(void***)(a1 + 0x68);
    edi35 = edi35 + 20;
    v36 = (void*)20;
    ebp37 = a4 - 1;
    if (!ebp37) {
        addr_0x405bcf_4:
        a2->f188 = v21;
        a2->f192 = a2->f192 + a4;
        a2->f185 = (uint8_t)(a2->f185 | 2);
        goto addr_0x405bee_2;
    } else {
        goto addr_0x405b00_7;
    }
}

struct s154 {
    int8_t[560] pad560;
    uint8_t f560;
};

void fun_405c4d(struct s154* a1, uint8_t a2) {
    uint32_t eax3;

    if (a1) {
        *(uint8_t*)&eax3 = (uint8_t)((uint8_t)(a1->f560 & 0xfe) | (uint8_t)(a2 & 1));
        a1->f560 = (uint8_t)(eax3 & 0xff);
    }
    return;
}

struct s155 {
    int8_t[536] pad536;
    int32_t f536;
    int32_t f540;
};

void fun_405c75(struct s155* a1, int32_t a2, int32_t a3) {
    a1->f540 = a3;
    a1->f536 = a2;
    return;
}

struct s156 {
    int8_t[110] pad110;
    uint8_t f110;
};

void fun_406862(int32_t a1, int32_t a2, int32_t a3) {
    struct s156* esi4;
    int32_t v5;

    esi4->f110 = (uint8_t)(esi4->f110 & 0xfe);
    goto v5;
}

int32_t fun_4069d2() {
    return 0;
}

struct s157 {
    int8_t[569] pad569;
    int8_t f569;
    int8_t[2] pad572;
    int32_t f572;
};

void fun_406a19(struct s157* a1, int32_t a2, int32_t a3) {
    int32_t edx4;

    edx4 = a2;
    a1->f569 = *(int8_t*)&edx4;
    a1->f572 = a3;
    return;
}

void fun_407231(int32_t a1) {
    int32_t ecx2;
    uint32_t edi3;
    int32_t edi4;
    int32_t edi5;
    int8_t* esi6;
    int32_t v7;
    int32_t edi8;
    int8_t* edi9;
    int32_t edi10;
    int32_t edx11;
    int1_t zf12;
    int32_t v13;

    ecx2 = 8;
    if (edi3 <= 7) {
        if ((uint32_t)(8 + edi4) > 8) {
            ecx2 = 8 - edi5;
        }
        esi6 = (int8_t*)(v7 + edi8);
        edi9 = (int8_t*)(edi10 + edx11);
        zf12 = 1;
        while (ecx2) {
            --ecx2;
            zf12 = *esi6 == *edi9;
            *edi9 = *esi6;
            ++edi9;
            ++esi6;
        }
        if (!zf12) {
        }
    }
    goto v13;
}

void fun_4072c5(int32_t a1) {
    int8_t* esi2;
    int8_t* esi3;
    int32_t ecx4;
    int1_t zf5;
    int8_t* edi6;
    int32_t v7;

    esi2 = esi3;
    ecx4 = 8;
    if (!1) {
        ecx4 = 8;
    }
    zf5 = 1;
    while (ecx4) {
        --ecx4;
        zf5 = *esi2 == *edi6;
        *edi6 = *esi2;
        ++edi6;
        ++esi2;
    }
    if (!zf5) {
    }
    goto v7;
}

struct s158 {
    uint16_t f0;
    uint8_t f2;
    uint8_t f3;
    uint8_t f4;
    uint8_t f5;
    uint8_t f6;
};

struct s159 {
    int8_t[1] pad1;
    uint8_t f1;
};

void fun_407020(struct s159* ecx);

void** fun_4073bc(void** a1, struct s158* a2) {
    int32_t v3;
    void** v4;
    void** v5;
    void** ebx6;
    void** esi7;
    void** v8;
    void** v9;
    void** v10;
    void** v11;
    void** v12;
    void** eax13;
    uint32_t edx14;
    uint32_t eax15;
    uint16_t dx16;
    uint32_t edx17;
    uint32_t eax18;
    uint16_t dx19;
    uint32_t edx20;
    uint32_t eax21;
    uint16_t dx22;
    void** v23;
    uint32_t ecx24;
    int32_t edx25;
    void** eax26;
    void** v27;
    void** v28;
    void** v29;

    v3 = (int32_t)__return_address();
    if (!*(void***)(a1 + 0x210)) {
        eax13 = fun_402940(a1, 29, v4, v5, ebx6, esi7, v8, v9, v10, v11, v12, *(void***)&v3);
        *(void***)(a1 + 0x210) = eax13;
    }
    *(uint16_t*)&edx14 = static_cast<uint16_t>(a2->f6);
    eax15 = edx14;
    dx16 = (uint16_t)(*(uint16_t*)&eax15 % 61);
    *(uint16_t*)&eax15 = (uint16_t)(*(uint16_t*)&eax15 / 61);
    *(int8_t*)&eax15 = *(int8_t*)&dx16;
    *(uint16_t*)&edx17 = static_cast<uint16_t>(a2->f5);
    eax18 = edx17;
    dx19 = (uint16_t)(*(uint16_t*)&eax18 % 60);
    *(uint16_t*)&eax18 = (uint16_t)(*(uint16_t*)&eax18 / 60);
    *(int8_t*)&eax18 = *(int8_t*)&dx19;
    *(uint16_t*)&edx20 = static_cast<uint16_t>(a2->f4);
    eax21 = edx20;
    dx22 = (uint16_t)(*(uint16_t*)&eax21 % 24);
    *(uint16_t*)&eax21 = (uint16_t)(*(uint16_t*)&eax21 / 24);
    *(int8_t*)&eax21 = *(int8_t*)&dx22;
    v23 = (void**)static_cast<uint32_t>(a2->f0);
    ecx24 = a2->f2 + 0xffffffff;
    edx25 = (__intrinsic() >> 1) - ((int32_t)ecx24 >> 31);
    eax26 = (void**)((ecx24 - (edx25 + edx25 * 2 << 2)) * 4 + (uint32_t)fun_407020);
    v27 = eax26;
    *(uint8_t*)&eax26 = (uint8_t)(a2->f3 & 31);
    v28 = *(void***)(a1 + 0x210);
    fun_417450(v28, 0x407050, (uint8_t)eax26 & 0xff, v27, v23, eax21 & 0xff, eax18 & 0xff, eax15 & 0xff, ebx6, esi7, v29);
    return *(void***)(a1 + 0x210);
}

void fun_40748c(void** a1, void*** a2) {
    void** ebx3;
    void** v4;
    void** v5;
    void** v6;
    void** v7;
    void** v8;

    ebx3 = (void**)0;
    if (a2) {
        ebx3 = *a2;
    }
    if (ebx3) {
        fun_407590(a1, ebx3, v4);
        v5 = *(void***)(a1 + 0x244);
        v6 = *(void***)(a1 + 0x24c);
        fun_402b2c(ebx3, v6, v5, 0x4074b0, a1, ebx3, v7, v8);
        *a2 = (void**)0;
    }
    return;
}

struct s160 {
    int8_t[184] pad184;
    uint32_t f184;
};

struct s161 {
    int8_t[184] pad184;
    uint32_t f184;
};

void fun_407515(int32_t ecx, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10) {
    void** ebx11;
    void** v12;
    void** v13;
    struct s160* edx14;
    struct s161* edx15;
    int32_t eax16;

    if (ecx != 2) {
        fun_40850c(ebx11, 0x406be0, v12, v13, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
    } else {
        edx14->f184 = edx15->f184 & (uint32_t)~eax16;
    }
    goto a8;
}

int32_t fun_407555() {
    return "1.2.1";
}

int32_t fun_40756d() {
    return " libpng version 1.2.1 - December 12, 2001 (header)\n";
}

int32_t fun_407585() {
    return "1.2.1";
}

void fun_40763a() {
}

void fun_4076c1() {
}

void fun_40771e() {
}

void fun_407805() {
}

struct s162 {
    int8_t[1] pad1;
    int32_t f1;
};

void fun_407f80(uint8_t* ecx);

struct s163 {
    int8_t[108] pad108;
    uint32_t f108;
};

struct s164 {
    int8_t[64] pad64;
    int32_t f64;
};

void fun_40800f(int32_t a1, int32_t a2, int32_t a3) {
    void* esp4;
    void* v5;
    void* ebx6;
    uint32_t edx7;
    void* v8;
    uint32_t edx9;
    int32_t* esi10;
    void* v11;
    struct s162* edi12;
    void* ebx13;
    void* ebx14;
    void* ecx15;
    void* ebx16;
    void* ecx17;
    void* ebx18;
    void* ebx19;
    void* v20;
    void* ebx21;
    void* ebx22;
    void* ecx23;
    void* ebx24;
    void* ecx25;
    void* ebx26;
    int32_t v27;
    void* ebx28;
    void* ecx29;
    void* ebx30;
    void* ecx31;
    void* v32;
    int32_t* edi33;
    void* ebx34;
    int32_t* v35;
    int32_t ecx36;
    void* ebx37;
    void** ebx38;
    void** ebp39;
    uint32_t edx40;
    struct s163* v41;
    int32_t eax42;
    struct s164* v43;
    int8_t v44;
    void* eax45;
    int8_t v46;
    void* ebp47;
    void** v48;
    int32_t v49;
    void* ebp50;
    void* ecx51;
    void* esi52;
    void** edi53;
    void** ebx54;
    uint32_t eax55;
    void* ebp56;
    void* edx57;
    void* ebp58;
    void* edx59;
    void* ebp60;
    void* edx61;
    void* ebp62;
    void* ebp63;
    void* ebp64;

    esp4 = __zero_stack_offset();
    while (1) {
        *(int8_t*)((int32_t)v5 + (int32_t)ebx6) = *(int8_t*)&edx7;
        v8 = (void*)((int32_t)v5 + 1);
        while (1) {
            edx9 = static_cast<uint32_t>(*(uint8_t*)((int32_t)esi10 + (int32_t)v11));
            edi12 = (struct s162*)((int32_t)edi12 + 2);
            if (edx9 - 41 > 81 || edx9 - 91 <= 5) {
                *(int8_t*)((int32_t)v8 + (int32_t)ebx13) = 91;
                *(int8_t*)((int32_t)v8 + 1 + (int32_t)ebx14) = *(int8_t*)((edx9 >> 4) + (int32_t)fun_407f80);
                ecx15 = (void*)((int32_t)v8 + 1 + 1);
                *(int8_t*)((int32_t)ecx15 + (int32_t)ebx16) = *(int8_t*)((edx9 & 15) + (int32_t)fun_407f80);
                ecx17 = (void*)((int32_t)ecx15 + 1);
                *(int8_t*)((int32_t)ecx17 + (int32_t)ebx18) = 93;
                v5 = (void*)((int32_t)ecx17 + 1);
            } else {
                *(int8_t*)((int32_t)v8 + (int32_t)ebx19) = *(int8_t*)&edx9;
                v5 = (void*)((int32_t)v8 + 1);
            }
            if ((int32_t)edi12 > 3) 
                goto addr_0x408085_7;
            edx7 = static_cast<uint32_t>(*(uint8_t*)((int32_t)edi12 + (int32_t)v20));
            esi10 = &edi12->f1;
            if (edx7 - 41 > 81) 
                goto addr_0x407fd7_9;
            if (edx7 - 91 > 5) 
                break;
            addr_0x407fd7_9:
            *(int8_t*)((int32_t)v5 + (int32_t)ebx21) = 91;
            *(int8_t*)((int32_t)v5 + 1 + (int32_t)ebx22) = *(int8_t*)((edx7 >> 4) + (int32_t)fun_407f80);
            ecx23 = (void*)((int32_t)v5 + 1 + 1);
            *(int8_t*)((int32_t)ecx23 + (int32_t)ebx24) = *(int8_t*)((edx7 & 15) + (int32_t)fun_407f80);
            ecx25 = (void*)((int32_t)ecx23 + 1);
            *(int8_t*)((int32_t)ecx25 + (int32_t)ebx26) = 93;
            v8 = (void*)((int32_t)ecx25 + 1);
        }
    }
    addr_0x408085_7:
    if (v27) {
        *(int8_t*)((int32_t)v5 + (int32_t)ebx28) = 58;
        ecx29 = (void*)((int32_t)v5 + 1);
        *(int8_t*)((int32_t)ecx29 + (int32_t)ebx30) = 32;
        ecx31 = (void*)((int32_t)ecx29 + 1);
        v32 = ecx31;
        edi33 = (int32_t*)((int32_t)ecx31 + (int32_t)ebx34);
        esi10 = v35;
        ecx36 = 16;
        while (ecx36) {
            --ecx36;
            *edi33 = *esi10;
            ++edi33;
            ++esi10;
        }
        *(int8_t*)((int32_t)esp4 + (int32_t)v32 + 0x7f) = 0;
    } else {
        *(int8_t*)((int32_t)v5 + (int32_t)ebx37) = 0;
    }
    ebx38 = ebp39;
    edx40 = v41->f108;
    if (!(v41->f108 & 0xc0000)) {
        addr_0x4081a5_17:
        eax42 = v43->f64;
        if (eax42) {
            eax42(v43, ebx38);
        }
    } else {
        if (v44 != 35) {
            if (v41->f108 & 0x80000) {
                ebx38 = (void**)((int32_t)esp4 + 48);
                goto addr_0x4081a5_17;
            }
        } else {
            eax45 = (void*)1;
            if (v46 != 32) {
                do {
                    eax45 = (void*)((int32_t)eax45 + 1);
                    if ((int32_t)eax45 > 14) 
                        break;
                } while (*(int8_t*)((int32_t)eax45 + (int32_t)ebp47) != 32);
            }
            if (!(edx40 & 0x80000)) 
                goto addr_0x408188_27; else 
                goto addr_0x408110_28;
        }
    }
    fun_408578(v48, ebx38);
    goto v49;
    addr_0x408188_27:
    ebx38 = (void**)((int32_t)eax45 + (uint32_t)ebp50);
    goto addr_0x4081a5_17;
    addr_0x408110_28:
    ecx51 = (void*)0;
    esi52 = (void*)((int32_t)eax45 + 0xffffffff);
    edi53 = (void**)((int32_t)esp4 + 48);
    if ((int32_t)0 >= (int32_t)esi52) 
        goto addr_0x408180_30;
    ebx54 = edi53;
    eax55 = (uint32_t)esi52 & 3;
    if (!((uint1_t)((int32_t)esi52 < (int32_t)0) | (uint1_t)(esi52 == 0))) {
        if (!eax55) {
            do {
                addr_0x408154_33:
                *(int8_t*)((uint32_t)ecx51 + (uint8_t)ebx54) = *(int8_t*)((int32_t)ebp56 + (uint32_t)ecx51 + 1);
                edx57 = (void*)((uint32_t)ecx51 + 1);
                *(int8_t*)((uint32_t)edx57 + (uint8_t)ebx54) = *(int8_t*)((int32_t)ebp58 + (uint32_t)edx57 + 1);
                edx59 = (void*)((uint32_t)ecx51 + 2);
                *(int8_t*)((uint32_t)edx59 + (uint8_t)ebx54) = *(int8_t*)((int32_t)ebp60 + (uint32_t)edx59 + 1);
                edx61 = (void*)((uint32_t)ecx51 + 3);
                *(int8_t*)((uint32_t)edx61 + (uint8_t)ebx54) = *(int8_t*)((int32_t)ebp62 + (uint32_t)edx61 + 1);
                ecx51 = (void*)((uint32_t)ecx51 + 4);
            } while ((int32_t)ecx51 < (int32_t)esi52);
            goto addr_0x408180_30;
        } else {
            if ((int32_t)eax55 > (int32_t)1) {
                if ((int32_t)eax55 > (int32_t)2) {
                    ecx51 = (void*)1;
                }
                *(int8_t*)((uint32_t)ecx51 + (uint8_t)edi53) = *(int8_t*)((int32_t)ebp63 + (uint32_t)ecx51 + 1);
                ecx51 = (void*)((uint32_t)ecx51 + 1);
            }
        }
    }
    *(int8_t*)((uint32_t)ecx51 + (uint8_t)ebx54) = *(int8_t*)((int32_t)ebp64 + (uint32_t)ecx51 + 1);
    ecx51 = (void*)((uint32_t)ecx51 + 1);
    if ((int32_t)ecx51 >= (int32_t)esi52) {
        addr_0x408180_30:
        *(int8_t*)((uint32_t)ecx51 + (uint8_t)edi53) = 0;
        ebx38 = edi53;
        goto addr_0x4081a5_17;
    } else {
        esi52 = esi52;
        goto addr_0x408154_33;
    }
}

void fun_408099() {
}

struct s165 {
    int8_t[1] pad1;
    int32_t f1;
};

void** fun_4081dc(void** a1, int32_t* a2) {
    void* esp3;
    void* ebx4;
    void* v5;
    struct s165* edi6;
    uint8_t* ebp7;
    uint32_t edx8;
    void* ecx9;
    void* ecx10;
    void* v11;
    uint32_t edx12;
    void* ecx13;
    void* ecx14;
    void* ecx15;
    void* ecx16;
    void* ecx17;
    void* v18;
    int32_t* edi19;
    int32_t* esi20;
    int32_t ecx21;
    void* eax22;
    void* edx23;
    int8_t v24;
    int8_t v25;
    void** eax26;

    esp3 = (void*)((int32_t)__zero_stack_offset() - 0x7c - 4 - 4 - 4 - 4);
    ebx4 = (void*)((int32_t)esp3 + 32);
    v5 = (void*)0;
    edi6 = (struct s165*)0;
    ebp7 = (uint8_t*)(a1 + 0x11c);
    do {
        edx8 = static_cast<uint32_t>(*(uint8_t*)((int32_t)edi6 + (uint32_t)ebp7));
        if (edx8 - 41 > 81 || edx8 - 91 <= 5) {
            *(int8_t*)((int32_t)v5 + (int32_t)ebx4) = 91;
            *(int8_t*)((int32_t)v5 + 1 + (int32_t)ebx4) = *(int8_t*)((edx8 >> 4) + (int32_t)fun_407f80);
            ecx9 = (void*)((int32_t)v5 + 1 + 1);
            *(int8_t*)((int32_t)ecx9 + (int32_t)ebx4) = *(int8_t*)((edx8 & 15) + (int32_t)fun_407f80);
            ecx10 = (void*)((int32_t)ecx9 + 1);
            *(int8_t*)((int32_t)ecx10 + (int32_t)ebx4) = 93;
            v11 = (void*)((int32_t)ecx10 + 1);
        } else {
            *(int8_t*)((int32_t)v5 + (int32_t)ebx4) = *(int8_t*)&edx8;
            v11 = (void*)((int32_t)v5 + 1);
        }
        edx12 = static_cast<uint32_t>(*(uint8_t*)((int32_t)&edi6->f1 + (uint32_t)ebp7));
        edi6 = (struct s165*)((int32_t)edi6 + 2);
        if (edx12 - 41 > 81 || edx12 - 91 <= 5) {
            *(int8_t*)((int32_t)v11 + (int32_t)ebx4) = 91;
            ecx13 = (void*)((int32_t)v11 + 1);
            *(int8_t*)((int32_t)ecx13 + (int32_t)ebx4) = *(int8_t*)((edx12 >> 4) + (int32_t)fun_407f80);
            ecx14 = (void*)((int32_t)ecx13 + 1);
            *(int8_t*)((int32_t)ecx14 + (int32_t)ebx4) = *(int8_t*)((edx12 & 15) + (int32_t)fun_407f80);
            ecx15 = (void*)((int32_t)ecx14 + 1);
            *(int8_t*)((int32_t)ecx15 + (int32_t)ebx4) = 93;
            v5 = (void*)((int32_t)ecx15 + 1);
        } else {
            *(int8_t*)((int32_t)v11 + (int32_t)ebx4) = *(int8_t*)&edx12;
            v5 = (void*)((int32_t)v11 + 1);
        }
    } while ((int32_t)edi6 <= 3);
    if (a2) {
        *(int8_t*)((int32_t)v5 + (int32_t)ebx4) = 58;
        ecx16 = (void*)((int32_t)v5 + 1);
        *(int8_t*)((int32_t)ecx16 + (int32_t)ebx4) = 32;
        ecx17 = (void*)((int32_t)ecx16 + 1);
        v18 = ecx17;
        edi19 = (int32_t*)((int32_t)ecx17 + (int32_t)ebx4);
        esi20 = a2;
        ecx21 = 16;
        while (ecx21) {
            --ecx21;
            *edi19 = *esi20;
            ++edi19;
            ++esi20;
        }
        *(int8_t*)((int32_t)esp3 + (int32_t)v18 + 95) = 0;
    } else {
        *(int8_t*)((int32_t)v5 + (int32_t)ebx4) = 0;
    }
    eax22 = (void*)0;
    edx23 = *(void**)(a1 + 68);
    if (*(uint8_t*)(a1 + 0x6e) & 12 && (v24 == 35 && (eax22 = (void*)1, v25 != 32))) {
        do {
            eax22 = (void*)((int32_t)eax22 + 1);
            if ((int32_t)eax22 > 14) 
                break;
        } while (*(int8_t*)((int32_t)esp3 + (int32_t)eax22 + 32) != 32);
    }
    if (!edx23) {
        eax26 = fun_4085f8(a1, (int32_t)esp3 - 8 + (int32_t)eax22 + 40);
    } else {
        eax26 = a1;
        edx23(eax26, (int32_t)esp3 - 8 + (int32_t)eax22 + 40);
    }
    return eax26;
}

void fun_4082cd() {
}

void fun_408345() {
}

void fun_40854a() {
}

struct s166 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
};

struct s167 {
    int8_t[1] pad1;
    int8_t f1;
    int8_t[1] pad3;
    int8_t f3;
    int8_t[1] pad5;
    int8_t f5;
    int8_t[1] pad7;
    int8_t f7;
};

struct s168 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s169 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s170 {
    int8_t f0;
    int8_t f1;
};

struct s171 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s172 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s173 {
    int8_t f0;
    int8_t f1;
};

struct s174 {
    int8_t[11] pad11;
    int8_t f11;
};

struct s175 {
    int8_t[4] pad4;
    uint32_t f4;
};

struct s176 {
    int8_t[10] pad10;
    int8_t f10;
};

struct s177 {
    int8_t[8] pad8;
    uint8_t f8;
};

struct s178 {
    int8_t[8] pad8;
    uint8_t f8;
};

void fun_408a45(int32_t a1, int32_t a2, int32_t a3) {
    uint32_t esi4;
    uint32_t esi5;
    uint32_t ebx6;
    uint32_t eax7;
    struct s166* edx8;
    struct s167* ecx9;
    int8_t* edx10;
    struct s168* edx11;
    struct s169* ecx12;
    void* edx13;
    struct s170* edx14;
    struct s171* edx15;
    int8_t* ecx16;
    struct s172* ecx17;
    struct s173* edx18;
    int8_t* ecx19;
    struct s174* ebp20;
    struct s175* ebp21;
    struct s176* ebp22;
    struct s177* ebp23;
    struct s178* ebp24;
    int32_t v25;

    esi4 = esi5;
    ebx6 = 0;
    if (0 >= esi4) 
        goto addr_0x408aa8_3;
    eax7 = esi4 & 3;
    if (!((uint1_t)((int32_t)esi4 < (int32_t)0) | (uint1_t)(esi4 == 0))) {
        if (!eax7) {
            do {
                addr_0x408a84_6:
                edx8->f0 = ecx9->f1;
                edx8->f1 = ecx9->f3;
                edx8->f2 = ecx9->f5;
                edx8->f3 = ecx9->f7;
                ++ecx9;
                ++edx8;
                ebx6 = ebx6 + 4;
            } while (ebx6 < esi4);
            goto addr_0x408aa8_3;
        } else {
            if ((int32_t)eax7 > (int32_t)1) {
                if ((int32_t)eax7 > (int32_t)2) {
                    *edx10 = edx11->f1;
                    ecx12 = (struct s169*)((int32_t)edx13 + 2);
                    edx14 = (struct s170*)&edx15->f1;
                    ebx6 = 1;
                }
                ecx16 = &ecx12->f1;
                edx14->f0 = *ecx16;
                ecx17 = (struct s172*)(ecx16 + 1);
                edx18 = (struct s173*)&edx14->f1;
                ++ebx6;
            }
        }
    }
    ecx19 = &ecx17->f1;
    edx18->f0 = *ecx19;
    ecx9 = (struct s167*)(ecx19 + 1);
    edx8 = (struct s166*)&edx18->f1;
    ++ebx6;
    if (ebx6 >= esi4) {
        addr_0x408aa8_3:
        ebp20->f11 = 8;
        ebp21->f4 = esi4;
    } else {
        goto addr_0x408a84_6;
    }
    ebp22->f10 = 1;
    ebp23->f8 = (uint8_t)(ebp24->f8 & 0xfb);
    goto v25;
}

struct s179 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
    int8_t[1] pad4;
    int8_t f4;
    int8_t[3] pad8;
    int8_t f8;
    int8_t[3] pad12;
    int8_t f12;
};

struct s180 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

struct s181 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

struct s182 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

void fun_408ce6(int32_t a1, int32_t a2, int32_t a3, int32_t a4) {
    int8_t al5;
    uint32_t edi6;
    struct s179* ebx7;
    struct s179* esi8;
    uint32_t ebp9;
    uint32_t eax10;
    uint32_t ebp11;
    int32_t ebp12;
    int32_t ebp13;
    int8_t dl14;
    uint32_t ebp15;
    int8_t dl16;
    struct s180* edx17;
    int8_t cl18;
    struct s181* edx19;
    int8_t cl20;
    struct s182* edx21;
    int8_t cl22;
    uint32_t ebp23;
    int8_t dl24;
    int8_t dl25;

    if (al5 != 6) 
        goto addr_0x408f85_3;
    edi6 = 0;
    ebx7 = esi8;
    if (0 >= ebp9) 
        goto addr_0x408f85_3;
    eax10 = ebp11 & 3;
    if ((uint1_t)(ebp12 < 0) | (uint1_t)(ebp13 == 0)) {
        addr_0x408d2f_6:
        dl14 = ebx7->f0;
        ebx7->f0 = ebx7->f2;
        ebx7->f2 = dl14;
        ++edi6;
        ebx7 = (struct s179*)&ebx7->f4;
        if (edi6 >= ebp15) {
            addr_0x408f85_3:
            goto a4;
        } else {
            goto addr_0x408d48_8;
        }
    } else {
        if (!eax10) {
            do {
                addr_0x408d48_8:
                dl16 = ebx7->f0;
                ebx7->f0 = ebx7->f2;
                ebx7->f2 = dl16;
                edx17 = (struct s180*)&ebx7->f4;
                cl18 = ebx7->f4;
                ebx7->f4 = edx17->f2;
                edx17->f2 = cl18;
                edx19 = (struct s181*)&ebx7->f8;
                cl20 = ebx7->f8;
                ebx7->f8 = edx19->f2;
                edx19->f2 = cl20;
                edx21 = (struct s182*)&ebx7->f12;
                cl22 = ebx7->f12;
                ebx7->f12 = edx21->f2;
                edx21->f2 = cl22;
                edi6 = edi6 + 4;
                ebx7 = (struct s179*)((int32_t)ebx7 + 16);
            } while (edi6 < ebp23);
        } else {
            if ((int32_t)eax10 > (int32_t)1) {
                if ((int32_t)eax10 > (int32_t)2) {
                    dl24 = esi8->f0;
                    esi8->f0 = esi8->f2;
                    esi8->f2 = dl24;
                    edi6 = 1;
                    ebx7 = (struct s179*)&esi8->f4;
                }
                dl25 = ebx7->f0;
                ebx7->f0 = ebx7->f2;
                ebx7->f2 = dl25;
                ++edi6;
                ebx7 = (struct s179*)&ebx7->f4;
                goto addr_0x408d2f_6;
            }
        }
    }
    goto addr_0x408f85_3;
}

struct s183 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
    int8_t f6;
    int8_t[1] pad8;
    int8_t f8;
    int8_t[3] pad12;
    int8_t f12;
    int8_t[3] pad16;
    int8_t f16;
    int8_t[1] pad18;
    int8_t f18;
    int8_t[5] pad24;
    int8_t f24;
};

struct s184 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

struct s185 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

struct s186 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

struct s187 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

struct s188 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

struct s189 {
    int8_t f0;
    int8_t f1;
    int8_t[2] pad4;
    int8_t f4;
    int8_t f5;
};

void fun_408d8e() {
    int8_t dl1;
    int8_t al2;
    int8_t al3;
    uint32_t edi4;
    struct s183* ecx5;
    struct s183* esi6;
    uint32_t ebp7;
    uint32_t eax8;
    uint32_t ebp9;
    int32_t ebp10;
    int32_t ebp11;
    uint32_t edi12;
    struct s183* ecx13;
    uint32_t ebp14;
    uint32_t eax15;
    uint32_t ebp16;
    int32_t ebp17;
    int32_t ebp18;
    int8_t dl19;
    int8_t dl20;
    uint32_t ebp21;
    int8_t dl22;
    int8_t dl23;
    struct s184* edx24;
    int8_t bl25;
    int8_t bl26;
    struct s185* edx27;
    int8_t bl28;
    int8_t bl29;
    struct s186* edx30;
    int8_t bl31;
    int8_t bl32;
    uint32_t ebp33;
    int8_t dl34;
    int8_t dl35;
    int8_t dl36;
    int8_t dl37;
    int8_t dl38;
    int8_t dl39;
    uint32_t ebp40;
    int8_t dl41;
    int8_t dl42;
    struct s187* edx43;
    int8_t bl44;
    int8_t bl45;
    struct s188* edx46;
    int8_t bl47;
    int8_t bl48;
    struct s189* edx49;
    int8_t bl50;
    int8_t bl51;
    uint32_t ebp52;
    int8_t dl53;
    int8_t dl54;
    int8_t dl55;
    int8_t dl56;

    if (dl1 != 16) 
        goto 0x408f85;
    if (al2 != 2) {
        if (al3 != 6) 
            goto 0x408f85;
        edi4 = 0;
        ecx5 = esi6;
        if (0 >= ebp7) 
            goto 0x408f85;
        eax8 = ebp9 & 3;
        if (!((uint1_t)(ebp10 < 0) | (uint1_t)(ebp11 == 0))) 
            goto addr_0x408eb1_7;
    } else {
        edi12 = 0;
        ecx13 = esi6;
        if (0 >= ebp14) 
            goto 0x408f85;
        eax15 = ebp16 & 3;
        if ((uint1_t)(ebp17 < 0) | (uint1_t)(ebp18 == 0)) 
            goto addr_0x408df8_10; else 
            goto addr_0x408db6_11;
    }
    addr_0x408ef3_12:
    dl19 = ecx5->f0;
    ecx5->f0 = ecx5->f4;
    ecx5->f4 = dl19;
    dl20 = ecx5->f1;
    ecx5->f1 = ecx5->f5;
    ecx5->f5 = dl20;
    ++edi4;
    ecx5 = (struct s183*)&ecx5->f8;
    if (edi4 >= ebp21) 
        goto 0x408f85;
    goto addr_0x408f14_14;
    addr_0x408eb1_7:
    if (!eax8) {
        while (1) {
            addr_0x408f14_14:
            dl22 = ecx5->f0;
            ecx5->f0 = ecx5->f4;
            ecx5->f4 = dl22;
            dl23 = ecx5->f1;
            ecx5->f1 = ecx5->f5;
            ecx5->f5 = dl23;
            edx24 = (struct s184*)&ecx5->f8;
            bl25 = ecx5->f8;
            ecx5->f8 = edx24->f4;
            edx24->f4 = bl25;
            bl26 = edx24->f1;
            edx24->f1 = edx24->f5;
            edx24->f5 = bl26;
            edx27 = (struct s185*)&ecx5->f16;
            bl28 = ecx5->f16;
            ecx5->f16 = edx27->f4;
            edx27->f4 = bl28;
            bl29 = edx27->f1;
            edx27->f1 = edx27->f5;
            edx27->f5 = bl29;
            edx30 = (struct s186*)&ecx5->f24;
            bl31 = ecx5->f24;
            ecx5->f24 = edx30->f4;
            edx30->f4 = bl31;
            bl32 = edx30->f1;
            edx30->f1 = edx30->f5;
            edx30->f5 = bl32;
            edi4 = edi4 + 4;
            ecx5 = (struct s183*)((int32_t)ecx5 + 32);
            if (edi4 >= ebp33) 
                goto "???";
        }
    } else {
        if ((int32_t)eax8 > (int32_t)1) {
            if ((int32_t)eax8 > (int32_t)2) {
                dl34 = ecx5->f0;
                ecx5->f0 = ecx5->f4;
                ecx5->f4 = dl34;
                dl35 = ecx5->f1;
                ecx5->f1 = ecx5->f5;
                ecx5->f5 = dl35;
                edi4 = 1;
                ecx5 = (struct s183*)&ecx5->f8;
            }
            dl36 = ecx5->f0;
            ecx5->f0 = ecx5->f4;
            ecx5->f4 = dl36;
            dl37 = ecx5->f1;
            ecx5->f1 = ecx5->f5;
            ecx5->f5 = dl37;
            ++edi4;
            ecx5 = (struct s183*)&ecx5->f8;
            goto addr_0x408ef3_12;
        }
    }
    addr_0x408df8_10:
    dl38 = ecx13->f0;
    ecx13->f0 = ecx13->f4;
    ecx13->f4 = dl38;
    dl39 = ecx13->f1;
    ecx13->f1 = ecx13->f5;
    ecx13->f5 = dl39;
    ++edi12;
    ecx13 = (struct s183*)&ecx13->f6;
    if (edi12 >= ebp40) 
        goto 0x408f85;
    goto addr_0x408e1c_20;
    addr_0x408db6_11:
    if (!eax15) {
        do {
            addr_0x408e1c_20:
            dl41 = ecx13->f0;
            ecx13->f0 = ecx13->f4;
            ecx13->f4 = dl41;
            dl42 = ecx13->f1;
            ecx13->f1 = ecx13->f5;
            ecx13->f5 = dl42;
            edx43 = (struct s187*)&ecx13->f6;
            bl44 = ecx13->f6;
            ecx13->f6 = edx43->f4;
            edx43->f4 = bl44;
            bl45 = edx43->f1;
            edx43->f1 = edx43->f5;
            edx43->f5 = bl45;
            edx46 = (struct s188*)&ecx13->f12;
            bl47 = ecx13->f12;
            ecx13->f12 = edx46->f4;
            edx46->f4 = bl47;
            bl48 = edx46->f1;
            edx46->f1 = edx46->f5;
            edx46->f5 = bl48;
            edx49 = (struct s189*)&ecx13->f18;
            bl50 = ecx13->f18;
            ecx13->f18 = edx49->f4;
            edx49->f4 = bl50;
            bl51 = edx49->f1;
            edx49->f1 = edx49->f5;
            edx49->f5 = bl51;
            edi12 = edi12 + 4;
            ecx13 = (struct s183*)&ecx13->f24;
        } while (edi12 < ebp52);
    } else {
        if ((int32_t)eax15 > (int32_t)1) {
            if ((int32_t)eax15 > (int32_t)2) {
                dl53 = esi6->f0;
                esi6->f0 = esi6->f4;
                esi6->f4 = dl53;
                dl54 = esi6->f1;
                esi6->f1 = esi6->f5;
                esi6->f5 = dl54;
                edi12 = 1;
                ecx13 = (struct s183*)&esi6->f6;
            }
            dl55 = ecx13->f0;
            ecx13->f0 = ecx13->f4;
            ecx13->f4 = dl55;
            dl56 = ecx13->f1;
            ecx13->f1 = ecx13->f5;
            ecx13->f5 = dl56;
            ++edi12;
            ecx13 = (struct s183*)&ecx13->f6;
            goto addr_0x408df8_10;
        }
    }
    goto 0x408f85;
}

void fun_408e92() {
}

void fun_408f8a() {
}

void fun_40901a() {
}

void fun_409035() {
}

void fun_40904a() {
}

struct s190 {
    int8_t[4] pad4;
    uint32_t f4;
    int8_t[1] pad9;
    uint8_t f9;
};

struct s191 {
    uint8_t f0;
    uint8_t f1;
    uint8_t f2;
    uint8_t f3;
};

void fun_40916d(struct s190* a1, struct s191* a2) {
    struct s191* ecx3;
    int32_t ebx4;
    struct s191* edx5;
    uint32_t eax6;

    if (a1->f9 > 7) 
        goto addr_0x409219_2;
    ecx3 = (struct s191*)((uint32_t)a2 + a1->f4);
    if (a1->f9 != 1) {
        if (a1->f9 != 2) {
            if (a1->f9 != 4) 
                goto addr_0x409219_2;
            ebx4 = 0x420640;
        } else {
            ebx4 = 0x420540;
        }
    } else {
        ebx4 = 0x420440;
    }
    edx5 = a2;
    if ((uint32_t)edx5 >= (uint32_t)ecx3) 
        goto addr_0x409219_2;
    eax6 = (uint32_t)ecx3 - (uint32_t)edx5 & 3;
    if ((int32_t)edx5 < (int32_t)ecx3) {
        if (!eax6) {
            do {
                addr_0x4091ec_12:
                edx5->f0 = *(uint8_t*)(edx5->f0 + ebx4);
                edx5->f1 = *(uint8_t*)(edx5->f1 + ebx4);
                edx5->f2 = *(uint8_t*)(edx5->f2 + ebx4);
                edx5->f3 = *(uint8_t*)(edx5->f3 + ebx4);
                ++edx5;
            } while ((uint32_t)edx5 < (uint32_t)ecx3);
            goto addr_0x409219_2;
        } else {
            if ((int32_t)eax6 > (int32_t)1) {
                if ((int32_t)eax6 > (int32_t)2) {
                    edx5->f0 = *(uint8_t*)(edx5->f0 + ebx4);
                    edx5 = (struct s191*)&edx5->f1;
                }
                edx5->f0 = *(uint8_t*)(edx5->f0 + ebx4);
                edx5 = (struct s191*)&edx5->f1;
            }
        }
    }
    edx5->f0 = *(uint8_t*)(edx5->f0 + ebx4);
    edx5 = (struct s191*)&edx5->f1;
    if ((uint32_t)edx5 >= (uint32_t)ecx3) {
        addr_0x409219_2:
        return;
    } else {
        goto addr_0x4091ec_12;
    }
}

void fun_409195() {
}

struct s192 {
    int8_t[4] pad4;
    uint32_t f4;
    uint8_t f8;
};

struct s193 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
    int8_t f4;
    int8_t f5;
    int8_t f6;
    int8_t[1] pad8;
    int8_t f8;
    int8_t f9;
    int8_t[2] pad12;
    int8_t f12;
    int8_t f13;
};

void fun_40921c(struct s192* a1, struct s193* a2) {
    uint32_t eax3;
    struct s193* eax4;
    uint32_t ebx5;
    uint32_t ecx6;
    uint32_t edx7;
    struct s193* eax8;
    uint32_t esi9;
    uint32_t ecx10;
    uint32_t edx11;
    struct s193* eax12;
    uint32_t esi13;
    uint32_t ecx14;
    uint32_t edx15;

    if (a1->f8) {
        eax3 = static_cast<uint32_t>((uint16_t)a1->f8);
        if (*(int16_t*)&eax3 != 0x804) {
            if (*(int16_t*)&eax3 != 0x1004) 
                goto addr_0x409369_4;
            eax4 = a2;
            ebx5 = a1->f4;
            ecx6 = 0;
            if (0 >= ebx5) 
                goto addr_0x409369_4;
            edx7 = ebx5 & 15;
            if (!((uint1_t)((int32_t)ebx5 < (int32_t)0) | (uint1_t)(ebx5 == 0))) 
                goto addr_0x40930e_7;
        } else {
            eax8 = a2;
            esi9 = a1->f4;
            ecx10 = 0;
            if (0 >= esi9) 
                goto addr_0x409369_4;
            edx11 = esi9 & 7;
            if ((uint1_t)((int32_t)esi9 < (int32_t)0) | (uint1_t)(esi9 == 0)) 
                goto addr_0x4092cb_10;
            if (!edx11) 
                goto addr_0x4092dc_12;
            if ((int32_t)edx11 <= (int32_t)2) {
                addr_0x4092cb_10:
                eax8->f0 = (int8_t)~eax8->f0;
                eax8 = (struct s193*)&eax8->f2;
                ecx10 = ecx10 + 2;
                if (ecx10 >= esi9) 
                    goto addr_0x409369_4; else 
                    goto addr_0x4092db_14;
            } else {
                if ((int32_t)edx11 <= (int32_t)4) {
                    addr_0x4092c3_16:
                    eax8->f0 = (int8_t)~eax8->f0;
                    eax8 = (struct s193*)&eax8->f2;
                    ecx10 = ecx10 + 2;
                    goto addr_0x4092cb_10;
                } else {
                    if ((int32_t)edx11 >= (int32_t)7) {
                        do {
                            addr_0x4092dc_12:
                            eax8->f0 = (int8_t)~eax8->f0;
                            eax8->f2 = (int8_t)~eax8->f2;
                            eax8->f4 = (int8_t)~eax8->f4;
                            eax8->f6 = (int8_t)~eax8->f6;
                            eax8 = (struct s193*)&eax8->f8;
                            ecx10 = ecx10 + 8;
                        } while (ecx10 < esi9);
                        goto addr_0x4092f1_18;
                    } else {
                        a2->f0 = (int8_t)~a2->f0;
                        eax8 = (struct s193*)&a2->f2;
                        ecx10 = 2;
                        goto addr_0x4092c3_16;
                    }
                }
            }
        }
    } else {
        eax12 = a2;
        esi13 = a1->f4;
        ecx14 = 0;
        if (0 >= esi13) 
            goto addr_0x409369_4;
        edx15 = esi13 & 3;
        if ((uint1_t)((int32_t)esi13 < (int32_t)0) | (uint1_t)(esi13 == 0)) 
            goto addr_0x40925c_22; else 
            goto addr_0x409244_23;
    }
    addr_0x409339_24:
    eax4->f0 = (int8_t)~eax4->f0;
    eax4->f1 = (int8_t)~eax4->f1;
    eax4 = (struct s193*)&eax4->f4;
    ecx6 = ecx6 + 4;
    if (ecx6 >= ebx5) {
        addr_0x409369_4:
        return;
    } else {
        do {
            addr_0x409348_25:
            eax4->f0 = (int8_t)~eax4->f0;
            eax4->f1 = (int8_t)~eax4->f1;
            eax4->f4 = (int8_t)~eax4->f4;
            eax4->f5 = (int8_t)~eax4->f5;
            eax4->f8 = (int8_t)~eax4->f8;
            eax4->f9 = (int8_t)~eax4->f9;
            eax4->f12 = (int8_t)~eax4->f12;
            eax4->f13 = (int8_t)~eax4->f13;
            eax4 = (struct s193*)((int32_t)eax4 + 16);
            ecx6 = ecx6 + 16;
        } while (ecx6 < ebx5);
        goto addr_0x409369_4;
    }
    addr_0x40930e_7:
    if (!edx7) 
        goto addr_0x409348_25;
    if ((int32_t)edx7 <= (int32_t)4) 
        goto addr_0x409339_24;
    if ((int32_t)edx7 > (int32_t)8) {
        if ((int32_t)edx7 >= (int32_t)13) 
            goto addr_0x409348_25;
        eax4->f0 = (int8_t)~eax4->f0;
        eax4->f1 = (int8_t)~eax4->f1;
        eax4 = (struct s193*)&eax4->f4;
        ecx6 = 4;
    }
    eax4->f0 = (int8_t)~eax4->f0;
    eax4->f1 = (int8_t)~eax4->f1;
    eax4 = (struct s193*)&eax4->f4;
    ecx6 = ecx6 + 4;
    goto addr_0x409339_24;
    addr_0x4092db_14:
    goto addr_0x4092dc_12;
    addr_0x4092f1_18:
    goto addr_0x409369_4;
    addr_0x40925c_22:
    eax12->f0 = (int8_t)~eax12->f0;
    eax12 = (struct s193*)&eax12->f1;
    ++ecx14;
    if (ecx14 >= esi13) 
        goto addr_0x409369_4; else 
        goto addr_0x409268_31;
    addr_0x409244_23:
    if (!edx15) {
        do {
            addr_0x409268_31:
            eax12->f0 = (int8_t)~eax12->f0;
            eax12->f1 = (int8_t)~eax12->f1;
            eax12->f2 = (int8_t)~eax12->f2;
            eax12->f3 = (int8_t)~eax12->f3;
            eax12 = (struct s193*)&eax12->f4;
            ecx14 = ecx14 + 4;
        } while (ecx14 < esi13);
    } else {
        if ((int32_t)edx15 > (int32_t)1) {
            if ((int32_t)edx15 > (int32_t)2) {
                a2->f0 = (int8_t)~a2->f0;
                eax12 = (struct s193*)&a2->f1;
                ecx14 = 1;
            }
            eax12->f0 = (int8_t)~eax12->f0;
            eax12 = (struct s193*)&eax12->f1;
            ++ecx14;
            goto addr_0x40925c_22;
        }
    }
    goto addr_0x409369_4;
}

void fun_409282() {
}

void* fun_415660(struct s26* a1, uint32_t a2);

struct s194 {
    int8_t f0;
    int8_t f1;
};

uint32_t fun_40a090(struct s26* a1, int32_t a2) {
    struct s26* ebp3;
    uint32_t edi4;
    uint32_t v5;
    void** eax6;
    void** ecx7;
    int32_t ecx8;
    void** edx9;
    uint32_t ebx10;
    void** ecx11;
    void** eax12;
    void** edx13;
    void** eax14;
    void** cx15;
    void* eax16;
    void* eax17;
    int8_t al18;
    int32_t esi19;
    uint32_t v20;
    uint32_t eax21;
    int32_t edx22;
    int32_t esi23;
    int8_t cl24;
    int8_t cl25;
    int32_t edx26;
    void* eax27;
    int32_t edx28;
    int32_t eax29;
    int32_t ecx30;
    int32_t ecx31;
    void* eax32;
    void** ebx33;
    int1_t below_or_equal34;
    void** ecx35;
    void* eax36;
    void** edx37;
    struct s27* eax38;
    void** edx39;
    void** esi40;
    void*** edi41;
    void** ebx42;
    uint32_t ecx43;
    uint32_t ecx44;
    struct s28* ecx45;
    uint32_t ebx46;
    struct s28* ecx47;
    void** ecx48;
    struct s194* edx49;
    void** eax50;
    int32_t ecx51;
    void** edi52;
    void** eax53;
    uint32_t ecx54;
    int32_t ecx55;
    void** ecx56;
    void** eax57;
    void* eax58;
    void** ecx59;
    void* eax60;
    int32_t edx61;
    void** v62;
    struct s27* eax63;
    void** edx64;
    int32_t eax65;
    int32_t eax66;
    void** esi67;
    void*** edi68;
    void** ebx69;
    uint32_t ecx70;
    uint32_t ecx71;
    struct s28* ecx72;
    void** edi73;
    struct s28* ecx74;

    ebp3 = a1;
    edi4 = 0;
    v5 = 0;
    while (1) {
        eax6 = ebp3->f108;
        if ((uint8_t)eax6 < (uint8_t)0x106) {
            fun_409ee0(ecx7, ebp3);
            eax6 = ebp3->f108;
            if ((uint8_t)eax6 >= (uint8_t)0x106) 
                goto addr_0x40a0ca_4;
            if (!a2) 
                break;
            addr_0x40a0ca_4:
            if (!eax6) 
                goto addr_0x40a3ba_6;
        }
        if ((uint8_t)eax6 >= (uint8_t)3) {
            ecx8 = ebp3->f80;
            edx9 = ebp3->f100;
            ebx10 = 0;
            *(int8_t*)&ebx10 = *(int8_t*)((uint32_t)ebp3->f48 + (uint8_t)edx9 + 2);
            ecx11 = ebp3->f60;
            edi4 = 0;
            eax12 = (void**)(((uint8_t)ebp3->f64 << *(uint8_t*)&ecx8 ^ ebx10) & ebp3->f76);
            ebp3->f64 = eax12;
            *(void***)&edi4 = *(void***)(ecx11 + (uint8_t)eax12 * 2);
            ebp3->f56[(ebp3->f44 & (uint8_t)edx9) * 2] = *(void***)&edi4;
            edx13 = ebp3->f64;
            eax14 = ebp3->f60;
            cx15 = ebp3->f100;
            v5 = edi4;
            *(void***)(eax14 + (uint8_t)edx13 * 2) = cx15;
        }
        if (edi4 && ((uint8_t)((uint8_t)ebp3->f100 - edi4) <= (uint8_t)((uint32_t)ebp3->f36 - 0x106) && ebp3->f128 != 2)) {
            eax16 = fun_415660(ebp3, edi4);
            ebp3->f88 = eax16;
        }
        eax17 = ebp3->f88;
        if ((uint32_t)eax17 < 3) {
            al18 = *(int8_t*)((uint8_t)ebp3->f100 + (uint32_t)ebp3->f48);
            ebp3->f5788[ebp3->f5784] = 0;
            *(int8_t*)((int32_t)ebp3->f5776 + ebp3->f5784) = al18;
            esi19 = ebp3->f5784;
            *(int8_t*)&v20 = al18;
            eax21 = v20 & 0xff;
            ebp3->f5784 = esi19 + 1;
            *(int16_t*)((uint32_t)ebp3 + eax21 * 4 + 0x8c) = (int16_t)(*(int16_t*)((uint32_t)ebp3 + eax21 * 4 + 0x8c) + 1);
            edx22 = 0;
            *(uint8_t*)&edx22 = static_cast<uint8_t>((uint1_t)(ebp3->f5784 == ebp3->f5780 - 1));
            ecx7 = ebp3->f108 - 1;
            ebp3->f108 = ecx7;
            esi23 = edx22;
        } else {
            cl24 = *(int8_t*)&eax17;
            *(uint16_t*)&eax17 = (uint16_t)((uint8_t)ebp3->f100 - ebp3->f104);
            cl25 = (int8_t)(cl24 - 3);
            ebp3->f5788[ebp3->f5784] = *(uint16_t*)&eax17;
            *(int8_t*)((int32_t)ebp3->f5776 + ebp3->f5784) = cl25;
            *(int8_t*)&a1 = cl25;
            ebp3->f5784 = ebp3->f5784 + 1;
            edx26 = 0;
            *(int8_t*)&edx26 = *(int8_t*)(((uint32_t)a1 & 0xff) + 0x41e370);
            eax27 = (void*)((uint32_t)eax17 + 0xffff);
            *(int16_t*)((uint32_t)ebp3 + edx26 * 4 + 0x490) = (int16_t)(*(int16_t*)((uint32_t)ebp3 + edx26 * 4 + 0x490) + 1);
            if (*(uint16_t*)&eax27 >= 0x100) {
                edx28 = 0;
                *(int8_t*)&edx28 = *(int8_t*)((((uint32_t)eax27 & 0xffff) >> 7) + 0x41e270);
                eax29 = edx28;
            } else {
                ecx30 = 0;
                *(int8_t*)&ecx30 = *(int8_t*)(((uint32_t)eax27 & 0xffff) + 0x41e170);
                eax29 = ecx30;
            }
            *(int16_t*)((uint32_t)ebp3 + eax29 * 4 + 0x980) = (int16_t)(*(int16_t*)((uint32_t)ebp3 + eax29 * 4 + 0x980) + 1);
            ecx31 = 0;
            eax32 = ebp3->f88;
            *(uint8_t*)&ecx31 = static_cast<uint8_t>((uint1_t)(ebp3->f5784 == ebp3->f5780 - 1));
            ebx33 = (void**)((uint8_t)ebp3->f108 - (uint32_t)eax32);
            below_or_equal34 = (uint32_t)eax32 <= (uint32_t)ebp3->f120;
            ebp3->f108 = ebx33;
            esi23 = ecx31;
            if (!below_or_equal34) 
                goto addr_0x40a26c_17;
            if ((uint8_t)ebx33 < (uint8_t)3) 
                goto addr_0x40a26c_17; else 
                goto addr_0x40a20f_19;
        }
        addr_0x40a30b_20:
        ebp3->f100 = ebp3->f100 + 1;
        addr_0x40a30e_21:
        if (!esi23) 
            continue;
        ecx35 = ebp3->f84;
        if ((int8_t)ecx35 < (int8_t)0) {
            eax36 = (void*)0;
        } else {
            eax36 = (void*)((uint32_t)ebp3->f48 + (uint8_t)ecx35);
        }
        edx37 = ebp3->f100;
        fun_415d10(ebp3, eax36, (uint8_t)edx37 - (uint8_t)ecx35, 0);
        ebp3->f84 = ebp3->f100;
        eax38 = ebp3->f0;
        edx39 = eax38->f28->f20;
        ecx7 = eax38->f16;
        if ((uint8_t)edx39 > (uint8_t)ecx7) {
            edx39 = ecx7;
        }
        if (!edx39) {
            addr_0x40a3a2_28:
            if (ebp3->f0->f16) 
                continue; else 
                break;
        } else {
            esi40 = eax38->f28->f16;
            edi41 = eax38->f12;
            ebx42 = edx39;
            ecx43 = (uint8_t)edx39 >> 2;
            while (ecx43) {
                --ecx43;
                *edi41 = *(void***)esi40;
                edi41 = edi41 + 4;
                esi40 = esi40 + 4;
            }
            ecx44 = (uint8_t)ebx42 & 3;
            while (ecx44) {
                --ecx44;
                *edi41 = *(void***)esi40;
                ++edi41;
                ++esi40;
            }
            ecx45 = eax38->f28;
            eax38->f12 = (void***)((uint32_t)eax38->f12 + (uint8_t)edx39);
            ecx45->f16 = (void**)((uint8_t)ecx45->f16 + (uint8_t)edx39);
            ebx46 = eax38->f20;
            ecx47 = eax38->f28;
            eax38->f16 = (void**)((uint8_t)eax38->f16 - (uint8_t)edx39);
            edi4 = v5;
            eax38->f20 = ebx46 + (uint8_t)edx39;
            ecx47->f20 = (void**)((uint8_t)ecx47->f20 - (uint8_t)edx39);
            ecx7 = eax38->f28->f20;
            if (ecx7) 
                goto addr_0x40a3a2_28;
        }
        ecx7 = eax38->f28->f8;
        eax38->f28->f16 = ecx7;
        goto addr_0x40a3a2_28;
        addr_0x40a26c_17:
        ecx48 = (void**)((uint8_t)ebp3->f100 + (uint32_t)eax32);
        edx49 = (struct s194*)((uint32_t)ebp3->f48 + (uint8_t)ecx48);
        eax50 = (void**)0;
        ebp3->f100 = ecx48;
        ecx51 = ebp3->f80;
        ebp3->f88 = (void*)0;
        *(int8_t*)&eax50 = edx49->f0;
        ebp3->f64 = eax50;
        ecx7 = (void**)0;
        *(int8_t*)&ecx7 = edx49->f1;
        ebp3->f64 = (void**)(((uint8_t)eax50 << *(uint8_t*)&ecx51 ^ (uint8_t)ecx7) & ebp3->f76);
        goto addr_0x40a30e_21;
        addr_0x40a20f_19:
        ebp3->f88 = (void*)((uint32_t)eax32 - 1);
        do {
            edi52 = ebp3->f64;
            eax53 = ebp3->f100 + 1;
            ebp3->f100 = eax53;
            ecx54 = 0;
            *(int8_t*)&ecx54 = *(int8_t*)((uint8_t)eax53 + (uint32_t)ebp3->f48 + 2);
            ecx55 = ebp3->f80;
            ecx56 = ebp3->f60;
            eax57 = (void**)((ecx54 ^ (uint8_t)edi52 << *(uint8_t*)&ecx55) & ebp3->f76);
            ebp3->f64 = eax57;
            edi4 = 0;
            *(void***)&edi4 = *(void***)(ecx56 + (uint8_t)eax57 * 2);
            ebp3->f56[((uint8_t)eax53 & ebp3->f44) * 2] = *(void***)&edi4;
            ecx7 = ebp3->f64;
            *(void***)(ebp3->f60 + (uint8_t)ecx7 * 2) = ebp3->f100;
            eax58 = (void*)((uint32_t)ebp3->f88 - 1);
            v5 = edi4;
            ebp3->f88 = eax58;
        } while (eax58);
        goto addr_0x40a30b_20;
    }
    return 0;
    addr_0x40a3ba_6:
    ecx59 = ebp3->f84;
    if ((int8_t)ecx59 < (int8_t)0) {
        eax60 = (void*)0;
    } else {
        eax60 = (void*)((uint32_t)ebp3->f48 + (uint8_t)ecx59);
    }
    edx61 = 0;
    *(uint8_t*)&edx61 = static_cast<uint8_t>((uint1_t)(a2 == 4));
    v62 = (void**)((uint8_t)ebp3->f100 - (uint8_t)ecx59);
    fun_415d10(ebp3, eax60, v62, edx61);
    ebp3->f84 = ebp3->f100;
    eax63 = ebp3->f0;
    edx64 = eax63->f28->f20;
    if ((uint8_t)edx64 > (uint8_t)eax63->f16) {
        edx64 = eax63->f16;
    }
    if (!edx64) {
        addr_0x40a44d_45:
        if (ebp3->f0->f16) {
            eax65 = 0;
            *(uint8_t*)&eax65 = static_cast<uint8_t>((uint1_t)(a2 == 4));
            return eax65 + eax65 + 1;
        } else {
            eax66 = 0;
            *(uint8_t*)&eax66 = static_cast<uint8_t>((uint1_t)(a2 != 4));
            return (uint32_t)(eax66 - 1) & 2;
        }
    } else {
        esi67 = eax63->f28->f16;
        edi68 = eax63->f12;
        ebx69 = edx64;
        ecx70 = (uint8_t)edx64 >> 2;
        while (ecx70) {
            --ecx70;
            *edi68 = *(void***)esi67;
            edi68 = edi68 + 4;
            esi67 = esi67 + 4;
        }
        ecx71 = (uint8_t)ebx69 & 3;
        while (ecx71) {
            --ecx71;
            *edi68 = *(void***)esi67;
            ++edi68;
            ++esi67;
        }
        ecx72 = eax63->f28;
        eax63->f12 = (void***)((uint32_t)eax63->f12 + (uint8_t)edx64);
        ecx72->f16 = (void**)((uint8_t)ecx72->f16 + (uint8_t)edx64);
        edi73 = eax63->f16;
        ecx74 = eax63->f28;
        eax63->f20 = eax63->f20 + (uint8_t)edx64;
        eax63->f16 = (void**)((uint8_t)edi73 - (uint8_t)edx64);
        ecx74->f20 = (void**)((uint8_t)ecx74->f20 - (uint8_t)edx64);
        if (eax63->f28->f20) 
            goto addr_0x40a44d_45;
    }
    eax63->f28->f16 = eax63->f28->f8;
    goto addr_0x40a44d_45;
}

void fun_40ab16() {
}

void** fun_418238(void** a1, int32_t a2, void** a3, void** a4);

void** fun_40ab4e(void** a1) {
    void** v2;
    void** v3;
    void** eax4;
    void** ebx5;
    void** esi6;

    v2 = *(void***)(a1 + 84);
    eax4 = fun_418238(a1, 1, v3, v2);
    if (eax4 != v3) {
        eax4 = fun_408404(a1, 0x40a9ec, v3, v2, ebx5, esi6);
    }
    return eax4;
}

struct s195 {
    int8_t[84] pad84;
    int32_t f84;
};

void fun_41812b(int32_t a1);

void fun_40ab8a(struct s195* a1) {
    int32_t v2;

    if (a1->f84) {
        v2 = a1->f84;
        fun_41812b(v2);
    }
    return;
}

struct s196 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s197 {
    int8_t[111] pad111;
    uint8_t f111;
};

uint8_t g6c7a0064;

void fun_40abaa() {
    struct s196* ebx1;
    struct s197* ebx2;
    uint8_t ah3;
    uint8_t ah4;

    asm("outsb");
    asm("outsb");
    ebx1->f111 = (uint8_t)(ebx2->f111 & ah3);
    asm("insd");
    if (0) 
        goto 0x40ac2f;
    if (1) 
        goto 0x40ac33;
    g6c7a0064 = (uint8_t)(g6c7a0064 & ah4);
}

void fun_40ac22() {
}

void fun_40ac9a() {
}

void fun_40ad0e() {
}

void fun_40adf9() {
}

void fun_40b2ce() {
}

void fun_40b51a() {
}

struct s198 {
    int8_t[67] pad67;
    uint8_t f67;
    int8_t[42] pad110;
    uint8_t f110;
};

struct s199 {
    int8_t[104] pad104;
    uint8_t f104;
    int8_t[6] pad111;
    uint8_t f111;
};

struct s200 {
    int8_t[115] pad115;
    int32_t f115;
};

struct s201 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s202 {
    int8_t[100] pad100;
    int32_t f100;
};

struct s203 {
    int8_t[101] pad101;
    uint8_t f101;
};

void fun_40b930(void* ecx) {
    int32_t* esp2;
    struct s198* ecx3;
    uint1_t cf4;
    struct s199* ebx5;
    struct s200* eax6;
    struct s201* ebx7;
    int32_t eax8;
    int16_t bx9;
    int16_t di10;
    int1_t zf11;
    int16_t bx12;
    int16_t di13;
    void* esp14;
    struct s202* ebp15;
    struct s203* ebx16;
    void* ebx17;
    int32_t eax18;
    uint8_t ah19;
    int32_t* eax20;
    int32_t ebp21;

    esp2 = (int32_t*)__zero_stack_offset();
    ecx3 = (struct s198*)((int32_t)ecx - 1);
    asm("outsb");
    if (cf4 | (uint1_t)(ecx3 == 0)) {
        addr_0x40b995_2:
        asm("outsb");
        ebx5->f111 = 0;
        asm("insd");
        if (0) 
            goto 0x40ba0f;
    } else {
        asm("insb");
        esp2 = (int32_t*)(eax6->f115 * 0x20424752);
        if (__intrinsic()) {
            addr_0x40b9a4_4:
            ecx3->f110 = 0;
            ecx3->f67 = 0;
            goto addr_0x40b9ad_5;
        } else {
            asm("outsb");
            if (__intrinsic()) {
                addr_0x40b9ad_5:
                ebx7 = (struct s201*)((int32_t)ebx5 + 1);
                *(esp2 - 1) = eax8;
                goto addr_0x40b9b0_7;
            } else {
                asm("outsb");
                *(uint8_t*)((int16_t)(bx9 + di10) + 0x6e) = 0;
                zf11 = *(int8_t*)((int16_t)(bx12 + di13) + 0x6e) == 0;
                if (zf11) {
                    addr_0x40b9b0_7:
                    ebx7->f104 = 0;
                    if (ebx7->f104) 
                        goto 0x40ba23; else 
                        goto addr_0x40b9b5_9;
                } else {
                    asm("outsb");
                    if (!zf11) {
                        if (1) 
                            goto 0x40b9c0;
                        asm("arpl [gs:ecx+0x66], bp");
                        esp14 = (void*)(ebp15->f100 * 0x706d4500);
                        if (__undefined()) 
                            goto 0x40b9d6;
                        ebx16->f101 = 0;
                        if (!__intrinsic()) 
                            goto 0x40b9d9;
                        asm("outsd");
                        if (0) 
                            goto 0x40b9c9;
                        ecx3->f110 = 0;
                        ecx3->f67 = 0;
                        ebx5 = (struct s199*)((int32_t)ebx17 + 1);
                        esp2 = (int32_t*)((int32_t)esp14 - 4);
                        *esp2 = eax18;
                        ebx5->f104 = (uint8_t)(ebx5->f104 & ah19);
                        zf11 = ebx5->f104 == 0;
                    }
                    if (!zf11) 
                        goto 0x40b9e0;
                    eax8 = *eax20 * 0xffffff90;
                    --esp2;
                    *esp2 = ebp21;
                    asm("outsb");
                    goto addr_0x40b995_2;
                }
            }
        }
    }
    if (1) 
        goto 0x40ba13;
    goto addr_0x40b9a4_4;
    addr_0x40b9b5_9:
}

void fun_40b9fe() {
}

struct s204 {
    int8_t[115] pad115;
    int32_t f115;
};

void fun_40bd90(int32_t ecx) {
    uint1_t cf2;
    struct s204* eax3;

    asm("outsb");
    if (cf2 | (uint1_t)(ecx - 1 == 0)) 
        goto 0x40bdf5;
    asm("insb");
    if (__intrinsic()) 
        goto 0x40be15;
    *(int32_t*)(eax3->f115 * 0x20544942 - 4) = 0x65707320;
    asm("arpl [ecx+0x66], bp");
}

struct s205 {
    int8_t[1] pad1;
    int8_t f1;
};

void fun_40bfc3(int32_t ecx) {
    int8_t* eax2;
    int8_t* eax3;
    int8_t al4;
    int8_t* eax5;
    struct s205* eax6;

    *eax2 = (int8_t)(*eax3 + al4);
    eax5 = &eax6->f1;
    *eax5 = (int8_t)(*eax5 + *(int8_t*)&eax5);
    *eax5 = (int8_t)(*eax5 + *(int8_t*)&eax5);
    *eax5 = (int8_t)(*eax5 + *(int8_t*)&eax5);
    if ((uint1_t)!!(ecx - 1) & (uint1_t)!!*eax5) 
        goto 0x40c00f; else 
        goto "???";
}

void fun_40c1cd() {
}

void fun_40c691(uint32_t ecx, void** a2, void** a3, void** a4, void** a5, void** a6) {
    uint32_t eax7;
    uint32_t edx8;
    void** v9;
    uint32_t eax10;
    uint32_t edx11;
    uint32_t eax12;
    uint32_t edx13;
    int8_t dl14;
    uint32_t eax15;
    void** v16;
    uint32_t eax17;
    uint32_t eax18;
    int32_t edi19;
    int32_t ebp20;
    int32_t ebp21;
    int32_t edi22;
    void** v23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    uint32_t eax28;
    uint32_t edi29;
    void** v30;
    uint32_t eax31;
    uint32_t edi32;
    uint32_t eax33;
    uint32_t edi34;
    int32_t eax35;
    int32_t edi36;
    uint32_t eax37;
    uint32_t ebp38;
    void** v39;
    uint32_t eax40;
    uint32_t ebp41;
    uint32_t eax42;
    uint32_t ebp43;
    int32_t eax44;
    int32_t ebp45;
    int32_t v46;
    int32_t v47;
    int32_t v48;
    int32_t v49;
    void** v50;
    void** v51;
    void** v52;
    void** v53;
    void** v54;
    void** v55;
    int32_t v56;

    eax7 = edx8 >> 24;
    *(int8_t*)&v9 = *(int8_t*)&eax7;
    eax10 = edx11 >> 16;
    *(int8_t*)(&v9 + 1) = *(int8_t*)&eax10;
    eax12 = edx13 >> 8;
    *(int8_t*)(&v9 + 2) = *(int8_t*)&eax12;
    *(int8_t*)(&v9 + 3) = dl14;
    eax15 = ecx >> 24;
    *(int8_t*)&v16 = *(int8_t*)&eax15;
    eax17 = ecx >> 16;
    *(int8_t*)(&v16 + 1) = *(int8_t*)&eax17;
    eax18 = ecx >> 8;
    *(int8_t*)(&v16 + 2) = *(int8_t*)&eax18;
    *(int8_t*)(&v16 + 3) = *(int8_t*)&ecx;
    if (edi19 > 0x13880 || (ebp20 > 0x13880 || ebp21 + edi22 > 0x186a0)) {
        fun_40850c(v23, 0x40c550, v24, v25, __return_address(), a2, a3, a4, a5, a6, v9, v16, v26, v27);
    } else {
        eax28 = edi29 >> 24;
        *(int8_t*)&v30 = *(int8_t*)&eax28;
        eax31 = edi32 >> 16;
        *(int8_t*)(&v30 + 1) = *(int8_t*)&eax31;
        eax33 = edi34 >> 8;
        *(int8_t*)(&v30 + 2) = *(int8_t*)&eax33;
        eax35 = edi36;
        *(int8_t*)(&v30 + 3) = *(int8_t*)&eax35;
        eax37 = ebp38 >> 24;
        *(int8_t*)&v39 = *(int8_t*)&eax37;
        eax40 = ebp41 >> 16;
        *(int8_t*)(&v39 + 1) = *(int8_t*)&eax40;
        eax42 = ebp43 >> 8;
        *(int8_t*)(&v39 + 2) = *(int8_t*)&eax42;
        eax44 = ebp45;
        *(int8_t*)(&v39 + 3) = *(int8_t*)&eax44;
        if (v46 > 0x13880 || (v47 > 0x13880 || v48 + v49 > 0x186a0)) {
            fun_40850c(v50, 0x40c590, v51, v52, __return_address(), a2, a3, a4, a5, a6, v9, v16, v30, v39);
        } else {
            fun_410b88(v53, 0x406a73, 32, v53, 0x406a73, 32);
            fun_410bf4(v54, (int32_t)__zero_stack_offset() + 16, 32, 0x40c7ea, v53, 0x406a73, 32, v54, (int32_t)__zero_stack_offset() + 16, 32, 0x40c7ea, v53, 0x406a73, 32);
            fun_410c30(v55, 0x406a73, 32, v55, 0x406a73, 32);
        }
    }
    goto v56;
}

void fun_40c94e() {
}

void fun_40ca41() {
}

void fun_40cc16() {
}

void fun_40cc5a() {
}

void fun_40ceee() {
}

void fun_40cf81() {
}

void fun_40d082() {
}

void fun_40d25a() {
}

void fun_40da7f() {
}

void fun_40df41() {
}

void fun_40dfd5() {
}

void fun_40e085() {
}

void fun_40e096() {
}

void fun_40e102() {
}

void fun_40e125() {
}

void fun_40e19e() {
}

void fun_40e23a() {
}

void fun_40e2fa() {
}

void fun_40e41e() {
}

void fun_40e436() {
}

void fun_40e45a() {
}

void fun_40e471() {
}

void fun_40e489() {
}

void fun_40e4a1() {
}

void fun_40e679() {
}

void fun_40ea7a() {
}

void fun_40ea95() {
}

void fun_40eab1() {
}

void fun_40f0e9() {
}

void fun_40f4e9() {
}

void fun_40f739() {
}

void fun_40f7dd() {
}

void fun_40f80d() {
}

void fun_40f83d() {
}

void fun_40f961() {
}

void fun_40f9ce() {
}

void fun_40fbae() {
}

void fun_40feaa() {
}

void fun_4101e9() {
}

void fun_410505() {
}

void fun_410549() {
}

void fun_4105e2() {
}

void fun_410625() {
}

void fun_4106f1() {
}

void fun_4108ee() {
}

void fun_410a71() {
}

void fun_410d4e() {
}

void** fun_410e79(void** a1, int32_t a2) {
    void** eax3;

    fun_410b88(a1, 0x406a78, 4, a1, 0x406a78, 4);
    fun_410bf4(a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, 0x410eb9, a1, 0x406a78, 4, a1, (int32_t)__zero_stack_offset() - 36 - 4 - 4 + 28, 4, 0x410eb9, a1, 0x406a78, 4);
    eax3 = fun_410c30(a1, 0x406a78, 4, a1, 0x406a78, 4);
    return eax3;
}

void fun_402959() {
}

void fun_4029d9() {
}

void fun_402a32() {
}

struct s206 {
    int8_t[101] pad101;
    uint8_t f101;
    int8_t[9] pad111;
    uint8_t f111;
};

void fun_402b80(struct s71* ecx) {
    struct s206* esi2;
    void* esi3;
    uint8_t ah4;
    uint1_t zf5;
    uint8_t ah6;
    uint8_t ah7;

    esi2 = (struct s206*)((int32_t)esi3 - 1);
    esi2->f101 = (uint8_t)(esi2->f101 & ah4);
    asm("popad");
    if (!esi2->f101) 
        goto 0x402bfe;
    if (0) 
        goto 0x402bf0;
    if (!1) {
        asm("popad");
        if (0) 
            goto 0x402bf5;
        esi2->f111 = 0;
        zf5 = (uint1_t)(esi2->f111 == 0);
        if (zf5) 
            goto 0x402bb5;
        asm("popad");
        asm("insb");
        asm("insb");
        asm("outsd");
        if (!(uint1_t)static_cast<uint32_t>(zf5)) 
            goto 0x402c00;
        ecx->f110 = 0;
        ecx->f32 = (uint8_t)(ecx->f32 & ah6);
        ecx->f116 = (uint8_t)(ecx->f116 & ah7);
        asm("popad");
        if (1) 
            goto 0x402c20;
        if (0) 
            goto 0x402c13;
    }
    asm("popad");
    asm("insd");
}

void fun_410b85() {
}

void fun_402e39() {
}

void fun_40314a() {
}

struct s207 {
    int8_t[1] pad1;
    int8_t f1;
};

void fun_410dd5(int32_t ecx) {
    int8_t* eax2;
    int8_t* eax3;
    int8_t al4;
    int8_t* eax5;
    int8_t* eax6;
    int8_t al7;
    int32_t edx8;
    int32_t edx9;
    int8_t* eax10;
    struct s207* eax11;

    *eax2 = (int8_t)(*eax3 + al4);
    *eax5 = (int8_t)(*eax6 + al7);
    *(int8_t*)(edx8 - 8) = (int8_t)(*(int8_t*)(edx9 - 8) + *(int8_t*)((int32_t)&ecx + 1));
    eax10 = &eax11->f1;
    *eax10 = (int8_t)(*eax10 + *(int8_t*)&eax10);
    *eax10 = (int8_t)(*eax10 + *(int8_t*)&eax10);
    *eax10 = (int8_t)(*eax10 + *(int8_t*)&eax10);
    if ((uint1_t)!!(ecx - 1) & (uint1_t)!!*eax10) 
        goto 0x410e27; else 
        goto "???";
}

struct s208 {
    uint8_t f0;
    int8_t[109] pad110;
    uint8_t f110;
    int8_t[1] pad112;
    uint8_t f112;
    int8_t[351044485] pad351044598;
    int8_t f351044598;
};

struct s209 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s210 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s211 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s212 {
    int8_t[116] pad116;
    uint8_t f116;
};

struct s213 {
    int8_t[116] pad116;
    uint8_t f116;
};

struct s214 {
    int8_t[114] pad114;
    int32_t f114;
};

struct s215 {
    int8_t[97] pad97;
    int32_t f97;
};

struct s216 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s217 {
    int8_t[109] pad109;
    uint8_t f109;
};

struct s218 {
    int8_t[109] pad109;
    uint8_t f109;
};

struct s219 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s220 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s221 {
    int8_t[97] pad97;
    int32_t f97;
};

struct s222 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s223 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s224 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s225 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s226 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s227 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s228 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s229 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s230 {
    int8_t[97] pad97;
    int32_t f97;
};

struct s231 {
    int8_t[115] pad115;
    uint8_t f115;
};

struct s232 {
    int8_t[115] pad115;
    uint8_t f115;
};

struct s233 {
    int8_t[115] pad115;
    int8_t f115;
};

struct s234 {
    int8_t[55] pad55;
    int8_t f55;
};

struct s235 {
    int8_t[55] pad55;
    int8_t f55;
};

struct s236 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s237 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s238 {
    int8_t[110] pad110;
    int8_t f110;
};

struct s239 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s240 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s241 {
    int8_t[104] pad104;
    int8_t f104;
};

struct s242 {
    int8_t[95] pad95;
    int32_t f95;
};

uint8_t g6e6920c6;

struct s243 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s244 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s245 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s246 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s247 {
    int8_t[110] pad110;
    int8_t f110;
};

struct s248 {
    int8_t[111] pad111;
    int8_t f111;
};

struct s249 {
    int8_t[109] pad109;
    uint8_t f109;
};

struct s250 {
    int8_t[109] pad109;
    uint8_t f109;
};

void fun_4034f9(struct s208* ecx) {
    int8_t** esp2;
    uint32_t* esi3;
    uint32_t* esi4;
    uint32_t ebp5;
    uint8_t* esi6;
    uint8_t* esi7;
    struct s209* edi8;
    struct s210* ebp9;
    struct s211* ebp10;
    uint8_t ah11;
    void** esp12;
    struct s212* ebx13;
    struct s213* ebx14;
    uint8_t dh15;
    void** esp16;
    struct s214* ebp17;
    int16_t bp18;
    int16_t di19;
    int16_t bp20;
    int16_t di21;
    uint8_t dh22;
    uint1_t zf23;
    int16_t bp24;
    int16_t di25;
    struct s215* ebx26;
    struct s216* esi27;
    uint8_t ah28;
    uint1_t cf29;
    int1_t of30;
    uint1_t below_or_equal31;
    uint1_t below_or_equal32;
    int32_t ebp33;
    void* edi34;
    int32_t ebp35;
    void* edi36;
    int32_t ebp37;
    uint8_t dh38;
    struct s217* ebx39;
    struct s218* ebx40;
    uint8_t dh41;
    struct s219* edx42;
    struct s220* edx43;
    uint8_t ah44;
    void* eax45;
    int32_t ebp46;
    void* eax47;
    int32_t ebp48;
    uint8_t dh49;
    uint8_t ah50;
    struct s221* ebx51;
    struct s222* esi52;
    struct s223* esi53;
    uint8_t ah54;
    struct s224* edx55;
    struct s225* edx56;
    uint8_t ah57;
    void* eax58;
    int32_t ebp59;
    void* eax60;
    int32_t ebp61;
    uint8_t dh62;
    uint8_t ah63;
    struct s226* edx64;
    struct s227* edx65;
    uint8_t ah66;
    struct s228* edx67;
    struct s229* edx68;
    uint8_t dh69;
    int32_t eax70;
    int32_t eax71;
    int8_t dl72;
    int32_t eax73;
    struct s230* ebx74;
    struct s231* ebp75;
    struct s232* ebp76;
    uint8_t dh77;
    struct s233* ebp78;
    uint1_t below_or_equal79;
    int8_t* edi80;
    int8_t bl81;
    struct s234* eax82;
    void* eax83;
    struct s235* eax84;
    void* eax85;
    int8_t bh86;
    struct s236* eax87;
    struct s237* eax88;
    uint8_t dh89;
    struct s238* eax90;
    uint8_t ah91;
    struct s239* ebx92;
    struct s240* ebx93;
    uint8_t dh94;
    struct s241* ebx95;
    struct s242* ebp96;
    uint8_t dh97;
    uint1_t zf98;
    struct s243* edx99;
    struct s244* edx100;
    uint8_t ah101;
    struct s245* eax102;
    struct s246* eax103;
    uint8_t dh104;
    struct s247* eax105;
    struct s248* esi106;
    int32_t eax107;
    int32_t eax108;
    int8_t dl109;
    int32_t ebp110;
    void* edi111;
    int32_t ebp112;
    void* edi113;
    int32_t ebp114;
    uint8_t dh115;
    struct s249* ebx116;
    struct s250* ebx117;
    uint8_t dh118;
    int32_t eax119;
    int32_t eax120;
    int8_t dl121;

    esp2 = (int8_t**)__zero_stack_offset();
    *esi3 = *esi4 ^ ebp5;
    *esi6 = (uint8_t)(*esi7 ^ *(uint8_t*)((int32_t)&ecx + 1));
    edi8->f114 = 0;
    ebp9->f97 = (uint8_t)(ebp10->f97 & ah11);
    if (0) {
        addr_0x403572_2:
        esp12 = (void**)(esp2 - 1);
        *(void***)esp12 = esp12;
        esp2 = (int8_t**)(esp12 - 1);
        *esp2 = (int8_t*)0x6e692065;
        asm("outsw");
        ebx13->f116 = (uint8_t)(ebx14->f116 & dh15);
        if (0) 
            goto addr_0x403602_3;
    } else {
        esp16 = (void**)(ebp17->f114 * 0x90909000 - 4);
        *(void***)esp16 = esp16;
        esp2 = (int8_t**)(esp16 - 1);
        *esp2 = (int8_t*)0x6e702065;
        *(uint8_t*)((int16_t)(bp18 + di19) + 0x74) = (uint8_t)(*(uint8_t*)((int16_t)(bp20 + di21) + 0x74) & dh22);
        zf23 = (uint1_t)(*(int8_t*)((int16_t)(bp24 + di25) + 0x74) == 0);
        if (0) {
            addr_0x4035a1_5:
            if (0) {
                addr_0x403611_6:
                asm("outsd");
                if (!zf23) 
                    goto 0x403682; else 
                    goto addr_0x403616_7;
            } else {
                esp2 = (int8_t**)(ebx26->f97 * 0x6e6f6974);
                esi27->f111 = (uint8_t)(esi27->f111 & ah28);
                cf29 = 0;
                of30 = 0;
                below_or_equal31 = (uint1_t)static_cast<uint32_t>((uint1_t)(esi27->f111 == 0));
                if (0) {
                    addr_0x4035d1_9:
                    ecx = (struct s208*)((int32_t)ecx + 1);
                    below_or_equal32 = (uint1_t)(cf29 | (uint1_t)(ecx == 0));
                    if (__intrinsic()) 
                        goto addr_0x403653_10; else 
                        goto addr_0x4035e3_11;
                } else {
                    addr_0x4035b1_12:
                    if (!below_or_equal31) {
                        addr_0x403625_13:
                        if (of30) 
                            goto 0x4036b0; else 
                            goto addr_0x403642_14;
                    } else {
                        esi27 = (struct s216*)(*(int32_t*)((int32_t)ecx + ebp33 * 2 + 0x6e) * 0x73692067);
                        *(uint8_t*)((int32_t)edi34 + ebp35 * 2 + 0x6f) = (uint8_t)(*(uint8_t*)((int32_t)edi36 + ebp37 * 2 + 0x6f) & dh38);
                        ebx39->f109 = (uint8_t)(ebx40->f109 & dh41);
                        asm("popad");
                        asm("insb");
                        goto addr_0x4035c4_16;
                    }
                }
            }
        } else {
            asm("arpl [eax+0x61], si");
            asm("insb");
            asm("insb");
            asm("outsd");
            asm("arpl [ecx+0x74], sp");
            edx42->f121 = (uint8_t)(edx43->f121 & ah44);
            *(uint8_t*)((int32_t)eax45 + ebp46 * 2 + 0x65) = (uint8_t)(*(uint8_t*)((int32_t)eax47 + ebp48 * 2 + 0x65) & dh49);
            *(uint8_t*)((int32_t)ecx + 0x70) = (uint8_t)(*(uint8_t*)((int32_t)ecx + 0x70) & ah50);
            of30 = 0;
            below_or_equal31 = (uint1_t)static_cast<uint32_t>((uint1_t)(*(uint8_t*)((int32_t)ecx + 0x70) == 0));
            if (0) {
                goto addr_0x4035b1_12;
            }
            esp2 = (int8_t**)(ebx51->f97 * 0x6e6f6974);
            esi52->f111 = (uint8_t)(esi53->f111 & ah54);
            if (0) 
                goto addr_0x403570_20; else 
                goto addr_0x403550_21;
        }
    }
    asm("arpl [eax+0x61], si");
    asm("insb");
    asm("insb");
    asm("outsd");
    asm("arpl [ecx+0x74], sp");
    edx55->f121 = (uint8_t)(edx56->f121 & ah57);
    *(uint8_t*)((int32_t)eax58 + ebp59 * 2 + 0x65) = (uint8_t)(*(uint8_t*)((int32_t)eax60 + ebp61 * 2 + 0x65) & dh62);
    *(uint8_t*)((int32_t)ecx + 0x70) = (uint8_t)(*(uint8_t*)((int32_t)ecx + 0x70) & ah63);
    zf23 = (uint1_t)(*(uint8_t*)((int32_t)ecx + 0x70) == 0);
    goto addr_0x4035a1_5;
    addr_0x403616_7:
    edx64->f101 = (uint8_t)(edx65->f101 & ah66);
    edx67->f101 = (uint8_t)(edx68->f101 & dh69);
    asm("arpl [edi+0x6d], bp");
    if (0) 
        goto 0x40368b;
    asm("insb");
    *(int8_t*)(eax70 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax71 - 0x6f6f6f70) + dl72);
    of30 = __intrinsic();
    below_or_equal31 = (uint1_t)(__intrinsic() | (uint1_t)(*(int8_t*)(eax73 - 0x6f6f6f70) == 0));
    goto addr_0x403625_13;
    addr_0x4035e3_11:
    asm("insb");
    esp2 = (int8_t**)(ebx74->f97 * 0x6e6f6974);
    ebp75->f115 = (uint8_t)(ebp76->f115 & dh77);
    zf23 = (uint1_t)(ebp78->f115 == 0);
    below_or_equal79 = (uint1_t)static_cast<uint32_t>(zf23);
    if (!1) {
        if (0) {
            addr_0x403667_25:
            edi80 = *esp2;
            if (!below_or_equal79) {
                *(int8_t*)((int32_t)edi80 + (int32_t)esi27) = (int8_t)(*(int8_t*)((int32_t)edi80 + (int32_t)esi27) + bl81);
                eax82 = (struct s234*)((int32_t)eax83 + 1 + 1);
                eax82->f55 = (int8_t)(eax82->f55 + *(int8_t*)&eax82);
                eax84 = (struct s235*)((int32_t)eax82 + 1);
                eax84->f55 = (int8_t)(eax84->f55 + *(int8_t*)((int32_t)&eax84 + 1));
                eax85 = (void*)((int32_t)eax84 + 1);
                *(int8_t*)((int32_t)eax85 - 0x63ffbfc9) = (int8_t)(*(int8_t*)((int32_t)eax85 - 0x63ffbfc9) + *(int8_t*)&eax85);
                asm("aaa");
                *(int8_t*)((int32_t)edi80 + (int32_t)esi27 - 0x7c09ffc0) = (int8_t)(*(int8_t*)((int32_t)edi80 + (int32_t)esi27 - 0x7c09ffc0) + bh86);
            } else {
                goto addr_0x403673_29;
            }
        } else {
            asm("arpl [gs:ecx+0x74], sp");
            eax87->f110 = (uint8_t)(eax88->f110 & dh89);
            ++esp2;
            if (!(uint1_t)static_cast<uint32_t>((uint1_t)(eax90->f110 == 0))) {
                addr_0x403674_31:
                *(int8_t*)((int32_t)ecx + 0x14ec83f6) = (int8_t)(*(int8_t*)((int32_t)ecx + 0x14ec83f6) + *(int8_t*)&ecx);
            } else {
                addr_0x403602_3:
                *(uint8_t*)ecx = (uint8_t)(*(uint8_t*)ecx - *(uint8_t*)((int32_t)&ecx + 1));
                *(uint8_t*)((int32_t)ecx + 0x6e) = (uint8_t)(*(uint8_t*)((int32_t)ecx + 0x6e) & ah91);
                ebx92->f104 = (uint8_t)(ebx93->f104 & dh94);
                zf23 = (uint1_t)(ebx95->f104 == 0);
                goto addr_0x403611_6;
            }
        }
    }
    addr_0x403642_14:
    ++esp2;
    if (!below_or_equal31) 
        goto 0x4036b8;
    esi27 = (struct s216*)(ebp96->f95 * 0x6f666e69);
    g6e6920c6 = (uint8_t)(g6e6920c6 & dh97);
    cf29 = 0;
    zf98 = (uint1_t)(g6e6920c6 == 0);
    below_or_equal32 = (uint1_t)static_cast<uint32_t>(zf98);
    if (1) {
        addr_0x403673_29:
        goto addr_0x403674_31;
    } else {
        addr_0x403653_10:
        asm("outsb");
        if (below_or_equal32) 
            goto 0x4036bc;
    }
    if (cf29) 
        goto 0x403679;
    asm("arpl [ecx+0x6c], sp");
    asm("insb");
    edx99->f101 = (uint8_t)(edx100->f101 & ah101);
    asm("outsw");
    if (!0) {
        eax102->f110 = (uint8_t)(eax103->f110 & dh104);
        below_or_equal79 = (uint1_t)static_cast<uint32_t>((uint1_t)(eax105->f110 == 0));
        goto addr_0x403667_25;
    }
    addr_0x403570_20:
    goto addr_0x403572_2;
    addr_0x403550_21:
    if (!(uint1_t)static_cast<uint32_t>((uint1_t)(esi106->f111 == 0))) {
        addr_0x4035c4_16:
        asm("insb");
        *(int8_t*)(eax107 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax108 - 0x6f6f6f70) + dl109);
        cf29 = __intrinsic();
        goto addr_0x4035d1_9;
    } else {
        esi27 = (struct s216*)(*(int32_t*)((int32_t)ecx + ebp110 * 2 + 0x6e) * 0x73692067);
        *(uint8_t*)((int32_t)edi111 + ebp112 * 2 + 0x6f) = (uint8_t)(*(uint8_t*)((int32_t)edi113 + ebp114 * 2 + 0x6f) & dh115);
        ebx116->f109 = (uint8_t)(ebx117->f109 & dh118);
        asm("popad");
        asm("insb");
        asm("insb");
        *(int8_t*)(eax119 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax120 - 0x6f6f6f70) + dl121);
        goto addr_0x403570_20;
    }
}

void fun_4038f8() {
    int1_t pf1;

    if (pf1) 
        goto 0x403966;
}

void fun_4039f5() {
}

void fun_410d96() {
}

void fun_403cda() {
}

void fun_403ce5() {
}

void fun_403cf1() {
}

void fun_403cfd() {
}

void fun_403d09() {
}

struct s251 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s252 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s253 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s254 {
    int8_t[64] pad64;
    int8_t f64;
};

struct s255 {
    int8_t[64] pad64;
    int8_t f64;
};

void fun_403e80(int32_t ecx) {
    struct s251* esi2;
    struct s252* esi3;
    uint8_t ah4;
    struct s253* esi5;
    int8_t* eax6;
    int8_t* eax7;
    int8_t al8;
    int8_t* eax9;
    int8_t* eax10;
    int8_t al11;
    int8_t* eax12;
    int8_t* eax13;
    int8_t al14;
    struct s254* eax15;
    struct s255* eax16;
    int8_t dh17;
    int8_t* eax18;
    int8_t* eax19;
    int8_t al20;
    int8_t* eax21;
    int8_t* eax22;
    int8_t al23;
    int8_t* eax24;
    int8_t* eax25;
    int8_t al26;
    int8_t* eax27;
    int8_t* eax28;
    int8_t* eax29;
    int8_t al30;
    int8_t* eax31;
    int8_t* eax32;
    int8_t al33;
    int8_t* eax34;
    int8_t* eax35;
    int8_t al36;
    int32_t eax37;
    int32_t eax38;
    uint8_t al39;

    asm("outsb");
    asm("outsb");
    esi2->f105 = (uint8_t)(esi3->f105 & ah4);
    asm("insb");
    if (!esi5->f105) 
        goto 0x403ef2;
    if (!0) {
        if (1) 
            goto 0x403f0a;
        asm("outsd");
        *eax6 = (int8_t)(*eax7 + al8);
        *eax9 = (int8_t)(*eax10 + al11);
        *eax12 = (int8_t)(*eax13 + al14);
        eax15->f64 = (int8_t)(eax16->f64 + dh17);
        *eax18 = (int8_t)(*eax19 + al20);
        *eax21 = (int8_t)(*eax22 + al23);
        *eax24 = (int8_t)(*eax25 + al26);
        if ((uint1_t)!!(ecx - 1) & (uint1_t)!!*eax27) 
            goto addr_0x403eef_6;
    }
    *eax28 = (int8_t)(*eax29 + al30);
    *eax31 = (int8_t)(*eax32 + al33);
    *eax34 = (int8_t)(*eax35 + al36);
    *(uint8_t*)(eax37 - 0x7d) = (uint8_t)(*(uint8_t*)(eax38 - 0x7d) & al39);
    addr_0x403eef_6:
}

struct s256 {
    int8_t[115] pad115;
    uint8_t f115;
    int8_t[485262210] pad485262326;
    int8_t f485262326;
};

struct s257 {
    int8_t[110] pad110;
    int32_t f110;
    int8_t[1798451886] pad1798452000;
    uint8_t f1798452000;
};

struct s258 {
    int8_t[32] pad32;
    int32_t f32;
    int8_t[81] pad117;
    uint8_t f117;
};

struct s259 {
    int8_t[117] pad117;
    uint8_t f117;
};

struct s260 {
    int8_t[117] pad117;
    uint8_t f117;
};

struct s261 {
    int8_t[117] pad117;
    int8_t f117;
};

struct s262 {
    int8_t[78] pad78;
    uint8_t f78;
};

struct s263 {
    int8_t[68] pad68;
    int32_t f68;
};

uint8_t g90003231;

struct s264 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s265 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s266 {
    int8_t[78] pad78;
    uint8_t f78;
};

struct s267 {
    int8_t[78] pad78;
    uint8_t f78;
};

struct s268 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s269 {
    int8_t[121] pad121;
    uint8_t f121;
};

struct s270 {
    int8_t[8] pad8;
    uint8_t f8;
};

struct s271 {
    int8_t[8] pad8;
    int16_t f8;
    int8_t[238] pad248;
    void*** f248;
};

void fun_404800(struct s256* ecx, void** a2, void** a3, void** a4, void** a5, void** a6, int32_t a7, int32_t a8) {
    uint32_t v2;
    struct s257* edi9;
    void* edi10;
    int1_t zf11;
    int1_t sf12;
    int1_t of13;
    int1_t cf14;
    struct s258* ebx15;
    void* ebx16;
    void** ebp17;
    void** v18;
    struct s258* v19;
    uint1_t cf20;
    uint1_t below_or_equal21;
    int32_t esi22;
    uint8_t bh23;
    struct s259* ebx24;
    struct s260* ebx25;
    uint8_t dh26;
    struct s261* ebx27;
    uint8_t dh28;
    struct s262* eax29;
    uint8_t dl30;
    int1_t zf31;
    struct s263* v32;
    void** v33;
    uint8_t dh34;
    struct s264* edx35;
    struct s265* edx36;
    uint8_t ah37;
    struct s266* eax38;
    struct s267* eax39;
    uint8_t dl40;
    int8_t bl41;
    uint32_t eax42;
    uint8_t dh43;
    struct s268* edx44;
    struct s269* edx45;
    uint8_t dl46;
    uint8_t* esi47;
    uint8_t* esi48;
    uint8_t bh49;
    uint8_t dh50;
    struct s270* v51;
    struct s271* v52;
    void*** v53;
    int32_t eax54;
    int32_t v55;
    int32_t eax56;
    void*** ebx57;
    int32_t edi58;
    void** esi59;
    void** v60;
    void** v61;
    void** v62;
    int32_t v63;

    *(void***)&v2 = a2;
    edi9 = (struct s257*)((int32_t)edi10 - 1);
    zf11 = edi9 == 0;
    sf12 = (int32_t)edi9 < 0;
    of13 = __intrinsic();
    asm("outsb");
    asm("insb");
    if (sf12) {
        asm("arpl [edi+0x6d], bp");
        if (of13) {
            addr_0x40487c_3:
            goto addr_0x404880_4;
        } else {
            if (!cf14) {
                addr_0x404880_4:
                ebx15 = (struct s258*)((int32_t)ebx16 + 1);
                asm("outsd");
                asm("insd");
                if (__intrinsic()) {
                    addr_0x4048f7_6:
                    ebp17 = v18;
                    goto addr_0x4048fb_7;
                } else {
                    if (1) {
                        addr_0x4048fb_7:
                        ebx15 = v19;
                        if (!(*(uint8_t*)((int32_t)&ebx15 + 1) & 4)) {
                            addr_0x404910_9:
                            goto addr_0x404913_10;
                        } else {
                            goto addr_0x404905_12;
                        }
                    } else {
                        ebp17 = (void**)(edi9->f110 * 0x6e697720);
                        cf20 = __intrinsic();
                        below_or_equal21 = (uint1_t)(cf20 | __undefined());
                        goto addr_0x40488b_14;
                    }
                }
            } else {
                ebp17 = (void**)(edi9->f110 * 0x6e697720);
                cf20 = __intrinsic();
                below_or_equal21 = (uint1_t)(cf20 | __undefined());
                asm("outsd");
                if (!below_or_equal21) {
                    addr_0x40488b_14:
                    asm("outsd");
                    if (!below_or_equal21) {
                        addr_0x4048b3_16:
                        goto addr_0x4048bc_17;
                    } else {
                        esi22 = ebx15->f32 * 0x6e696562;
                        goto addr_0x404894_19;
                    }
                } else {
                    *(uint8_t*)((int32_t)edi9 + 0x6b323320) = (uint8_t)(*(uint8_t*)((int32_t)edi9 + 0x6b323320) & bh23);
                    ebx24->f117 = (uint8_t)(ebx25->f117 & dh26);
                    cf20 = 0;
                    zf11 = ebx27->f117 == 0;
                    sf12 = __intrinsic();
                    of13 = 0;
                    if (0) {
                        addr_0x404894_19:
                        *(uint8_t*)((int16_t)((int16_t)*(void**)&ebp17 + (int16_t)*(void**)&esi22) + 0x65) = (uint8_t)(*(uint8_t*)((int16_t)((int16_t)*(void**)&ebp17 + (int16_t)*(void**)&esi22) + 0x65) & dh28);
                        cf20 = 0;
                        zf11 = *(int8_t*)((int16_t)((int16_t)*(void**)&ebp17 + (int16_t)*(void**)&esi22) + 0x65) == 0;
                        sf12 = __intrinsic();
                        of13 = 0;
                        goto addr_0x40489b_21;
                    } else {
                        asm("outsd");
                    }
                }
            }
        }
    }
    if (0) {
        addr_0x40489b_21:
        if (1) {
            addr_0x404905_12:
            fun_408fa4(ebp17, __return_address());
            goto addr_0x404910_9;
        } else {
            if (zf11) {
                addr_0x4048c2_25:
                asm("insb");
                if (!sf12) {
                    addr_0x4048e5_26:
                    eax29->f78 = (uint8_t)(eax29->f78 & dl30);
                    *(int8_t*)((int32_t)ecx + 0x1cec83f6) = (int8_t)(*(int8_t*)((int32_t)ecx + 0x1cec83f6) + *(int8_t*)&ecx);
                    goto addr_0x4048f7_6;
                } else {
                    asm("arpl [edi+0x6d], bp");
                    if (of13) {
                        addr_0x40493c_28:
                        if (zf11) {
                            addr_0x404955_29:
                            zf31 = (*(uint8_t*)&ebx15 & 4) == 0;
                            goto addr_0x404958_30;
                        } else {
                            addr_0x404941_31:
                            fun_40904c(ebp17, &v32->f68);
                            goto addr_0x404951_32;
                        }
                    } else {
                        if (!cf20) {
                            goto addr_0x404941_31;
                        }
                    }
                }
            } else {
                if (zf11) {
                    addr_0x404913_10:
                    fun_402e04(*(int16_t*)&ecx, ebp17, v33, *(void***)&v2, a3, a4, a5, a6);
                    if (*(uint8_t*)&ebx15 & 32) {
                        fun_40908c(ebp17, v33);
                        goto addr_0x404932_37;
                    }
                } else {
                    g90003231 = (uint8_t)(g90003231 & dh34);
                    cf20 = 0;
                    goto addr_0x4048b3_16;
                }
            }
        }
    } else {
        edx35->f121 = (uint8_t)(edx36->f121 & ah37);
        eax38->f78 = (uint8_t)(eax39->f78 & dl40);
        *(uint8_t*)&ebx15 = (uint8_t)(bl41 + *(uint8_t*)((int32_t)&ecx + 1));
        eax29 = (struct s262*)(eax42 | 0x90909090);
        cf20 = 0;
        edi9 = (struct s257*)((int32_t)edi9 + 1 - 1);
        asm("outsb");
        asm("insb");
        if ((int32_t)edi9 >= 0) {
            addr_0x404865_40:
            if (0) {
                addr_0x4048db_41:
                ebx15->f117 = (uint8_t)(ebx15->f117 & dh43);
                zf31 = ebx15->f117 == 0;
                if (0) {
                    addr_0x404951_32:
                    goto addr_0x404955_29;
                } else {
                    asm("outsd");
                    if (0) {
                        addr_0x404958_30:
                        if (!zf31) {
                            fun_40901c(ebp17);
                            goto addr_0x404966_44;
                        }
                    } else {
                        edx44->f121 = 0;
                        goto addr_0x4048e5_26;
                    }
                }
            } else {
                edx45->f121 = 0;
                eax29->f78 = (uint8_t)(eax29->f78 & dl46);
                edi9 = (struct s257*)((int32_t)edi9 + 1);
                *(uint8_t*)&ebx16 = (uint8_t)(*(uint8_t*)&ebx15 + *(uint8_t*)((int32_t)&ecx + 1));
                eax29 = (struct s262*)((uint32_t)eax29 | 0x90909090);
                goto addr_0x40487c_3;
            }
        } else {
            asm("arpl [edi+0x6d], bp");
            if (__intrinsic()) {
                addr_0x4048bc_17:
                goto addr_0x4048c0_48;
            } else {
                if (1) {
                    addr_0x4048c0_48:
                    edi9 = (struct s257*)((int32_t)edi9 - 1);
                    zf11 = edi9 == 0;
                    sf12 = (int32_t)edi9 < 0;
                    of13 = __intrinsic();
                    asm("outsb");
                    goto addr_0x4048c2_25;
                } else {
                    ebp17 = (void**)(edi9->f110 * 0x6e697720);
                    asm("outsd");
                    if ((uint1_t)(__intrinsic() | __undefined())) {
                        *esi47 = (uint8_t)(*esi48 & bh49);
                        ebx15->f117 = (uint8_t)(ebx15->f117 & dh50);
                        if (0) {
                            addr_0x4048d4_53:
                            *(uint8_t*)((int32_t)ecx + 0x73) = 0;
                            goto addr_0x4048db_41;
                        } else {
                            asm("outsd");
                            goto addr_0x404865_40;
                        }
                    }
                }
            }
        }
    }
    ebp17 = (void**)(edi9->f110 * 0x74656d20);
    goto addr_0x4048d4_53;
    addr_0x404932_37:
    if (!(*(uint8_t*)&ebx15 & 64)) 
        goto addr_0x404955_29;
    zf11 = (v51->f8 & 2) == 0;
    goto addr_0x40493c_28;
    addr_0x404966_44:
    if (*(uint8_t*)((int32_t)&ebx15 + 1) & 1) {
        fun_408f98(ebp17);
    }
    if (*(uint8_t*)((int32_t)&ebx15 + 1) & 8) {
        a3 = (void**)0;
        v2 = 0;
        fun_408fb0(ebp17, 0, 0);
    }
    if ((int8_t)*(uint8_t*)&ebx15 < (int8_t)0) {
        fun_408f8c(ebp17, v2, a3);
    }
    if (*(uint8_t*)((int32_t)&ebx15 + 1) & 2) {
        fun_409008(ebp17, v2, a3);
    }
    if (*(uint8_t*)&ebx15 & 8) {
        fun_409038(ebp17, v2, a3);
    }
    if (v52->f8 < 0 && (v53 = v52->f248, eax54 = fun_40906c(ebp17, v2, a3), v55 = eax54, eax56 = 0, 0 < v55)) {
        do {
            ebx57 = v53;
            edi58 = eax56 + 1;
            if ((uint8_t)0 < (uint8_t)*(void***)(ebp17 + 0xcc)) {
                esi59 = (void**)0;
                do {
                    v60 = *ebx57;
                    fun_403678(ebp17, v60, a3);
                    ++esi59;
                    ebx57 = ebx57 + 4;
                } while ((uint8_t)esi59 < (uint8_t)*(void***)(ebp17 + 0xcc));
            }
            eax56 = edi58;
        } while (eax56 < v55);
    }
    v61 = ebp17;
    fun_4030dc(v61, v62, a3, a4, a5, a6);
    goto v63;
}

void fun_4045fd() {
}

void fun_4046b6() {
}

void fun_408fad() {
}

struct s272 {
    int8_t[96] pad96;
    int32_t f96;
    int8_t f100;
    int8_t f101;
};

void fun_409095(struct s272* a1, int32_t a2, int32_t a3, int32_t a4) {
    int32_t ecx5;
    int32_t ebx6;

    ecx5 = a3;
    ebx6 = a4;
    a1->f96 = a2;
    a1->f100 = *(int8_t*)&ecx5;
    a1->f101 = *(int8_t*)&ebx6;
    return;
}

void fun_40906a() {
}

void fun_408fa1() {
}

void fun_408f95() {
}

struct s273 {
    int8_t[92] pad92;
    int32_t f92;
    int8_t[18] pad114;
    uint8_t f114;
};

void fun_404db8(struct s273* a1, int32_t a2) {
    a1->f114 = (uint8_t)(a1->f114 | 16);
    a1->f92 = a2;
    return;
}

void fun_402aaa() {
}

void fun_402a8e() {
}

struct s274 {
    int8_t[32] pad32;
    uint8_t f32;
    int8_t[39] pad72;
    uint8_t f72;
    int8_t[37] pad110;
    uint8_t f110;
    int8_t[3] pad114;
    uint8_t f114;
    int8_t[1] pad116;
    uint8_t f116;
};

struct s275 {
    int8_t[101] pad101;
    uint8_t f101;
    int8_t[1] pad103;
    int32_t f103;
    uint8_t f105;
    int8_t[3] pad111;
    uint8_t f111;
};

struct s276 {
    struct s276** f0;
    int8_t[97] pad98;
    int32_t f98;
    int32_t f99;
    uint8_t f101;
    int32_t f102;
    int32_t f104;
    int32_t f105;
    int32_t f110;
    uint8_t f112;
    uint8_t f114;
    uint8_t f118;
    int8_t[1426910213] pad1426910339;
    int8_t f1426910339;
};

struct s277 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s278 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s279 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s280 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s281 {
    int8_t[111] pad111;
    int8_t f111;
};

struct s282 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s283 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s284 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s285 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s286 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s287 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s288 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s289 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s290 {
    int8_t[111] pad111;
    uint8_t f111;
};

void fun_404fd3(struct s274* ecx) {
    struct s275* esi2;
    struct s275* esi3;
    struct s276* edi4;
    struct s276* edi5;
    struct s276** esp6;
    int1_t zf7;
    struct s277* edx8;
    struct s278* edx9;
    uint8_t bh10;
    uint8_t dh11;
    struct s276* ebp12;
    struct s279* ebx13;
    uint1_t cf14;
    uint1_t zf15;
    uint1_t below_or_equal16;
    struct s280* ebx17;
    int1_t zf18;
    struct s281* ebx19;
    struct s276* edx20;
    struct s276* eax21;
    int32_t eax22;
    struct s276* edx23;
    struct s282* ebx24;
    struct s283* ebx25;
    uint8_t dh26;
    struct s284* ebx27;
    struct s285* ebx28;
    uint8_t dh29;
    struct s286* ebx30;
    struct s276** esp31;
    struct s276* edx32;
    int8_t bl33;
    uint8_t* eax34;
    uint8_t* eax35;
    uint8_t dh36;
    void* al37;
    struct s276** esp38;
    struct s276* edx39;
    uint8_t dh40;
    int8_t dl41;
    struct s287* bx42;
    struct s288* bx43;
    uint8_t dh44;
    struct s289* bx45;
    struct s276** esp46;
    struct s276* edx47;
    struct s276** esp48;
    struct s276* edx49;
    int8_t dl50;
    int1_t zf51;
    struct s276* edx52;
    int8_t dl53;
    uint1_t zf54;
    struct s276* edx55;
    uint1_t cf56;
    uint1_t below_or_equal57;
    struct s276** esp58;
    uint8_t dh59;
    uint8_t dh60;
    uint1_t zf61;
    struct s276* edx62;
    int8_t dl63;
    int8_t dl64;

    esi2 = esi3;
    edi4 = edi5;
    esp6 = (struct s276**)((int32_t)__zero_stack_offset() - 4);
    if (zf7) {
        addr_0x405058_2:
        edx8->f101 = (uint8_t)(edx9->f101 & bh10);
        if (0) {
            addr_0x4050cc_3:
            *(uint8_t*)((int32_t)ecx + (uint32_t)edi4 * 2 + 0x70) = (uint8_t)(*(uint8_t*)((int32_t)ecx + (uint32_t)edi4 * 2 + 0x70) & dh11);
            asm("das");
            *(uint8_t*)((uint32_t)ebp12 + 0x70) = 0;
            if (!*(uint8_t*)((uint32_t)ebp12 + 0x70)) {
                addr_0x405144_4:
                asm("outsb");
                ebx13->f111 = 0;
                cf14 = 0;
                zf15 = (uint1_t)(ebx13->f111 == 0);
                below_or_equal16 = (uint1_t)static_cast<uint32_t>(zf15);
                asm("insd");
                if (0) 
                    goto addr_0x4051bf_5;
            } else {
                ebx17->f111 = 0;
                zf18 = ebx19->f111 == 0;
                goto addr_0x4050dd_7;
            }
        } else {
            ecx->f110 = 0;
            ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
            esp6 = (struct s276**)((uint8_t)esp6 + 1 - 4);
            *esp6 = edx20;
            ecx->f110 = (uint8_t)(ecx->f110 + *(uint8_t*)&ecx);
            if (__intrinsic() | (uint1_t)(ecx->f110 == 0)) {
                addr_0x4050cb_9:
                goto addr_0x4050cc_3;
            } else {
                asm("insb");
                esp6 = (struct s276**)(*(int32_t*)((uint32_t)eax21 + 0x69) * 0x6567616d);
                goto addr_0x405071_11;
            }
        }
    } else {
        ebp12 = (struct s276*)(esi2->f103 * 0x6d616720);
        asm("insd");
        asm("popad");
        --esp6;
        asm("popad");
        asm("insb");
        if (eax22 == 0x90900030) {
            addr_0x40507a_13:
            ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
            esp6 = (struct s276**)((uint8_t)esp6 + 1 - 4);
            *esp6 = edx23;
            ecx->f110 = (uint8_t)(ecx->f110 + *(uint8_t*)&ecx);
            if (__intrinsic() | (uint1_t)(ecx->f110 == 0)) 
                goto addr_0x4050e6_14; else 
                goto addr_0x405085_15;
        } else {
            ebx24->f105 = (uint8_t)(ebx25->f105 & dh26);
            if (__intrinsic()) {
                addr_0x405071_11:
                ebx27->f105 = (uint8_t)(ebx28->f105 & dh29);
                zf18 = ebx30->f105 == 0;
                if (__intrinsic()) {
                    addr_0x4050dd_7:
                    asm("insd");
                    asm("popad");
                    if (zf18) {
                        goto addr_0x405150_18;
                    } else {
                        addr_0x4050e6_14:
                        asm("outsd");
                        asm("outsb");
                        ecx->f110 = 0;
                        ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
                        esp31 = (struct s276**)((uint8_t)esp6 + 1 - 4);
                        *esp31 = edx32;
                        *(uint8_t*)&ebx13 = (uint8_t)(bl33 + *(uint8_t*)((int32_t)&ecx + 1));
                        eax21 = (struct s276*)((uint32_t)eax21 | 0x90909090);
                        goto addr_0x405100_19;
                    }
                } else {
                    ecx->f110 = 0;
                    goto addr_0x40507a_13;
                }
            } else {
                *eax34 = (uint8_t)(*eax35 & dh36);
                *(void**)&eax21 = (void*)((int8_t)al37 - 32);
                esp38 = esp6 - 1;
                asm("popad");
                asm("insb");
                asm("insb");
                asm("outsd");
                asm("arpl [ecx+0x74], sp");
                ebp12 = (struct s276*)(*(int32_t*)((uint32_t)edi4 + 0x6e) * 0x696b7320);
                if (__intrinsic()) {
                    addr_0x405095_22:
                    ecx = (struct s274*)((int32_t)ecx - 1);
                    eax21 = (struct s276*)((uint32_t)eax21 - 1);
                    esp31 = (struct s276**)((uint8_t)esp38 + 1 - 4);
                    *esp31 = edx39;
                    ecx->f110 = (uint8_t)(ecx->f110 + *(uint8_t*)&ecx);
                    if (__intrinsic() | (uint1_t)(ecx->f110 == 0)) {
                        addr_0x405100_19:
                        esp6 = esp31 - 1;
                        *esp6 = ebp12;
                        asm("outsb");
                        ebp12 = (struct s276*)(esi2->f111 * 0x77);
                        goto addr_0x405105_23;
                    } else {
                        asm("insb");
                        esp38 = (struct s276**)(*(int32_t*)((uint32_t)eax21 + 99) * 0x726f6c6f);
                        *(uint8_t*)((int32_t)ecx + (uint32_t)edi4 * 2 + 0x70) = (uint8_t)(*(uint8_t*)((int32_t)ecx + (uint32_t)edi4 * 2 + 0x70) & dh40);
                        ecx->f110 = 0;
                        ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
                        goto addr_0x4050b3_25;
                    }
                } else {
                    *(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) = (int8_t)(*(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) + dl41);
                    ecx = (struct s274*)((int32_t)ecx - 1);
                    asm("insd");
                    asm("popad");
                    *(uint8_t*)&bx42->f105 = (uint8_t)(*(uint8_t*)&bx43->f105 & dh44);
                    if (!*(int8_t*)&bx45->f105) {
                        addr_0x4050b3_25:
                        esp46 = (struct s276**)((uint8_t)esp38 + 1 - 4);
                        *esp46 = edx47;
                        *(uint8_t*)((uint32_t)ebp12 - 0x4372ff8a) = (uint8_t)(*(uint8_t*)((uint32_t)ebp12 - 0x4372ff8a) + *(uint8_t*)&ecx);
                        asm("daa");
                        *(struct s276***)eax21 = (struct s276**)((uint8_t)*(struct s276***)eax21 + (uint8_t)*(void**)&eax21);
                        *(struct s276***)eax21 = (struct s276**)((uint8_t)*(struct s276***)eax21 + (uint8_t)*(void**)&eax21);
                        ecx = (struct s274*)((int32_t)ecx - 1);
                        asm("outsb");
                        if (__intrinsic() | (uint1_t)(ecx == 0)) {
                            addr_0x405125_27:
                            esp6 = esp46 - 1;
                            *esp6 = ebp12;
                            asm("outsb");
                            goto addr_0x405144_4;
                        } else {
                            asm("insb");
                            esp6 = (struct s276**)(*(int32_t*)((uint32_t)eax21 + 99) * 0x726f6c6f);
                            goto addr_0x4050cb_9;
                        }
                    } else {
                        *(uint8_t*)((uint32_t)edi4 + 0x72) = 0;
                        *(uint8_t*)((uint32_t)eax21 + 0x65) = 0;
                        esp6 = (struct s276**)(*(int32_t*)((uint32_t)edi4 + 0x68) * 0x73692074);
                        goto addr_0x405058_2;
                    }
                }
            }
        }
    }
    if (1) {
        goto addr_0x4051c5_32;
    }
    addr_0x405150_18:
    ebp12 = (struct s276*)(*(int32_t*)((uint32_t)edi4 + 0x6e) * 0x74656d20);
    esp48 = esp6 - 1;
    *esp48 = (struct s276*)0x6920646f;
    asm("outsb");
    ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
    esp6 = (struct s276**)((uint8_t)esp48 + 1 - 4);
    *esp6 = edx49;
    *(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) = (int8_t)(*(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) + dl50);
    goto addr_0x405171_33;
    addr_0x405085_15:
    asm("insb");
    esp6 = (struct s276**)(*(int32_t*)((uint32_t)eax21 + 98) * 0x64207469);
    if (__intrinsic()) {
        addr_0x405105_23:
        asm("outsb");
        ecx->f110 = 0;
        zf51 = ecx->f110 == 0;
        if (zf51) {
            addr_0x405171_33:
            goto addr_0x40517a_34;
        } else {
            if (0) {
                addr_0x40517a_34:
                goto addr_0x40517e_36;
            } else {
                asm("popad");
                asm("arpl [ebp+0x20], sp");
                asm("insd");
                if (zf51) {
                    addr_0x40517e_36:
                    esi2 = (struct s275*)((int32_t)esi2 - 1);
                    edi4 = (struct s276*)((uint32_t)edi4 + 1);
                    esi2->f101 = 0;
                    asm("popad");
                    if (!esi2->f101) {
                        addr_0x4051fe_38:
                        goto addr_0x4051ff_39;
                    } else {
                        if (0) {
                            addr_0x4051f0_41:
                        } else {
                            if (1) {
                                goto addr_0x4051ae_44;
                            }
                            asm("popad");
                            if (!0) 
                                goto addr_0x405190_46;
                        }
                    }
                } else {
                    asm("outsd");
                    ecx->f110 = 0;
                    ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
                    esp46 = (struct s276**)((uint8_t)esp6 + 1 - 4);
                    *esp46 = edx52;
                    *(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) = (int8_t)(*(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) + dl53);
                    goto addr_0x405125_27;
                }
            }
        }
    } else {
        esp38 = esp6 - 1;
        *esp38 = (struct s276*)0x206e6920;
        goto addr_0x405095_22;
    }
    goto addr_0x4051fe_38;
    addr_0x405190_46:
    esi2->f111 = 0;
    zf54 = (uint1_t)(esi2->f111 == 0);
    if (zf54) {
        addr_0x4051b5_50:
        asm("outsb");
        *(uint8_t*)((int32_t)esi2 + 0x69) = 0;
        cf14 = 0;
        zf15 = (uint1_t)(*(uint8_t*)((int32_t)esi2 + 0x69) == 0);
        below_or_equal16 = (uint1_t)static_cast<uint32_t>(zf15);
        asm("insb");
        if (!zf15) {
            addr_0x4051bf_5:
            if (0) {
                goto addr_0x4051e3_53;
            } else {
                asm("insd");
                if (zf15) {
                    addr_0x40522d_55:
                    if (!cf14) 
                        goto 0x405250; else 
                        goto addr_0x405230_56;
                } else {
                    addr_0x4051c5_32:
                    asm("outsd");
                    ecx->f110 = 0;
                    ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
                    *(struct s276**)((uint8_t)esp6 + 1 - 4) = edx55;
                    ecx->f110 = (uint8_t)(ecx->f110 + *(uint8_t*)&ecx);
                    cf56 = __intrinsic();
                    below_or_equal57 = (uint1_t)(cf56 | (uint1_t)(ecx->f110 == 0));
                    if (below_or_equal57) {
                        addr_0x405235_57:
                        if (cf56) 
                            goto 0x4052a0; else 
                            goto addr_0x40523a_58;
                    } else {
                        asm("insb");
                        esp6 = (struct s276**)(*(int32_t*)((uint32_t)eax21 + 0x66) * 0x65746c69);
                        if (__intrinsic()) {
                            addr_0x4051ff_39:
                            goto addr_0x405200_60;
                        } else {
                            asm("insd");
                            if (__undefined()) 
                                goto 0x40524b; else 
                                goto addr_0x4051e3_53;
                        }
                    }
                }
            }
        }
    } else {
        asm("popad");
        asm("insb");
        asm("insb");
        asm("outsd");
        if (!(uint1_t)static_cast<uint32_t>(zf54)) {
            addr_0x405200_60:
            esp58 = esp6 - 1;
            *esp58 = edi4;
            esp6 = (struct s276**)(*(int32_t*)((uint8_t)esp58 + (int32_t)esi2 * 2 + 0x68) * 0x6f6f7420);
            ecx->f114 = 0;
            *(uint8_t*)&(*(struct s290**)&esi2)->f111 = (uint8_t)(*(uint8_t*)&(*(struct s290**)&esi2)->f111 & dh59);
            *(uint8_t*)((uint32_t)eax21 + 0x72) = (uint8_t)(*(uint8_t*)((uint32_t)eax21 + 0x72) & dh60);
            below_or_equal57 = (uint1_t)static_cast<uint32_t>((uint1_t)(*(uint8_t*)((uint32_t)eax21 + 0x72) == 0));
            goto addr_0x405213_63;
        } else {
            ecx->f110 = 0;
            ecx->f32 = 0;
            --esp6;
            *esp6 = eax21;
            esi2 = (struct s275*)((int32_t)esi2 - 1);
            edi4 = (struct s276*)((uint32_t)edi4 + 1);
            ecx->f116 = 0;
            zf61 = (uint1_t)(ecx->f116 == 0);
            below_or_equal57 = (uint1_t)static_cast<uint32_t>(zf61);
            asm("popad");
            if (1) {
                addr_0x405220_65:
                asm("popad");
                if (zf61) 
                    goto 0x405286;
            } else {
                if (0) {
                    addr_0x405213_63:
                    asm("outsd");
                    asm("arpl [ebp+0x73], sp");
                    if (1) {
                        addr_0x40523b_67:
                        asm("outsd");
                        if (!below_or_equal57) 
                            goto 0x40526c; else 
                            goto addr_0x40523e_68;
                    } else {
                        zf61 = __undefined();
                        goto addr_0x405220_65;
                    }
                } else {
                    addr_0x4051ae_44:
                    asm("popad");
                    asm("insd");
                    *(void**)&eax21 = (void*)((uint8_t)*(void**)&eax21 | (uint8_t)*(struct s276***)eax21);
                    --esp6;
                    *esp6 = (struct s276*)((uint32_t)ebp12 - 1);
                    asm("outsb");
                    goto addr_0x4051b5_50;
                }
            }
        }
    }
    cf14 = (uint1_t)((uint8_t)esp6 < (uint8_t)*(struct s276***)eax21);
    below_or_equal16 = (uint1_t)((uint8_t)esp6 <= (uint8_t)*(struct s276***)eax21);
    if (cf14) 
        goto "fP@";
    if (!below_or_equal16) 
        goto 0x40528d;
    if ((int8_t)esp6 >= (int8_t)*(struct s276***)eax21) 
        goto 0x4052a1; else 
        goto addr_0x40522d_55;
    addr_0x4051e3_53:
    asm("outsd");
    ecx->f110 = 0;
    ecx->f72 = (uint8_t)(ecx->f72 & *(uint8_t*)&ecx);
    esp6 = (struct s276**)((uint8_t)esp6 + 1 - 4);
    *esp6 = edx62;
    *(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) = (int8_t)(*(int8_t*)((uint32_t)eax21 - 0x6f6f6f70) + dl63);
    goto addr_0x4051f0_41;
    addr_0x405230_56:
    if (!below_or_equal16) 
        goto 0x40529b;
    asm("insb");
    asm("insb");
    *(uint8_t*)((uint32_t)edi4 + 0x76) = 0;
    cf56 = 0;
    below_or_equal57 = (uint1_t)static_cast<uint32_t>((uint1_t)(*(uint8_t*)((uint32_t)edi4 + 0x76) == 0));
    goto addr_0x405235_57;
    addr_0x40523a_58:
    asm("insb");
    goto addr_0x40523b_67;
    addr_0x40523e_68:
    *(int8_t*)((uint32_t)eax21 + 0x550cec83) = (int8_t)(*(int8_t*)((uint32_t)eax21 + 0x550cec83) + dl64);
}

struct s292 {
    int8_t[48] pad48;
    uint32_t f48;
    uint32_t f52;
    void** f56;
};

struct s291 {
    void** f0;
    int8_t[27] pad28;
    int32_t f28;
    int8_t[16] pad48;
    int32_t f48;
    struct s292* f52;
    int8_t[4] pad60;
    int32_t f60;
};

struct s293 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
};

struct s294 {
    void** f0;
    int8_t[59] pad60;
    int32_t f60;
};

struct s295 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
    int8_t[3] pad52;
    void** f52;
    int8_t[3] pad56;
    void** f56;
    int8_t[3] pad60;
    void** f60;
};

struct s297 {
    int8_t[56] pad56;
    void** f56;
    int8_t[128] pad185;
    uint8_t f185;
};

struct s296 {
    void** f0;
    int8_t[15] pad16;
    void** f16;
    int8_t[51] pad68;
    struct s297* f68;
};

void fun_40557b(int8_t cl) {
    struct s291* esp2;
    int32_t* eax3;
    void*** esp4;
    void** eax5;
    struct s293* esp6;
    struct s294* esp7;
    void** esi8;
    int32_t* esp9;
    struct s295* esp10;
    struct s296* esp11;
    int32_t ebp12;
    int32_t ebp13;
    void*** esp14;
    void** edi15;
    struct s293* esp16;
    int32_t esi17;
    void** ebx18;
    int32_t edi19;
    uint32_t eax20;
    uint32_t ebx21;
    uint32_t eax22;
    struct s292* edx23;
    struct s294* esp24;
    int32_t* esp25;
    struct s295* esp26;
    void** eax27;
    struct s297* edx28;
    uint32_t eax29;
    struct s294* esp30;
    int32_t* esp31;
    struct s295* esp32;
    struct s296* esp33;
    uint32_t* esp34;

    asm("outsb");
    esp2 = (struct s291*)(*eax3 * 0x6e);
    asm("outsd");
    if (!__undefined()) {
        if (!__intrinsic()) {
            addr_0x405601_4:
            esp2 = (struct s291*)&esp2->pad48;
            goto addr_0x405605_5;
        } else {
            if (__intrinsic()) {
                addr_0x4055fe_7:
                esp4 = (void***)((int32_t)esp2 - 4);
                *esp4 = eax5;
                esp6 = (struct s293*)(esp4 - 4);
                esp6->f0 = 0x405604;
                fun_417ac0(esp6->f4, esp6->f8, esp6->f12, esp6->f16, esp6->f20, esp6->f24, esp6->f28, esp6->f32);
                esp2 = (struct s291*)&esp6->f4;
                goto addr_0x405601_4;
            } else {
                asm("outsd");
                if (__intrinsic()) {
                    addr_0x405605_5:
                    esp7 = (struct s294*)((int32_t)esp2 - 8 - 4);
                    esp7->f0 = esi8;
                    esp9 = (int32_t*)((int32_t)esp7 - 4);
                    *esp9 = esp7->f60;
                    esp10 = (struct s295*)(esp9 - 1);
                    esp10->f0 = 0x405615;
                    fun_4029a0(esp10->f4, esp10->f8, esp10->f12, esp10->f16, esp10->f20, esp10->f24, esp10->f28, esp10->f32, esp10->f36, esp10->f40, esp10->f44, esp10->f48, esp10->f52, esp10->f56, esp10->f60);
                    esp11 = (struct s296*)&esp10->f4;
                    goto addr_0x405648_9;
                } else {
                    *(int8_t*)(ebp12 - 0x137cff8a) = (int8_t)(*(int8_t*)(ebp13 - 0x137cff8a) + cl);
                    esp14 = (void***)((int32_t)esp2 - 4);
                    *esp14 = edi15;
                    esp16 = (struct s293*)(esp14 - 4);
                    esp16->f0 = esi17;
                    esp2 = (struct s291*)((int32_t)esp16 - 4);
                    esp2->f0 = ebx18;
                    edi19 = esp2->f60;
                    if (!esp2->f48) 
                        goto 0x40575b;
                }
            }
        }
    }
    if (!esp2->f52) 
        goto 0x40575b;
    if (!edi19) 
        goto 0x40575b;
    eax20 = edi19 + esp2->f52->f48;
    ebx21 = esp2->f52->f52;
    if ((int32_t)eax20 <= (int32_t)ebx21) {
        addr_0x40564b_14:
        if ((uint1_t)(edi19 < 0) | (uint1_t)(edi19 == 0)) 
            goto 0x40575b;
    } else {
        esi8 = esp2->f52->f56;
        if (!esi8) {
            eax22 = edi19 + 8;
            edx23 = esp2->f52;
            edx23->f52 = eax22;
            edx23->f48 = 0;
            esp24 = (struct s294*)((int32_t)esp2 - 8 - 4);
            esp24->f0 = (void**)(eax22 << 4);
            esp25 = (int32_t*)((int32_t)esp24 - 4);
            *esp25 = esp24->f60;
            esp26 = (struct s295*)(esp25 - 1);
            esp26->f0 = 0x40563a;
            eax27 = fun_402940(esp26->f4, esp26->f8, esp26->f12, esp26->f16, esp26->f20, esp26->f24, esp26->f28, esp26->f32, esp26->f36, esp26->f40, esp26->f44, esp26->f48);
            esp11 = (struct s296*)&esp26->f4;
            edx28 = esp11->f68;
            edx28->f56 = eax27;
            edx28->f185 = (uint8_t)(edx28->f185 | 64);
            goto addr_0x405648_9;
        } else {
            eax29 = eax20 + 8;
            esp2->f52->f52 = eax29;
            esp30 = (struct s294*)((int32_t)esp2 - 8 - 4);
            esp30->f0 = (void**)(eax29 << 4);
            esp31 = (int32_t*)((int32_t)esp30 - 4);
            *esp31 = esp30->f60;
            esp32 = (struct s295*)(esp31 - 1);
            esp32->f0 = 0x4055ef;
            eax5 = fun_402940(esp32->f4, esp32->f8, esp32->f12, esp32->f16, esp32->f20, esp32->f24, esp32->f28, esp32->f32, esp32->f36, esp32->f40, esp32->f44, esp32->f48);
            esp33 = (struct s296*)&esp32->f4;
            esp33->f68->f56 = eax5;
            esp34 = (uint32_t*)((int32_t)esp33 - 4 - 4);
            *esp34 = ebx21 << 4;
            esp2 = (struct s291*)(esp34 - 1);
            esp2->f0 = esi8;
            goto addr_0x4055fe_7;
        }
    }
    esp2->f28 = edi19;
    addr_0x405648_9:
    esp2 = (struct s291*)&esp11->f16;
    goto addr_0x40564b_14;
}

void fun_405bf6(void** a1, void** a2, void** a3) {
    void** v4;
    void** v5;
    void** v6;
    void** v7;
    void** ebx8;
    void** esi9;
    void** v10;
    void** v11;
    void** v12;
    void** v13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** eax22;

    v4 = (void**)__return_address();
    if (*(void***)(a1 + 0xac)) {
        v5 = *(void***)(a1 + 0xac);
        fun_4029a0(a1, v5, v6, v7, ebx8, esi9, v10, v11, v12, v13, v14, v4, a1, a2, a3);
    }
    *(void***)(a1 + 0xb0) = a2;
    eax22 = fun_402940(a1, a2, v15, v16, ebx8, esi9, v17, v18, v19, v20, v21, v4);
    *(void***)(a1 + 0xac) = eax22;
    *(void***)(a1 + 0x80) = eax22;
    *(void***)(a1 + 0x84) = *(void***)(a1 + 0xb0);
    return;
}

void fun_405c91(void** a1, void** a2, void** a3) {
    void** ebx4;
    void** esi5;
    void** v6;
    void** v7;

    if (a1 && a2) {
        if (*(void***)(a2 + 0xf8) && *(void***)(a2 + 0xf8) != a3) {
            fun_406c0c(a1, a2, 64, 0, ebx4, esi5, v6, v7);
        }
        *(void***)(a2 + 0xf8) = a3;
        if (a3) {
            *(void***)(a2 + 9) = (void**)((uint8_t)*(void***)(a2 + 9) | 0x80);
        }
    }
    return;
}

struct s298 {
    int8_t[8] pad8;
    uint8_t f8;
    int8_t[81] pad90;
    int32_t f90;
    int32_t f94;
    int16_t f98;
};

struct s299 {
    int32_t f0;
    int32_t f4;
    uint16_t f8;
};

void fun_405cdd(int32_t a1, struct s298* a2, struct s299* a3) {
    uint32_t eax4;

    if (a1 && a2) {
        a2->f90 = a3->f0;
        a2->f94 = a3->f4;
        eax4 = static_cast<uint32_t>(a3->f8);
        a2->f98 = *(int16_t*)&eax4;
        a2->f8 = (uint8_t)(a2->f8 | 32);
    }
    return;
}

struct s300 {
    int8_t[8] pad8;
    uint8_t f8;
    int8_t[247] pad256;
    int32_t f256;
    int32_t f260;
    int32_t f264;
    int32_t f268;
    int32_t f272;
    int32_t f276;
    int32_t f280;
    int32_t f284;
};

struct s301 {
    int8_t[1] pad1;
    int8_t f1;
};

void fun_405d0c(int32_t ecx, int32_t a2, struct s300* a3) {
    int8_t* eax4;
    int8_t* eax5;
    int8_t al6;
    int8_t* eax7;
    int8_t* eax8;
    int8_t al9;
    int32_t edx10;
    int32_t edx11;
    int8_t* eax12;
    struct s301* eax13;
    struct s300* edx14;
    int32_t v15;
    int32_t v16;
    int32_t v17;
    int32_t v18;
    int32_t v19;
    int32_t v20;
    int32_t v21;
    int32_t v22;
    int32_t v23;

    *eax4 = (int8_t)(*eax5 + al6);
    *eax7 = (int8_t)(*eax8 + al9);
    *(int8_t*)(edx10 - 8) = (int8_t)(*(int8_t*)(edx11 - 8) + *(int8_t*)((int32_t)&ecx + 1));
    eax12 = &eax13->f1;
    *eax12 = (int8_t)(*eax12 + *(int8_t*)&eax12);
    *eax12 = (int8_t)(*eax12 + *(int8_t*)&eax12);
    *eax12 = (int8_t)(*eax12 + *(int8_t*)&eax12);
    if ((uint1_t)!!(ecx - 1) & (uint1_t)!!*eax12) {
        goto addr_0x405d61_3;
    } else {
        edx14 = a3;
        asm("fld qword [esp+0x38]");
        asm("fld qword [esp+0x40]");
        asm("fld qword [esp+0x48]");
        asm("fld qword [esp+0x50]");
        asm("fld qword [esp+0x58]");
        asm("fld qword [esp+0x60]");
        asm("fld qword [esp+0x68]");
        asm("fstp qword [esp+0x8]");
        asm("fld qword [esp+0x70]");
        asm("fstp qword [esp]");
        if (!a2 || !edx14) {
            asm("fstp st0");
            asm("fstp st0");
            asm("fstp st0");
            asm("fstp st0");
            asm("fstp st0");
            asm("fstp st0");
        } else {
            addr_0x405d61_3:
            asm("fxch st0, st5");
            asm("fst dword [edx+0x80]");
            asm("fxch st0, st4");
            asm("fst dword [edx+0x84]");
            asm("fxch st0, st3");
            asm("fst dword [edx+0x88]");
            asm("fxch st0, st2");
            asm("fst dword [edx+0x8c]");
            asm("fxch st0, st1");
            asm("fst dword [edx+0x90]");
            asm("fxch st0, st5");
            asm("fst dword [edx+0x94]");
            asm("fld qword [esp+0x8]");
            asm("fstp dword [edx+0x98]");
            asm("fld qword [esp]");
            asm("fstp dword [edx+0x9c]");
            asm("fld qword [0x405d10]");
            asm("fmul st5, st0");
            asm("fld qword [0x405d18]");
            asm("fadd st6, st0");
            asm("fxch st0, st5");
            asm("fmul st0, st1");
            asm("fadd st0, st5");
            asm("fxch st0, st4");
            asm("fmul st0, st1");
            asm("fadd st0, st5");
            asm("fxch st0, st3");
            asm("fmul st0, st1");
            asm("fadd st0, st5");
            asm("fxch st0, st7");
            asm("fmul st0, st1");
            asm("fadd st0, st5");
            asm("fxch st0, st2");
            asm("fmul st0, st1");
            asm("fadd st0, st5");
            asm("fxch st0, st6");
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st3");
            edx14->f256 = v15;
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st1");
            edx14->f260 = v16;
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st4");
            edx14->f264 = v17;
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st3");
            edx14->f268 = v18;
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st1");
            edx14->f272 = v19;
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            edx14->f276 = v20;
            asm("fld qword [esp+0x8]");
            asm("fmul st0, st2");
            asm("fadd st0, st1");
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            asm("fxch st0, st1");
            edx14->f280 = v21;
            asm("fmul qword [esp]");
            asm("fstp qword [esp]");
            asm("fadd qword [esp]");
            asm("fnstcw word [esp+0x1a]");
            asm("fldcw word [esp+0x18]");
            asm("fistp dword [esp+0x14]");
            asm("fldcw word [esp+0x1a]");
            edx14->f284 = v22;
            edx14->f8 = (uint8_t)(edx14->f8 | 4);
        }
        goto v23;
    }
}

struct s302 {
    int8_t[8] pad8;
    uint8_t f8;
    int8_t[247] pad256;
    int32_t f256;
    int32_t f260;
    int32_t f264;
    int32_t f268;
    int32_t f272;
    int32_t f276;
    int32_t f280;
    int32_t f284;
};

void fun_405f50(int32_t a1, struct s302* a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, int32_t a7, int32_t a8, int32_t a9, int32_t a10) {
    int8_t* eax11;
    int8_t* eax12;
    int8_t al13;
    int8_t* eax14;
    int8_t* eax15;
    int8_t al16;
    int32_t edx17;
    int32_t edx18;
    int8_t ch19;

    *eax11 = (int8_t)(*eax12 + al13);
    *eax14 = (int8_t)(*eax15 + al16);
    *(int8_t*)(edx17 - 8) = (int8_t)(*(int8_t*)(edx18 - 8) + ch19);
    if (a1 && a2) {
        a2->f256 = a3;
        a2->f260 = a4;
        a2->f264 = a5;
        a2->f268 = a6;
        a2->f272 = a7;
        a2->f276 = a8;
        a2->f280 = a9;
        a2->f284 = a10;
        asm("fild dword [esp+0x1c]");
        asm("fld qword [0x405f50]");
        asm("fdiv st1, st0");
        asm("fxch st0, st1");
        asm("fstp dword [eax+0x80]");
        asm("fild dword [esp+0x1c]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x84]");
        asm("fild dword [esp+0x1c]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x88]");
        asm("fild dword [esp+0x1c]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x8c]");
        asm("fild dword [esp+0x1c]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x90]");
        asm("fild dword [esp+0x4c]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x94]");
        asm("fild dword [esp+0x50]");
        asm("fdiv st0, st1");
        asm("fstp dword [eax+0x98]");
        asm("fild dword [esp+0x54]");
        asm("fdivrp st1, st0");
        asm("fstp dword [eax+0x9c]");
        a2->f8 = (uint8_t)(a2->f8 | 4);
    }
    return;
}

struct s303 {
    int8_t[1] pad1;
    int8_t f1;
};

void fun_40604e(void* ecx, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8, void** a9, void** a10) {
    int8_t* eax11;
    int8_t* eax12;
    int8_t al13;
    int8_t* eax14;
    int8_t* eax15;
    int8_t al16;
    int32_t edx17;
    int32_t edx18;
    int8_t* eax19;
    struct s303* eax20;
    void** ecx21;
    void** eax22;
    void** edx23;
    void** v24;
    void** v25;
    int32_t v26;

    *eax11 = (int8_t)(*eax12 + al13);
    *eax14 = (int8_t)(*eax15 + al16);
    *(int8_t*)(edx17 - 8) = (int8_t)(*(int8_t*)(edx18 - 8) + *(int8_t*)((int32_t)&ecx + 1));
    eax19 = &eax20->f1;
    *eax19 = (int8_t)(*eax19 + *(int8_t*)&eax19);
    *eax19 = (int8_t)(*eax19 + *(int8_t*)&eax19);
    *eax19 = (int8_t)(*eax19 + *(int8_t*)&eax19);
    ecx21 = (void**)((int32_t)ecx - 1);
    if ((uint1_t)!!ecx21 & (uint1_t)!!*eax19) {
        addr_0x40609f_2:
        asm("fldcw word [esp+0x18]");
        asm("fistp dword [esp+0x14]");
        eax22 = a6;
        asm("fldcw word [esp+0x1a]");
        *(void***)(edx23 + 0xfc) = eax22;
        *(void***)(edx23 + 8) = (void**)((uint8_t)*(void***)(edx23 + 8) | 1);
        asm("fldz");
        asm("fucompp");
        asm("fnstsw ax");
        if (!((uint8_t)(*(uint8_t*)(&eax22 + 1) & 68) ^ 64)) {
            fun_40850c(ecx21, 0x404fe0, v24, v25, __return_address(), a2, a3, a4, a5, a6, a7, a8, a9, a10);
        }
    } else {
        ecx21 = a2;
        edx23 = a3;
        asm("fld qword [esp+0x38]");
        if (!ecx21 || !edx23) {
            asm("fstp st0");
        } else {
            asm("fld st0");
            asm("fmul qword [0x406050]");
            asm("fadd qword [0x406058]");
            asm("fxch st0, st1");
            asm("fst dword [edx+0x28]");
            asm("fxch st0, st1");
            asm("fnstcw word [esp+0x1a]");
            goto addr_0x40609f_2;
        }
    }
    goto v26;
}

void** fun_4060e2(void** a1, void** a2, void** a3) {
    int8_t* eax4;
    int8_t* eax5;
    int8_t al6;
    int8_t* eax7;
    int8_t* eax8;
    int8_t al9;
    int32_t edx10;
    int32_t edx11;
    int8_t ch12;
    void** eax13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;

    *eax4 = (int8_t)(*eax5 + al6);
    *eax7 = (int8_t)(*eax8 + al9);
    *(int8_t*)(edx10 - 8) = (int8_t)(*(int8_t*)(edx11 - 8) + ch12);
    eax13 = a2;
    if (a1 && (eax13 && (*(void***)(eax13 + 0xfc) = a3, *(void***)(eax13 + 8) = (void**)((uint8_t)*(void***)(eax13 + 8) | 1), !a3))) {
        eax13 = fun_40850c(a1, 0x404fe0, v14, v15, v16, v17, v18, a3, v19, v20, v21, __return_address(), a1, a2);
    }
    return eax13;
}

void** fun_40613c(void** a1, void** a2, uint16_t* a3) {
    void** esi4;
    void** ebx5;
    uint16_t* edi6;
    void** ebx7;
    void** esi8;
    void** edi9;
    void** v10;
    void** v11;
    void** v12;
    void** eax13;
    uint32_t ecx14;
    uint32_t edx15;
    void** eax16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;
    void** v22;

    esi4 = a1;
    ebx5 = a2;
    edi6 = a3;
    if (esi4 && ebx5) {
        if (*(void***)(ebx5 + 20)) {
            fun_406c0c(esi4, ebx5, 8, 0, ebx7, esi8, edi9, v10);
            eax13 = fun_402940(esi4, 0x200, v11, 0x40617b, esi4, ebx5, 8, 0, ebx7, esi8, edi9, v12);
            *(void***)(esi4 + 0x1f4) = eax13;
            ecx14 = 0;
            if (*(void***)(ebx5 + 20)) {
                do {
                    edx15 = static_cast<uint32_t>(edi6[ecx14]);
                    *(void***)(*(void***)(esi4 + 0x1f4) + ecx14 * 2) = *(void***)&edx15;
                    ++ecx14;
                } while ((int32_t)ecx14 < (int32_t)static_cast<uint32_t>((uint16_t)*(void***)(ebx5 + 20)));
            }
            eax16 = *(void***)(esi4 + 0x1f4);
            *(void***)(ebx5 + 0x7c) = eax16;
            *(void***)(ebx5 + 8) = (void**)((uint8_t)*(void***)(ebx5 + 8) | 64);
            *(void***)(ebx5 + 0xb8) = (void**)((uint8_t)*(void***)(ebx5 + 0xb8) | 8);
        } else {
            eax16 = fun_40850c(esi4, 0x405000, v17, v18, ebx7, esi8, edi9, v19, v20, v21, v22, __return_address(), a1, a2);
        }
    }
    return eax16;
}

struct s304 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[90] pad100;
    int32_t f100;
    int32_t f104;
    int8_t f108;
};

void fun_4061ce(int32_t a1, struct s304* a2, int32_t a3, int32_t a4, int32_t a5) {
    int32_t eax6;

    if (a1 && a2) {
        a2->f100 = a3;
        a2->f104 = a4;
        eax6 = a5;
        a2->f108 = *(int8_t*)&eax6;
        a2->f9 = (uint8_t)(a2->f9 | 1);
    }
    return;
}

struct s305 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[150] pad160;
    void** f160;
    int8_t[3] pad164;
    int32_t f164;
    int32_t f168;
    void** f172;
    int8_t[3] pad176;
    void** f176;
    int8_t[3] pad180;
    int8_t f180;
    int8_t f181;
    int8_t[2] pad184;
    uint8_t f184;
};

void fun_4061f9(void** a1, struct s305* a2, void** a3, int32_t a4, int32_t a5, int32_t a6, uint32_t a7, void** a8, void*** a9) {
    int32_t v10;
    void** v11;
    void** ebp12;
    void** v13;
    void** edi14;
    void** v15;
    void** esi16;
    void** v17;
    void** ebx18;
    void** ebx19;
    void** ebp20;
    void** edi21;
    int32_t ecx22;
    void** esi23;
    void** v24;
    void** v25;
    void** v26;
    void** v27;
    void** v28;
    void** eax29;
    void** v30;
    void** v31;
    int32_t eax32;
    void** edi33;
    int32_t ecx34;
    void** esi35;
    void** v36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** eax41;
    void** v42;
    void** v43;
    void** v44;
    void** v45;
    void** v46;
    void** v47;
    void** v48;
    void** eax49;
    uint32_t ebp50;
    uint32_t eax51;
    void** edi52;
    int32_t ecx53;
    void** v54;
    void** v55;
    void** v56;
    void** v57;
    void** v58;
    void** eax59;
    void** eax60;
    void** v61;
    void** v62;
    void** v63;
    void** v64;
    void** edi65;
    int32_t ecx66;
    void** esi67;
    void** v68;
    void** v69;
    void** v70;
    void** v71;
    void** v72;
    void** eax73;
    void** eax74;
    void** v75;
    void** v76;
    void** v77;
    void** v78;
    uint32_t ebx79;
    void** edi80;
    int32_t ecx81;
    void** esi82;
    void** v83;
    void** v84;
    void** v85;
    void** v86;
    void** v87;
    void** eax88;
    void** eax89;
    void** v90;
    void** v91;
    void** v92;
    void** v93;
    uint32_t ebx94;
    void** edi95;
    int32_t ecx96;
    void** esi97;
    void** v98;
    void** v99;
    void** v100;
    void** v101;
    void** v102;
    void** eax103;
    void** eax104;
    void** v105;
    void** v106;
    void** v107;
    void** v108;
    uint32_t ebx109;
    void** edi110;
    int32_t ecx111;
    void** v112;
    void** v113;
    void** v114;
    void** v115;
    void** v116;
    void** eax117;
    void** eax118;
    void** v119;
    void** v120;
    void** v121;
    void** v122;
    void** edi123;
    int32_t ecx124;
    void** v125;
    void** v126;
    void** v127;
    void** v128;
    void** v129;
    void** eax130;
    void** eax131;
    void** v132;
    void** v133;
    void** v134;
    void** v135;
    void** edi136;
    int32_t ecx137;
    void** v138;
    void** v139;
    void** v140;
    void** v141;
    void** v142;
    void** eax143;
    void** eax144;
    void** v145;
    void** v146;
    void** v147;
    void** v148;

    v10 = (int32_t)__return_address();
    v11 = ebp12;
    v13 = edi14;
    v15 = esi16;
    v17 = ebx18;
    ebx19 = a3;
    ebp20 = a8;
    if (!a1 || !a2) {
        addr_0x40656d_2:
        return;
    } else {
        edi21 = ebx19;
        ecx22 = -1;
        do {
            if (!ecx22) 
                break;
            --ecx22;
            ++edi21;
        } while (*(void***)edi21);
        esi23 = (void**)~ecx22;
        eax29 = fun_402940(a1, esi23, v24, v25, v17, v15, v13, v11, v26, v27, v28, *(void***)&v10);
        a2->f160 = eax29;
        fun_417ac0(eax29, ebx19, esi23, 0x40623f, a1, esi23, v30, v31);
        a2->f164 = a4;
        a2->f168 = a5;
        eax32 = a6;
        a2->f180 = *(int8_t*)&eax32;
        a2->f181 = *(int8_t*)&a7;
        edi33 = ebp20;
        ecx34 = -1;
        do {
            if (!ecx34) 
                break;
            --ecx34;
            ++edi33;
        } while (*(void***)edi33);
        esi35 = (void**)~ecx34;
        eax41 = fun_402940(a1, esi35, v36, v37, v17, v15, v13, v11, v38, v39, v40, *(void***)&v10);
        a2->f172 = eax41;
        fun_417ac0(eax41, ebp20, esi35, 0x4062a1, a1, esi35, v42, v43);
        eax49 = fun_402940(a1, a7 * 4 + 4, v44, v45, v17, v15, v13, v11, v46, v47, v48, *(void***)&v10);
        a2->f176 = eax49;
        *(void***)(eax49 + a7 * 4) = (void**)0;
        ebp50 = 0;
        if ((int32_t)0 >= (int32_t)a7) 
            goto addr_0x40655e_10;
        eax51 = a7 & 3;
        if (!((uint1_t)((int32_t)a7 < (int32_t)0) | (uint1_t)(a7 == 0))) 
            goto addr_0x406303_12;
    }
    addr_0x4063b7_13:
    edi52 = a9[ebp50 * 4];
    ecx53 = -1;
    do {
        if (!ecx53) 
            break;
        --ecx53;
        ++edi52;
    } while (*(void***)edi52);
    esi35 = (void**)~ecx53;
    eax59 = fun_402940(a1, esi35, v54, v55, v17, v15, v13, v11, v56, v57, v58, *(void***)&v10);
    *(void***)(a2->f176 + ebp50 * 4) = eax59;
    eax60 = a2->f176;
    v61 = a9[ebp50 * 4];
    v62 = *(void***)(eax60 + ebp50 * 4);
    fun_417ac0(v62, v61, esi35, 0x4063da, a1, esi35, v63, v64);
    ++ebp50;
    if ((int32_t)ebp50 >= (int32_t)a7) {
        addr_0x40655e_10:
        a2->f9 = (uint8_t)(a2->f9 | 4);
        a2->f184 = (uint8_t)(a2->f184 | 0x80);
        goto addr_0x40656d_2;
    } else {
        do {
            addr_0x406410_17:
            edi65 = a9[ebp50 * 4];
            ecx66 = -1;
            do {
                if (!ecx66) 
                    break;
                --ecx66;
                ++edi65;
            } while (*(void***)edi65);
            esi67 = (void**)~ecx66;
            eax73 = fun_402940(a1, esi67, v68, v69, v17, v15, v13, v11, v70, v71, v72, *(void***)&v10);
            *(void***)(a2->f176 + ebp50 * 4) = eax73;
            eax74 = a2->f176;
            v75 = a9[ebp50 * 4];
            v76 = *(void***)(eax74 + ebp50 * 4);
            fun_417ac0(v76, v75, esi67, 0x406433, a1, esi67, v77, v78);
            ebx79 = ebp50 + 1;
            edi80 = a9[ebx79 * 4];
            ecx81 = -1;
            do {
                if (!ecx81) 
                    break;
                --ecx81;
                ++edi80;
            } while (*(void***)edi80);
            esi82 = (void**)~ecx81;
            eax88 = fun_402940(a1, esi82, v83, v84, v17, v15, v13, v11, v85, v86, v87, *(void***)&v10);
            *(void***)(a2->f176 + ebx79 * 4) = eax88;
            eax89 = a2->f176;
            v90 = a9[ebx79 * 4];
            v91 = *(void***)(eax89 + ebx79 * 4);
            fun_417ac0(v91, v90, esi82, 0x406484, a1, esi82, v92, v93);
            ebx94 = ebp50 + 2;
            edi95 = a9[ebx94 * 4];
            ecx96 = -1;
            do {
                if (!ecx96) 
                    break;
                --ecx96;
                ++edi95;
            } while (*(void***)edi95);
            esi97 = (void**)~ecx96;
            eax103 = fun_402940(a1, esi97, v98, v99, v17, v15, v13, v11, v100, v101, v102, *(void***)&v10);
            *(void***)(a2->f176 + ebx94 * 4) = eax103;
            eax104 = a2->f176;
            v105 = a9[ebx94 * 4];
            v106 = *(void***)(eax104 + ebx94 * 4);
            fun_417ac0(v106, v105, esi97, 0x4064d5, a1, esi97, v107, v108);
            ebx109 = ebp50 + 3;
            edi110 = a9[ebx109 * 4];
            ecx111 = -1;
            do {
                if (!ecx111) 
                    break;
                --ecx111;
                ++edi110;
            } while (*(void***)edi110);
            esi35 = (void**)~ecx111;
            eax117 = fun_402940(a1, esi35, v112, v113, v17, v15, v13, v11, v114, v115, v116, *(void***)&v10);
            *(void***)(a2->f176 + ebx109 * 4) = eax117;
            eax118 = a2->f176;
            v119 = a9[ebx109 * 4];
            v120 = *(void***)(eax118 + ebx109 * 4);
            fun_417ac0(v120, v119, esi35, 0x406526, a1, esi35, v121, v122);
            ebp50 = ebp50 + 4;
        } while ((int32_t)ebp50 < (int32_t)a7);
        goto addr_0x40655e_10;
    }
    addr_0x406303_12:
    if (!eax51) 
        goto addr_0x406410_17;
    if ((int32_t)eax51 > (int32_t)1) {
        if ((int32_t)eax51 > (int32_t)2) {
            edi123 = *a9;
            ecx124 = -1;
            do {
                if (!ecx124) 
                    break;
                --ecx124;
                ++edi123;
            } while (*(void***)edi123);
            esi35 = (void**)~ecx124;
            eax130 = fun_402940(a1, esi35, v125, v126, v17, v15, v13, v11, v127, v128, v129, *(void***)&v10);
            *(void***)a2->f176 = eax130;
            eax131 = a2->f176;
            v132 = *a9;
            v133 = *(void***)eax131;
            fun_417ac0(v133, v132, esi35, 0x40633b, a1, esi35, v134, v135);
            ebp50 = 1;
        }
        edi136 = a9[ebp50 * 4];
        ecx137 = -1;
        do {
            if (!ecx137) 
                break;
            --ecx137;
            ++edi136;
        } while (*(void***)edi136);
        esi35 = (void**)~ecx137;
        eax143 = fun_402940(a1, esi35, v138, v139, v17, v15, v13, v11, v140, v141, v142, *(void***)&v10);
        *(void***)(a2->f176 + ebp50 * 4) = eax143;
        eax144 = a2->f176;
        v145 = a9[ebp50 * 4];
        v146 = *(void***)(eax144 + ebp50 * 4);
        fun_417ac0(v146, v145, esi35, 0x40638b, a1, esi35, v147, v148);
        ++ebp50;
        goto addr_0x4063b7_13;
    }
}

struct s306 {
    int8_t[8] pad8;
    uint8_t f8;
    int8_t[103] pad112;
    int32_t f112;
    int32_t f116;
    int8_t f120;
};

void fun_406575(int32_t a1, struct s306* a2, int32_t a3, int32_t a4, int32_t a5) {
    int32_t eax6;

    if (a1 && a2) {
        a2->f112 = a3;
        a2->f116 = a4;
        eax6 = a5;
        a2->f120 = *(int8_t*)&eax6;
        a2->f8 = (uint8_t)(a2->f8 | 0x80);
    }
    return;
}

void fun_4065a1() {
}

struct s307 {
    int8_t[8] pad8;
    uint8_t f8;
    int8_t[59] pad68;
    int32_t f68;
    int8_t f72;
};

struct s308 {
    int32_t f0;
    int8_t f4;
};

void fun_406621(int32_t a1, struct s307* a2, struct s308* a3) {
    if (a1 && a2) {
        a2->f68 = a3->f0;
        a2->f72 = a3->f4;
        a2->f8 = (uint8_t)(a2->f8 | 2);
    }
    return;
}

struct s309 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[34] pad44;
    int8_t f44;
};

void fun_406648(int32_t a1, struct s309* a2, int32_t a3) {
    int32_t eax4;

    if (a1 && a2) {
        eax4 = a3;
        a2->f44 = *(int8_t*)&eax4;
        a2->f9 = (uint8_t)(a2->f9 | 8);
    }
    return;
}

void fun_406664(void** a1, void** a2, void** a3, int32_t a4, void** a5, void** a6) {
    int32_t v7;
    void** v8;
    void** ebp9;
    void** v10;
    void** edi11;
    void** v12;
    void** esi13;
    void** v14;
    void** ebx15;
    void** ebp16;
    void** esi17;
    void** ebx18;
    void** edi19;
    int32_t ecx20;
    void** v21;
    void** v22;
    void** v23;
    void** v24;
    void** v25;
    void** eax26;
    void** v27;
    void** v28;
    void** v29;
    void** v30;
    void** v31;
    void** v32;
    void** eax33;
    void** v34;
    void** v35;
    int32_t eax36;

    v7 = (int32_t)__return_address();
    v8 = ebp9;
    v10 = edi11;
    v12 = esi13;
    v14 = ebx15;
    ebp16 = a1;
    esi17 = a2;
    ebx18 = a3;
    if (ebp16 && (esi17 && (ebx18 && a5))) {
        edi19 = ebx18;
        ecx20 = -1;
        do {
            if (!ecx20) 
                break;
            --ecx20;
            ++edi19;
            ++esi17;
        } while (*(void***)edi19);
        eax26 = fun_402940(ebp16, ~ecx20, v21, v22, v14, v12, v10, v8, v23, v24, v25, *(void***)&v7);
        fun_417f90(eax26, ebx18, v27, 0x4066b2, ebp16, ~ecx20);
        eax33 = fun_402940(ebp16, a6, v28, v29, v14, v12, v10, v8, v30, v31, v32, *(void***)&v7);
        fun_417ac0(eax33, a5, a6, 0x4066cf, ebp16, a6, v34, v35);
        fun_406c0c(ebp16, esi17, 16, 0, v14, v12, v10, v8);
        *(void***)(esi17 + 0xcc) = a6;
        *(void***)(esi17 + 0xc4) = eax26;
        *(void***)(esi17 + 0xc8) = eax33;
        eax36 = a4;
        *(void***)(esi17 + 0xd0) = *(void***)&eax36;
        *(void***)(esi17 + 0xb8) = (void**)((uint8_t)*(void***)(esi17 + 0xb8) | 16);
        *(void***)(esi17 + 9) = (void**)((uint8_t)*(void***)(esi17 + 9) | 16);
    }
    return;
}

struct s310 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s311 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[50] pad60;
    int32_t f60;
    int32_t f64;
};

struct s312 {
    int32_t f0;
    int32_t f4;
};

void fun_406728(struct s310* a1, struct s311* a2, struct s312* a3) {
    if (a1 && (a2 && !(a1->f105 & 2))) {
        a2->f60 = a3->f0;
        a2->f64 = a3->f4;
        a2->f9 = (uint8_t)(a2->f9 | 2);
    }
    return;
}

struct s313 {
    uint32_t f0;
    void** f4;
    int8_t[3] pad8;
    uint16_t f8;
};

void fun_406752(void** a1, void** a2, void** a3, void** a4, struct s313* a5) {
    void** v6;
    void** ebp7;
    void** esi8;
    void** ebx9;
    void** esi10;
    void** edi11;
    void** v12;
    void** eax13;
    void** v14;
    uint32_t eax15;

    v6 = ebp7;
    esi8 = a4;
    if (a1 && a2) {
        if (a3) {
            fun_406c0c(a1, a2, 0x2000, 0, ebx9, esi10, edi11, v6);
            eax13 = fun_402940(a1, 0x100, v12, 0x406788, a1, a2, 0x2000, 0, ebx9, esi10, edi11, v6);
            *(void***)(a2 + 76) = eax13;
            *(void***)(a1 + 0x188) = eax13;
            v14 = *(void***)(a2 + 76);
            fun_417ac0(v14, a3, esi8, 0, ebx9, esi10, edi11, v6);
            *(uint8_t*)(a2 + 0xb9) = (uint8_t)(*(uint8_t*)(a2 + 0xb9) | 32);
        }
        if (a5 && (*(uint32_t*)(a2 + 80) = a5->f0, *(void***)(a2 + 84) = a5->f4, eax15 = static_cast<uint32_t>(a5->f8), *(void***)(a2 + 88) = *(void***)&eax15, !esi8)) {
            esi8 = (void**)1;
        }
        *(void***)(a2 + 22) = esi8;
        *(void***)(a2 + 8) = (void**)((uint8_t)*(void***)(a2 + 8) | 16);
    }
    return;
}

struct s314 {
    int8_t[9] pad9;
    uint8_t f9;
    int8_t[210] pad220;
    int8_t f220;
};

void fun_4067ee(int32_t a1, struct s314* a2, int32_t a3) {
    int32_t eax4;

    asm("fld qword [esp+0x10]");
    asm("fld qword [esp+0x18]");
    if (!a1 || !a2) {
        asm("fstp st0");
        asm("fstp st0");
        return;
    } else {
        asm("fxch st0, st1");
        eax4 = a3;
        a2->f220 = *(int8_t*)&eax4;
        a2->f9 = (uint8_t)(a2->f9 | 64);
        asm("fstp qword [edx+0xe0]");
        asm("fstp qword [edx+0xe8]");
        return;
    }
}

struct s315 {
    void** f0;
    int8_t[3] pad4;
    void** f4;
    void** f5;
    int8_t[4] pad10;
    void** f10;
    int8_t[4] pad15;
    void** f15;
};

void fun_406829(void** a1, int32_t a2, void** a3, void*** a4) {
    void** esi5;
    int32_t edi6;
    void*** ebx7;
    void*** ebp8;
    void** v9;
    void** v10;
    void** ebx11;
    void** esi12;
    void** edi13;
    void** ebp14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    int32_t v19;
    int32_t v20;
    int32_t v21;
    int32_t v22;
    int32_t v23;
    int16_t v24;
    void** eax25;
    void** v26;
    void** edx27;
    void** ebx28;
    void** v29;
    struct s315* edx30;
    void*** ecx31;
    uint32_t eax32;
    int32_t eax33;
    int32_t eax34;
    int32_t eax35;
    int32_t eax36;
    void** v37;
    void** v38;
    void** v39;
    void** v40;
    void** v41;
    void** v42;
    void** v43;

    esi5 = a1;
    edi6 = a2;
    if (!a4) {
        if ((uint32_t)(edi6 - 2) > 1) {
            *(uint8_t*)(esi5 + 0x6d) = (uint8_t)(*(uint8_t*)(esi5 + 0x6d) & 0x7f);
        } else {
            *(uint8_t*)(esi5 + 0x6d) = (uint8_t)(*(uint8_t*)(esi5 + 0x6d) | 0x80);
        }
        if (edi6 != 3) 
            goto 0x406864;
        *(uint8_t*)(esi5 + 0x6e) = (uint8_t)(*(uint8_t*)(esi5 + 0x6e) | 1);
        goto 0x406962;
    }
    if (!a3) 
        goto 0x406962;
    ebx7 = *(void****)(esi5 + 0x220);
    ebp8 = (void***)((int32_t)a4 + (int32_t)ebx7);
    eax25 = fun_402940(esi5, ebp8 + (int32_t)ebp8 * 4, v9, v10, ebx11, esi12, edi13, ebp14, v15, v16, v17, v18, esi5, ebp8 + (int32_t)ebp8 * 4, v19, v20, ebx11, esi12, edi13, ebp14, v21, v22, v23, v24);
    v26 = eax25;
    edx27 = *(void***)(esi5 + 0x224);
    if (edx27) 
        goto addr_0x4068a6_9;
    addr_0x4068d4_10:
    ebx28 = (void**)((uint8_t)v26 + (uint32_t)(ebx7 + (int32_t)ebx7 * 4));
    fun_417ac0(ebx28, a3, a4 + (int32_t)a4 * 4, v29, ebx11, esi12, edi13, ebp14);
    edx30 = (struct s315*)(ebx28 + 4);
    if ((int32_t)a4 <= 0) {
        addr_0x40694b_11:
        *(void****)(esi5 + 0x220) = ebp8;
        *(void***)(esi5 + 0x224) = v26;
        *(uint8_t*)(esi5 + 0x215) = (uint8_t)(*(uint8_t*)(esi5 + 0x215) | 4);
    } else {
        ecx31 = a4;
        eax32 = (uint32_t)-(int32_t)ecx31 & 3;
        if (!eax32) {
            do {
                addr_0x406934_13:
                eax33 = edi6;
                edx30->f0 = *(void***)&eax33;
                edx30->f5 = *(void***)&eax33;
                edx30->f10 = *(void***)&eax33;
                edx30->f15 = *(void***)&eax33;
                ecx31 = ecx31 - 4;
                edx30 = (struct s315*)((uint32_t)edx30 + 20);
            } while (ecx31);
            goto addr_0x40694b_11;
        } else {
            if ((int32_t)eax32 < (int32_t)3) {
                if ((int32_t)eax32 < (int32_t)2) {
                    eax34 = edi6;
                    *(void***)(ebx28 + 4) = *(void***)&eax34;
                    --ecx31;
                    edx30 = (struct s315*)(ebx28 + 9);
                }
                eax35 = edi6;
                edx30->f0 = *(void***)&eax35;
                --ecx31;
                edx30 = (struct s315*)&edx30->f5;
            }
            eax36 = edi6;
            edx30->f0 = *(void***)&eax36;
            edx30 = (struct s315*)&edx30->f5;
            --ecx31;
            if (!ecx31) 
                goto addr_0x40694b_11;
        }
    }
    goto addr_0x406934_13;
    addr_0x4068a6_9:
    fun_417ac0(v26, edx27, ebx7 + (int32_t)ebx7 * 4, v37, ebx11, esi12, edi13, ebp14);
    v38 = *(void***)(esi5 + 0x224);
    fun_4029a0(esi5, v38, v39, 0x4068b8, v26, edx27, ebx7 + (int32_t)ebx7 * 4, v40, ebx11, esi12, edi13, ebp14, v41, v42, v43);
    *(void***)(esi5 + 0x224) = (void**)0;
    goto addr_0x4068d4_10;
}

struct s316 {
    int8_t[188] pad188;
    void* f188;
    int32_t f192;
};

void fun_40696a(int32_t a1, struct s316* a2, int32_t a3, int32_t a4) {
    int32_t eax5;

    if (a1 && (a2 && (a3 >= 0 && a3 < a2->f192))) {
        eax5 = a4;
        *(int8_t*)((int32_t)a2->f188 + (a3 + a3 * 4) * 4 + 16) = *(int8_t*)&eax5;
    }
    return;
}

struct s317 {
    int8_t[8] pad8;
    uint32_t f8;
};

void fun_40699d(int32_t a1, struct s317* a2, int32_t a3) {
    if (a1 && a2) {
        a2->f8 = a2->f8 & (uint32_t)~a3;
    }
    return;
}

struct s318 {
    int8_t[560] pad560;
    uint32_t f560;
};

void fun_4069b9(struct s318* a1, uint32_t a2) {
    if (!a1) 
        goto 0x4069d4;
    a1->f560 = a2 & 5;
    return;
}

struct s319 {
    int8_t[576] pad576;
    uint32_t f576;
};

void fun_4069d8(struct s319* a1, uint32_t a2) {
    uint32_t ebx3;
    uint32_t ecx4;

    ebx3 = 0xfc;
    ecx4 = a1->f576;
    if ((ecx4 & 3) != 3) {
        ebx3 = 0;
        *(uint8_t*)&ecx4 = (uint8_t)(*(uint8_t*)&ecx4 & 3);
        a1->f576 = ecx4;
    }
    a1->f576 = ~ebx3 & a1->f576 | a2 & ebx3;
    return;
}

struct s320 {
    int8_t[68] pad68;
    int8_t f68;
};

struct s321 {
    int8_t[78] pad78;
    int32_t f78;
};

struct s322 {
    void* f0;
    int8_t[66] pad67;
    int8_t f67;
    int8_t[4] pad72;
    int8_t f72;
    uint8_t f73;
    int8_t[2] pad76;
    int8_t f76;
    int8_t[3] pad80;
    int8_t f80;
    int8_t[1] pad82;
    int8_t f82;
    int8_t[22] pad105;
    uint8_t f105;
    int8_t[570425238] pad570425344;
    int8_t f570425344;
    int8_t[1393355906] pad1426910339;
    int8_t f1426910339;
};

struct s323 {
    int8_t[69] pad69;
    int8_t f69;
};

struct s324 {
    int8_t[75] pad75;
    int8_t f75;
};

struct s325 {
    int8_t[75] pad75;
    int8_t f75;
};

struct s326 {
    int8_t f0;
    int8_t[64] pad65;
    int8_t f65;
};

struct s327 {
    int8_t[72] pad72;
    int8_t f72;
};

struct s328 {
    int8_t[72] pad72;
    int8_t f72;
};

struct s329 {
    int8_t f0;
    int8_t[96] pad97;
    uint8_t f97;
};

struct s330 {
    int8_t[67] pad67;
    uint8_t f67;
    int8_t[16] pad84;
    uint8_t f84;
};

struct s331 {
    int8_t[1] pad1;
    void* f1;
};

struct s332 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s333 {
    int8_t[84] pad84;
    int8_t f84;
    int8_t[1426063275] pad1426063360;
    uint8_t f1426063360;
};

void fun_406a35(int16_t cx) {
    struct s320* ecx1;
    uint8_t* esi2;
    uint32_t ebp3;
    uint32_t* eax4;
    uint32_t* eax5;
    uint32_t eax6;
    int8_t* eax7;
    int8_t* eax8;
    int8_t al9;
    int8_t* eax10;
    int8_t* eax11;
    int8_t al12;
    int8_t* eax13;
    int8_t* eax14;
    int8_t al15;
    int8_t* eax16;
    int8_t* eax17;
    int8_t al18;
    int8_t* eax19;
    int8_t* eax20;
    int8_t al21;
    int8_t* eax22;
    int8_t* eax23;
    int8_t al24;
    struct s321* eax25;
    int32_t edx26;
    struct s322* eax27;
    uint32_t eax28;
    struct s323* ecx29;
    int8_t dl30;
    struct s324* edx31;
    struct s325* edx32;
    struct s326* edi33;
    void* edi34;
    struct s327* ebx35;
    struct s328* ebx36;
    struct s329* ebp37;
    void* ebp38;
    struct s330* ecx39;
    uint64_t v40;
    struct s322* ebx41;
    struct s331* ebx42;
    struct s322* eax43;
    struct s332* esi44;
    int8_t dh45;
    int8_t dh46;
    int8_t dh47;
    int8_t dh48;
    struct s333* edx49;
    void* edx50;
    int1_t zf51;
    int8_t bh52;
    int8_t bh53;

    *(int16_t*)&ecx1 = cx;
    *esi2 = (uint8_t)(*esi2 ^ ebp3);
    *(uint8_t*)((int32_t)&ecx1 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&ecx1 + 1) ^ *esi2);
    *eax4 = *eax5 ^ eax6;
    *eax7 = (int8_t)(*eax8 + al9);
    *eax10 = (int8_t)(*eax11 + al12);
    *eax13 = (int8_t)(*eax14 + al15);
    *eax16 = (int8_t)(*eax17 + al18);
    *eax19 = (int8_t)(*eax20 + al21);
    *eax22 = (int8_t)(*eax23 + al24);
    eax25->f78 = edx26;
    eax27 = (struct s322*)((eax28 | 0x490a1a0a) - 1);
    ecx1->f68 = (int8_t)(ecx1->f68 + *(int8_t*)&ecx1);
    ecx29 = (struct s323*)((int32_t)ecx1 + 1);
    ecx29->f69 = (int8_t)(ecx29->f69 + *(int8_t*)&ecx29);
    *(int8_t*)((uint32_t)eax27 + 76) = (int8_t)(*(int8_t*)((uint32_t)eax27 + 76) + dl30);
    edx31->f75 = (int8_t)(edx32->f75 + *(int8_t*)((int32_t)&eax27 + 1));
    edi33 = (struct s326*)((int32_t)edi34 + 1 + 1);
    ebx35->f72 = (int8_t)(ebx36->f72 + *(int8_t*)((int32_t)&eax27 + 1));
    edi33->f65 = (int8_t)(edi33->f65 + *(int8_t*)((int32_t)&eax27 + 1));
    ebp37 = (struct s329*)((int32_t)ebp38 + 1 - 1 - 1);
    ecx39 = (struct s330*)((int32_t)ecx29 + 1);
    *(uint8_t*)((uint32_t)eax27 + 73) = (uint8_t)(*(uint8_t*)((uint32_t)eax27 + 73) + *(uint8_t*)((int32_t)&ecx39 + 1));
    *(void***)((int32_t)&v40 + 4) = (void**)((int32_t)__zero_stack_offset() + 1 - 4 - 4 + 1 - 4 + 1 - 4 - 4 - 4);
    ecx39->f67 = (uint8_t)(ecx39->f67 + *(uint8_t*)((int32_t)&ecx39 + 1));
    ebx41 = (struct s322*)&ebx42->f1;
    *(struct s322**)&v40 = eax27;
    ecx39->f84 = (uint8_t)(ecx39->f84 + *(uint8_t*)((int32_t)&ecx39 + 1));
    eax43 = *(struct s322**)&v40;
    asm("outsd");
    esi44 = (struct s332*)(esi2 - 1 + 1 + 1);
    if (__intrinsic()) {
        addr_0x406ad6_4:
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint32_t)eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
        *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
        goto addr_0x406ae4_5;
    } else {
        *(int8_t*)((uint32_t)ebx41 + 67) = (int8_t)(*(int8_t*)((uint32_t)ebx41 + 67) + dh45);
        *(int8_t*)((uint32_t)eax43 + 72) = (int8_t)(*(int8_t*)((uint32_t)eax43 + 72) + dh46);
        ecx39 = *(struct s330**)((int32_t)&v40 + 2);
        if (!__intrinsic()) {
            addr_0x406ae4_5:
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint32_t)eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
            goto addr_0x406aff_8;
        } else {
            ecx39 = (struct s330*)((int32_t)ecx39 - 1);
            *(int8_t*)((uint32_t)ebx41 + 80) = (int8_t)(*(int8_t*)((uint32_t)ebx41 + 80) + dh47);
            *(int8_t*)((uint32_t)ebx41 + 82) = (int8_t)(*(int8_t*)((uint32_t)ebx41 + 82) + dh48);
            edi33 = (struct s326*)&edi33->pad65;
            edx49 = (struct s333*)((int32_t)edx50 + 1);
            *(uint8_t*)((int32_t)ebp37 + (uint32_t)eax43 * 2 + 88) = (uint8_t)(*(int8_t*)((int32_t)ebp37 + (uint32_t)eax43 * 2 + 88) + (uint8_t)*(void**)((int32_t)&edx49 + 1));
            zf51 = *(int8_t*)((int32_t)ebp37 + (uint32_t)eax43 * 2 + 88) == 0;
            if (zf51) {
                addr_0x406aff_8:
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint32_t)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 | (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint32_t)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint32_t)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (int8_t)*(void**)&ecx39);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(int8_t*)((uint32_t)eax43 + 0x22000000) = (int8_t)(*(int8_t*)((uint32_t)eax43 + 0x22000000) + (int8_t)*(void**)&ecx39);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(uint8_t*)((int32_t)edx49 + 0x55000000) = (uint8_t)(*(uint8_t*)((int32_t)edx49 + 0x55000000) + *(uint8_t*)((int32_t)&ecx39 + 1));
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                bh52 = (int8_t)(*(int8_t*)((int32_t)&ebx41 + 1) + *(int8_t*)((int32_t)&ebx41 + 1));
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                bh53 = (int8_t)(bh52 + bh52);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                edi33->f0 = (int8_t)(edi33->f0 + (int8_t)*(void**)&ecx39);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(int8_t*)((int32_t)&ebx41 + 1) = (int8_t)(bh53 + bh53);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)ebx41 = (void*)((uint8_t)*(void**)ebx41 + (uint8_t)*(void**)((int32_t)&edx49 + 1));
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(int8_t*)((int32_t)&ebx41 + 1) = (int8_t)(*(int8_t*)((int32_t)&ebx41 + 1) + *(int8_t*)((int32_t)&ebx41 + 1));
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                ebp37->f0 = (int8_t)(ebp37->f0 + *(int8_t*)&edx49);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + 1);
                *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
                asm("outsd");
                asm("outsd");
                ebp37->f97 = 0;
                asm("outsb");
                if (!__intrinsic()) {
                    addr_0x406bc9_11:
                    goto addr_0x406bcf_12;
                } else {
                    if (1) {
                        addr_0x406bcf_12:
                        goto addr_0x406bd3_14;
                    } else {
                        asm("outsw");
                        if (0) {
                            addr_0x406bd3_14:
                            asm("outsb");
                            asm("outsb");
                            esi44->f114 = 0;
                            if (0) 
                                goto 0x406c0e;
                        } else {
                            esi44 = (struct s332*)((int32_t)esi44 - 1);
                            *(uint8_t*)((uint32_t)ebx41 + 0x69) = 0;
                            asm("a16 outsb");
                            asm("popad");
                            if (!*(uint8_t*)((uint32_t)ebx41 + 0x69)) 
                                goto 0x406c33;
                            if (0) 
                                goto addr_0x406c25_18; else 
                                goto addr_0x406bc0_19;
                        }
                    }
                }
            } else {
                ebp37 = (struct s329*)((int32_t)ebp37 - 1 + 1);
                *(uint8_t*)((int32_t)edx49 + (int32_t)edx49 * 2 + 78) = (uint8_t)(*(int8_t*)((int32_t)edx49 + (int32_t)edx49 * 2 + 78) + (uint8_t)*(void**)((int32_t)&edx49 + 1));
                *(int8_t*)((int32_t)edx49 + 84) = (int8_t)(*(int8_t*)((int32_t)edx49 + 84) + *(int8_t*)((int32_t)&ebx41 + 1));
                eax43 = ebx41;
                if (!*(int8_t*)((int32_t)edx49 + 84)) 
                    goto addr_0x406ac3_21; else 
                    goto addr_0x406ac3_21;
            }
        }
    }
    if (0) 
        goto 0x406c51;
    if (0) 
        goto 0x406c53;
    asm("insd");
    if (!esi44->f114) 
        goto 0x406c5b;
    if (0) 
        goto 0x406c18;
    asm("popad");
    if (__undefined()) 
        goto 0x406c64;
    if (__intrinsic()) 
        goto 0x406c6c;
    if (__intrinsic()) 
        goto 0x406c38;
    *(int8_t*)((uint32_t)eax43 + 0x550cec83) = (int8_t)(*(int8_t*)((uint32_t)eax43 + 0x550cec83) + *(int8_t*)&edx49);
    addr_0x406c25_18:
    addr_0x406bc0_19:
    *(int8_t*)((uint32_t)eax43 - 0x6f6f6f70) = (int8_t)(*(int8_t*)((uint32_t)eax43 - 0x6f6f6f70) + *(int8_t*)&edx49);
    goto addr_0x406bc9_11;
    addr_0x406ac3_21:
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)&eax43 = (void*)static_cast<uint32_t>((uint8_t)*(void**)&eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)&eax43 = (void*)((uint8_t)*(void**)&eax43 + (uint8_t)*(void**)eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    *(void**)eax43 = (void*)((uint8_t)*(void**)eax43 + (uint8_t)*(void**)&eax43);
    goto addr_0x406ad6_4;
}

void fun_406c72() {
}

struct s335 {
    uint8_t f0;
    int8_t[109] pad110;
    uint8_t f110;
    int8_t[6] pad117;
    int8_t f117;
};

struct s334 {
    void** f0;
    int8_t[23] pad24;
    int8_t f24;
    int8_t[3] pad28;
    int32_t f28;
    int8_t[24] pad56;
    struct s335* f56;
};

struct s336 {
    uint8_t f0;
    int8_t[96] pad97;
    uint8_t f97;
    int8_t[14] pad112;
    int32_t f112;
    int8_t[1] pad117;
    int8_t f117;
};

struct s337 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s338 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s339 {
    int8_t[1] pad1;
    void** f1;
};

struct s340 {
    int8_t[101] pad101;
    int32_t f101;
    int8_t[3] pad108;
    uint8_t f108;
    int8_t[1] pad110;
    int32_t f110;
    uint8_t f114;
    int8_t[2] pad117;
    uint8_t f117;
};

struct s341 {
    int32_t f0;
    void** f4;
    int8_t[7] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
};

struct s342 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s343 {
    int8_t f0;
    int8_t[3] pad4;
    int8_t f4;
};

uint8_t g30252064;

void fun_407020(struct s159* ecx) {
    struct s334* esp2;
    struct s336* edx3;
    void* edx4;
    struct s337* esi5;
    struct s338* esi6;
    int8_t al7;
    int32_t ebp8;
    int32_t ebp9;
    struct s335* ecx10;
    uint8_t* eax11;
    void** ebx12;
    struct s339* ebx13;
    int1_t zf14;
    int1_t of15;
    struct s340* edi16;
    uint1_t zf17;
    int32_t* esp18;
    void*** esp19;
    void** esi20;
    struct s341* esp21;
    int1_t cf22;
    struct s340** esp23;
    int8_t al24;
    int16_t di25;
    int16_t di26;
    void** eax27;
    struct s343* eax28;
    void* edi29;
    uint32_t eax30;
    void* esi31;

    esp2 = (struct s334*)__zero_stack_offset();
    edx3 = (struct s336*)((int32_t)edx4 - 1);
    asm("popad");
    asm("outsb");
    esi5->f101 = (int8_t)(esi6->f101 + al7);
    ebp8 = ebp9 - 1;
    asm("popad");
    ecx10 = (struct s335*)&ecx->f1;
    if (__intrinsic()) {
        addr_0x4070a1_3:
        ecx10->f0 = 0;
        *(uint8_t*)((int32_t)&ecx10 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&ecx10 + 1) ^ *eax11);
        goto addr_0x4070a5_4;
    } else {
        *(int8_t*)(ebp8 + 97) = (int8_t)(*(int8_t*)(ebp8 + 97) + *(int8_t*)&ecx10);
        edx3 = (struct s336*)((int32_t)edx3 - 1);
        if (edx3) {
            addr_0x4070a5_4:
            *(uint8_t*)((int32_t)&edx3 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&edx3 + 1) ^ *eax11);
            ecx10->f0 = (uint8_t)(ecx10->f0 ^ *(uint8_t*)((int32_t)&edx3 + 1));
            *(uint8_t*)((int32_t)&eax11 + 1) = 0xff;
            *eax11 = (uint8_t)(*eax11 & 0xff);
            ebx12 = (void**)&ebx13->f1;
            zf14 = ebx12 == 0;
            of15 = __intrinsic();
            asm("outsd");
            if (of15) {
                addr_0x40712b_7:
                esp2 = (struct s334*)((uint32_t)esp2 - 4);
                esp2->f0 = ebx12;
                asm("arpl [eax+0x61], bp");
                asm("insb");
                asm("outsb");
                asm("popad");
                if (zf14) {
                    addr_0x407161_8:
                    goto addr_0x407162_9;
                } else {
                    edi16->f114 = (uint8_t)(edi16->f114 & *(uint8_t*)&eax11);
                    zf17 = (uint1_t)(edi16->f114 == 0);
                    asm("outsd");
                    if (!zf17) {
                        if (!((uint1_t)__intrinsic() | zf17)) {
                            esp18 = (int32_t*)((uint32_t)esp2 + 0xfffffff8 - 4);
                            *esp18 = (int32_t)"Too many bytes for PNG signature.";
                            esp19 = (void***)(esp18 - 1);
                            *esp19 = esi20;
                            esp21 = (struct s341*)(esp19 - 4);
                            esp21->f0 = 0x4071bc;
                            fun_408404(esp21->f4, 0x406ba0, esp21->f12, esp21->f16, esp21->f20, esp21->f24);
                            esp2 = (struct s334*)&esp21->f4;
                            goto addr_0x4071bb_13;
                        }
                    } else {
                        *(uint8_t*)((int32_t)edx3 + (uint8_t)esi20) = 0;
                        *(uint8_t*)&eax11 = (uint8_t)(*(uint8_t*)&eax11 - 32);
                        ecx10 = (struct s335*)((uint32_t)ecx10 - 1);
                        asm("outsb");
                        asm("arpl [esi], bp");
                        *(uint8_t*)&eax11 = (uint8_t)(*(uint8_t*)&eax11 | *eax11);
                        goto addr_0x407146_15;
                    }
                }
            } else {
                if (0) {
                    addr_0x40711d_17:
                    goto addr_0x407120_18;
                } else {
                    esp2 = (struct s334*)((uint32_t)esp2 - 4);
                    esp2->f0 = (void**)0x63282074;
                    *eax11 = (uint8_t)(*eax11 - (uint32_t)esp2);
                    ecx10->f0 = (uint8_t)(ecx10->f0 ^ (uint32_t)edi16);
                    eax11 = eax11 - 0x31303032;
                    edi16->f108 = (uint8_t)(edi16->f108 & *(uint8_t*)&eax11);
                    asm("outsb");
                    asm("outsb");
                    edx3->f97 = (uint8_t)(edx3->f97 & *(uint8_t*)&edx3);
                    asm("outsb");
                    if (0) {
                        addr_0x407146_15:
                        ecx10->f0 = (uint8_t)(ecx10->f0 + *(uint8_t*)((int32_t)&edx3 + 1));
                        goto addr_0x407147_20;
                    } else {
                        cf22 = (uint32_t)eax11 < 0x72686550;
                        eax11 = eax11 - 0x72686550;
                        if (!cf22) {
                            addr_0x407149_22:
                            *eax11 = (uint8_t)(*eax11 ^ (uint32_t)eax11);
                            goto addr_0x40714e_23;
                        } else {
                            asm("outsb");
                            *(uint8_t*)((int32_t)&eax11 + 1) = 0xff;
                            *eax11 = (uint8_t)(*eax11 & 0xff);
                            ++ebx12;
                            asm("outsd");
                            if (__intrinsic()) {
                                addr_0x40715c_25:
                                *(uint8_t*)((uint32_t)ecx10 + ebp8 * 2 + 98) = 0;
                                of15 = 0;
                                goto addr_0x407161_8;
                            } else {
                                if (0) {
                                    addr_0x40714e_23:
                                    goto addr_0x40715c_25;
                                } else {
                                    esp2 = (struct s334*)((uint32_t)esp2 - 4);
                                    esp2->f0 = (void**)0x63282074;
                                    *eax11 = (uint8_t)(*eax11 - (uint32_t)esp2);
                                    ecx10->f0 = (uint8_t)(ecx10->f0 ^ (uint32_t)edi16);
                                    *(uint8_t*)&eax11 = (uint8_t)(*(uint8_t*)&eax11 - 32);
                                    ecx10->f0 = (uint8_t)(ecx10->f0 ^ (uint32_t)edi16);
                                    ecx10->f110 = (uint8_t)(ecx10->f110 & *(uint8_t*)&eax11);
                                    of15 = 0;
                                    if (0) {
                                        addr_0x407162_9:
                                        if (of15) {
                                            esp23 = (struct s340**)((uint32_t)esp2 - 36 - 4);
                                            *esp23 = edi16;
                                            esp2 = (struct s334*)(esp23 - 1);
                                            esp2->f0 = esi20;
                                            ecx10 = esp2->f56;
                                            goto addr_0x4071df_29;
                                        }
                                    } else {
                                        asm("popad");
                                        if (1) {
                                            addr_0x407120_18:
                                            edi16->f117 = (uint8_t)(edi16->f117 & *(uint8_t*)&eax11);
                                            if (!__intrinsic()) {
                                                addr_0x407147_20:
                                                *(uint8_t*)((int32_t)&ecx10 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&ecx10 + 1) ^ (uint8_t)*(void***)esi20);
                                                goto addr_0x407149_22;
                                            } else {
                                                ++ebp8;
                                                zf14 = ebp8 == 0;
                                                of15 = __intrinsic();
                                                if (0) {
                                                    addr_0x407193_32:
                                                    goto 0x65646165;
                                                } else {
                                                    asm("arpl [eax], sp");
                                                    goto addr_0x40712b_7;
                                                }
                                            }
                                        } else {
                                            addr_0x407100_34:
                                            esp2 = (struct s334*)&esp2->pad24;
                                            ebp8 = edi16->f101 * 0x20200a72;
                                            *(uint8_t*)(ebx12 + 0x6f) = (uint8_t)(*(uint8_t*)(ebx12 + 0x6f) & *(uint8_t*)&eax11);
                                            if (0) {
                                                addr_0x407187_35:
                                                ecx10->f0 = (uint8_t)(ecx10->f0 ^ *(uint8_t*)((int32_t)&edx3 + 1));
                                                *eax11 = 0;
                                                esp2 = (struct s334*)((uint32_t)esp2 - 4);
                                                esp2->f0 = (void**)0x65646165;
                                                if (0) {
                                                    addr_0x4071bb_13:
                                                    esp2 = (struct s334*)((uint32_t)esp2 + 16);
                                                } else {
                                                    goto addr_0x407193_32;
                                                }
                                            } else {
                                                if (0) {
                                                    addr_0x407179_38:
                                                    asm("insd");
                                                    ecx10->f0 = 0;
                                                    *(uint8_t*)((int32_t)&ecx10 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&ecx10 + 1) ^ *eax11);
                                                    *(uint8_t*)((int32_t)&edx3 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&edx3 + 1) ^ *eax11);
                                                    goto addr_0x407187_35;
                                                } else {
                                                    esp2 = (struct s334*)((uint32_t)esp2 - 4);
                                                    esp2->f0 = (void**)0x63282074;
                                                    *eax11 = (uint8_t)(*eax11 - (uint32_t)esp2);
                                                    ecx10->f0 = (uint8_t)(ecx10->f0 ^ (uint32_t)edi16);
                                                    goto addr_0x40711d_17;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            edx3->f117 = (int8_t)(edx3->f117 + *(int8_t*)&ecx10);
            asm("insb");
            ecx10->f117 = (int8_t)(ecx10->f117 + al24);
            *(uint8_t*)((int16_t)((int16_t)*(struct s342**)&ebp8 + di25) + 0x65) = (uint8_t)(*(int8_t*)((int16_t)((int16_t)*(struct s342**)&ebp8 + di26) + 0x65) + *(uint8_t*)&edx3);
            if (__intrinsic()) 
                goto addr_0x407044_41; else 
                goto addr_0x407044_41;
        }
    }
    eax27 = ebx12;
    if ((int8_t)eax27 < (int8_t)0) {
        eax27 = (void**)0;
    }
    *(uint8_t*)(esi20 + 0x12c) = *(uint8_t*)&eax27;
    goto *(int32_t*)((uint32_t)esp2 + 4 + 4 + 20);
    *(uint8_t*)&(*(struct s342**)&ebp8)->f101 = 0;
    if (0) {
        addr_0x4071df_29:
        esp2->f24 = (int8_t)0;
        esp2->f28 = 0;
        esp2->f24 = 0x89;
        esp2->f24 = (int8_t)0x474e5089;
        eax28 = (struct s343*)&esp2->f24;
        eax28->f4 = 13;
        eax28->f4 = (int8_t)0xa1a0a0d;
        if ((uint32_t)ecx10 > 8) 
            goto 0x407234;
    } else {
        *eax11 = (uint8_t)(*eax11 ^ (uint32_t)esp2);
        eax11 = eax11 - 0x63654420;
        goto addr_0x407179_38;
    }
    if (ecx10) 
        goto 0x407239; else 
        goto "???";
    addr_0x407044_41:
    edi16 = (struct s340*)((int32_t)edi29 - 1);
    asm("arpl [eax+eax+0x4e], si");
    asm("outsd");
    asm("arpl [gs:eax], ax");
    eax11 = (uint8_t*)(eax30 & 0x73252064);
    g30252064 = 0;
    *(uint8_t*)((int32_t)&eax11 + 1) = (uint8_t)(*(uint8_t*)((int32_t)&eax11 + 1) ^ *(uint8_t*)((int32_t)edx3 + (uint32_t)edi16 + 37));
    edx3->f0 = (uint8_t)(edx3->f0 ^ *(uint8_t*)((int32_t)&edx3 + 1));
    esi20 = (void**)((int32_t)esi31 - *eax11);
    *eax11 = (uint8_t)(*eax11 ^ *(uint8_t*)((int32_t)&edx3 + 1));
    *eax11 = (uint8_t)(*eax11 ^ *(uint8_t*)&eax11);
    *(uint8_t*)((int32_t)&eax11 + 1) = 0xff;
    asm("insb");
    esp2 = (struct s334*)(edx3->f112 * 0x7620676e);
    if (__intrinsic()) 
        goto addr_0x407100_34;
    ebp8 = edi16->f110 * 0x322e3120;
    *eax11 = (uint8_t)(*eax11 ^ (uint32_t)esp2);
    eax11 = eax11 - 0x63654420;
    asm("insd");
    goto addr_0x4070a1_3;
}

void fun_40719a(int32_t a1, int32_t a2) {
}

void fun_407266(int32_t a1, uint32_t a2) {
    if (a2 > 8) 
        goto 0x4072c8;
    if (a2) 
        goto 0x4072cd;
    goto 0x4072e2;
}

void fun_4155e0(int32_t a1);

void fun_4072f2(int32_t a1) {
    fun_4155e0(a1 + 0x74);
    return;
}

void fun_40735e() {
    void** v1;

    fun_40737c((int32_t)__zero_stack_offset() - 4 + 8, 0, v1);
    return;
}

void fun_4074d5() {
}

int32_t fun_40753e() {
    return "\n libpng version 1.2.1 - December 12, 2001\n   Copyright (c) 1998-2001 Glenn Randers-Pehrson\n   Copyright (c) 1996, 1997 Andreas Dilger\n   Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.\n";
}

int32_t fun_40755e(int32_t a1) {
    if (a1) 
        goto 0x407570;
    return " libpng version 1.2.1 - December 12, 2001 (header)\n";
}

int32_t fun_407576(int32_t a1) {
    if (a1) 
        goto 0x407588;
    return "1.2.1";
}

void fun_40758e() {
}

void** fun_407654(void** a1, void** a2, void** a3, void** a4, void** a5, void** a6, void** a7) {
    void** v8;
    void** v9;
    void** v10;
    void** v11;
    void** v12;
    void** eax13;

    eax13 = fun_4029a0(__return_address(), a1, v8, v9, v10, v11, v12, __return_address(), a1, a2, a3, a4, a5, a6, a7);
    return eax13;
}

void fun_407729() {
}

void fun_407859() {
}

void fun_407f80(uint8_t* ecx) {
    uint8_t dh2;

    *ecx = (uint8_t)(*ecx ^ dh2);
    asm("aaa");
}

void fun_40818d() {
}

struct s344 {
    int8_t[112] pad112;
    int32_t f112;
};

uint8_t g25203a73;

struct s345 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s346 {
    int8_t[114] pad114;
    uint8_t f114;
};

uint8_t g6c000a73;

struct s347 {
    int8_t[103] pad103;
    int32_t f103;
};

struct s348 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s349 {
    int8_t[97] pad97;
    uint8_t f97;
};

uint8_t g6f202c73;

void fun_408368(void* ecx) {
    int32_t* esp2;
    struct s344* edx3;
    int1_t zf4;
    uint8_t ah5;
    int32_t ebp6;
    int32_t ebp7;
    struct s345* di8;
    struct s346* di9;
    uint8_t ah10;
    int32_t ebp11;
    struct s347* esi12;
    struct s348* bx13;
    struct s349* bx14;
    uint8_t dh15;
    uint8_t ah16;

    asm("insb");
    esp2 = (int32_t*)(edx3->f112 * 0x6520676e);
    zf4 = __undefined();
    if (__intrinsic()) 
        goto 0x4083e4;
    asm("outsd");
    if (!__intrinsic()) {
        asm("outsb");
        asm("outsd");
        g25203a73 = (uint8_t)(g25203a73 & ah5);
        if (!1) {
            *(int8_t*)((int32_t)ecx + ebp6 * 2 + 98) = (int8_t)(*(int8_t*)((int32_t)ecx + ebp7 * 2 + 98) + *(int8_t*)((int32_t)&ecx + 1));
            if (__intrinsic()) 
                goto 0x4083f4;
            *(uint8_t*)&di8->f114 = (uint8_t)(*(uint8_t*)&di9->f114 & ah10);
        }
        if (0) 
            goto 0x4083fb;
        if (0) 
            goto addr_0x4083c8_9; else 
            goto addr_0x40838e_10;
    }
    if (zf4) {
        addr_0x4083d7_12:
    } else {
        if (__intrinsic()) 
            goto 0x40841a;
        asm("outsd");
        if (__intrinsic()) 
            goto 0x4083e5;
        g6c000a73 = 0;
        asm("popad");
        if (!__intrinsic()) 
            goto addr_0x4083bb_16;
    }
    addr_0x4083bb_16:
    ebp11 = esi12->f103 * 0x2e6f6e20;
    g25203a73 = 0;
    addr_0x4083c8_9:
    if (!1) {
        *(int8_t*)((int32_t)ecx + ebp11 * 2 + 98) = (int8_t)(*(int8_t*)((int32_t)ecx + ebp11 * 2 + 98) + *(int8_t*)((int32_t)&ecx + 1));
        if (__intrinsic()) 
            goto 0x40843e;
        *(uint8_t*)&bx13->f97 = (uint8_t)(*(uint8_t*)&bx14->f97 & dh15);
    }
    if (0) 
        goto 0x408444;
    goto addr_0x4083d7_12;
    addr_0x40838e_10:
    g6f202c73 = (uint8_t)(g6f202c73 & ah16);
    zf4 = g6f202c73 == 0;
    if (1) {
        goto *esp2;
    }
}

struct s350 {
    int8_t[108] pad108;
    uint32_t f108;
};

void fun_408560(struct s350* a1, uint32_t a2) {
    if (a1) {
        a1->f108 = a1->f108 & 0xfff3ffff & a2;
    }
    return;
}

void fun_4085cd() {
}

struct s351 {
    uint32_t f0;
    uint32_t f4;
    int8_t[1] pad9;
    int8_t f9;
    int8_t f10;
    int8_t f11;
};

struct s352 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
    int8_t f4;
    int8_t f5;
    int8_t f6;
    int8_t[1] pad8;
    int8_t f8;
    int8_t f9;
    int8_t f10;
    int8_t f11;
    int8_t f12;
    int8_t f13;
    int8_t f14;
};

struct s353 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
    int8_t f4;
    int8_t f5;
    int8_t f6;
    int8_t f7;
    int8_t f8;
    int8_t f9;
    int8_t f10;
    int8_t f11;
};

struct s354 {
    int8_t f0;
    int8_t f1;
    int8_t[1] pad3;
    int8_t f3;
};

struct s355 {
    int8_t f0;
    int8_t f1;
};

struct s356 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
};

struct s357 {
    int8_t f0;
    int8_t f1;
};

struct s358 {
    int8_t f0;
    int8_t f1;
};

struct s359 {
    int8_t f0;
    int8_t f1;
};

struct s360 {
    int8_t f0;
    int8_t f1;
};

struct s361 {
    int8_t f0;
    int8_t f1;
};

struct s362 {
    int8_t f0;
    int8_t[2] pad3;
    int8_t f3;
};

struct s363 {
    int8_t f0;
    int8_t f1;
};

void fun_408670(struct s351* a1, int8_t* a2, int32_t a3) {
    struct s351* ebp4;
    int32_t ebx5;
    int8_t* edx6;
    int8_t* ecx7;
    uint32_t esi8;
    struct s352* ecx9;
    struct s353* edx10;
    uint32_t ebx11;
    uint32_t v12;
    struct s354* ecx13;
    struct s355* edx14;
    struct s356* ecx15;
    struct s357* edx16;
    struct s358* ecx17;
    struct s359* edx18;
    struct s360* ecx19;
    struct s361* edx20;
    struct s362* ecx21;
    struct s363* edx22;
    uint32_t ebx23;
    uint32_t ebx24;
    uint32_t v25;
    uint32_t eax26;
    int8_t* edx27;
    struct s352* ecx28;
    uint32_t ebx29;
    uint32_t eax30;
    uint32_t ebx31;
    uint32_t v32;
    uint32_t eax33;
    struct s352* ecx34;
    int8_t* edx35;
    uint32_t ebx36;
    uint32_t eax37;
    int8_t* ecx38;
    int8_t* ecx39;
    int8_t* edx40;
    int8_t* ecx41;
    int8_t* edx42;
    int8_t* ecx43;
    int8_t* ecx44;
    int8_t* edx45;
    struct s354* ecx46;
    int8_t* edx47;
    struct s354* ecx48;
    int8_t* edx49;
    struct s354* ecx50;
    int8_t* edx51;
    uint32_t ebx52;
    uint32_t eax53;
    int8_t* ecx54;
    int8_t* edx55;
    int8_t* ecx56;
    int8_t* edx57;
    int8_t* ecx58;
    int8_t* edx59;
    int8_t* ecx60;
    int8_t* edx61;
    int8_t* ecx62;
    int8_t* edx63;
    uint32_t eax64;
    int8_t* ecx65;
    int8_t* ecx66;
    int8_t* edx67;
    int8_t* ecx68;
    int8_t* edx69;
    int8_t* ecx70;
    int8_t* edx71;
    int8_t* ecx72;
    int8_t* edx73;
    int8_t* ecx74;
    int8_t* ecx75;
    int8_t* edx76;
    int8_t* ecx77;
    int8_t* edx78;
    struct s354* ecx79;
    int8_t* edx80;
    struct s356* ecx81;
    int8_t* edx82;
    int8_t* edx83;
    int8_t* edx84;
    struct s354* ecx85;
    int8_t* edx86;
    struct s356* ecx87;
    int8_t* edx88;

    ebp4 = a1;
    ebx5 = a3;
    edx6 = a2;
    ecx7 = edx6;
    esi8 = ebp4->f0;
    if (ebp4->f10 != 4) {
        if (ebp4->f10 != 2) 
            goto 0x408c13;
        if (ebp4->f9 == 8) 
            goto addr_0x4089da_4;
    } else {
        if (ebp4->f9 != 8) {
            if (*(int8_t*)&ebx5 < 0) {
                ecx9 = (struct s352*)(edx6 + 8);
                edx10 = (struct s353*)(edx6 + 6);
                ebx11 = 1;
                v12 = esi8 + esi8;
                if (1 < esi8 && ((int32_t)esi8 > (int32_t)1 && !(esi8 + 0xffffffff & 1) || (edx10->f0 = ecx9->f0, ecx13 = (struct s354*)&ecx9->f1, edx14 = (struct s355*)&edx10->f1, edx14->f0 = ecx13->f0, ecx15 = (struct s356*)&ecx13->f1, edx16 = (struct s357*)&edx14->f1, edx16->f0 = ecx15->f0, ecx17 = (struct s358*)&ecx15->f1, edx18 = (struct s359*)&edx16->f1, edx18->f0 = ecx17->f0, ecx19 = (struct s360*)&ecx17->f1, edx20 = (struct s361*)&edx18->f1, edx20->f0 = ecx19->f0, ecx21 = (struct s362*)&ecx19->f1, edx22 = (struct s363*)&edx20->f1, edx22->f0 = ecx21->f0, edx10 = (struct s353*)&edx22->f1, ecx9 = (struct s352*)&ecx21->f3, ebx11 = 2, 2 < esi8))) {
                    do {
                        edx10->f0 = ecx9->f0;
                        edx10->f1 = ecx9->f1;
                        edx10->f2 = ecx9->f2;
                        edx10->f3 = ecx9->f3;
                        edx10->f4 = ecx9->f4;
                        edx10->f5 = ecx9->f5;
                        edx10->f6 = ecx9->f8;
                        edx10->f7 = ecx9->f9;
                        edx10->f8 = ecx9->f10;
                        edx10->f9 = ecx9->f11;
                        edx10->f10 = ecx9->f12;
                        edx10->f11 = ecx9->f13;
                        ++edx10;
                        ecx9 = (struct s352*)((int32_t)ecx9 + 16);
                        ebx11 = ebx11 + 2;
                    } while (ebx11 < esi8);
                    goto addr_0x4089b0_10;
                }
            }
            ebx23 = 0;
            v12 = esi8 + esi8;
            if (0 >= esi8) 
                goto addr_0x4089b0_10;
            if ((uint1_t)((int32_t)esi8 < (int32_t)0) | (uint1_t)(esi8 == 0)) 
                goto addr_0x40892a_13;
            if (!(esi8 & 1)) 
                goto addr_0x40895c_15; else 
                goto addr_0x40892a_13;
        } else {
            if (*(int8_t*)&ebx5 >= 0) {
                ebx24 = 0;
                v25 = esi8 + esi8;
                if (0 >= esi8) 
                    goto addr_0x408840_18;
                eax26 = esi8 & 3;
                if ((uint1_t)((int32_t)esi8 < (int32_t)0) | (uint1_t)(esi8 == 0)) 
                    goto addr_0x4087d2_20; else 
                    goto addr_0x40879a_21;
            } else {
                edx27 = edx6 + 3;
                ecx28 = (struct s352*)(a2 + 4);
                ebx29 = 1;
                v25 = esi8 + esi8;
                if (1 >= esi8) 
                    goto addr_0x408840_18;
                eax30 = esi8 + 0xffffffff & 3;
                if ((int32_t)esi8 <= (int32_t)1) 
                    goto addr_0x408709_24; else 
                    goto addr_0x4086cc_25;
            }
        }
    }
    if (*(int8_t*)&ebx5 >= 0) {
        ebx31 = 0;
        v32 = esi8 + esi8;
        if (0 >= esi8) 
            goto addr_0x408c00_28;
        eax33 = esi8 & 3;
        if (!((uint1_t)((int32_t)esi8 < (int32_t)0) | (uint1_t)(esi8 == 0))) 
            goto addr_0x408b82_30;
    } else {
        ecx34 = (struct s352*)(edx6 + 4);
        edx35 = edx6 + 2;
        ebx36 = 1;
        v32 = esi8 + esi8;
        if (1 >= esi8) 
            goto addr_0x408c00_28;
        eax37 = esi8 + 0xffffffff & 3;
        if ((int32_t)esi8 <= (int32_t)1) 
            goto addr_0x408b11_33; else 
            goto addr_0x408ae1_34;
    }
    addr_0x408bb0_35:
    ecx38 = ecx7 + 2;
    *edx6 = *ecx38;
    ecx39 = ecx38 + 1;
    edx40 = edx6 + 1;
    *edx40 = *ecx39;
    ecx7 = ecx39 + 1;
    edx6 = edx40 + 1;
    ++ebx31;
    if (ebx31 >= esi8) {
        addr_0x408c00_28:
        ebp4->f11 = 16;
        ebp4->f4 = v32;
    } else {
        do {
            addr_0x408bc4_36:
            *edx6 = ecx7[2];
            edx6[1] = ecx7[3];
            edx6[2] = ecx7[6];
            edx6[3] = ecx7[7];
            edx6[4] = ecx7[10];
            edx6[5] = ecx7[11];
            edx6[6] = ecx7[14];
            edx6[7] = ecx7[15];
            ecx7 = ecx7 + 16;
            edx6 = edx6 + 8;
            ebx31 = ebx31 + 4;
        } while (ebx31 < esi8);
        goto addr_0x408c00_28;
    }
    addr_0x408b82_30:
    if (!eax33) 
        goto addr_0x408bc4_36;
    if ((int32_t)eax33 > (int32_t)1) {
        if ((int32_t)eax33 > (int32_t)2) {
            *edx6 = edx6[2];
            ecx41 = edx6 + 3;
            edx42 = edx6 + 1;
            *edx42 = *ecx41;
            ecx7 = ecx41 + 1;
            edx6 = edx42 + 1;
            ebx31 = 1;
        }
        ecx43 = ecx7 + 2;
        *edx6 = *ecx43;
        ecx44 = ecx43 + 1;
        edx45 = edx6 + 1;
        *edx45 = *ecx44;
        ecx7 = ecx44 + 1;
        edx6 = edx45 + 1;
        ++ebx31;
        goto addr_0x408bb0_35;
    }
    addr_0x408b11_33:
    *edx35 = ecx34->f0;
    ecx46 = (struct s354*)&ecx34->f1;
    edx47 = edx35 + 1;
    *edx47 = ecx46->f0;
    edx35 = edx47 + 1;
    ecx34 = (struct s352*)&ecx46->f3;
    ++ebx36;
    if (ebx36 >= esi8) 
        goto addr_0x408c00_28; else 
        goto addr_0x408b28_41;
    addr_0x408ae1_34:
    if (!eax37) {
        do {
            addr_0x408b28_41:
            *edx35 = ecx34->f0;
            edx35[1] = ecx34->f1;
            edx35[2] = ecx34->f4;
            edx35[3] = ecx34->f5;
            edx35[4] = ecx34->f8;
            edx35[5] = ecx34->f9;
            edx35[6] = ecx34->f12;
            edx35[7] = ecx34->f13;
            edx35 = edx35 + 8;
            ecx34 = (struct s352*)((int32_t)ecx34 + 16);
            ebx36 = ebx36 + 4;
        } while (ebx36 < esi8);
    } else {
        if ((int32_t)eax37 > (int32_t)1) {
            if ((int32_t)eax37 > (int32_t)2) {
                *edx35 = ecx34->f0;
                ecx48 = (struct s354*)&ecx34->f1;
                edx49 = edx35 + 1;
                *edx49 = ecx48->f0;
                edx35 = edx49 + 1;
                ecx34 = (struct s352*)&ecx48->f3;
                ebx36 = 2;
            }
            *edx35 = ecx34->f0;
            ecx50 = (struct s354*)&ecx34->f1;
            edx51 = edx35 + 1;
            *edx51 = ecx50->f0;
            edx35 = edx51 + 1;
            ecx34 = (struct s352*)&ecx50->f3;
            ++ebx36;
            goto addr_0x408b11_33;
        }
    }
    goto addr_0x408c00_28;
    addr_0x4089da_4:
    if (*(int8_t*)&ebx5 >= 0) 
        goto 0x408a48;
    ebx52 = 0;
    if (0 >= esi8) 
        goto 0x408aa8;
    eax53 = esi8 & 3;
    if (!((uint1_t)((int32_t)esi8 < (int32_t)0) | (uint1_t)(esi8 == 0))) 
        goto addr_0x4089f1_49;
    addr_0x408a0d_50:
    *edx6 = *ecx7;
    ++edx6;
    ecx7 = ecx7 + 2;
    ++ebx52;
    if (ebx52 >= esi8) 
        goto 0x408aa8;
    esi8 = esi8;
    goto addr_0x408a20_52;
    addr_0x4089f1_49:
    if (!eax53) {
        do {
            addr_0x408a20_52:
            *edx6 = *ecx7;
            edx6[1] = ecx7[2];
            edx6[2] = ecx7[4];
            edx6[3] = ecx7[6];
            edx6 = edx6 + 4;
            ecx7 = ecx7 + 8;
            ebx52 = ebx52 + 4;
        } while (ebx52 < esi8);
    } else {
        if ((int32_t)eax53 > (int32_t)1) {
            if ((int32_t)eax53 > (int32_t)2) {
                ++edx6;
                ecx7 = edx6 + 1;
                ebx52 = 1;
            }
            *edx6 = *ecx7;
            ++edx6;
            ecx7 = ecx7 + 2;
            ++ebx52;
            goto addr_0x408a0d_50;
        }
    }
    goto 0x408aa8;
    addr_0x40892a_13:
    *edx6 = edx6[2];
    ecx54 = edx6 + 3;
    edx55 = edx6 + 1;
    *edx55 = *ecx54;
    ecx56 = ecx54 + 1;
    edx57 = edx55 + 1;
    *edx57 = *ecx56;
    ecx58 = ecx56 + 1;
    edx59 = edx57 + 1;
    *edx59 = *ecx58;
    ecx60 = ecx58 + 1;
    edx61 = edx59 + 1;
    *edx61 = *ecx60;
    ecx62 = ecx60 + 1;
    edx63 = edx61 + 1;
    *edx63 = *ecx62;
    ecx7 = ecx62 + 1;
    edx6 = edx63 + 1;
    ebx23 = 1;
    if (1 >= esi8) {
        addr_0x4089b0_10:
        ebp4->f11 = 48;
        eax64 = v12 + esi8;
        ebp4->f4 = eax64 + eax64;
    } else {
        esi8 = esi8;
        goto addr_0x40895c_15;
    }
    addr_0x4089bf_59:
    ebp4->f10 = 3;
    goto 0x408c0f;
    do {
        addr_0x40895c_15:
        *edx6 = ecx7[2];
        edx6[1] = ecx7[3];
        edx6[2] = ecx7[4];
        edx6[3] = ecx7[5];
        edx6[4] = ecx7[6];
        edx6[5] = ecx7[7];
        edx6[6] = ecx7[10];
        edx6[7] = ecx7[11];
        edx6[8] = ecx7[12];
        edx6[9] = ecx7[13];
        edx6[10] = ecx7[14];
        edx6[11] = ecx7[15];
        ecx7 = ecx7 + 16;
        edx6 = edx6 + 12;
        ebx23 = ebx23 + 2;
    } while (ebx23 < esi8);
    goto addr_0x4089b0_10;
    addr_0x4087d2_20:
    ecx65 = ecx7 + 1;
    *edx6 = *ecx65;
    ecx66 = ecx65 + 1;
    edx67 = edx6 + 1;
    *edx67 = *ecx66;
    ecx68 = ecx66 + 1;
    edx69 = edx67 + 1;
    *edx69 = *ecx68;
    ecx7 = ecx68 + 1;
    edx6 = edx69 + 1;
    ++ebx24;
    if (ebx24 >= esi8) {
        addr_0x408840_18:
        ebp4->f11 = 24;
        ebp4->f4 = esi8 + v25;
        goto addr_0x4089bf_59;
    } else {
        esi8 = esi8;
        goto addr_0x4087ec_61;
    }
    addr_0x40879a_21:
    if (!eax26) {
        do {
            addr_0x4087ec_61:
            *edx6 = ecx7[1];
            edx6[1] = ecx7[2];
            edx6[2] = ecx7[3];
            edx6[3] = ecx7[5];
            edx6[4] = ecx7[6];
            edx6[5] = ecx7[7];
            edx6[6] = ecx7[9];
            edx6[7] = ecx7[10];
            edx6[8] = ecx7[11];
            edx6[9] = ecx7[13];
            edx6[10] = ecx7[14];
            edx6[11] = ecx7[15];
            ecx7 = ecx7 + 16;
            edx6 = edx6 + 12;
            ebx24 = ebx24 + 4;
        } while (ebx24 < esi8);
        goto addr_0x408840_18;
    } else {
        if ((int32_t)eax26 > (int32_t)1) {
            if ((int32_t)eax26 > (int32_t)2) {
                *edx6 = edx6[1];
                ecx70 = edx6 + 2;
                edx71 = edx6 + 1;
                *edx71 = *ecx70;
                ecx72 = ecx70 + 1;
                edx73 = edx71 + 1;
                *edx73 = *ecx72;
                ecx7 = ecx72 + 1;
                edx6 = edx73 + 1;
                ebx24 = 1;
            }
            ecx74 = ecx7 + 1;
            *edx6 = *ecx74;
            ecx75 = ecx74 + 1;
            edx76 = edx6 + 1;
            *edx76 = *ecx75;
            ecx77 = ecx75 + 1;
            edx78 = edx76 + 1;
            *edx78 = *ecx77;
            ecx7 = ecx77 + 1;
            edx6 = edx78 + 1;
            ++ebx24;
            goto addr_0x4087d2_20;
        }
    }
    addr_0x408709_24:
    *edx27 = ecx28->f0;
    ecx79 = (struct s354*)&ecx28->f1;
    edx80 = edx27 + 1;
    *edx80 = ecx79->f0;
    ecx81 = (struct s356*)&ecx79->f1;
    edx82 = edx80 + 1;
    *edx82 = ecx81->f0;
    edx27 = edx82 + 1;
    ecx28 = (struct s352*)&ecx81->f2;
    ++ebx29;
    if (ebx29 >= esi8) 
        goto addr_0x408840_18;
    esi8 = esi8;
    goto addr_0x408728_67;
    addr_0x4086cc_25:
    if (!eax30) {
        do {
            addr_0x408728_67:
            *edx27 = ecx28->f0;
            edx27[1] = ecx28->f1;
            edx27[2] = ecx28->f2;
            edx27[3] = ecx28->f4;
            edx27[4] = ecx28->f5;
            edx27[5] = ecx28->f6;
            edx27[6] = ecx28->f8;
            edx27[7] = ecx28->f9;
            edx27[8] = ecx28->f10;
            edx27[9] = ecx28->f12;
            edx27[10] = ecx28->f13;
            edx27[11] = ecx28->f14;
            edx27 = edx27 + 12;
            ecx28 = (struct s352*)((int32_t)ecx28 + 16);
            ebx29 = ebx29 + 4;
        } while (ebx29 < esi8);
    } else {
        if ((int32_t)eax30 > (int32_t)1) {
            if ((int32_t)eax30 > (int32_t)2) {
                *edx27 = a2[4];
                edx83 = edx27 + 1;
                *edx83 = a2[5];
                edx84 = edx83 + 1;
                *edx84 = a2[6];
                edx27 = edx84 + 1;
                ecx28 = (struct s352*)(a2 + 8);
                ebx29 = 2;
            }
            *edx27 = ecx28->f0;
            ecx85 = (struct s354*)&ecx28->f1;
            edx86 = edx27 + 1;
            *edx86 = ecx85->f0;
            ecx87 = (struct s356*)&ecx85->f1;
            edx88 = edx86 + 1;
            *edx88 = ecx87->f0;
            edx27 = edx88 + 1;
            ecx28 = (struct s352*)&ecx87->f2;
            ++ebx29;
            goto addr_0x408709_24;
        }
    }
    goto addr_0x408840_18;
}

void fun_409006() {
}

uint32_t fun_40a490(struct s26* a1, int32_t a2) {
    struct s26* ebx3;
    uint32_t v4;
    void** eax5;
    void** ecx6;
    int32_t ecx7;
    void** esi8;
    uint32_t edx9;
    uint32_t ecx10;
    void** edx11;
    void** eax12;
    void** eax13;
    void** dx14;
    uint16_t ecx15;
    void* eax16;
    void* eax17;
    void** eax18;
    int8_t al19;
    int32_t ebp20;
    uint32_t v21;
    int16_t* eax22;
    uint16_t* esi23;
    void** edi24;
    int32_t edx25;
    int32_t eax26;
    int8_t cl27;
    int32_t eax28;
    int32_t edx29;
    uint32_t eax30;
    int32_t edx31;
    int32_t eax32;
    int32_t ecx33;
    int32_t ecx34;
    int32_t ebp35;
    void* eax36;
    int32_t ecx37;
    uint32_t edx38;
    void** edx39;
    void** eax40;
    uint32_t ecx41;
    void** eax42;
    void** dx43;
    void** edx44;
    void** edx45;
    void* ecx46;
    struct s27* eax47;
    void** edx48;
    void** ecx49;
    void* eax50;
    void** edx51;
    struct s27* eax52;
    void** edx53;
    void** esi54;
    void*** edi55;
    void** ebp56;
    uint32_t ecx57;
    uint32_t ecx58;
    struct s28* ecx59;
    void** edi60;
    struct s28* ecx61;
    void** esi62;
    void*** edi63;
    void** ebp64;
    uint32_t ecx65;
    uint32_t ecx66;
    struct s28* ecx67;
    void** edi68;
    struct s28* ecx69;
    int8_t al70;
    int32_t edi71;
    int16_t* eax72;
    void* eax73;
    int32_t ecx74;
    void** edx75;
    struct s27* eax76;
    void** edx77;
    int32_t eax78;
    int32_t eax79;
    void** esi80;
    void*** edi81;
    void** ebp82;
    uint32_t ecx83;
    uint32_t ecx84;
    struct s28* ecx85;
    void** edi86;
    struct s28* ecx87;

    ebx3 = a1;
    v4 = 0;
    do {
        addr_0x40a4a3_2:
        eax5 = ebx3->f108;
        if ((uint8_t)eax5 < (uint8_t)0x106) {
            fun_409ee0(ecx6, ebx3);
            eax5 = ebx3->f108;
            if ((uint8_t)eax5 >= (uint8_t)0x106) 
                goto addr_0x40a4cc_4;
            if (!a2) 
                break;
            addr_0x40a4cc_4:
            if (!eax5) 
                goto addr_0x40a8a2_6;
        }
        if ((uint8_t)eax5 >= (uint8_t)3) {
            ecx7 = ebx3->f80;
            esi8 = ebx3->f100;
            edx9 = 0;
            *(int8_t*)&edx9 = *(int8_t*)((uint32_t)ebx3->f48 + (uint8_t)esi8 + 2);
            ecx10 = 0;
            edx11 = ebx3->f60;
            eax12 = (void**)(((uint8_t)ebx3->f64 << *(uint8_t*)&ecx7 ^ edx9) & ebx3->f76);
            ebx3->f64 = eax12;
            *(void***)&ecx10 = *(void***)(edx11 + (uint8_t)eax12 * 2);
            ebx3->f56[(ebx3->f44 & (uint8_t)esi8) * 2] = *(void***)&ecx10;
            eax13 = ebx3->f64;
            dx14 = ebx3->f100;
            v4 = ecx10;
            *(void***)(ebx3->f60 + (uint8_t)eax13 * 2) = dx14;
        }
        ecx15 = ebx3->f104;
        ebx3->f112 = ebx3->f88;
        ebx3->f92 = ecx15;
        ebx3->f88 = (void*)2;
        if (v4 && ((uint32_t)ebx3->f112 < (uint32_t)ebx3->f120 && (uint8_t)((uint8_t)ebx3->f100 - v4) <= (uint8_t)((uint32_t)ebx3->f36 - 0x106))) {
            if (ebx3->f128 != 2) {
                eax16 = fun_415660(ebx3, v4);
                ebx3->f88 = eax16;
            }
            if ((uint32_t)ebx3->f88 <= 5 && (ebx3->f128 == 1 || (int1_t)(ebx3->f88 == 3) && (uint8_t)ebx3->f100 - ebx3->f104 > 0x1000)) {
                ebx3->f88 = (void*)2;
            }
        }
        eax17 = ebx3->f112;
        if ((uint32_t)eax17 < 3 || (uint32_t)ebx3->f88 > (uint32_t)eax17) {
            if (!ebx3->f96) {
                ecx6 = ebx3->f100 + 1;
                eax18 = ebx3->f108 - 1;
                ebx3->f96 = 1;
                ebx3->f100 = ecx6;
                ebx3->f108 = eax18;
                goto addr_0x40a4a3_2;
            }
            al19 = *(int8_t*)((uint8_t)ebx3->f100 + (uint32_t)ebx3->f48 - 1);
            ebx3->f5788[ebx3->f5784] = 0;
            *(int8_t*)((int32_t)ebx3->f5776 + ebx3->f5784) = al19;
            ebp20 = ebx3->f5784;
            *(int8_t*)&v21 = al19;
            eax22 = (int16_t*)((uint32_t)ebx3 + (v21 & 0xff) * 4 + 0x8c);
            ebx3->f5784 = ebp20 + 1;
            *eax22 = (int16_t)(*eax22 + 1);
            if (ebx3->f5784 == ebx3->f5780 - 1) 
                goto addr_0x40a7ee_18;
        } else {
            esi23 = ebx3->f5788;
            edi24 = (void**)((uint8_t)ebx3->f100 + (uint8_t)ebx3->f108 + 0xfffffffd);
            edx25 = ebx3->f5784;
            eax26 = 0;
            *(uint16_t*)&eax26 = (uint16_t)((uint8_t)ebx3->f100 - ebx3->f92);
            cl27 = (int8_t)(*(int8_t*)&eax17 - 3);
            *(int8_t*)&a1 = cl27;
            eax28 = eax26 - 1;
            esi23[edx25] = *(uint16_t*)&eax28;
            *(int8_t*)((int32_t)ebx3->f5776 + ebx3->f5784) = cl27;
            ebx3->f5784 = ebx3->f5784 + 1;
            edx29 = 0;
            *(int8_t*)&edx29 = *(int8_t*)(((uint32_t)a1 & 0xff) + 0x41e370);
            eax30 = (uint32_t)(eax28 + 0xffff);
            *(int16_t*)((uint32_t)ebx3 + edx29 * 4 + 0x490) = (int16_t)(*(int16_t*)((uint32_t)ebx3 + edx29 * 4 + 0x490) + 1);
            if (*(uint16_t*)&eax30 >= 0x100) {
                edx31 = 0;
                *(int8_t*)&edx31 = *(int8_t*)(((eax30 & 0xffff) >> 7) + 0x41e270);
                eax32 = edx31;
            } else {
                ecx33 = 0;
                *(int8_t*)&ecx33 = *(int8_t*)((eax30 & 0xffff) + 0x41e170);
                eax32 = ecx33;
            }
            *(int16_t*)((uint32_t)ebx3 + eax32 * 4 + 0x980) = (int16_t)(*(int16_t*)((uint32_t)ebx3 + eax32 * 4 + 0x980) + 1);
            ecx34 = 0;
            *(uint8_t*)&ecx34 = static_cast<uint8_t>((uint1_t)(ebx3->f5784 == ebx3->f5780 - 1));
            ebp35 = ecx34;
            eax36 = (void*)((uint32_t)ebx3->f112 + 0xfffffffe);
            ebx3->f108 = (void**)((uint8_t)ebx3->f108 + (1 - (uint32_t)ebx3->f112));
            ebx3->f112 = eax36;
            do {
                ecx6 = ebx3->f100 + 1;
                ebx3->f100 = ecx6;
                if ((uint8_t)ecx6 <= (uint8_t)edi24) {
                    ecx37 = ebx3->f80;
                    edx38 = 0;
                    *(int8_t*)&edx38 = *(int8_t*)((uint32_t)ebx3->f48 + (uint8_t)ecx6 + 2);
                    edx39 = ebx3->f60;
                    eax40 = (void**)(((uint8_t)ebx3->f64 << *(uint8_t*)&ecx37 ^ edx38) & ebx3->f76);
                    ebx3->f64 = eax40;
                    ecx41 = 0;
                    *(void***)&ecx41 = *(void***)(edx39 + (uint8_t)eax40 * 2);
                    ebx3->f56[(ebx3->f44 & (uint8_t)ecx6) * 2] = *(void***)&ecx41;
                    eax42 = ebx3->f64;
                    dx43 = ebx3->f100;
                    v4 = ecx41;
                    ecx6 = ebx3->f60;
                    *(void***)(ecx6 + (uint8_t)eax42 * 2) = dx43;
                }
                ebx3->f112 = (void*)((uint32_t)ebx3->f112 - 1);
            } while (ebx3->f112);
            edx44 = ebx3->f100 + 1;
            ebx3->f96 = 0;
            ebx3->f88 = (void*)2;
            ebx3->f100 = edx44;
            if (!ebp35) 
                goto addr_0x40a4a3_2;
            edx45 = ebx3->f84;
            if ((int8_t)edx45 < (int8_t)0) {
                ecx46 = (void*)0;
            } else {
                ecx46 = (void*)((uint32_t)ebx3->f48 + (uint8_t)edx45);
            }
            fun_415d10(ebx3, ecx46, (uint8_t)edx44 - (uint8_t)edx45, 0);
            ebx3->f84 = ebx3->f100;
            eax47 = ebx3->f0;
            edx48 = eax47->f28->f20;
            ecx6 = eax47->f16;
            if ((uint8_t)edx48 > (uint8_t)ecx6) {
                edx48 = ecx6;
            }
            if (!edx48) 
                continue; else 
                goto addr_0x40a71d_33;
        }
        addr_0x40a875_34:
        ecx6 = ebx3->f108 - 1;
        ebx3->f100 = ebx3->f100 + 1;
        ebx3->f108 = ecx6;
        continue;
        addr_0x40a7ee_18:
        ecx49 = ebx3->f84;
        if ((int8_t)ecx49 < (int8_t)0) {
            eax50 = (void*)0;
        } else {
            eax50 = (void*)((uint32_t)ebx3->f48 + (uint8_t)ecx49);
        }
        edx51 = ebx3->f100;
        fun_415d10(ebx3, eax50, (uint8_t)edx51 - (uint8_t)ecx49, 0);
        ebx3->f84 = ebx3->f100;
        eax52 = ebx3->f0;
        edx53 = eax52->f28->f20;
        if ((uint8_t)edx53 > (uint8_t)eax52->f16) {
            edx53 = eax52->f16;
        }
        if (!edx53) 
            goto addr_0x40a875_34;
        esi54 = eax52->f28->f16;
        edi55 = eax52->f12;
        ebp56 = edx53;
        ecx57 = (uint8_t)edx53 >> 2;
        while (ecx57) {
            --ecx57;
            *edi55 = *(void***)esi54;
            edi55 = edi55 + 4;
            esi54 = esi54 + 4;
        }
        ecx58 = (uint8_t)ebp56 & 3;
        while (ecx58) {
            --ecx58;
            *edi55 = *(void***)esi54;
            ++edi55;
            ++esi54;
        }
        ecx59 = eax52->f28;
        eax52->f12 = (void***)((uint32_t)eax52->f12 + (uint8_t)edx53);
        ecx59->f16 = (void**)((uint8_t)ecx59->f16 + (uint8_t)edx53);
        edi60 = eax52->f16;
        ecx61 = eax52->f28;
        eax52->f20 = eax52->f20 + (uint8_t)edx53;
        eax52->f16 = (void**)((uint8_t)edi60 - (uint8_t)edx53);
        ecx61->f20 = (void**)((uint8_t)ecx61->f20 - (uint8_t)edx53);
        if (eax52->f28->f20) 
            goto addr_0x40a875_34;
        eax52->f28->f16 = eax52->f28->f8;
        goto addr_0x40a875_34;
        addr_0x40a71d_33:
        esi62 = eax47->f28->f16;
        edi63 = eax47->f12;
        ebp64 = edx48;
        ecx65 = (uint8_t)edx48 >> 2;
        while (ecx65) {
            --ecx65;
            *edi63 = *(void***)esi62;
            edi63 = edi63 + 4;
            esi62 = esi62 + 4;
        }
        ecx66 = (uint8_t)ebp64 & 3;
        while (ecx66) {
            --ecx66;
            *edi63 = *(void***)esi62;
            ++edi63;
            ++esi62;
        }
        ecx67 = eax47->f28;
        eax47->f12 = (void***)((uint32_t)eax47->f12 + (uint8_t)edx48);
        ecx67->f16 = (void**)((uint8_t)ecx67->f16 + (uint8_t)edx48);
        edi68 = eax47->f16;
        ecx69 = eax47->f28;
        eax47->f20 = eax47->f20 + (uint8_t)edx48;
        eax47->f16 = (void**)((uint8_t)edi68 - (uint8_t)edx48);
        ecx69->f20 = (void**)((uint8_t)ecx69->f20 - (uint8_t)edx48);
        ecx6 = eax47->f28->f20;
        if (ecx6) 
            continue;
        ecx6 = eax47->f28->f8;
        eax47->f28->f16 = ecx6;
    } while (ebx3->f0->f16);
    return 0;
    addr_0x40a8a2_6:
    if (ebx3->f96) {
        al70 = *(int8_t*)((uint8_t)ebx3->f100 + (uint32_t)ebx3->f48 - 1);
        ebx3->f5788[ebx3->f5784] = 0;
        *(int8_t*)((int32_t)ebx3->f5776 + ebx3->f5784) = al70;
        edi71 = ebx3->f5784;
        *(int8_t*)&a1 = al70;
        eax72 = (int16_t*)((uint32_t)ebx3 + ((uint32_t)a1 & 0xff) * 4 + 0x8c);
        ebx3->f5784 = edi71 + 1;
        *eax72 = (int16_t)(*eax72 + 1);
        ebx3->f96 = 0;
    }
    if ((int8_t)ebx3->f84 < (int8_t)0) {
        eax73 = (void*)0;
    } else {
        eax73 = (void*)((uint32_t)ebx3->f48 + (uint8_t)ebx3->f84);
    }
    ecx74 = 0;
    *(uint8_t*)&ecx74 = static_cast<uint8_t>((uint1_t)(a2 == 4));
    edx75 = (void**)((uint8_t)ebx3->f100 - (uint8_t)ebx3->f84);
    fun_415d10(ebx3, eax73, edx75, ecx74);
    ebx3->f84 = ebx3->f100;
    eax76 = ebx3->f0;
    edx77 = eax76->f28->f20;
    if ((uint8_t)edx77 > (uint8_t)eax76->f16) {
        edx77 = eax76->f16;
    }
    if (!edx77) {
        addr_0x40a992_64:
        if (ebx3->f0->f16) {
            eax78 = 0;
            *(uint8_t*)&eax78 = static_cast<uint8_t>((uint1_t)(a2 == 4));
            return eax78 + eax78 + 1;
        } else {
            eax79 = 0;
            *(uint8_t*)&eax79 = static_cast<uint8_t>((uint1_t)(a2 != 4));
            return (uint32_t)(eax79 - 1) & 2;
        }
    } else {
        esi80 = eax76->f28->f16;
        edi81 = eax76->f12;
        ebp82 = edx77;
        ecx83 = (uint8_t)edx77 >> 2;
        while (ecx83) {
            --ecx83;
            *edi81 = *(void***)esi80;
            edi81 = edi81 + 4;
            esi80 = esi80 + 4;
        }
        ecx84 = (uint8_t)ebp82 & 3;
        while (ecx84) {
            --ecx84;
            *edi81 = *(void***)esi80;
            ++edi81;
            ++esi80;
        }
        ecx85 = eax76->f28;
        eax76->f12 = (void***)((uint32_t)eax76->f12 + (uint8_t)edx77);
        ecx85->f16 = (void**)((uint8_t)ecx85->f16 + (uint8_t)edx77);
        edi86 = eax76->f16;
        ecx87 = eax76->f28;
        eax76->f20 = eax76->f20 + (uint8_t)edx77;
        eax76->f16 = (void**)((uint8_t)edi86 - (uint8_t)edx77);
        ecx87->f20 = (void**)((uint8_t)ecx87->f20 - (uint8_t)edx77);
        if (eax76->f28->f20) 
            goto addr_0x40a992_64;
    }
    eax76->f28->f16 = eax76->f28->f8;
    goto addr_0x40a992_64;
}

struct s364 {
    int8_t[97] pad97;
    uint8_t f97;
    int8_t[18] pad116;
    uint8_t f116;
};

struct s365 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s366 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s367 {
    int8_t[32] pad32;
    int32_t f32;
};

struct s368 {
    int8_t[114] pad114;
    int8_t f114;
};

struct s369 {
    int8_t[114] pad114;
    int8_t f114;
};

struct s370 {
    int8_t[32] pad32;
    int32_t f32;
};

struct s371 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s372 {
    int8_t[95] pad95;
    int32_t f95;
};

void fun_40a9d0(struct s30* ecx) {
    uint96_t v2;
    struct s364* ebx3;
    void* ebx4;
    void* edi5;
    int32_t ebp6;
    void* edi7;
    int32_t ebp8;
    uint8_t dh9;
    int32_t ebp10;
    struct s365* edi11;
    struct s366* edi12;
    uint8_t dh13;
    int32_t esi14;
    struct s367* ebp15;
    uint8_t dh16;
    uint8_t dh17;
    struct s368* edi18;
    struct s369* edi19;
    int8_t dl20;
    struct s370* ebp21;
    void* edi22;
    int32_t ebp23;
    void* edi24;
    int32_t ebp25;
    uint8_t dh26;
    int1_t zf27;
    void* edi28;
    int32_t ebp29;
    uint8_t* eax30;
    uint8_t* eax31;
    uint8_t ah32;
    int1_t zf33;
    int8_t* eax34;
    int32_t ebp35;
    uint8_t dh36;
    uint8_t ah37;
    uint8_t dh38;
    struct s372* ebp39;
    int32_t eax40;
    int32_t eax41;
    int8_t dl42;
    int8_t* eax43;
    int8_t* eax44;
    int8_t al45;
    void* eax46;
    int32_t ebp47;
    void* eax48;
    int32_t ebp49;
    int8_t dh50;

    *(int32_t*)((int32_t)&v2 + 6) = (int32_t)__return_address();
    ebx3 = (struct s364*)((int32_t)ebx4 + 1);
    asm("popad");
    asm("insb");
    asm("insb");
    *(uint8_t*)((int32_t)edi5 + ebp6 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi7 + ebp8 * 2 + 32) & dh9);
    *(int32_t*)((int32_t)&v2 + 2) = ebp10;
    edi11->f114 = (uint8_t)(edi12->f114 & dh13);
    esi14 = ebp15->f32 * 0x636e7566;
    if (__undefined()) {
        addr_0x40aa52_2:
        ebx3->f97 = (uint8_t)(ebx3->f97 & dh16);
        asm("insd");
        ebx3->f116 = (uint8_t)(ebx3->f116 & dh17);
        if (0) 
            goto 0x40aad2;
    } else {
        asm("outsd");
        asm("outsb");
        edi18->f114 = (int8_t)(edi19->f114 + dl20);
        esi14 = ebp21->f32 * 0x6f727245;
        ecx = (struct s30*)((int32_t)ecx + 1);
        if (!ecx) {
            addr_0x40aa87_5:
        } else {
            asm("insd");
            if (__intrinsic()) 
                goto 0x40aa8b;
            *(uint8_t*)((int32_t)edi22 + ebp23 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi24 + ebp25 * 2 + 32) & dh26);
            zf27 = *(int8_t*)((int32_t)edi28 + ebp29 * 2 + 32) == 0;
            if (1) 
                goto addr_0x40aa84_8; else 
                goto addr_0x40aa1f_9;
        }
    }
    asm("arpl [ebp+esi*2+0x72], si");
    *eax30 = (uint8_t)(*eax31 & ah32);
    zf33 = *eax34 == 0;
    if (1) 
        goto "P";
    if (zf33) 
        goto 0x40aadf;
    ebp35 = *(int32_t*)(esi14 + 0x67) * 0x61657220;
    asm("popad");
    if (__undefined()) 
        goto "@";
    asm("o16 outsb");
    *(uint8_t*)((int32_t)*(void**)((int32_t)&v2 + 8) + ebp35 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)*(void**)((int32_t)&v2 + 8) + ebp35 * 2 + 32) & dh36);
    *(int8_t*)(ebp35 - 0x137cff8a) = (int8_t)(*(int8_t*)(ebp35 - 0x137cff8a) + *(int8_t*)&ecx);
    addr_0x40aa84_8:
    goto addr_0x40aa87_5;
    addr_0x40aa1f_9:
    if (!zf27) {
        asm("popad");
        if (zf27) 
            goto 0x40aa90;
        asm("o16 outsb");
        ecx->f110 = (uint8_t)(ecx->f110 & ah37);
        (*(struct s371**)&v2)->f114 = (uint8_t)((*(struct s371**)&v2)->f114 & dh38);
        esi14 = ebp39->f95 * 0x61746164;
    }
    asm("o16 outsb");
    ecx->f110 = 0;
    *(int8_t*)(eax40 + 0x26b48d) = (int8_t)(*(int8_t*)(eax41 + 0x26b48d) + dl42);
    *eax43 = (int8_t)(*eax44 + al45);
    *(int8_t*)((int32_t)eax46 + ebp47 * 2 + 0x65) = (int8_t)(*(int8_t*)((int32_t)eax48 + ebp49 * 2 + 0x65) + dh50);
    goto addr_0x40aa52_2;
}

void fun_40ab2d() {
}

void fun_40ae66() {
}

struct s373 {
    int8_t[109] pad109;
    uint8_t f109;
};

struct s374 {
    int8_t[98] pad98;
    int32_t f98;
};

struct s375 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s376 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s377 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s378 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s379 {
    int8_t[98] pad98;
    int32_t f98;
};

struct s380 {
    int8_t[71] pad71;
    uint8_t f71;
};

struct s381 {
    int8_t[71] pad71;
    uint8_t f71;
};

struct s382 {
    int8_t[71] pad71;
    uint8_t f71;
};

struct s383 {
    int8_t[98] pad98;
    int32_t f98;
};

struct s384 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s385 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s386 {
    int8_t[98] pad98;
    int32_t f98;
};

struct s387 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s388 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s389 {
    int8_t[114] pad114;
    int8_t f114;
};

struct s390 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s391 {
    int8_t[110] pad110;
    int32_t f110;
};

struct s392 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s393 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s394 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s395 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s396 {
    int8_t[111] pad111;
    int8_t f111;
};

struct s397 {
    int8_t[98] pad98;
    int32_t f98;
};

void fun_40afee(void* ecx) {
    int32_t esi2;
    int32_t esi3;
    struct s373* ecx4;
    uint1_t cf5;
    uint1_t cf6;
    struct s374* eax7;
    struct s375* edi8;
    struct s376* edi9;
    uint8_t ah10;
    uint1_t cf11;
    struct s377* eax12;
    void* eax13;
    int8_t bl14;
    int8_t* ebx15;
    int8_t* ebx16;
    int8_t* eax17;
    int32_t ebp18;
    struct s378* ebx19;
    int16_t bx20;
    int16_t bx21;
    int8_t dl22;
    struct s379* eax23;
    struct s380* edx24;
    struct s381* edx25;
    uint8_t dl26;
    struct s382* edx27;
    void* edx28;
    int16_t bx29;
    int16_t di30;
    int16_t bx31;
    int16_t di32;
    int16_t bx33;
    int16_t di34;
    int32_t* esp35;
    struct s383* eax36;
    struct s384* eax37;
    struct s385* eax38;
    int16_t bx39;
    int16_t bx40;
    int16_t bx41;
    int16_t bx42;
    struct s386* eax43;
    struct s387* edi44;
    struct s388* edi45;
    uint8_t ah46;
    int1_t zf47;
    struct s389* edi48;
    int32_t ebx49;
    int32_t ebx50;
    int8_t al51;
    struct s390* ebx52;
    struct s391* edi53;
    struct s392* ebx54;
    struct s393* ebx55;
    struct s394* ebx56;
    struct s395* ebx57;
    uint8_t ah58;
    struct s396* ebx59;
    int16_t bx60;
    int16_t bx61;
    struct s397* eax62;

    esi2 = esi3;
    ecx4 = (struct s373*)((int32_t)ecx - 1);
    asm("outsb");
    if (cf5 | (uint1_t)(ecx4 == 0)) {
        addr_0x40b055_2:
        if (__intrinsic()) 
            goto addr_0x40b0d4_3;
    } else {
        asm("insb");
        cf6 = __intrinsic();
        if (__intrinsic()) {
            addr_0x40b074_5:
            goto addr_0x40b07e_6;
        } else {
            *(int32_t*)(eax7->f98 * 0x64207469 - 4) = 0x726f6620;
            edi8->f114 = (uint8_t)(edi9->f114 & ah10);
            cf6 = 0;
            asm("popad");
            if (!__intrinsic()) {
                addr_0x40b07e_6:
                ecx4 = (struct s373*)((int32_t)ecx4 - 1);
                asm("outsb");
                if (cf6 | (uint1_t)(ecx4 == 0)) {
                    addr_0x40b0f5_8:
                    ecx4 = (struct s373*)((int32_t)ecx4 - 1);
                    asm("outsb");
                    if (cf6 | (uint1_t)(ecx4 == 0)) {
                        addr_0x40b175_9:
                        asm("popad");
                        asm("insb");
                        cf11 = __intrinsic();
                        if (cf11) {
                            addr_0x40b1a2_10:
                            ecx4 = (struct s373*)((int32_t)ecx4 - 1);
                            asm("outsb");
                            if (cf11 | (uint1_t)(ecx4 == 0)) {
                                eax12 = (struct s377*)((int32_t)eax13 + 1);
                                *(int8_t*)((int32_t)&eax12 + 1) = (int8_t)(*(int8_t*)((int32_t)&eax12 + 1) + bl14);
                                ebx15[esi2 * 4] = (int8_t)(ebx16[esi2 * 4] + *(int8_t*)((int32_t)&eax12 + 1));
                                eax17 = &eax12->f1;
                                *eax17 = (int8_t)(*eax17 + *(int8_t*)&eax17);
                                *(int8_t*)(ebp18 - 0x77c00bd) = (int8_t)(*(int8_t*)(ebp18 - 0x77c00bd) + *(int8_t*)&ecx4);
                            } else {
                                asm("insb");
                                goto addr_0x40b1b5_13;
                            }
                        } else {
                            if (__undefined()) 
                                goto 0x40b1fd;
                            if (__intrinsic()) 
                                goto 0x40b1eb;
                            ebx19->f112 = 0;
                            asm("arpl [gs:ecx+0x66], bp");
                            goto addr_0x40b18d_17;
                        }
                    } else {
                        addr_0x40b114_18:
                        asm("insb");
                        goto addr_0x40b11c_19;
                    }
                } else {
                    asm("insb");
                    goto addr_0x40b095_21;
                }
            } else {
                asm("arpl [ecx+0x6c], sp");
                ecx4->f109 = 0;
                asm("popad");
                *(int8_t*)((int16_t)(bx20 + *(int16_t*)&esi2) - 0x6f70) = (int8_t)(*(int8_t*)((int16_t)(bx21 + *(int16_t*)&esi2) - 0x6f70) + dl22);
                ecx4 = (struct s373*)((int32_t)ecx4 - 1);
                asm("outsb");
                if (__intrinsic() | (uint1_t)(ecx4 == 0)) {
                    addr_0x40b095_21:
                    if (__intrinsic()) 
                        goto addr_0x40b114_18; else 
                        goto addr_0x40b0a0_23;
                } else {
                    asm("insb");
                    if (__intrinsic()) 
                        goto addr_0x40b0b4_25;
                    *(int32_t*)(eax23->f98 * 0x64207469 - 4) = 0x726f6620;
                    edx24->f71 = (uint8_t)(edx25->f71 & dl26);
                    edx27 = (struct s382*)((int32_t)edx28 + 1);
                    ecx4->f109 = 0;
                    asm("popad");
                    *(int8_t*)((int16_t)(bx29 + di30) + 0x6e) = (int8_t)(*(int8_t*)((int16_t)(bx31 + di32) + 0x6e) + *(int8_t*)&ecx4);
                    if (__intrinsic() | (uint1_t)(*(int8_t*)((int16_t)(bx33 + di34) + 0x6e) == 0)) 
                        goto addr_0x40b0b5_27; else 
                        goto addr_0x40b054_28;
                }
            }
        }
    }
    esp35 = (int32_t*)(eax36->f98 * 0x64207469 - 4);
    *esp35 = 0x726f6620;
    eax37->f97 = 0;
    asm("insb");
    if (!eax38->f97) {
        addr_0x40b0e0_30:
        *(esp35 - 1) = 0x726f6620;
        edx27->f71 = (uint8_t)(edx27->f71 & *(uint8_t*)&edx27);
        edx27 = (struct s382*)((int32_t)edx27 + 1);
        ecx4 = (struct s373*)((int32_t)ecx4 + 1);
        ecx4->f109 = 0;
        asm("popad");
        *(uint8_t*)((int16_t)(bx39 + *(int16_t*)&esi2) - 0x6f70) = (uint8_t)(*(int8_t*)((int16_t)(bx40 + *(int16_t*)&esi2) - 0x6f70) + *(uint8_t*)&edx27);
        cf6 = __intrinsic();
        goto addr_0x40b0f5_8;
    } else {
        ecx4->f109 = 0;
        asm("popad");
        *(uint8_t*)((int16_t)(bx41 + *(int16_t*)&esi2) - 0x6f70) = (uint8_t)(*(int8_t*)((int16_t)(bx42 + *(int16_t*)&esi2) - 0x6f70) + *(uint8_t*)&edx27);
        cf6 = __intrinsic();
        goto addr_0x40b074_5;
    }
    addr_0x40b0a0_23:
    *(int32_t*)(eax43->f98 * 0x64207469 - 4) = 0x726f6620;
    edi44->f114 = (uint8_t)(edi45->f114 & ah46);
    cf11 = 0;
    zf47 = edi48->f114 == 0;
    asm("popad");
    if (!__intrinsic()) {
        addr_0x40b11e_32:
        asm("insb");
        asm("outsd");
        if (0) {
            addr_0x40b144_33:
            ecx4 = (struct s373*)((int32_t)ecx4 - 1);
            asm("outsb");
            if (cf11 | (uint1_t)(ecx4 == 0)) {
                addr_0x40b1b5_13:
                asm("insb");
                asm("popad");
                asm("arpl [ebp+0x20], sp");
                if (__undefined()) {
                    *(uint8_t*)&edx27 = 64;
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)&edx27 = 64;
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(uint8_t*)((int32_t)edx27 + esi2 * 4 + 64) = (uint8_t)(*(int8_t*)((int32_t)edx27 + esi2 * 4 + 64) + *(uint8_t*)((int32_t)&edx27 + 1));
                    *(int8_t*)(ebx49 - 0xf97073c) = (int8_t)(*(int8_t*)(ebx50 - 0xf97073c) + al51);
                } else {
                    if (__intrinsic()) 
                        goto 0x40b22b;
                    ebx52->f112 = 0;
                    asm("arpl [gs:ecx+0x66], bp");
                    goto addr_0x40b1d3_37;
                }
            } else {
                addr_0x40b154_38:
                asm("insb");
                if (!__intrinsic()) {
                    addr_0x40b1d3_37:
                } else {
                    ebp18 = edi53->f110 * 0x70797420;
                    ebx54->f112 = 0;
                    asm("arpl [gs:ecx+0x66], bp");
                    goto addr_0x40b175_9;
                }
            }
        } else {
            if (zf47) {
                addr_0x40b19f_41:
                goto addr_0x40b1a2_10;
            } else {
                if (0) {
                    addr_0x40b18d_17:
                    cf11 = __intrinsic();
                    goto addr_0x40b19f_41;
                } else {
                    ebx55->f112 = 0;
                    asm("arpl [gs:ecx+0x66], bp");
                    cf11 = __intrinsic();
                    goto addr_0x40b135_44;
                }
            }
        }
    } else {
        asm("arpl [ecx+0x6c], sp");
        if (__intrinsic()) {
            addr_0x40b11c_19:
            ebx56->f111 = (uint8_t)(ebx57->f111 & ah58);
            cf11 = 0;
            zf47 = ebx59->f111 == 0;
            goto addr_0x40b11e_32;
        } else {
            addr_0x40b0b4_25:
            asm("popad");
        }
    }
    addr_0x40b0b5_27:
    ecx4->f109 = 0;
    asm("popad");
    *(uint8_t*)((int16_t)(bx60 + *(int16_t*)&esi2) - 0x6f70) = (uint8_t)(*(int8_t*)((int16_t)(bx61 + *(int16_t*)&esi2) - 0x6f70) + *(uint8_t*)&edx27);
    cf11 = __intrinsic();
    ecx4 = (struct s373*)((int32_t)ecx4 - 1);
    asm("outsb");
    if (cf11 | (uint1_t)(ecx4 == 0)) {
        addr_0x40b135_44:
        goto addr_0x40b144_33;
    } else {
        addr_0x40b0d4_3:
        asm("insb");
        esp35 = (int32_t*)(eax62->f98 * 0x64207469);
        if (__intrinsic()) 
            goto addr_0x40b154_38; else 
            goto addr_0x40b0e0_30;
    }
    addr_0x40b054_28:
    asm("insb");
    goto addr_0x40b055_2;
}

void fun_40b205() {
    int32_t eax1;
    uint8_t al2;
    int32_t eax3;
    int8_t* ebx4;
    int32_t esi5;
    int8_t* ebx6;
    int32_t eax7;
    int32_t edx8;
    int32_t edx9;

    *(uint8_t*)&eax1 = (uint8_t)(al2 & 0xb2);
    eax3 = eax1 + 1;
    ebx4[esi5 * 4] = (int8_t)(ebx6[esi5 * 4] + *(int8_t*)((int32_t)&eax3 + 1));
    eax7 = eax3 + 1;
    *(int8_t*)(edx8 + esi5 * 4 - 0x4d53ffc0) = (int8_t)(*(int8_t*)(edx9 + esi5 * 4 - 0x4d53ffc0) + *(int8_t*)&eax7);
}

void fun_40b234() {
    void* edx1;
    int32_t esi2;
    void* edx3;
    int32_t esi4;
    int8_t dh5;

    asm("lds esi, [edx+0xb2c50040]");
    *(int8_t*)((int32_t)edx1 + esi2 * 4 + 64) = (int8_t)(*(int8_t*)((int32_t)edx3 + esi4 * 4 + 64) + dh5);
}

void fun_40b2da() {
}

void fun_410bf2() {
}

struct s398 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
};

void fun_410c72(struct s398* a1, uint32_t a2) {
    uint32_t edx3;
    uint32_t eax4;
    uint32_t eax5;
    uint32_t eax6;

    edx3 = a2;
    eax4 = edx3 >> 24;
    a1->f0 = *(int8_t*)&eax4;
    eax5 = edx3 >> 16;
    a1->f1 = *(int8_t*)&eax5;
    eax6 = edx3 >> 8;
    a1->f2 = *(int8_t*)&eax6;
    a1->f3 = *(int8_t*)&edx3;
    return;
}

struct s399 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s400 {
    int8_t[110] pad110;
    int32_t f110;
};

struct s401 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s402 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s403 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s404 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s405 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s406 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s407 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s408 {
    int8_t[104] pad104;
    int8_t f104;
};

struct s409 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s410 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s411 {
    int8_t[78] pad78;
    uint8_t f78;
};

struct s412 {
    int8_t[78] pad78;
    uint8_t f78;
};

void fun_40b5d0(void* ecx) {
    struct s399* ecx2;
    uint1_t cf3;
    void* esp4;
    struct s400* eax5;
    int1_t cf6;
    struct s401* ebx7;
    struct s402* ebx8;
    uint8_t ah9;
    struct s403* eax10;
    struct s404* eax11;
    uint8_t dh12;
    struct s405* eax13;
    int32_t eax14;
    int32_t eax15;
    int8_t dl16;
    int16_t bp17;
    int16_t si18;
    int16_t bp19;
    int16_t si20;
    uint8_t dh21;
    void* edi22;
    int32_t ebp23;
    void* edi24;
    int32_t ebp25;
    uint8_t dh26;
    void* edi27;
    int32_t ebp28;
    void** esp29;
    struct s406* ebx30;
    struct s407* ebx31;
    uint8_t ah32;
    struct s408* ebx33;
    struct s409* edi34;
    struct s410* edi35;
    uint8_t ah36;
    struct s411* eax37;
    struct s412* eax38;
    uint8_t dl39;
    int32_t ebx40;
    int32_t ebx41;
    int8_t al42;

    ecx2 = (struct s399*)((int32_t)ecx - 1);
    asm("outsb");
    if (!(cf3 | (uint1_t)(ecx2 == 0))) {
        asm("insb");
        esp4 = (void*)(eax5->f110 * 0x65626d75);
        cf6 = __intrinsic();
        if (!cf6) {
            asm("outsd");
            ebx7->f111 = (uint8_t)(ebx8->f111 & ah9);
            asm("insb");
            asm("outsd");
            if (!0) {
                ecx2->f110 = 0;
                eax10->f97 = (uint8_t)(eax11->f97 & dh12);
                asm("insb");
                if (!eax13->f97) 
                    goto "H";
                *(int8_t*)(eax14 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax15 - 0x6f6f6f70) + dl16);
                cf6 = __intrinsic();
            }
        }
        asm("a16 outsb");
        asm("outsd");
        if (!cf6) {
            asm("outsb");
            *(uint8_t*)((int16_t)(bp17 + si18) + 0x65) = (uint8_t)(*(uint8_t*)((int16_t)(bp19 + si20) + 0x65) & dh21);
            if (1) 
                goto 0x40b692;
            if (1) 
                goto 0x40b694;
            *(uint8_t*)((int32_t)edi22 + ebp23 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi24 + ebp25 * 2 + 32) & dh26);
            if (!(uint1_t)static_cast<uint32_t>((uint1_t)(*(int8_t*)((int32_t)edi27 + ebp28 * 2 + 32) == 0))) 
                goto 0x40b698;
            esp29 = (void**)((int32_t)esp4 - 4);
            *(void***)esp29 = esp29;
            ebx30->f104 = (uint8_t)(ebx31->f104 & ah32);
            if (ebx33->f104) 
                goto 0x40b6a3;
        }
    }
    asm("outsb");
    edi34->f114 = (uint8_t)(edi35->f114 & ah36);
    asm("popad");
    if (!__intrinsic()) 
        goto 0x40b6b2;
    asm("arpl [ecx+0x6c], sp");
    eax37->f78 = (uint8_t)(eax38->f78 & dl39);
    *(int8_t*)(ebx40 + 0x57552cec) = (int8_t)(*(int8_t*)(ebx41 + 0x57552cec) + al42);
}

struct s413 {
    int8_t[121] pad121;
    int32_t f121;
};

struct s414 {
    int8_t[80] pad80;
    uint8_t f80;
};

struct s415 {
    int8_t[80] pad80;
    uint8_t f80;
};

struct s416 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s417 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s418 {
    int8_t[104] pad104;
    int8_t f104;
};

void fun_40bb2b(struct s9* ecx) {
    struct s413* ebp2;
    void* ebp3;
    void* esp4;
    struct s414* ebx5;
    struct s415* ebx6;
    uint8_t dh7;
    void** esp8;
    struct s416* ebx9;
    struct s417* ebx10;
    uint8_t ah11;
    struct s418* ebx12;

    ebp2 = (struct s413*)((int32_t)ebp3 + 1);
    asm("insd");
    if (__intrinsic()) 
        goto 0x40bba3;
    if ((int32_t)ebp2 >= 0) 
        goto 0x40bb51;
    esp4 = (void*)(ebp2->f121 * 0x77);
    asm("outsd");
    if (__intrinsic()) 
        goto 0x40bb9c;
    ecx->f110 = 0;
    ebx5->f80 = (uint8_t)(ebx6->f80 & dh7);
    esp8 = (void**)((int32_t)esp4 - 1 - 4);
    *(void***)esp8 = esp8;
    ebx9->f104 = (uint8_t)(ebx10->f104 & ah11);
    if (ebx12->f104) 
        goto 0x40bbb3;
}

void fun_40bbaa() {
}

struct s419 {
    int8_t f0;
    int8_t[110] pad111;
    uint8_t f111;
};

struct s420 {
    int8_t[100] pad100;
    int32_t f100;
};

void fun_40bed0(int32_t ecx) {
    int32_t ecx2;
    uint1_t cf3;
    uint1_t cf4;
    struct s419* eax5;
    int32_t edx6;
    int32_t edx7;
    int8_t bl8;
    uint8_t dh9;
    uint32_t eax10;
    struct s420* ebp11;
    uint8_t dh12;
    uint8_t dh13;

    ecx2 = ecx - 1;
    asm("outsb");
    if (cf3 | (uint1_t)(ecx2 == 0)) {
        addr_0x40bf35_2:
        goto addr_0x40bf38_3;
    } else {
        asm("insb");
        cf4 = __intrinsic();
        if (!(uint1_t)(cf4 | __undefined())) {
            addr_0x40bf47_5:
            --ecx2;
            asm("outsb");
            if (cf4 | (uint1_t)(ecx2 == 0)) {
                addr_0x40bfb5_6:
                eax5->f0 = (int8_t)(eax5->f0 + *(int8_t*)&eax5);
                *(int8_t*)(edx6 - 0x66666667) = (int8_t)(*(int8_t*)(edx7 - 0x66666667) + bl8);
                asm("cdq");
                goto 0x40c002;
            } else {
                asm("insb");
                cf4 = __intrinsic();
                goto addr_0x40bf5b_8;
            }
        } else {
            cf4 = __intrinsic();
            if (__undefined()) {
                addr_0x40bf09_10:
                --ecx2;
                asm("outsb");
                if (cf4 | (uint1_t)(ecx2 == 0)) {
                    addr_0x40bf75_11:
                    goto addr_0x40bf84_12;
                } else {
                    asm("insb");
                    cf4 = __intrinsic();
                    if (cf4) {
                        addr_0x40bf84_12:
                        asm("outsb");
                        if (cf4 | (uint1_t)(ecx2 - 1 == 0)) 
                            goto 0x40bff5;
                    } else {
                        eax5->f111 = (uint8_t)(eax5->f111 & dh9);
                        asm("arpl [ecx+0x66], bp");
                        cf4 = __intrinsic();
                        goto addr_0x40bf35_2;
                    }
                }
            } else {
                if (!cf4) {
                    addr_0x40bf5b_8:
                    goto addr_0x40bf5d_16;
                } else {
                    asm("arpl [gs:ecx+0x66], bp");
                    cf4 = __intrinsic();
                    if (__undefined()) {
                        addr_0x40bf5d_16:
                        if (cf4) 
                            goto 0x40bfc5; else 
                            goto addr_0x40bf60_18;
                    } else {
                        if (__undefined()) {
                            addr_0x40bf38_3:
                            goto addr_0x40bf44_20;
                        } else {
                            eax5 = (struct s419*)(eax10 & 0x77202c66);
                            cf4 = 0;
                            *(int32_t*)(ebp11->f100 * 0x69687700 + 4 - 4) = 0x5f657469;
                            if (!__intrinsic()) {
                                addr_0x40bf44_20:
                                goto addr_0x40bf47_5;
                            } else {
                                eax5 = (struct s419*)((uint32_t)eax5 & 0x90000a66);
                                cf4 = 0;
                                goto addr_0x40bf09_10;
                            }
                        }
                    }
                }
            }
        }
    }
    asm("insb");
    eax5->f111 = (uint8_t)(eax5->f111 & dh12);
    asm("arpl [ecx+0x66], bp");
    goto addr_0x40bfb5_6;
    addr_0x40bf60_18:
    asm("outsb");
    eax5->f111 = (uint8_t)(eax5->f111 & dh13);
    asm("arpl [ecx+0x66], bp");
    cf4 = __intrinsic();
    goto addr_0x40bf75_11;
}

void fun_40c0cd() {
}

void fun_40c3d5() {
}

void fun_40c97e() {
}

void fun_40c9e6() {
}

void fun_40ca72() {
}

struct s421 {
    uint8_t f0;
    int8_t[109] pad110;
    uint8_t f110;
};

struct s422 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s423 {
    int8_t[103] pad103;
    int32_t f103;
};

struct s424 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s425 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s426 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s427 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s428 {
    int8_t[101] pad101;
    uint8_t f101;
};

uint8_t g20393720;

struct s429 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s430 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s431 {
    int8_t[110] pad110;
    int32_t f110;
};

struct s432 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s433 {
    int8_t[110] pad110;
    int8_t f110;
};

struct s434 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s435 {
    int8_t[105] pad105;
    int8_t f105;
};

struct s436 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s437 {
    int8_t[110] pad110;
    uint8_t f110;
};

struct s438 {
    int8_t[110] pad110;
    int8_t f110;
};

struct s439 {
    int8_t[100] pad100;
    int32_t f100;
};

struct s440 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s441 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s442 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s443 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s444 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s445 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s446 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s447 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s448 {
    int8_t[114] pad114;
    uint8_t f114;
};

struct s449 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s450 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s451 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s452 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s453 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s454 {
    int8_t[101] pad101;
    int8_t f101;
};

struct s455 {
    int8_t[101] pad101;
    uint8_t f101;
};

struct s456 {
    int8_t[118] pad118;
    int32_t f118;
};

void fun_40ccb0(void* ecx) {
    int32_t* esp2;
    struct s421* ecx3;
    uint1_t cf4;
    struct s422* ebx5;
    int32_t ebp6;
    struct s423* esi7;
    struct s424* edx8;
    struct s425* edx9;
    uint8_t dh10;
    struct s426* edx11;
    struct s427* esi12;
    struct s428* ebx13;
    uint1_t cf14;
    int32_t eax15;
    int8_t dl16;
    int1_t sf17;
    struct s429* ebx18;
    struct s430* ebx19;
    uint8_t ah20;
    uint8_t* eax21;
    uint8_t* eax22;
    uint8_t dh23;
    struct s431* eax24;
    struct s432* ebp25;
    struct s433* ebp26;
    struct s434* eax27;
    int1_t zf28;
    struct s435* eax29;
    struct s436* ebp30;
    struct s437* ebp31;
    uint8_t ah32;
    struct s438* ebp33;
    struct s439* ebp34;
    int8_t dl35;
    struct s440* edx36;
    uint8_t dh37;
    struct s441* ebx38;
    struct s442* edx39;
    struct s443* edx40;
    uint8_t dh41;
    struct s444* edx42;
    struct s445* esi43;
    struct s446* ebx44;
    uint1_t zf45;
    struct s447* ebx46;
    uint1_t below_or_equal47;
    int8_t dl48;
    struct s448* esi49;
    struct s449* ebx50;
    struct s450* edx51;
    struct s451* edx52;
    int8_t bl53;
    struct s452* edx54;
    struct s453* edx55;
    uint8_t dh56;
    struct s454* edx57;
    struct s455* ebx58;
    int32_t eax59;
    int32_t eax60;
    int8_t dl61;
    struct s456* esi62;
    uint8_t* edx63;
    uint8_t* edx64;
    uint8_t dh65;
    int8_t dl66;

    esp2 = (int32_t*)__zero_stack_offset();
    ecx3 = (struct s421*)((int32_t)ecx - 1);
    asm("outsb");
    if (cf4 | (uint1_t)(ecx3 == 0)) {
        addr_0x40cd15_2:
        ebx5->f101 = 0;
        if (!__intrinsic()) {
            addr_0x40cd93_3:
            ebp6 = esi7->f103 * 0x61707320;
            asm("arpl [ebp+0x73], sp");
            edx8->f101 = (uint8_t)(edx9->f101 & dh10);
            asm("insd");
            asm("outsd");
            if (edx11->f101) {
                esi12->f114 = 0;
                asm("outsd");
                asm("insd");
                ebx13->f101 = 0;
                if (!__intrinsic()) {
                    addr_0x40ce27_6:
                    g20393720 = 0;
                    cf14 = 0;
                    asm("arpl [eax+0x61], bp");
                    if (0) 
                        goto 0x40ce94; else 
                        goto addr_0x40ce33_7;
                } else {
                    asm("outsd");
                    if (0) {
                        addr_0x40ce17_9:
                        *(uint8_t*)(ebp6 + 0x6e) = 0;
                        if (!*(uint8_t*)(ebp6 + 0x6e)) 
                            goto 0x40ce86; else 
                            goto addr_0x40ce1e_10;
                    } else {
                        *(int8_t*)(eax15 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax15 - 0x6f6f6f70) + dl16);
                        cf14 = __intrinsic();
                        sf17 = *(int8_t*)(eax15 - 0x6f6f6f70) < 0;
                        goto addr_0x40cdc4_12;
                    }
                }
            }
        } else {
            asm("outsd");
            if (0) {
                addr_0x40cd83_14:
                goto addr_0x40cd86_15;
            } else {
                ebx18->f104 = (uint8_t)(ebx19->f104 & ah20);
                asm("popad");
                if (0) {
                    addr_0x40cd86_15:
                    asm("insb");
                    asm("popad");
                    goto addr_0x40cd93_3;
                } else {
                    asm("arpl [ebp+0x72], si");
                    *eax21 = (uint8_t)(*eax22 & dh23);
                    sf17 = __intrinsic();
                    goto addr_0x40cd2b_18;
                }
            }
        }
    } else {
        asm("insb");
        esp2 = (int32_t*)(eax24->f110 * 0x65626d75);
        if (__intrinsic()) {
            addr_0x40ccdf_20:
            asm("outsd");
            ebp25->f110 = 0;
            if (!ebp26->f110) {
                goto addr_0x40cd52_22;
            }
        } else {
            asm("outsd");
            eax27->f105 = 0;
            cf14 = 0;
            zf28 = eax29->f105 == 0;
            sf17 = __intrinsic();
            if (1) {
                addr_0x40cd3a_24:
                goto addr_0x40cd42_25;
            } else {
                asm("outsd");
                if (0) {
                    addr_0x40cd2b_18:
                    if (sf17) 
                        goto addr_0x40cd52_22; else 
                        goto addr_0x40cd2d_27;
                } else {
                    asm("insd");
                    ebp30->f110 = (uint8_t)(ebp31->f110 & ah32);
                    cf14 = 0;
                    zf28 = ebp33->f110 == 0;
                    sf17 = __intrinsic();
                    if (zf28) {
                        addr_0x40cd42_25:
                        if (zf28) {
                            addr_0x40cdc4_12:
                            goto addr_0x40cdcb_29;
                        } else {
                            addr_0x40cd52_22:
                            asm("popad");
                            ebp6 = *(int32_t*)((int32_t)ecx3 + ebp6 * 2 + 0x6e) * 0x70732067;
                            goto addr_0x40cd55_30;
                        }
                    } else {
                        asm("arpl [ecx+0x66], bp");
                        esp2 = (int32_t*)(ebp34->f100 * 0x72657a00);
                        goto addr_0x40ccdf_20;
                    }
                }
            }
        }
    }
    addr_0x40ce0b_32:
    asm("outsd");
    if (0) 
        goto 0x40ce72;
    *(int8_t*)(eax15 + 0x7779656b) = (int8_t)(*(int8_t*)(eax15 + 0x7779656b) + dl35);
    asm("outsd");
    if (__intrinsic()) 
        goto 0x40ce7b; else 
        goto addr_0x40ce17_9;
    addr_0x40ce33_7:
    asm("arpl [ebp+0x72], si");
    goto addr_0x40ce36_34;
    addr_0x40ce1e_10:
    *(uint8_t*)(ebp6 + 0x75) = 0;
    if (1) 
        goto 0x40ce97;
    edx36->f101 = 0;
    ecx3->f0 = (uint8_t)(ecx3->f0 & dh37);
    goto addr_0x40ce27_6;
    ebx38->f101 = 0;
    if (!__intrinsic()) {
        goto addr_0x40cd66_38;
    }
    asm("outsd");
    if (!0) 
        goto addr_0x40ccf1_40;
    addr_0x40cd55_30:
    asm("popad");
    asm("arpl [ebp+0x73], sp");
    edx39->f101 = (uint8_t)(edx40->f101 & dh41);
    cf14 = 0;
    sf17 = __intrinsic();
    asm("insd");
    asm("outsd");
    if (!edx42->f101) {
        addr_0x40cdcb_29:
        if (sf17) 
            goto 0x40ce47;
    } else {
        addr_0x40cd66_38:
        esi43->f114 = 0;
        asm("outsd");
        asm("insd");
        ebx44->f101 = 0;
        zf45 = (uint1_t)(ebx46->f101 == 0);
        below_or_equal47 = (uint1_t)static_cast<uint32_t>(zf45);
        if (!__intrinsic()) {
            addr_0x40cde8_41:
            asm("insd");
            asm("outsd");
            if (below_or_equal47) 
                goto 0x40ce51; else 
                goto addr_0x40cdec_42;
        } else {
            asm("outsd");
            if (0) {
                addr_0x40cdd8_44:
                if (zf45) 
                    goto 0x40ce3f; else 
                    goto addr_0x40cdda_45;
            } else {
                *(int8_t*)(eax15 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax15 - 0x6f6f6f70) + dl48);
                goto addr_0x40cd83_14;
            }
        }
    }
    if (cf14) {
        addr_0x40ce36_34:
    } else {
        ecx3->f110 = 0;
        zf45 = (uint1_t)(ecx3->f110 == 0);
        goto addr_0x40cdd8_44;
    }
    addr_0x40cdec_42:
    esi49->f114 = 0;
    asm("outsd");
    asm("insd");
    ebx50->f101 = 0;
    if (!__intrinsic()) 
        goto 0x40ce6e;
    asm("outsd");
    if (0) 
        goto 0x40ce5e;
    edx51->f101 = (int8_t)(edx52->f101 + bl53);
    if (__intrinsic()) 
        goto 0x40ce6e; else 
        goto addr_0x40cdff_52;
    addr_0x40cdda_45:
    if (0) 
        goto 0x40ce45;
    asm("outsd");
    if (0) {
        addr_0x40cdff_52:
        *(uint8_t*)(ebp6 + 0x6e) = 0;
        if (!*(uint8_t*)(ebp6 + 0x6e)) 
            goto 0x40ce6e;
    } else {
        if (1) 
            goto 0x40ce51;
        asm("popad");
        asm("arpl [ebp+0x73], sp");
        edx54->f101 = (uint8_t)(edx55->f101 & dh56);
        below_or_equal47 = (uint1_t)static_cast<uint32_t>((uint1_t)(edx57->f101 == 0));
        goto addr_0x40cde8_41;
    }
    ebx58->f101 = 0;
    if (!__intrinsic()) 
        goto 0x40ce82; else 
        goto addr_0x40ce0b_32;
    addr_0x40ccf1_40:
    *(int8_t*)(eax59 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax60 - 0x6f6f6f70) + dl61);
    ebp6 = esi62->f118 * 0x64696c61;
    goto addr_0x40cd15_2;
    addr_0x40cd2d_27:
    *edx63 = (uint8_t)(*edx64 ^ dh65);
    eax15 = *esp2;
    *(int8_t*)(eax15 - 0x6f6f6f70) = (int8_t)(*(int8_t*)(eax15 - 0x6f6f6f70) + dl66);
    cf14 = __intrinsic();
    zf28 = *(int8_t*)(eax15 - 0x6f6f6f70) == 0;
    sf17 = *(int8_t*)(eax15 - 0x6f6f6f70) < 0;
    goto addr_0x40cd3a_24;
}

void fun_40ce8e() {
}

void fun_40d09e() {
}

struct s457 {
    int8_t[84] pad84;
    uint8_t f84;
};

struct s458 {
    int8_t[84] pad84;
    uint8_t f84;
};

struct s459 {
    int8_t[84] pad84;
    int8_t f84;
};

void fun_40d1c4(struct s10* ecx) {
    int32_t ebp2;
    struct s457* edx3;
    struct s458* edx4;
    uint8_t bh5;
    struct s459* edx6;

    asm("insd");
    if (__intrinsic()) 
        goto 0x40d23c;
    if (ebp2 + 1 >= 0) 
        goto 0x40d1ea;
    asm("outsd");
    if (__intrinsic()) 
        goto 0x40d235;
    ecx->f110 = 0;
    edx3->f84 = (uint8_t)(edx4->f84 & bh5);
    if (!edx6->f84) 
        goto 0x40d1fa;
    asm("arpl [eax+0x75], bp");
    asm("outsb");
}

struct s460 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s461 {
    int8_t[116] pad116;
    int32_t f116;
};

struct s462 {
    int8_t[101] pad101;
    int32_t f101;
};

struct s463 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s464 {
    int8_t[104] pad104;
    int8_t f104;
};

void fun_40d3b0(void* ecx) {
    int1_t cf2;
    struct s460* esi3;
    struct s461* eax4;
    int1_t cf5;
    int32_t edi6;
    struct s462* edx7;
    uint8_t dh8;
    struct s463* ebx9;
    struct s464* ebx10;

    asm("outsb");
    if (!cf2) {
        asm("arpl [edi+0x67], bp");
        asm("outsb");
        esi3 = (struct s460*)(eax4->f116 * 0x20657079);
        cf5 = __intrinsic();
        asm("outsw");
        if (cf5) {
            addr_0x40d3eb_3:
            goto addr_0x40d3f0_4;
        } else {
            asm("outsd");
            esi3 = (struct s460*)((int32_t)esi3 + 1 + 1);
            if (!cf5) {
                addr_0x40d3f0_4:
                asm("outsb");
                if (cf5) 
                    goto 0x40d459;
            } else {
                asm("arpl [eax+0x75], bp");
                asm("outsb");
                cf5 = __intrinsic();
                goto addr_0x40d3eb_3;
            }
        }
        asm("arpl [edi+0x67], bp");
        asm("outsb");
        edi6 = edx7->f101 * 0x71652064;
        if (!__undefined()) 
            goto 0x40d462;
        if (__undefined()) 
            goto 0x40d46c;
        asm("outsd");
        asm("outsb");
        *(uint8_t*)((int32_t)ecx + edi6 * 2 + 0x70) = (uint8_t)(*(uint8_t*)((int32_t)ecx + edi6 * 2 + 0x70) & dh8);
        esi3->f111 = 0;
        if (0) 
            goto 0x40d42f;
        if (0) 
            goto 0x40d454;
        ebx9->f104 = 0;
        if (ebx10->f104) 
            goto 0x40d486;
    }
}

struct s465 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s466 {
    int8_t[104] pad104;
    int8_t f104;
};

void fun_40dc30() {
    int1_t cf1;
    uint1_t cf2;
    void* ecx3;
    void* ebp4;
    void* ecx5;
    uint8_t dh6;
    struct s465* ebx7;
    struct s466* ebx8;

    asm("outsb");
    if (cf1) 
        goto 0x40dc99;
    asm("arpl [edi+0x67], bp");
    asm("outsb");
    cf2 = __intrinsic();
    asm("outsw");
    if (cf2) {
        addr_0x40dc6b_3:
        goto addr_0x40dc70_4;
    } else {
        if (__intrinsic()) {
            addr_0x40dc95_6:
        } else {
            ecx3 = ebp4;
            if (!cf2) {
                addr_0x40dc70_4:
                ecx5 = (void*)((int32_t)ecx3 - 1);
                asm("outsb");
                if (cf2 | (uint1_t)(ecx5 == 0)) 
                    goto 0x40dcd5;
            } else {
                asm("arpl [eax+0x75], bp");
                asm("outsb");
                cf2 = __intrinsic();
                goto addr_0x40dc6b_3;
            }
        }
    }
    asm("insb");
    if (!__intrinsic()) 
        goto 0x40dcef;
    asm("arpl [gs:ecx+0x66], bp");
    *(uint8_t*)((int32_t)ecx5 + (int32_t)ecx5 * 2 + 77) = (uint8_t)(*(uint8_t*)((int32_t)ecx5 + (int32_t)ecx5 * 2 + 77) & dh6);
    ebx7->f104 = 0;
    if (ebx8->f104) 
        goto 0x40dd02;
    goto addr_0x40dc95_6;
}

void fun_40de22() {
}

void fun_40e051() {
}

void fun_40f0ae() {
}

void fun_410b42() {
}

void fun_410c2e() {
}

void fun_410eda() {
}

struct s467 {
    int8_t[18] pad18;
    int8_t f18;
};

struct s468 {
    int8_t[18] pad18;
    int8_t f18;
};

struct s469 {
    int8_t[1] pad1;
    int8_t f1;
};

struct s470 {
    int8_t[19] pad19;
    int8_t f19;
};

struct s471 {
    int8_t[19] pad19;
    int8_t f19;
};

struct s472 {
    int8_t[402669589] pad402669589;
    int8_t f402669589;
};

struct s473 {
    int8_t[20] pad20;
    void* f20;
};

struct s474 {
    int8_t[21] pad21;
    int8_t f21;
};

struct s475 {
    int8_t[21] pad21;
    int8_t f21;
};

struct s476 {
    int8_t[23] pad23;
    int8_t f23;
};

int8_t g110;

int32_t g41d154 = 0x75494b20;

int32_t g424340 = 0;

int32_t g424344 = 0;

int32_t g41d158 = 0x754b9600;

int32_t g41d15c = 0x754975f0;

struct s477 {
    int8_t[4] pad4;
    int8_t f4;
};

int32_t g41d030 = 0x751a58c0;

int32_t g424348 = 0;

int32_t g41d040 = 0x76cc4db0;

int32_t g41d044 = 0x76cc5490;

int32_t g41d048 = 0x76d054a0;

int32_t g41d038 = 0x76d08210;

int32_t g41d03c = 0x76cc6990;

int32_t g41d04c = 0x76d08270;

int32_t g41d160 = 0x75493bb0;

int32_t g41d164 = 0x7550b340;

int32_t g41d0f4 = 0x76cc4d50;

int32_t g41d168 = 0x754ac7e0;

int32_t g41d16c = 0x754948c0;

int32_t g41d170 = 0x7549b980;

int32_t g41d058 = 0x76d05680;

int32_t g41d100 = 0x76cc1d30;

int32_t g41d174 = 0x75498ba0;

void fun_401871(void* ecx) {
    uint104_t v2;
    uint32_t* eax3;
    int32_t* eax4;
    int32_t eax5;
    uint1_t cf6;
    struct s467* ecx7;
    int32_t* eax8;
    int8_t bl9;
    struct s468* eax10;
    void* eax11;
    struct s469* eax12;
    struct s470* ebx13;
    struct s471* ebx14;
    int8_t* eax15;
    struct s472* edx16;
    void* edx17;
    struct s473* esi18;
    int8_t bh19;
    int8_t* ebx20;
    int8_t* ebx21;
    struct s474* ebp22;
    struct s475* ebp23;
    int16_t ss24;
    uint32_t eax25;
    uint8_t* eax26;
    int8_t bl27;
    uint8_t** edi28;
    int16_t ss29;
    struct s476* eax30;
    int16_t ss31;
    int32_t* eax32;
    int32_t ebx33;
    int32_t ebx34;
    uint32_t eax35;
    int1_t zf36;
    int32_t eax37;
    int32_t v38;
    int32_t v39;
    int32_t v40;
    int32_t ecx41;
    int32_t esi42;
    int32_t edx43;
    int32_t v44;
    int8_t* esi45;
    int8_t* v46;
    int8_t** esp47;
    int32_t ebp48;
    int8_t* v49;
    void* esp50;
    void* edi51;
    void* v52;
    uint32_t v53;
    void* ebx54;
    void* v55;
    uint32_t v56;
    int8_t* v57;
    int8_t* v58;
    int8_t* eax59;
    int8_t* v60;
    void* esp61;
    int8_t* edx62;
    int8_t* v63;
    int8_t* v64;
    int8_t* eax65;
    void* esp66;
    int8_t* eax67;
    int8_t* eax68;
    int8_t* ecx69;
    int32_t v70;
    struct s477* esi71;
    int8_t* edx72;
    int8_t* eax73;
    void* v74;
    uint32_t v75;
    int8_t* v76;
    int8_t* v77;
    int8_t* v78;
    int32_t edi79;
    int32_t eax80;
    int32_t eax81;
    int32_t eax82;
    void* esp83;
    int8_t* ecx84;
    int8_t* v85;
    int8_t* v86;
    void* esp87;
    int8_t* v88;
    int8_t* v89;
    int8_t* eax90;
    void* esp91;
    int8_t* v92;
    int8_t* eax93;
    int8_t* v94;
    int8_t* v95;
    int8_t* eax96;
    void* esp97;
    int8_t* ebp98;
    int8_t* v99;
    int8_t* v100;
    int8_t* v101;
    void* esp102;
    int8_t* v103;
    void* esp104;
    int8_t* v105;
    uint32_t eax106;
    void* esp107;
    int32_t ebx108;
    int8_t* v109;
    void* esp110;
    int8_t** esp111;
    int8_t* v112;
    int8_t* v113;
    int8_t* v114;
    int8_t* v115;
    int8_t* ebp116;
    int8_t* ebx117;
    int8_t* v118;
    int8_t* v119;
    int8_t* v120;
    int8_t* v121;
    int8_t* v122;
    int8_t* v123;
    int8_t* v124;
    int8_t* v125;
    int8_t* v126;
    int8_t* v127;
    int8_t* v128;
    int8_t* v129;
    int8_t* v130;
    int8_t* v131;
    void* esp132;
    int8_t* v133;
    int8_t* v134;
    void* esp135;
    int8_t** esp136;
    int8_t* v137;
    int8_t* edi138;
    int8_t* v139;
    void* esp140;
    int8_t** esp141;
    int8_t* v142;
    int8_t* v143;
    int8_t* v144;
    int8_t* v145;
    int8_t* v146;
    int8_t* v147;
    int8_t* v148;
    int8_t* v149;
    int8_t* v150;
    int8_t* v151;
    void* esp152;
    int8_t* v153;
    void* esp154;
    int8_t* v155;
    int8_t* v156;
    void* esp157;
    int8_t* v158;
    int8_t* v159;
    void* esp160;
    int8_t* edi161;
    void* esp162;
    void* esp163;
    int8_t** esp164;
    int32_t eax165;
    void* esp166;
    int32_t eax167;
    int32_t* esp168;
    void* esp169;
    int8_t** esp170;
    int8_t* v171;
    int8_t* v172;
    int32_t eax173;
    int8_t* v174;
    int32_t eax175;
    int32_t eax176;
    int32_t edi177;
    int32_t eax178;
    int32_t ebx179;
    int32_t ecx180;
    int32_t eax181;
    int32_t edx182;
    int32_t eax183;
    int32_t v184;

    *(int32_t*)((int32_t)&v2 + 6) = (int32_t)__return_address();
    *eax3 = *eax4 + eax5 + cf6;
    ecx7 = (struct s467*)((int32_t)ecx - 1);
    if (!((uint1_t)!!ecx7 & (uint1_t)!!*eax8)) {
        ecx7->f18 = (int8_t)(ecx7->f18 + bl9);
        eax10 = (struct s468*)((int32_t)eax11 + 1 + 1);
        eax10->f18 = (int8_t)(eax10->f18 + *(int8_t*)&ecx7);
        eax12 = (struct s469*)((int32_t)eax10 + 1);
        ebx13->f19 = (int8_t)(ebx14->f19 + *(int8_t*)&eax12);
        eax15 = &eax12->f1;
        *eax15 = (int8_t)(*eax15 + *(int8_t*)&eax15);
        *(int32_t*)((int32_t)__zero_stack_offset() + (int32_t)eax15) = *(int32_t*)((int32_t)__zero_stack_offset() + (int32_t)eax15) + (int32_t)eax15;
    }
    *(int8_t*)&eax15 = (int8_t)((int8_t)((int8_t)((int8_t)((int8_t)(*(int8_t*)&eax15 + 4) + 4) + 4) + 4) + 4);
    *(int8_t*)&eax15 = (int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)((int8_t)(*(int8_t*)&eax15 + *(int8_t*)((int32_t)__zero_stack_offset() + (int32_t)eax15)) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4) + 4);
    edx16 = (struct s472*)((int32_t)edx17 + (int32_t)esi18->f20);
    *(int8_t*)((int32_t)__zero_stack_offset() + (int32_t)edx16 + 0x14f90040) = (int8_t)(*(int8_t*)((int32_t)__zero_stack_offset() + (int32_t)edx16 + 0x14f90040) + bh19);
    *ebx20 = (int8_t)(*ebx21 + *(int8_t*)((int32_t)&edx16 + 1));
    ebp22->f21 = (int8_t)(ebp23->f21 + *(int8_t*)((int32_t)&ecx7 + 1));
    *(int8_t*)((int32_t)edx16 + 0x18004015) = (int8_t)(*(int8_t*)((int32_t)edx16 + 0x18004015) + *(int8_t*)((int32_t)&ecx7 + 1));
    *(int16_t*)((int32_t)&v2 + 4) = ss24;
    eax25 = (int32_t)(eax15 + 1 + 1 + 0x156d0040) + __intrinsic() + 1 + 1 + 1;
    eax26 = (uint8_t*)(eax25 + 0x14900040 + __intrinsic() + 1);
    *eax26 = (uint8_t)(*eax26 + bl27);
    *eax26 = (uint8_t)(*eax26 - (uint8_t)(*(int8_t*)&eax26 + (uint1_t)(*eax26 < (uint8_t)(*(int8_t*)&eax26 + __intrinsic()))));
    *edi28 = eax26;
    *(int16_t*)((int32_t)&v2 + 2) = ss29;
    eax30 = (struct s476*)(eax26 + 1);
    eax30->f23 = (int8_t)(eax30->f23 + *(int8_t*)((int32_t)&ecx7 + 1));
    *(int16_t*)&v2 = ss31;
    eax32 = (int32_t*)((uint32_t)eax30 + 1 + 1);
    *(int8_t*)(ebx33 - 0x7ef7dbbc) = (int8_t)(*(int8_t*)(ebx34 - 0x7ef7dbbc) + (int8_t)(*(int8_t*)&ecx7 + *(int8_t*)((int32_t)&eax25 + 1)));
    asm("in al, dx");
    eax35 = (uint32_t)eax32 + *eax32;
    g110 = (int8_t)(g110 + *(int8_t*)((int32_t)&ecx7 + 1));
    zf36 = g110 == 0;
    if (!zf36) {
        if (eax35 - 1 || (eax37 = v38, *(int16_t*)&eax37 != 1) && *(int16_t*)&eax37 != 2) {
            goto v39;
        } else {
            g41d154(v40, 1);
            ecx41 = g424340;
            esi42 = g41d028;
            esi42(ecx41, v40, 1);
            edx43 = g424344;
            esi42(edx43, ecx41, v40, 1);
            esi42();
            goto v44;
        }
    }
    esi45 = v46;
    esp47 = (int8_t**)((int32_t)__zero_stack_offset() - 2 - 2 - 2 + 1 - 4 - 4 - 4);
    ebp48 = g41d1a4;
    v49 = esi45;
    ebp48();
    esp50 = (void*)(esp47 - 1 - 1 - 1 - 1 + 1);
    edi51 = (void*)((int32_t)v52 - v53);
    ebx54 = (void*)((int32_t)v55 - v56);
    v57 = (int8_t*)((int32_t)esp50 + 52);
    v58 = esi45;
    eax59 = (int8_t*)g41d158(v58);
    v60 = eax59;
    ebp48(v60, v58);
    esp61 = (void*)((int32_t)esp50 - 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4);
    edx62 = v63;
    v64 = (int8_t*)((int32_t)esp61 + 32);
    eax65 = (int8_t*)g41d15c(48, 16, v64, 0, v60, v58);
    esp66 = (void*)((int32_t)esp61 - 4 - 4 - 4 - 4 + 4);
    if (!eax65) {
        v57 = eax65;
        g41d180(eax65, 48, 16, v64, 0, v60, v58);
        eax67 = (int8_t*)g41d180(1, eax65, 48, 16, v64, 0, v60, v58);
        esp66 = (void*)((int32_t)esp66 - 4 - 4 + 4 - 4 - 4 + 4);
        v49 = eax67;
    }
    asm("cdq");
    eax68 = v57;
    ecx69 = (int8_t*)(((int32_t)(v70 - (uint32_t)edx62 - (uint32_t)edi51 - (uint32_t)edx62) >> 1) + (uint32_t)&esi71->f4);
    if ((int32_t)ecx69 >= (int32_t)eax68) 
        goto addr_0x401a55_13;
    addr_0x401a62_14:
    ecx69 = eax68;
    goto addr_0x401a64_15;
    addr_0x401a55_13:
    edx62 = (int8_t*)((uint32_t)ecx69 + (uint32_t)edi51);
    if ((int32_t)edx62 <= (int32_t)(esp47 + 16)) {
        addr_0x401a64_15:
        asm("cdq");
        edx72 = v49;
        eax73 = (int8_t*)(((int32_t)(4 - (uint32_t)ebx54 - (uint32_t)edx62) >> 1) + (uint32_t)*(int8_t**)((int32_t)&v2 + 1));
        if ((int32_t)eax73 < (int32_t)edx72) {
            addr_0x401a8a_16:
            eax73 = edx72;
            goto addr_0x401a8c_17;
        } else {
            if ((int32_t)((uint32_t)eax73 + (uint32_t)ebx54) <= (int32_t)((int32_t)v74 - v75)) {
                addr_0x401a8c_17:
                v76 = eax73;
                v77 = ecx69;
                v78 = esi45;
                g41d1a8(v78, 0, v77, v76, 0, 0, 5, 48, 16, v64, 0, v60, v58);
                edi79 = g41d030;
                eax80 = (int32_t)edi79(14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58);
                g424340 = eax80;
                eax81 = (int32_t)edi79(32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58);
                g424348 = eax81;
                eax82 = (int32_t)edi79(12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58);
                esp83 = (void*)((int32_t)esp66 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4);
                ecx84 = g42454c;
                g424344 = eax82;
                v85 = (int8_t*)((int32_t)esp83 + 0x254);
                v86 = ecx84;
                g41d040(v86);
                esp87 = (void*)((int32_t)esp83 - 4 - 4 - 4 - 4 + 4);
                v88 = (int8_t*)((int32_t)esp87 + 24);
                v89 = (int8_t*)((int32_t)esp87 + 0x254);
                eax90 = fun_4021cc(v89, v88, v86);
                esp91 = (void*)((int32_t)esp87 - 4 - 4 - 4 + 4);
                if (eax90) {
                    v92 = eax90;
                    eax93 = (int8_t*)g41d044(2, v92, v89, v88, v86);
                    v94 = eax93;
                    v95 = eax93;
                    eax96 = (int8_t*)g41d048(v94, 2, v92, v89, v88, v86);
                    esp97 = (void*)((int32_t)esp91 - 4 - 4 - 4 + 4 - 4 - 4 + 4);
                    ebp98 = eax96;
                    v99 = ebp98;
                    v100 = eax90;
                    v101 = v85;
                    fun_4021c6((int32_t)esp97 + 0x254, v101, v100, v99, v94, 2, v92, v89, v88, v86);
                    esp102 = (void*)((int32_t)esp97 - 4 - 4 - 4 - 4 - 4 + 4);
                    v103 = (int8_t*)((int32_t)esp102 + 0x154);
                    g41d038(v103, 0x420248, (int32_t)esp97 + 0x254, v101, v100, v99, v94, 2, v92, v89, v88, v86);
                    esp104 = (void*)((int32_t)esp102 - 4 - 4 - 4 + 4);
                    v105 = (int8_t*)((int32_t)esp104 + 0x154);
                    eax106 = (uint32_t)g41d03c(v105, v103, 0x420248, (int32_t)esp97 + 0x254, v101, v100, v99, v94, 2, v92, v89, v88, v86);
                    esp107 = (void*)((int32_t)esp104 - 4 - 4 + 4);
                    ebx108 = g41d04c;
                    v109 = (int8_t*)((int32_t)esp107 + 0x154);
                    ebx108();
                    esp110 = (void*)((int32_t)esp107 - 4 - 4 - 4 + 4);
                    esp111 = (int8_t**)((int32_t)esp110 - 4);
                    v112 = (int8_t*)((int32_t)esp110 + 20);
                    v113 = (int8_t*)((int32_t)esp110 + 16);
                    v114 = (int8_t*)(esp111 + 86);
                    v115 = ebp98;
                    fun_4021c0(v115, v114, v113, v112, v109, 0x42023c, v105, v103, 0x420248, (int32_t)esp97 + 0x254, v101, v100, v99, v94, 2, v92, v89, v88, v86, v85, 0x100, 12, 0, 0, 0, 0, v95, 0, 0, 0, 0, 0, 0, 34, 0x424350, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58, 4, v57, v49, esp47 + 16, (int32_t)v74 - v75, ebp116, ebx117, &esi71->f4, *(int8_t**)((int32_t)&v2 + 1), *(int8_t**)((int32_t)&v2 + 5), *(int8_t**)((int32_t)&v2 + 9), v118, v119, v120, v121, v122, v123, v124, v125, v126, v127, v128, v129, v130, v131);
                    esp132 = (void*)(esp111 - 1 - 1 - 1 - 1 + 1);
                    v133 = v109;
                    v134 = (int8_t*)((int32_t)esp132 + 84);
                    g41d038(v134, v133, v115, v114, v113, v112);
                    esp135 = (void*)((int32_t)esp132 - 4 - 4 - 4 + 4);
                    esp136 = (int8_t**)((int32_t)esp135 - 4 - 4);
                    v137 = (int8_t*)((int32_t)esp135 + 0x154);
                    edi138 = (int8_t*)((int32_t)esp136 + (eax106 & 0xffff) + 0x15c);
                    v139 = edi138;
                    *edi138 = 0;
                    ebx108(v137, 0x42022c, v134, v133, v115, v114, v113, v112);
                    esp140 = (void*)(esp136 - 1 + 1);
                    esp141 = (int8_t**)((int32_t)esp140 - 4);
                    v142 = (int8_t*)((int32_t)esp140 + 20);
                    v143 = (int8_t*)((int32_t)esp140 + 16);
                    v144 = (int8_t*)(esp141 + 86);
                    v145 = ebp98;
                    fun_4021c0(v145, v144, v143, v142, v137, 0x42022c, v134, v133, v115, v114, v113, v112, v109, 0x42023c, v105, v103, 0x420248, v139, v101, v100, v99, v94, 2, v92, v89, v88, v86, v85, 0x100, 12, 0, 0, 0, 0, v95, 0, 0, 0, 0, 0, 0, 34, 0x424350, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58, 4, v57, v49, esp47 + 16, (int32_t)v74 - v75, ebp116, ebx117, &esi71->f4, *(int8_t**)((int32_t)&v2 + 1), *(int8_t**)((int32_t)&v2 + 5), *(int8_t**)((int32_t)&v2 + 9), v146, v147, v148, v149, v150, v151);
                    esp152 = (void*)(esp141 - 1 - 1 - 1 - 1 + 1);
                    v153 = (int8_t*)((int32_t)esp152 + 84);
                    ebx108(v153, 0x420228);
                    esp154 = (void*)((int32_t)esp152 - 4 - 4 - 4 + 4);
                    v155 = v143;
                    v156 = (int8_t*)((int32_t)esp154 + 84);
                    ebx108(v156, v155, v153, 0x420228);
                    esp157 = (void*)((int32_t)esp154 - 4 - 4 - 4 + 4);
                    v158 = (int8_t*)((int32_t)esp157 + 84);
                    v159 = esi45;
                    g41d160(v159, 0x193, v158, v156, v155, v153, 0x420228);
                    esp160 = (void*)((int32_t)esp157 - 4 - 4 - 4 - 4 + 4);
                    edi161 = (int8_t*)0x190;
                    do {
                        g41d164(esi45, edi161, (int32_t)esp160 + 84, 0x100, v159, 0x193, v158, v156, v155, v153, 0x420228);
                        esp162 = (void*)((int32_t)esp160 - 4 - 4 - 4 - 4 - 4 + 4);
                        *v145 = 0;
                        ebx108();
                        esp163 = (void*)((int32_t)esp162 - 4 - 4 - 4 + 4);
                        esp164 = (int8_t**)((int32_t)esp163 - 4);
                        eax165 = fun_4021c0(ebp98, esp164 + 86, (int32_t)esp163 + 16, (int32_t)esp163 + 20, (int32_t)esp162 + 0x154, (int32_t)esp162 + 84, esi45, edi161, 0, 0, v159, 0x193, v158, v156, v155, v153, 0x420228, v145, v144, v143, v142, v137, 0x42022c, v134, v133, v115, v114, v113, v112, v109, 0x42023c, v105, v103, 0x420248, v139, v101, v100, v99, v94, 2, v92, v89, v88, v86, v85, 0x100, 12, 0, 0, 0, 0, v95, 0, 0, 0, 0, 0, 0, 34, 0x424350, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0x424350, v78, 0, v77, v76, 0, 0, 0, 48, 16, v64, 0, v60, v58);
                        esp166 = (void*)(esp164 - 1 - 1 - 1 - 1 + 1);
                        if (!eax165 || (!((int32_t)esp162 + 84) || !((int32_t)esp162 + 0x154))) {
                            eax167 = (int32_t)g41d0f4(ebp98, esp164 + 86, (int32_t)esp163 + 16);
                            esp168 = (int32_t*)((int32_t)esp166 - 4 + 4 - 4);
                            g41d168(esp168 + 22, "Error %lu", eax167, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                            esp169 = (void*)(esp168 - 1 - 1 - 1 + 1 + 3);
                            esp170 = (int8_t**)((int32_t)esp169 - 4);
                            v171 = (int8_t*)((int32_t)esp169 + 84);
                        } else {
                            v171 = (int8_t*)((int32_t)esp162 + 0x154);
                            g41d038((int32_t)esp166 + 84, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                            esp170 = (int8_t**)((int32_t)esp166 - 4 - 4 - 4 + 4 - 4);
                        }
                        v172 = edi161;
                        g41d160(esi45, v172, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                        eax173 = g424344;
                        if (edi161 != 0x192) {
                            eax173 = g424340;
                        }
                        v174 = edi161;
                        eax175 = (int32_t)g41d16c(esi45, v174, 48, eax173, 1, esi45, v172, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                        g41d170(eax175, esi45, v174, 48, eax173, 1, esi45, v172, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                        esp160 = (void*)(esp170 - 1 - 1 - 1 + 1 - 1 - 1 - 1 - 1 - 1 - 1 + 1 - 1 - 1 + 1);
                        ++edi161;
                    } while ((int32_t)edi161 <= (int32_t)0x192);
                    g41d058((int32_t)esp163 + 20, eax175, esi45, v174, 48, eax173, 1, esi45, v172, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                    g41d100((int32_t)esp163 + 20, (int32_t)esp163 + 20, eax175, esi45, v174, 48, eax173, 1, esi45, v172, v171, ebp98, esp164 + 86, (int32_t)esp163 + 16);
                    esp91 = (void*)((int32_t)esp160 - 4 - 4 + 4 - 4 - 4 + 4);
                }
            } else {
                edx72 = (int8_t*)((int32_t)v74 - v75 - (uint32_t)ebx54);
                goto addr_0x401a8a_16;
            }
        }
    } else {
        eax68 = (int8_t*)((uint32_t)(esp47 + 16) - (uint32_t)edi51);
        goto addr_0x401a62_14;
    }
    eax176 = g424340;
    edi177 = g41d16c;
    eax178 = (int32_t)edi177(esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    ebx179 = g41d170;
    ebx179(eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    ecx180 = g424348;
    eax181 = (int32_t)edi177(esi45, 1, 48, ecx180, 1, eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    ebx179(eax181, esi45, 1, 48, ecx180, 1, eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    edx182 = g424340;
    eax183 = (int32_t)edi177(esi45, 0x193, 48, edx182, 1, eax181, esi45, 1, 48, ecx180, 1, eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    ebx179(eax183, esi45, 0x193, 48, edx182, 1, eax181, esi45, 1, 48, ecx180, 1, eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    fun_401db0((int32_t)esp91 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 - 4 - 4 - 4 - 4 - 4 - 4 + 4 - 4 - 4 + 4 + 84, 68, eax183, esi45, 0x193, 48, edx182, 1, eax181, esi45, 1, 48, ecx180, 1, eax178, esi45, 0x194, 48, eax176, 1, v89, v88, v86);
    edi177();
    g41d174();
    goto v184;
}

int32_t cb2_read_chunk_of_size(void* a1, uint32_t a2, void*** a3) {
    void** v4;
    int32_t eax5;

    v4 = *a3;
    eax5 = read_bytes(a1, 1, a2 & 0xffff, v4);
    return eax5;
}

struct s478 {
    int16_t f0;
    int8_t f2;
    int8_t f3;
    int8_t f4;
    int8_t f5;
    int8_t f6;
};

struct s479 {
    int8_t f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    int8_t f8;
    int8_t[3] pad12;
    int8_t f12;
    int8_t[3] pad16;
    int8_t f16;
    int8_t[3] pad20;
    uint16_t f20;
};

void fun_404a64(struct s478* a1, struct s479* a2) {
    uint32_t eax3;

    eax3 = a2->f20 + 0x76c;
    a1->f0 = *(int16_t*)&eax3;
    a1->f2 = (int8_t)(a2->f16 + 1);
    a1->f3 = a2->f12;
    a1->f4 = a2->f8;
    a1->f5 = a2->f4;
    a1->f6 = a2->f0;
    return;
}

struct s480 {
    int8_t[84] pad84;
    int32_t f84;
};

int32_t fun_4074e4(struct s480* a1) {
    return a1->f84;
}

struct s481 {
    int8_t[108] pad108;
    uint8_t f108;
    int8_t[83] pad192;
    int32_t f192;
};

void fun_404cec(struct s481* a1, int32_t a2) {
    a1->f108 = (uint8_t)(a1->f108 | 4);
    a1->f192 = a2;
    return;
}

void fun_402931(int32_t a1) {
}

void** fun_402a52(void** a1, int32_t a2, void** a3) {
    void** eax4;

    eax4 = fun_417e00(a1, a2, a3);
    return eax4;
}

struct s482 {
    int8_t[96] pad96;
    int32_t f96;
};

int32_t fun_4090b4(struct s482* a1) {
    return a1->f96;
}

void fun_40908a() {
}

void fun_404dc8() {
    fun_404ef4(__return_address(), fun_4034f9, 0, 0);
    return;
}

void fun_40686d() {
}

void fun_40730e() {
}

void fun_407379() {
}

int32_t fun_407546(int32_t a1) {
    if (a1) 
        goto 0x407558;
    return "1.2.1";
}

void fun_40766e() {
}

void fun_4083fc(int32_t a1) {
}

struct s483 {
    uint32_t f0;
    int8_t[4] pad8;
    uint8_t f8;
    int8_t f9;
};

struct s484 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
    int8_t f3;
    int8_t[2] pad6;
    int8_t f6;
    int8_t[2] pad9;
    int8_t f9;
};

struct s485 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

struct s486 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

struct s487 {
    int8_t f0;
    int8_t[1] pad2;
    int8_t f2;
};

void fun_408c1c(struct s483* a1, struct s484* a2) {
    uint32_t ebp3;
    uint32_t edi4;
    struct s484* ebx5;
    uint32_t eax6;
    int8_t dl7;
    int8_t dl8;
    struct s485* edx9;
    int8_t cl10;
    struct s486* edx11;
    int8_t cl12;
    struct s487* edx13;
    int8_t cl14;
    int8_t dl15;
    int8_t dl16;

    if (!(a1->f8 & 2)) 
        goto 0x408f85;
    ebp3 = a1->f0;
    if (a1->f9 != 8) 
        goto 0x408d90;
    if (a1->f8 != 2) 
        goto 0x408ce8;
    edi4 = 0;
    ebx5 = a2;
    if (0 >= ebp3) 
        goto 0x408f85;
    eax6 = ebp3 & 3;
    if ((uint1_t)((int32_t)ebp3 < (int32_t)0) | (uint1_t)(ebp3 == 0)) {
        addr_0x408c88_6:
        dl7 = ebx5->f0;
        ebx5->f0 = ebx5->f2;
        ebx5->f2 = dl7;
        ++edi4;
        ebx5 = (struct s484*)&ebx5->f3;
        if (edi4 >= ebp3) 
            goto 0x408f85;
    } else {
        if (!eax6) {
            do {
                addr_0x408ca0_8:
                dl8 = ebx5->f0;
                ebx5->f0 = ebx5->f2;
                ebx5->f2 = dl8;
                edx9 = (struct s485*)&ebx5->f3;
                cl10 = ebx5->f3;
                ebx5->f3 = edx9->f2;
                edx9->f2 = cl10;
                edx11 = (struct s486*)&ebx5->f6;
                cl12 = ebx5->f6;
                ebx5->f6 = edx11->f2;
                edx11->f2 = cl12;
                edx13 = (struct s487*)&ebx5->f9;
                cl14 = ebx5->f9;
                ebx5->f9 = edx13->f2;
                edx13->f2 = cl14;
                edi4 = edi4 + 4;
                ebx5 = (struct s484*)((int32_t)ebx5 + 12);
            } while (edi4 < ebp3);
            goto addr_0x408ce1_9;
        } else {
            if ((int32_t)eax6 > (int32_t)1) {
                if ((int32_t)eax6 > (int32_t)2) {
                    dl15 = a2->f0;
                    a2->f0 = a2->f2;
                    a2->f2 = dl15;
                    edi4 = 1;
                    ebx5 = (struct s484*)&a2->f3;
                }
                dl16 = ebx5->f0;
                ebx5->f0 = ebx5->f2;
                ebx5->f2 = dl16;
                ++edi4;
                ebx5 = (struct s484*)&ebx5->f3;
                goto addr_0x408c88_6;
            }
        }
    }
    goto addr_0x408ca0_8;
    addr_0x408ce1_9:
    goto 0x408f85;
}

struct s488 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t f3;
};

void fun_410c98(struct s488* a1, int32_t a2) {
    int32_t edx3;
    int32_t eax4;
    int32_t eax5;
    int32_t eax6;

    edx3 = a2;
    eax4 = edx3 >> 24;
    a1->f0 = *(int8_t*)&eax4;
    eax5 = edx3 >> 16;
    a1->f1 = *(int8_t*)&eax5;
    eax6 = edx3 >> 8;
    a1->f2 = *(int8_t*)&eax6;
    a1->f3 = *(int8_t*)&edx3;
    return;
}

struct s489 {
    int8_t[102] pad102;
    int32_t f102;
};

struct s490 {
    int8_t[72] pad72;
    uint8_t f72;
};

struct s491 {
    int8_t[72] pad72;
    uint8_t f72;
};

struct s493 {
    int8_t[32] pad32;
    int32_t f32;
    int8_t[59] pad95;
    int32_t f95;
    int8_t[1] pad100;
    int32_t f100;
};

struct s492 {
    int32_t f0;
    int8_t[72] pad76;
    struct s493* f76;
};

struct s494 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s495 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s496 {
    int32_t f0;
    void** f4;
    int8_t[3] pad8;
    void** f8;
    int8_t[3] pad12;
    void** f12;
    int8_t[3] pad16;
    void** f16;
    int8_t[3] pad20;
    void** f20;
    int8_t[3] pad24;
    void** f24;
    int8_t[3] pad28;
    void** f28;
    int8_t[3] pad32;
    void** f32;
    int8_t[3] pad36;
    void** f36;
    int8_t[3] pad40;
    void** f40;
    int8_t[3] pad44;
    void** f44;
    int8_t[3] pad48;
    void** f48;
    int8_t[3] pad52;
    void** f52;
    int8_t[3] pad56;
    void** f56;
};

struct s497 {
    int8_t[72] pad72;
    uint8_t f72;
};

struct s498 {
    int8_t[108] pad108;
    uint8_t f108;
};

struct s499 {
    int8_t[108] pad108;
    int8_t f108;
};

struct s500 {
    int32_t f0;
    uint32_t f4;
    int32_t f8;
    void** f12;
    int8_t[3] pad16;
    void* f16;
    void** f20;
    int8_t[3] pad24;
    int32_t f24;
};

struct s501 {
    int32_t f0;
    int8_t[12] pad16;
    int8_t f16;
    int8_t f17;
    int8_t f18;
    int8_t f19;
    int8_t f20;
    int8_t f21;
    int8_t f22;
    int8_t f23;
    int8_t[44] pad68;
    uint32_t f68;
    uint32_t f72;
    int32_t f76;
    int32_t f80;
};

struct s502 {
    int8_t[72] pad72;
    uint8_t f72;
};

void fun_40c4ac(int32_t ecx) {
    uint32_t esi2;
    uint32_t esi3;
    int32_t ecx4;
    uint1_t cf5;
    void* esp6;
    struct s489* eax7;
    struct s490* ebx8;
    struct s491* ebx9;
    uint8_t ah10;
    struct s492* esp11;
    int32_t edx12;
    struct s493* ebp13;
    void* ebp14;
    struct s494* edi15;
    struct s495* edi16;
    uint8_t dh17;
    uint1_t cf18;
    int32_t edi19;
    struct s493** esp20;
    struct s496* esp21;
    uint32_t* esp22;
    uint32_t* esp23;
    uint32_t ebx24;
    int32_t* esp25;
    struct s0* eax26;
    void* esp27;
    struct s497* ebx28;
    int32_t edx29;
    struct s498* edx30;
    struct s499* edx31;
    uint32_t* esp32;
    struct s500* esp33;
    uint8_t dh34;
    uint8_t dh35;
    uint32_t eax36;
    struct s493** esp37;
    struct s496* esp38;
    uint32_t* esp39;
    struct s501* esp40;
    int32_t ebx41;
    int32_t edx42;
    int32_t ecx43;
    uint32_t eax44;
    uint32_t eax45;
    uint32_t eax46;
    uint32_t eax47;
    uint32_t eax48;
    uint32_t eax49;
    uint32_t eax50;
    struct s492* esp51;
    struct s493** esp52;
    struct s496* esp53;
    void* esp54;
    struct s502* ebx55;
    int32_t edx56;
    uint8_t dh57;

    esi2 = esi3;
    ecx4 = ecx - 1;
    asm("outsb");
    if (!(cf5 | (uint1_t)(ecx4 == 0))) {
        asm("insb");
        esp6 = (void*)(eax7->f102 * 0x64657869);
        ebx8->f72 = (uint8_t)(ebx9->f72 & ah10);
        esp11 = (struct s492*)((int32_t)esp6 - 4);
        esp11->f0 = edx12;
        ebp13 = (struct s493*)((int32_t)ebp14 - 1);
        edi15->f104 = (uint8_t)(edi16->f104 & dh17);
        esi2 = ebp13->f32 * 0x6e696f70;
        cf18 = __intrinsic();
        if (!__undefined()) {
            if (!cf18) {
                addr_0x40c541_4:
                goto addr_0x40c543_5;
            } else {
                asm("arpl [gs:ecx+0x66], bp");
                esp11 = (struct s492*)(ebp13->f100 * 0x69687700);
                cf18 = __intrinsic();
                if (__undefined()) {
                    addr_0x40c543_5:
                    goto addr_0x40c550_7;
                } else {
                    edi19 = esp11->f0;
                    esp11 = (struct s492*)&esp11->pad76;
                    if (__undefined()) {
                        addr_0x40c51e_9:
                        if (cf18) {
                            addr_0x40c58a_10:
                            asm("outsb");
                            if (cf18 | (uint1_t)(ecx4 - 1 == 0)) {
                                addr_0x40c5f5_11:
                                esp20 = (struct s493**)((int32_t)esp11 - 4);
                                *esp20 = esp11->f76;
                                esp21 = (struct s496*)(esp20 - 1);
                                esp21->f0 = 0x40c603;
                                fun_40850c(esp21->f4, esp21->f8, esp21->f12, esp21->f16, esp21->f20, esp21->f24, esp21->f28, esp21->f32, esp21->f36, esp21->f40, esp21->f44, esp21->f48, esp21->f52, esp21->f56);
                                esp22 = (uint32_t*)(&esp21->f4 - 4);
                                *esp22 = esi2;
                                esp23 = esp22 - 1;
                                *esp23 = ebx24;
                                esp25 = (int32_t*)(esp23 - 1);
                                *esp25 = (int32_t)"white_x=%ld, white_y=%ld\n";
                                eax26 = g41ebe4;
                                goto addr_0x40c60c_12;
                            } else {
                                asm("insb");
                                esp27 = (void*)(*(int32_t*)((uint32_t)eax26 + 0x66) * 0x64657869);
                                ebx28->f72 = 0;
                                esp25 = (int32_t*)((int32_t)esp27 - 4);
                                *esp25 = edx29;
                                edx30->f108 = 0;
                                if (edx31->f108) {
                                    addr_0x40c60c_12:
                                    esp32 = (uint32_t*)(esp25 - 1);
                                    *esp32 = (uint32_t)eax26 + 64;
                                    esp33 = (struct s500*)(esp32 - 1);
                                    esp33->f0 = 0x40c618;
                                    fun_4180f9(esp33->f4, esp33->f8, esp33->f12, esp33->f16, esp33->f20, esp33->f24);
                                    goto 0x40c80d;
                                } else {
                                    eax26->f111 = (uint8_t)(eax26->f111 & dh34);
                                    ebp13 = (struct s493*)(*(int32_t*)(esi2 + 0x74) * 0x65707320);
                                    asm("arpl [ecx+0x66], bp");
                                    esp11 = (struct s492*)(ebp13->f100 * 0x2cec8300);
                                    goto addr_0x40c5b5_15;
                                }
                            }
                        } else {
                            eax26->f111 = (uint8_t)(eax26->f111 & dh35);
                            ebp13 = (struct s493*)(*(int32_t*)(esi2 + 0x74) * 0x65707320);
                            asm("arpl [ecx+0x66], bp");
                            esp11 = (struct s492*)(ebp13->f100 * 0x90909000);
                            cf18 = __intrinsic();
                            goto addr_0x40c541_4;
                        }
                    } else {
                        eax26 = (struct s0*)(eax36 & 0x202c646c);
                        cf18 = 0;
                        if (!(uint1_t)static_cast<uint32_t>((uint1_t)(eax26 == 0))) {
                            addr_0x40c550_7:
                            --ecx4;
                            asm("outsb");
                            if (cf18 | (uint1_t)(ecx4 == 0)) {
                                addr_0x40c5b5_15:
                                esp37 = (struct s493**)((int32_t)esp11 - 4);
                                *esp37 = ebp13;
                                esp38 = (struct s496*)(esp37 - 1);
                                esp38->f0 = edi19;
                                esp39 = (uint32_t*)((int32_t)esp38 - 4);
                                *esp39 = esi2;
                                esp40 = (struct s501*)(esp39 - 1);
                                esp40->f0 = ebx41;
                                ebx24 = esp40->f68;
                                esi2 = esp40->f72;
                                edx42 = esp40->f76;
                                ecx43 = esp40->f80;
                                if ((int32_t)ebx24 > (int32_t)0x13880 || ((int32_t)esi2 > (int32_t)0x13880 || (int32_t)(esi2 + ebx24) > (int32_t)0x186a0)) {
                                    esp11 = (struct s492*)((int32_t)esp40 - 8 - 4);
                                    esp11->f0 = (int32_t)"Invalid fixed cHRM white point specified";
                                    goto addr_0x40c5f5_11;
                                } else {
                                    eax44 = ebx24 >> 24;
                                    esp40->f16 = *(int8_t*)&eax44;
                                    eax45 = ebx24 >> 16;
                                    esp40->f17 = *(int8_t*)&eax45;
                                    eax46 = ebx24 >> 8;
                                    esp40->f18 = *(int8_t*)&eax46;
                                    esp40->f19 = *(int8_t*)&ebx24;
                                    eax47 = esi2 >> 24;
                                    esp40->f20 = *(int8_t*)&eax47;
                                    eax48 = esi2 >> 16;
                                    esp40->f21 = *(int8_t*)&eax48;
                                    eax49 = esi2 >> 8;
                                    esp40->f22 = *(int8_t*)&eax49;
                                    eax50 = esi2;
                                    esp40->f23 = *(int8_t*)&eax50;
                                    if (edx42 <= 0x13880 && ecx43 <= 0x13880) {
                                        if (ecx43 + edx42 <= 0x186a0) 
                                            goto 0x40c694;
                                    }
                                    esp51 = (struct s492*)((int32_t)esp40 - 8 - 4);
                                    esp51->f0 = (int32_t)"Invalid cHRM fixed red point specified";
                                    esp52 = (struct s493**)((int32_t)esp51 - 4);
                                    *esp52 = esp51->f76;
                                    esp53 = (struct s496*)(esp52 - 1);
                                    esp53->f0 = 0x40c68c;
                                    fun_40850c(esp53->f4, esp53->f8, esp53->f12, esp53->f16, esp53->f20, esp53->f24, esp53->f28, esp53->f32, esp53->f36, esp53->f40, esp53->f44, esp53->f48, esp53->f52, esp53->f56);
                                    goto 0x40c80a;
                                }
                            } else {
                                asm("insb");
                                esp54 = (void*)(*(int32_t*)((uint32_t)eax26 + 0x66) * 0x64657869);
                                ebx55->f72 = 0;
                                *(int32_t*)((int32_t)esp54 - 4) = edx56;
                                *(uint8_t*)(edi19 + 0x72) = 0;
                                asm("outsb");
                                eax26->f111 = (uint8_t)(eax26->f111 & dh57);
                                ebp13 = (struct s493*)(*(int32_t*)(esi2 + 0x74) * 0x65707320);
                                asm("arpl [ecx+0x66], bp");
                                goto addr_0x40c575_23;
                            }
                        } else {
                            esi2 = ebp13->f95 * 0x6c253d79;
                        }
                    }
                }
            }
        }
        *(uint8_t*)&eax26 = (uint8_t)(*(uint8_t*)&eax26 | eax26->f0);
        --ecx4;
        asm("outsb");
        if (!ecx4) {
            addr_0x40c575_23:
            esp11 = (struct s492*)(ebp13->f100 * 0x90909000);
            cf18 = __intrinsic();
            goto addr_0x40c58a_10;
        } else {
            asm("insb");
        }
    }
    esp11 = (struct s492*)(eax26->f99 * 0x204d5248);
    *(int16_t*)&edi19 = (int16_t)(*(int16_t*)((uint32_t)eax26 + 0x65) * 0x2064);
    cf18 = __intrinsic();
    goto addr_0x40c51e_9;
}

struct s503 {
    int8_t[105] pad105;
    uint8_t f105;
};

struct s504 {
    int8_t[108] pad108;
    uint8_t f108;
    int8_t[1] pad110;
    uint8_t f110;
    int8_t[4] pad115;
    uint8_t f115;
};

struct s505 {
    uint8_t f0;
    int8_t[1445260418] pad1445260419;
    int8_t f1445260419;
};

struct s506 {
    int8_t[111] pad111;
    uint8_t f111;
};

struct s507 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s508 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s509 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s510 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s511 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s512 {
    int8_t[104] pad104;
    int8_t f104;
};

struct s513 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s514 {
    int8_t[112] pad112;
    uint8_t f112;
};

struct s515 {
    int8_t[104] pad104;
    uint8_t f104;
};

void fun_40c830(void* ecx) {
    struct s503** esp2;
    struct s504* ecx3;
    uint1_t zf4;
    uint1_t cf5;
    struct s505* eax6;
    void* eax7;
    struct s506* bp8;
    struct s503* edi9;
    int1_t cf10;
    void* edx11;
    int32_t esi12;
    void* edx13;
    int32_t esi14;
    uint8_t dh15;
    int1_t zf16;
    void* edx17;
    int32_t esi18;
    int16_t bx19;
    int16_t di20;
    int16_t bx21;
    int16_t di22;
    uint8_t ah23;
    uint1_t zf24;
    int16_t bx25;
    int16_t di26;
    uint1_t below_or_equal27;
    uint8_t bh28;
    struct s507* ebx29;
    struct s508* ebx30;
    struct s509* ebx31;
    int8_t dl32;
    void* edi33;
    int32_t ebp34;
    void* edi35;
    int32_t ebp36;
    uint8_t dh37;
    void* edi38;
    int32_t ebp39;
    uint8_t dh40;
    int1_t zf41;
    struct s510* ebx42;
    struct s511* ebx43;
    uint8_t ah44;
    struct s512* ebx45;
    int32_t* eax46;
    struct s513* ebx47;
    struct s514* ebx48;
    uint8_t dh49;
    struct s515* ebx50;
    int32_t ebp51;
    int32_t ebp52;
    uint8_t dh53;
    int32_t ebp54;
    int16_t bx55;
    int16_t bx56;

    esp2 = (struct s503**)__zero_stack_offset();
    ecx3 = (struct s504*)((int32_t)ecx - 1);
    zf4 = (uint1_t)(ecx3 == 0);
    asm("outsb");
    if (cf5 | zf4) {
        addr_0x40c895_2:
        if (zf4) {
            eax6 = (struct s505*)((int32_t)eax7 - 0x722d666f);
            asm("popad");
            asm("outsb");
            *(uint8_t*)&bp8->f111 = 0;
            if (0) {
                addr_0x40c8c6_5:
                goto addr_0x40c8c7_6;
            } else {
                edi9 = *esp2;
                if (0) 
                    goto 0x40c922;
                *(int32_t*)(esp2 + 1 - 1) = 0x6e674900;
                goto addr_0x40c8b0_9;
            }
        }
    } else {
        asm("insb");
        cf10 = __intrinsic();
        if (cf10) {
            addr_0x40c85f_11:
            goto addr_0x40c86e_12;
        } else {
            asm("outsd");
            *(uint8_t*)((int32_t)edx11 + esi12 * 2 + 97) = (uint8_t)(*(uint8_t*)((int32_t)edx13 + esi14 * 2 + 97) & dh15);
            cf10 = 0;
            zf16 = *(int8_t*)((int32_t)edx17 + esi18 * 2 + 97) == 0;
            asm("outsb");
            if (1) {
                addr_0x40c8b8_14:
                if (zf16) 
                    goto 0x40c922; else 
                    goto addr_0x40c8bd_15;
            } else {
                asm("popad");
                if (0) {
                    addr_0x40c8b0_9:
                    asm("outsd");
                    if (0) 
                        goto 0x40c91f; else 
                        goto addr_0x40c8b6_17;
                } else {
                    asm("outsb");
                    if (zf16) {
                        addr_0x40c86e_12:
                        ecx3 = (struct s504*)((int32_t)ecx3 - 1);
                        asm("a16 outsb");
                        asm("outsd");
                        if (cf10) {
                            addr_0x40c8df_19:
                            goto addr_0x40c8e2_20;
                        } else {
                            asm("outsb");
                            *(uint8_t*)((int16_t)(bx19 + di20) + 0x74) = (uint8_t)(*(uint8_t*)((int16_t)(bx21 + di22) + 0x74) & ah23);
                            zf24 = (uint1_t)(*(int8_t*)((int16_t)(bx25 + di26) + 0x74) == 0);
                            below_or_equal27 = (uint1_t)static_cast<uint32_t>(zf24);
                            if (zf24) {
                                addr_0x40c8e2_20:
                                ecx3->f115 = 0;
                                *(uint8_t*)eax6 = (uint8_t)(*(uint8_t*)eax6 & bh28);
                                ebx29->f97 = (int8_t)(ebx30->f97 + *(int8_t*)&eax6);
                                zf24 = (uint1_t)(ebx31->f97 == 0);
                                below_or_equal27 = (uint1_t)(__intrinsic() | zf24);
                                asm("outsb");
                                asm("daa");
                                goto addr_0x40c8f4_22;
                            } else {
                                asm("insd");
                                if (0) {
                                    addr_0x40c8f4_22:
                                    if (zf24) {
                                        addr_0x40c916_24:
                                        *(int8_t*)((int32_t)eax6 + 0x5624ec83) = (int8_t)(*(int8_t*)((int32_t)eax6 + 0x5624ec83) + dl32);
                                    } else {
                                        if (!below_or_equal27) 
                                            goto "B"; else 
                                            goto addr_0x40c8f8_26;
                                    }
                                } else {
                                    *(uint8_t*)((int32_t)edi33 + ebp34 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi35 + ebp36 * 2 + 32) & dh37);
                                    if (!(uint1_t)static_cast<uint32_t>((uint1_t)(*(int8_t*)((int32_t)edi38 + ebp39 * 2 + 32) == 0))) {
                                        addr_0x40c8f8_26:
                                        edi9->f105 = (uint8_t)(edi9->f105 & dh40);
                                        zf41 = edi9->f105 == 0;
                                        goto addr_0x40c901_28;
                                    } else {
                                        ebx42->f104 = (uint8_t)(ebx43->f104 & ah44);
                                        zf41 = ebx45->f104 == 0;
                                        if (!zf41) {
                                            addr_0x40c901_28:
                                            if (zf41) 
                                                goto 0x40c96d; else 
                                                goto addr_0x40c905_30;
                                        } else {
                                            esp2 = (struct s503**)(*eax46 * 0x6f);
                                            zf4 = __undefined();
                                            goto addr_0x40c895_2;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        asm("arpl [edi+0x6c], bp");
                        asm("outsd");
                        if (0) {
                            addr_0x40c8c7_6:
                            asm("arpl [eax+0x75], bp");
                            asm("outsb");
                            *(int32_t*)(*(uint8_t*)eax6 * 0x77 - 4) = 0x62206e65;
                            goto addr_0x40c8df_19;
                        } else {
                            ebx47->f112 = (uint8_t)(ebx48->f112 & dh49);
                            asm("arpl [gs:ecx+0x66], bp");
                            cf10 = __intrinsic();
                            goto addr_0x40c85f_11;
                        }
                    }
                }
            }
        }
    }
    addr_0x40c90d_34:
    asm("popad");
    ebx50->f104 = 0;
    asm("popad");
    asm("outsb");
    asm("outsb");
    asm("insb");
    goto addr_0x40c916_24;
    addr_0x40c8bd_15:
    asm("insd");
    if (0) 
        goto 0x40c934;
    *(uint8_t*)((int32_t)edi9 + ebp51 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi9 + ebp52 * 2 + 32) & dh53);
    if (!(uint1_t)static_cast<uint32_t>((uint1_t)(*(int8_t*)((int32_t)edi9 + ebp54 * 2 + 32) == 0))) 
        goto 0x40c938; else 
        goto addr_0x40c8c6_5;
    addr_0x40c8b6_17:
    asm("outsb");
    *(uint8_t*)((int16_t)(bx55 + *(int16_t*)&edi9) + 0x74) = 0;
    zf16 = *(int8_t*)((int16_t)(bx56 + *(int16_t*)&edi9) + 0x74) == 0;
    goto addr_0x40c8b8_14;
    addr_0x40c905_30:
    ecx3->f110 = 0;
    ecx3->f108 = 0;
    if (0) 
        goto 0x40c975; else 
        goto addr_0x40c90d_34;
}

struct s516 {
    int8_t[103] pad103;
    int8_t f103;
    int8_t[6] pad110;
    uint8_t f110;
    int8_t[4] pad115;
    uint8_t f115;
};

struct s517 {
    int8_t[98] pad98;
    int32_t f98;
};

struct s518 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s519 {
    int8_t[97] pad97;
    uint8_t f97;
};

struct s520 {
    int8_t[97] pad97;
    int8_t f97;
};

struct s521 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s522 {
    int8_t[104] pad104;
    uint8_t f104;
};

struct s523 {
    int8_t[104] pad104;
    int8_t f104;
};

struct s524 {
    int8_t[111] pad111;
    uint8_t f111;
};

void fun_40ca8c(void* ecx) {
    struct s516* ecx2;
    uint1_t cf3;
    int32_t* eax4;
    uint8_t* eax5;
    uint8_t* eax6;
    uint8_t bh7;
    int32_t esp8;
    struct s517* eax9;
    struct s518* eax10;
    struct s519* eax11;
    uint8_t dh12;
    struct s520* eax13;
    void* edi14;
    int32_t ebp15;
    void* edi16;
    int32_t ebp17;
    uint8_t dh18;
    void* edi19;
    int32_t ebp20;
    struct s521* ebx21;
    struct s522* ebx22;
    uint8_t ah23;
    struct s523* ebx24;
    int32_t* eax25;
    struct s524* bp26;
    int16_t bx27;
    int16_t di28;
    int16_t bx29;
    int16_t di30;
    uint8_t ah31;
    int16_t bx32;
    int16_t di33;
    void* edi34;
    int32_t ebp35;
    void* edi36;
    int32_t ebp37;
    uint8_t dh38;
    void* edi39;
    int32_t ebp40;
    int16_t bx41;
    int16_t di42;
    int16_t bx43;
    int16_t di44;
    uint8_t ah45;
    int16_t bx46;
    int16_t di47;

    ecx2 = (struct s516*)((int32_t)ecx - 1);
    asm("outsb");
    if (cf3 | (uint1_t)(ecx2 == 0)) {
        addr_0x40caf5_2:
        asm("arpl [eax+0x75], bp");
        asm("outsb");
        *(int32_t*)(*eax4 * 0x77 - 4) = 0x62206e65;
        ecx2->f115 = 0;
        *eax5 = (uint8_t)(*eax6 & bh7);
        goto addr_0x40cb0e_3;
    } else {
        asm("insb");
        esp8 = eax9->f98 * 0x676b6361;
        if (__intrinsic()) {
            addr_0x40cb0e_3:
            goto addr_0x40cb0f_5;
        } else {
            if (!__undefined()) {
                addr_0x40cb0f_5:
                ecx2->f103 = (int8_t)(ecx2->f103 + *(int8_t*)&ecx2);
                asm("outsb");
                asm("outsd");
                if (__intrinsic()) 
                    goto 0x40cb7f;
            } else {
                eax10->f97 = (uint8_t)(eax11->f97 & dh12);
                asm("insb");
                if (!eax13->f97) {
                    addr_0x40cb1d_8:
                    asm("insd");
                    if (!0) {
                        *(uint8_t*)((int32_t)edi14 + ebp15 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi16 + ebp17 * 2 + 32) & dh18);
                        if (!(uint1_t)static_cast<uint32_t>((uint1_t)(*(int8_t*)((int32_t)edi19 + ebp20 * 2 + 32) == 0))) 
                            goto 0x40cb98;
                        ebx21->f104 = (uint8_t)(ebx22->f104 & ah23);
                        if (ebx24->f104) 
                            goto 0x40cba1;
                        esp8 = *eax25 * 0x6f;
                        if (!__undefined()) 
                            goto 0x40cbac;
                        asm("popad");
                        asm("outsb");
                        goto addr_0x40cb3f_15;
                    }
                } else {
                    ecx2->f110 = 0;
                    ecx2 = (struct s516*)((int32_t)ecx2 - 1);
                    asm("a16 outsb");
                    asm("outsd");
                    if (0) {
                        addr_0x40cb3f_15:
                        *(uint8_t*)&bp26->f111 = 0;
                        goto addr_0x40cb42_18;
                    } else {
                        asm("outsb");
                        *(uint8_t*)((int16_t)(bx27 + di28) + 0x74) = (uint8_t)(*(uint8_t*)((int16_t)(bx29 + di30) + 0x74) & ah31);
                        if (!*(int8_t*)((int16_t)(bx32 + di33) + 0x74)) {
                            addr_0x40cb42_18:
                            if (0) 
                                goto 0x40cb66; else 
                                goto addr_0x40cb46_20;
                        } else {
                            asm("insd");
                            if (0) 
                                goto 0x40cb54;
                            *(uint8_t*)((int32_t)edi34 + ebp35 * 2 + 32) = (uint8_t)(*(uint8_t*)((int32_t)edi36 + ebp37 * 2 + 32) & dh38);
                            if (!(uint1_t)static_cast<uint32_t>((uint1_t)(*(int8_t*)((int32_t)edi39 + ebp40 * 2 + 32) == 0))) 
                                goto 0x40cb58;
                            goto addr_0x40caf5_2;
                        }
                    }
                }
            }
        }
    }
    asm("outsb");
    *(uint8_t*)((int16_t)(bx41 + di42) + 0x74) = (uint8_t)(*(uint8_t*)((int16_t)(bx43 + di44) + 0x74) & ah45);
    if (!*(int8_t*)((int16_t)(bx46 + di47) + 0x74)) 
        goto 0x40cb82; else 
        goto addr_0x40cb1d_8;
    addr_0x40cb46_20:
    if (0) 
        goto 0x40cbc2;
    *(int32_t*)(esp8 + 4 - 4) = 0x24ec8300;
}

void fun_40d027(struct s11* ecx) {
    void* ebp2;
    void* ebp3;
    int32_t eax4;
    int32_t eax5;
    uint8_t dh6;
    int32_t eax7;

    ebp2 = (void*)((int32_t)ebp3 + 1);
    asm("insd");
    if (__intrinsic()) 
        goto 0x40d09f;
    if ((int32_t)ebp2 >= 0) 
        goto 0x40d04d;
    asm("outsd");
    if (__intrinsic()) 
        goto 0x40d098;
    ecx->f110 = 0;
    *(uint8_t*)((int32_t)ebp2 + eax4 * 2 + 88) = (uint8_t)(*(uint8_t*)((int32_t)ebp2 + eax5 * 2 + 88) & dh6);
    if (!*(int8_t*)((int32_t)ebp2 + eax7 * 2 + 88)) 
        goto 0x40d05d;
    asm("arpl [eax+0x75], bp");
    asm("outsb");
}

/* callback1? */
int16_t callback1_(void** a1, uint32_t a2, struct s32* a3) {
    struct s32* ebp4;
    void** esi5;
    uint32_t eax6;
    void** ebx7;
    uint32_t eax8;
    void*** edi9;
    void** edx10;
    uint32_t ecx11;
    uint32_t ecx12;

    ebp4 = a3;
    esi5 = a1;
    eax6 = ebp4->f12;
    ebx7 = (void**)(a2 & 0xffff);
    eax8 = fun_402770(eax6, esi5, ebx7);
    edi9 = ebp4->f8;
    edx10 = ebx7;
    ebp4->f12 = eax8;
    ecx11 = (uint8_t)ebx7 >> 2;
    while (ecx11) {
        --ecx11;
        *edi9 = *(void***)esi5;
        edi9 = edi9 + 4;
        esi5 = esi5 + 4;
    }
    ecx12 = (uint8_t)edx10 & 3;
    while (ecx12) {
        --ecx12;
        *edi9 = *(void***)esi5;
        ++edi9;
        ++esi5;
    }
    ebp4->f8 = (void***)((uint32_t)ebp4->f8 + (uint8_t)ebx7);
    return *(int16_t*)&a2;
}

struct s525 {
    int16_t f0;
    int8_t f2;
    int8_t f3;
    int8_t f4;
    int8_t f5;
    int8_t f6;
};

struct s526 {
    int8_t f0;
    int8_t[3] pad4;
    int8_t f4;
    int8_t[3] pad8;
    int8_t f8;
    int8_t[3] pad12;
    int8_t f12;
    int8_t[3] pad16;
    int8_t f16;
    int8_t[3] pad20;
    uint16_t f20;
};

struct s526* fun_417e90(void* a1);

void fun_404a98(struct s525* a1) {
    struct s526* eax2;
    uint32_t eax3;

    eax2 = fun_417e90((int32_t)__zero_stack_offset() - 24 - 4 - 12 + 48);
    eax3 = eax2->f20 + 0x76c;
    a1->f0 = *(int16_t*)&eax3;
    a1->f2 = (int8_t)(eax2->f16 + 1);
    a1->f3 = eax2->f12;
    a1->f4 = eax2->f8;
    a1->f5 = eax2->f4;
    a1->f6 = eax2->f0;
    return;
}

struct s527 {
    int8_t[184] pad184;
    uint32_t f184;
};

void fun_4074ec(int32_t a1, struct s527* a2, int32_t a3, uint32_t a4) {
    if (!a1) 
        goto 0x407539;
    if (!a2) 
        goto 0x407539;
    if (a3 != 1) 
        goto 0x407518;
    a2->f184 = a2->f184 | a4;
    goto 0x407539;
}

struct s528 {
    int8_t[108] pad108;
    uint8_t f108;
    int8_t[87] pad196;
    int32_t f196;
};

void fun_404d00(struct s528* a1, int32_t a2) {
    a1->f108 = (uint8_t)(a1->f108 | 1);
    a1->f196 = a2;
    return;
}

void fun_402a72() {
}

struct s529 {
    uint32_t f0;
    int8_t[5] pad9;
    int8_t f9;
    uint8_t f10;
};

struct s530 {
    int8_t f0;
    int8_t f1;
    int8_t f2;
    int8_t[1] pad4;
    int8_t f4;
    int8_t[1] pad6;
    int8_t f6;
};

struct s531 {
    int8_t f0;
    int8_t f1;
};

struct s532 {
    int8_t f0;
    int8_t f1;
};

struct s533 {
    int8_t f0;
    int8_t f1;
};

void fun_4090bc(struct s529* a1, struct s530* a2) {
    struct s530* ebx3;
    uint32_t esi4;
    uint32_t edi5;
    uint32_t eax6;
    int8_t dl7;
    struct s531* edx8;
    int8_t cl9;
    struct s532* edx10;
    int8_t cl11;
    struct s533* edx12;
    int8_t cl13;
    int8_t dl14;
    int8_t dl15;
    int8_t dl16;

    if (a1->f9 != 16) 
        goto addr_0x409169_2;
    ebx3 = a2;
    esi4 = a1->f10 * a1->f0;
    edi5 = 0;
    if (0 >= esi4) 
        goto addr_0x409169_2;
    eax6 = esi4 & 3;
    if (!((uint1_t)((int32_t)esi4 < (int32_t)0) | (uint1_t)(esi4 == 0))) {
        if (!eax6) {
            do {
                addr_0x409128_6:
                dl7 = ebx3->f0;
                ebx3->f0 = ebx3->f1;
                ebx3->f1 = dl7;
                edx8 = (struct s531*)&ebx3->f2;
                cl9 = ebx3->f2;
                ebx3->f2 = edx8->f1;
                edx8->f1 = cl9;
                edx10 = (struct s532*)&ebx3->f4;
                cl11 = ebx3->f4;
                ebx3->f4 = edx10->f1;
                edx10->f1 = cl11;
                edx12 = (struct s533*)&ebx3->f6;
                cl13 = ebx3->f6;
                ebx3->f6 = edx12->f1;
                edx12->f1 = cl13;
                edi5 = edi5 + 4;
                ebx3 = (struct s530*)((int32_t)ebx3 + 8);
            } while (edi5 < esi4);
            goto addr_0x409169_2;
        } else {
            if ((int32_t)eax6 > (int32_t)1) {
                if ((int32_t)eax6 > (int32_t)2) {
                    dl14 = ebx3->f0;
                    ebx3->f0 = ebx3->f1;
                    ebx3->f1 = dl14;
                    edi5 = 1;
                    ebx3 = (struct s530*)&ebx3->f2;
                }
                dl15 = ebx3->f0;
                ebx3->f0 = ebx3->f1;
                ebx3->f1 = dl15;
                ++edi5;
                ebx3 = (struct s530*)&ebx3->f2;
            }
        }
    }
    dl16 = ebx3->f0;
    ebx3->f0 = ebx3->f1;
    ebx3->f1 = dl16;
    ++edi5;
    ebx3 = (struct s530*)&ebx3->f2;
    if (edi5 >= esi4) {
        addr_0x409169_2:
        return;
    } else {
        goto addr_0x409128_6;
    }
}

struct s534 {
    int8_t f0;
    int8_t f1;
};

void fun_410cbc(struct s534* a1, uint32_t a2) {
    uint32_t edx3;
    uint32_t eax4;

    edx3 = a2;
    eax4 = edx3 >> 8;
    a1->f0 = *(int8_t*)&eax4;
    a1->f1 = *(int8_t*)&edx3;
    return;
}

struct s535 {
    int8_t[336] pad336;
    int32_t f336;
};

void fun_404ae2(struct s535* a1, int32_t a2) {
    int32_t edx3;

    edx3 = a2;
    if (edx3 < 0) {
        edx3 = 0;
    }
    a1->f336 = edx3;
    return;
}

void** fun_404d14(void** a1, void** a2) {
    void** ebx3;
    void** v4;
    void** v5;
    void** ebx6;
    void** esi7;
    void** v8;
    void** v9;
    void** v10;
    void** v11;
    void** v12;
    void** eax13;
    void** v14;
    void** v15;
    void** v16;
    void** v17;
    void** v18;
    void** v19;
    void** v20;
    void** v21;

    ebx3 = a2;
    if ((int8_t)ebx3 <= (int8_t)15) {
        if ((int8_t)ebx3 > (int8_t)7) {
            addr_0x404d46_3:
            if ((int1_t)(ebx3 == 8)) {
                eax13 = fun_40850c(a1, 0x404880, v4, v5, ebx6, esi7, v8, v9, v10, v11, v12, __return_address(), a1, a2);
                ebx3 = (void**)9;
            }
        } else {
            v14 = (void**)0x404840;
            goto addr_0x404d3d_6;
        }
    } else {
        v14 = (void**)fun_404800;
        goto addr_0x404d3d_6;
    }
    *(void***)(a1 + 0x6c) = (void**)((uint8_t)*(void***)(a1 + 0x6c) | 8);
    *(void***)(a1 + 0xbc) = ebx3;
    return eax13;
    addr_0x404d3d_6:
    eax13 = fun_40850c(a1, v14, v15, v16, ebx6, esi7, v17, v18, v19, v20, v21, __return_address(), a1, a2);
    goto addr_0x404d46_3;
}
