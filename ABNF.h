#ifndef ABNF_H
#define ABNF_H

#include <stddef.h>

/*Letters*/
int is_A(const unsigned char c);
int is_B(const unsigned char c);
int is_C(const unsigned char c);
int is_D(const unsigned char c);
int is_E(const unsigned char c);
int is_F(const unsigned char c);
int is_G(const unsigned char c);
int is_H(const unsigned char c);
int is_I(const unsigned char c);
int is_J(const unsigned char c);
int is_K(const unsigned char c);
int is_L(const unsigned char c);
int is_M(const unsigned char c);
int is_N(const unsigned char c);
int is_O(const unsigned char c);
int is_P(const unsigned char c);
int is_Q(const unsigned char c);
int is_R(const unsigned char c);
int is_S(const unsigned char c);
int is_T(const unsigned char c);
int is_U(const unsigned char c);
int is_V(const unsigned char c);
int is_W(const unsigned char c);
int is_X(const unsigned char c);
int is_Y(const unsigned char c);
int is_Z(const unsigned char c);

/*Digits*/
int is_0(const unsigned char c);
int is_1(const unsigned char c);
int is_2(const unsigned char c);
int is_3(const unsigned char c);
int is_4(const unsigned char c);
int is_5(const unsigned char c);
int is_6(const unsigned char c);
int is_7(const unsigned char c);
int is_8(const unsigned char c);
int is_9(const unsigned char c);

/*ABNF core rules*/
int is_ALPHA(const unsigned char c);
int is_BIT(const unsigned char c);
int is_CHAR(const unsigned char c);
int is_CR(const unsigned char c);
int is_CTL(const unsigned char c);
int is_DIGIT(const unsigned char c);
int is_DQUOTE(const unsigned char c);
int is_HEXDIG(const unsigned char c);
int is_HTAB(const unsigned char c);
int is_LF(const unsigned char c);
int is_OCTET(const unsigned char c);
int is_SP(const unsigned char c);
int is_VCHAR(const unsigned char c);
int is_WSP(const unsigned char c);

int is_CRLF(const unsigned char* s);

int is_LWSP(const unsigned char* s, size_t len);

#endif /*ABNF_H*/

