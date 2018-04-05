/*
 * Copyright 2013-2018 Embedded Solutions
 *
 * File: MLink.h     $Revision: 2.1.0 $
 *
 * Abstract:
 *	MLink function prototypes
 */

#ifndef _MLINK_H_
#define _MLINK_H_

#include <stdint.h>

#ifdef __GNUC__
    #define EXTERNC 
    #define MDAQ_API extern
#else
    #define EXTERNC extern "C" 
    #define MDAQ_API __declspec(dllexport)
#endif

/* Utility functions */ 
EXTERNC MDAQ_API int mlink_connect( const char *addr, uint16_t port, int *link );
EXTERNC MDAQ_API int mlink_disconnect( int link_fd );
EXTERNC MDAQ_API void mlink_disconnect_all( void );
EXTERNC MDAQ_API char *mlink_error( int err );
EXTERNC MDAQ_API int mlink_fw_version(int *link_fd, int *major, int *minor, int *fix, int *build);
EXTERNC MDAQ_API int mlink_lib_version(int *link_fd, int *major, int *minor, int *fix, int *build);
EXTERNC MDAQ_API int mlink_hwid( int *link_fd, int *hwid );

/* DSP handling functions */
EXTERNC MDAQ_API int mlink_dsp_run(int *link_fd,  const char *dsp_binary_path, double period);
EXTERNC MDAQ_API int mlink_dsp_signal_read(int signal_id, int signal_size, double *data, int data_size, int timeout);
EXTERNC MDAQ_API int mlink_dsp_mem_write(int *link_fd, int start_idx, int len, float *data);
EXTERNC MDAQ_API int mlink_dsp_stop(int *link_fd );

/* Digital IO functions */ 
EXTERNC MDAQ_API int mlink_dio_set_func( int *link_fd, uint8_t function, uint8_t enable );
EXTERNC MDAQ_API int mlink_dio_set_dir( int *link_fd, uint8_t pin, uint8_t dir, uint8_t init_value );
EXTERNC MDAQ_API int mlink_dio_write( int *link_fd, uint8_t pin, uint8_t value );
EXTERNC MDAQ_API int mlink_dio_read( int *link_fd, uint8_t pin, uint8_t *value );
EXTERNC MDAQ_API int mlink_led_write( int *link_fd, uint8_t led, uint8_t state );
EXTERNC MDAQ_API int mlink_func_read( int *link_fd, uint8_t key, uint8_t *state );

/* Encoder read functions */ 
EXTERNC MDAQ_API int mlink_enc_read( int *link_fd, uint8_t channels, uint8_t *dir, int32_t *value );
EXTERNC MDAQ_API int mlink_enc_init( int *link_fd, uint8_t channels, int32_t init_value );

/* PWM functions */ 
EXTERNC MDAQ_API int mlink_pwm_init( int *link_fd, uint8_t module, uint32_t period, uint8_t active_low, float duty_a, float duty_b );
EXTERNC MDAQ_API int mlink_pwm_write( int *link_fd, uint8_t module, float duty_a, float duty_b );

/* AI functions */ 
EXTERNC MDAQ_API int mlink_ai_read( int *link_fd, uint8_t *channels, uint8_t ch_count, double *range, uint8_t *mode, double *data );
EXTERNC MDAQ_API int mlink_ai_scan_init(int *link_fd, uint8_t *channels, uint8_t ch_count, double *range, uint8_t *mode, float *rate, float duration);
EXTERNC MDAQ_API int mlink_ai_scan(double *data, uint32_t scan_count, int32_t blocking);
EXTERNC MDAQ_API int mlink_ai_scan_stop( void );

/* AO functions */ 
EXTERNC MDAQ_API int mlink_ao_write( int *link_fd, uint8_t *channels, uint8_t ch_count, double *range, uint8_t mode, double *data );
EXTERNC MDAQ_API int mlink_ao_scan_init(int *link_fd, uint8_t *channels, uint8_t ch_count, float *data, int data_size, double *range, uint8_t stream_mode, float rate, float duration);
EXTERNC MDAQ_API int mlink_ao_scan(int *link_fd);
EXTERNC MDAQ_API int mlink_ao_scan_stop(int *link_fd);
EXTERNC MDAQ_API int mlink_ao_scan_data(int *link_fd, uint8_t *channels, int ch_count, float *data, int data_size, uint8_t opt);

#endif /* _MLINK_H_ */ 
