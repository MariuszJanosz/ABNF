#include "ABNF.h"

#include <stddef.h>

/*Letters*/
int is_A(const unsigned char c) {
    return 0x41 == c || 0x61 == c;/*A||a*/
}

int is_B(const unsigned char c) {
    return 0x42 == c || 0x62 == c;/*B||b*/
}

int is_C(const unsigned char c) {
    return 0x43 == c || 0x63 == c;/*C||c*/
}

int is_D(const unsigned char c) {
    return 0x44 == c || 0x64 == c;/*D||d*/
}

int is_E(const unsigned char c) {
    return 0x45 == c || 0x65 == c;/*E||e*/
}

int is_F(const unsigned char c) {
    return 0x46 == c || 0x66 == c;/*F||f*/
}

int is_G(const unsigned char c) {
    return 0x47 == c || 0x67 == c;/*G||g*/
}

int is_H(const unsigned char c) {
    return 0x48 == c || 0x68 == c;/*H||h*/
}

int is_I(const unsigned char c) {
    return 0x49 == c || 0x69 == c;/*I||i*/
}

int is_J(const unsigned char c) {
    return 0x4A == c || 0x6A == c;/*J||j*/
}

int is_K(const unsigned char c) {
    return 0x4B == c || 0x6B == c;/*K||k*/
}

int is_L(const unsigned char c) {
    return 0x4C == c || 0x6C == c;/*L||l*/
}

int is_M(const unsigned char c) {
    return 0x4D == c || 0x6D == c;/*M||m*/
}

int is_N(const unsigned char c) {
    return 0x4E == c || 0x6E == c;/*N||n*/
}

int is_O(const unsigned char c) {
    return 0x4F == c || 0x6F == c;/*O||o*/
}

int is_P(const unsigned char c) {
    return 0x50 == c || 0x70 == c;/*P||p*/
}

int is_Q(const unsigned char c) {
    return 0x51 == c || 0x71 == c;/*Q||q*/
}

int is_R(const unsigned char c) {
    return 0x52 == c || 0x72 == c;/*R||r*/
}

int is_S(const unsigned char c) {
    return 0x53 == c || 0x73 == c;/*S||s*/
}

int is_T(const unsigned char c) {
    return 0x54 == c || 0x74 == c;/*T||t*/
}

int is_U(const unsigned char c) {
    return 0x55 == c || 0x75 == c;/*U||u*/
}

int is_V(const unsigned char c) {
    return 0x56 == c || 0x76 == c;/*V||v*/
}

int is_W(const unsigned char c) {
    return 0x57 == c || 0x77 == c;/*W||w*/
}

int is_X(const unsigned char c) {
    return 0x58 == c || 0x78 == c;/*X||x*/
}

int is_Y(const unsigned char c) {
    return 0x59 == c || 0x79 == c;/*Y||y*/
}

int is_Z(const unsigned char c) {
    return 0x5A == c || 0x7A == c;/*Z||z*/
}

/*Digits*/
int is_0(const unsigned char c) {
    return 0x30 == c;/*0*/
}

int is_1(const unsigned char c) {
    return 0x31 == c;/*1*/
}

int is_2(const unsigned char c) {
    return 0x32 == c;/*2*/
}

int is_3(const unsigned char c) {
    return 0x33 == c;/*3*/
}

int is_4(const unsigned char c) {
    return 0x34 == c;/*4*/
}

int is_5(const unsigned char c) {
    return 0x35 == c;/*5*/
}

int is_6(const unsigned char c) {
    return 0x36 == c;/*6*/
}

int is_7(const unsigned char c) {
    return 0x37 == c;/*7*/
}

int is_8(const unsigned char c) {
    return 0x38 == c;/*8*/
}

int is_9(const unsigned char c) {
    return 0x39 == c;/*9*/
}

/*ABNF core rules*/
int is_ALPHA(const unsigned char c) {
                    /*A-Z                         a-z*/
    return (0x41 <= c && c <= 0x5A) || (0x61 <= c && c <= 0x7A);
}

int is_BIT(const unsigned char c) {
    return is_0(c) || is_1(c);
}

int is_CHAR(const unsigned char c) {
    return 0x01 <= c && c <= 0x7F; /*Any 7-bit ASCII except NUL*/
}

int is_CR(const unsigned char c) {
    return c == 0x0D; /*CR*/
}

int is_CTL(const unsigned char c) {
                    /*NUL-US              DEL*/
    return (0x00 <= c && c <= 0x1F) || (c == 0x7F);
}

int is_DIGIT(const unsigned char c) {
    return 0x30 <= c && c <= 0x39; /*0-9*/
}

int is_DQUOTE(const unsigned char c) {
    return 0x22 == c; /*"*/
}

int is_HEXDIG(const unsigned char c) {
    return is_DIGIT(c) || is_A(c) || is_B(c) || is_C(c) || is_D(c) || is_E(c) || is_F(c);
}

int is_HTAB(const unsigned char c) {
    return 0x09 == c;
}

int is_LF(const unsigned char c) {
    return 0x0A == c;
}

int is_OCTET(const unsigned char c) {
    return 0x00 <= c && c <= 0xFF;
}

int is_SP(const unsigned char c) {
    return 0x20 == c;
}

int is_VCHAR(const unsigned char c) {
    return 0x21 <= c && c <= 0x7E; /*Visible characters, no control or space*/
}

int is_WSP(const unsigned char c) {
    return is_SP(c) || is_HTAB(c);
}

int is_CRLF(const unsigned char* s) {
    if (is_CR(*s)) return is_LF(*(s + 1));
    return 0;
}

/* LWSP = *(WSP / CRLF WSP) */
int is_LWSP(const unsigned char* s, size_t len) {
    if (len == 0) return 1;
    int i = 0;
    while (i < len) {
        if (is_WSP(*(s + i))) {
            i += 1;
        }
        else if (is_CRLF(s + i)) {
            if (i + 2 >= len) {
                return 0;
            }
            i += 2;
        }
        else {
            return 0;
        }
    }
    return 1;
}

