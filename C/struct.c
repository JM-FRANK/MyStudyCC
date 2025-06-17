# include<stdio.h>

typedef struct{
    float realpart;      //* 实部
    float imagpart;      //* 虚部
}Complex;

void assign(Complex *A, float real, float imag);
void add(Complex *c, Complex A, Complex B);
void minus(Complex *c, Complex A, Complex B);
void multiply(Complex *c, Complex A, Complex B);
void divide(Complex *c, Complex A, Complex B);

void assign(Complex *A, float real, float imag){
    A->realpart = real;
    A->imagpart = imag;
}//* A -> real,imag

void add(Complex *c, Complex A, Complex B){
    c->realpart = A.realpart + B.realpart;
    c->imagpart = A.imagpart + B.imagpart;
}//* A+B=c

void minus(Complex *c, Complex A, Complex B){
    c->realpart = A.realpart - B.realpart;
    c->imagpart = A.imagpart - B.imagpart;
}//* A-B=c

void multiply(Complex *c, Complex A, Complex B){
    c->realpart = A.realpart * B.realpart - A.imagpart * B.imagpart;
    c->imagpart = A.imagpart * B.realpart + A.realpart * B.imagpart;
}//* A*B=c

void divide(Complex *c, Complex A, Complex B){
    float k = B.realpart * B.realpart - B.imagpart * B.imagpart;
    c->realpart = (A.realpart * B.realpart + A.imagpart * B.imagpart) / k;
    c->imagpart = (A.imagpart * B.realpart - A.realpart * B.imagpart) / k;
}//* A/B=c

void main(){
    Complex *z1, *z2, *z3, *z4;
    float RealPart, ImagPart;
    assign(z1, 8.0, 6.0);
    assign(z2, 4.0, 3.0);
    add(z3, *z1, *z2);


}