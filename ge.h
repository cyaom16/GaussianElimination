/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ge.h
 * Author: Quintu5icario
 *
 * Created on November 6, 2017, 9:37 PM
 */

#ifndef GE_H
#define GE_H
void print_matrix(float **a, int rows, int cols);
int ge_fw(float **matrix, int rows, int cols, float *x);
int ge_bw(float **matrix, int rows, int cols, float *x);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GE_H */

