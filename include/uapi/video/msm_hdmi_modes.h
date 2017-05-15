#ifndef _UAPI_MSM_HDMI_MODES_H__
#define _UAPI_MSM_HDMI_MODES_H__
#include <linux/types.h>
#include <linux/errno.h>

#define MSM_HDMI_RGB_888_24BPP_FORMAT       BIT(0)
#define MSM_HDMI_YUV_420_12BPP_FORMAT       BIT(1)

enum aspect_ratio {
	HDMI_RES_AR_INVALID,
	/* Add LGVR SVD */
	HDMI_RES_AR_3_2,
	HDMI_RES_AR_4_3,
	HDMI_RES_AR_5_4,
	HDMI_RES_AR_16_9,
	HDMI_RES_AR_16_10,
	HDMI_RES_AR_64_27,
	HDMI_RES_AR_256_135,
	HDMI_RES_AR_MAX,
};

enum msm_hdmi_s3d_mode {
	HDMI_S3D_NONE,
	HDMI_S3D_SIDE_BY_SIDE,
	HDMI_S3D_TOP_AND_BOTTOM,
	HDMI_S3D_FRAME_PACKING,
	HDMI_S3D_MAX,
};

struct msm_hdmi_mode_timing_info {
	uint32_t	video_format;
	uint32_t	active_h;
	uint32_t	front_porch_h;
	uint32_t	pulse_width_h;
	uint32_t	back_porch_h;
	uint32_t	active_low_h;
	uint32_t	active_v;
	uint32_t	front_porch_v;
	uint32_t	pulse_width_v;
	uint32_t	back_porch_v;
	uint32_t	active_low_v;
	/* Must divide by 1000 to get the actual frequency in MHZ */
	uint32_t	pixel_freq;
	/* Must divide by 1000 to get the actual frequency in HZ */
	uint32_t	refresh_rate;
	uint32_t	interlaced;
	uint32_t	supported;
	enum aspect_ratio ar;
	/* Flags indicating support for specific pixel formats */
	uint32_t        pixel_formats;
};

#define MSM_HDMI_INIT_RES_PAGE          1

#define MSM_HDMI_MODES_CEA		(1 << 0)
#define MSM_HDMI_MODES_XTND		(1 << 1)
#define MSM_HDMI_MODES_DVI		(1 << 2)
#define MSM_HDMI_MODES_ALL		(MSM_HDMI_MODES_CEA |\
					 MSM_HDMI_MODES_XTND |\
					 MSM_HDMI_MODES_DVI)

/* all video formats defined by CEA 861D */
#define HDMI_VFRMT_UNKNOWN		0
#define HDMI_VFRMT_640x480p60_4_3	1
#define HDMI_VFRMT_720x480p60_4_3	2
#define HDMI_VFRMT_720x480p60_16_9	3
#define HDMI_VFRMT_1280x720p60_16_9	4
#define HDMI_VFRMT_1920x1080i60_16_9	5
#define HDMI_VFRMT_720x480i60_4_3	6
#define HDMI_VFRMT_1440x480i60_4_3	HDMI_VFRMT_720x480i60_4_3
#define HDMI_VFRMT_720x480i60_16_9	7
#define HDMI_VFRMT_1440x480i60_16_9	HDMI_VFRMT_720x480i60_16_9
#define HDMI_VFRMT_720x240p60_4_3	8
#define HDMI_VFRMT_1440x240p60_4_3	HDMI_VFRMT_720x240p60_4_3
#define HDMI_VFRMT_720x240p60_16_9	9
#define HDMI_VFRMT_1440x240p60_16_9	HDMI_VFRMT_720x240p60_16_9
#define HDMI_VFRMT_2880x480i60_4_3	10
#define HDMI_VFRMT_2880x480i60_16_9	11
#define HDMI_VFRMT_2880x240p60_4_3	12
#define HDMI_VFRMT_2880x240p60_16_9	13
#define HDMI_VFRMT_1440x480p60_4_3	14
#define HDMI_VFRMT_1440x480p60_16_9	15
#define HDMI_VFRMT_1920x1080p60_16_9	16
#define HDMI_VFRMT_720x576p50_4_3	17
#define HDMI_VFRMT_720x576p50_16_9	18
#define HDMI_VFRMT_1280x720p50_16_9	19
#define HDMI_VFRMT_1920x1080i50_16_9	20
#define HDMI_VFRMT_720x576i50_4_3	21
#define HDMI_VFRMT_1440x576i50_4_3	HDMI_VFRMT_720x576i50_4_3
#define HDMI_VFRMT_720x576i50_16_9	22
#define HDMI_VFRMT_1440x576i50_16_9	HDMI_VFRMT_720x576i50_16_9
#define HDMI_VFRMT_720x288p50_4_3	23
#define HDMI_VFRMT_1440x288p50_4_3	HDMI_VFRMT_720x288p50_4_3
#define HDMI_VFRMT_720x288p50_16_9	24
#define HDMI_VFRMT_1440x288p50_16_9	HDMI_VFRMT_720x288p50_16_9
#define HDMI_VFRMT_2880x576i50_4_3	25
#define HDMI_VFRMT_2880x576i50_16_9	26
#define HDMI_VFRMT_2880x288p50_4_3	27
#define HDMI_VFRMT_2880x288p50_16_9	28
#define HDMI_VFRMT_1440x576p50_4_3	29
#define HDMI_VFRMT_1440x576p50_16_9	30
#define HDMI_VFRMT_1920x1080p50_16_9	31
#define HDMI_VFRMT_1920x1080p24_16_9	32
#define HDMI_VFRMT_1920x1080p25_16_9	33
#define HDMI_VFRMT_1920x1080p30_16_9	34
#define HDMI_VFRMT_2880x480p60_4_3	35
#define HDMI_VFRMT_2880x480p60_16_9	36
#define HDMI_VFRMT_2880x576p50_4_3	37
#define HDMI_VFRMT_2880x576p50_16_9	38
#define HDMI_VFRMT_1920x1250i50_16_9	39
#define HDMI_VFRMT_1920x1080i100_16_9	40
#define HDMI_VFRMT_1280x720p100_16_9	41
#define HDMI_VFRMT_720x576p100_4_3	42
#define HDMI_VFRMT_720x576p100_16_9	43
#define HDMI_VFRMT_720x576i100_4_3	44
#define HDMI_VFRMT_1440x576i100_4_3	HDMI_VFRMT_720x576i100_4_3
#define HDMI_VFRMT_720x576i100_16_9	45
#define HDMI_VFRMT_1440x576i100_16_9	HDMI_VFRMT_720x576i100_16_9
#define HDMI_VFRMT_1920x1080i120_16_9	46
#define HDMI_VFRMT_1280x720p120_16_9	47
#define HDMI_VFRMT_720x480p120_4_3	48
#define HDMI_VFRMT_720x480p120_16_9	49
#define HDMI_VFRMT_720x480i120_4_3	50
#define HDMI_VFRMT_1440x480i120_4_3	HDMI_VFRMT_720x480i120_4_3
#define HDMI_VFRMT_720x480i120_16_9	51
#define HDMI_VFRMT_1440x480i120_16_9	HDMI_VFRMT_720x480i120_16_9
#define HDMI_VFRMT_720x576p200_4_3	52
#define HDMI_VFRMT_720x576p200_16_9	53
#define HDMI_VFRMT_720x576i200_4_3	54
#define HDMI_VFRMT_1440x576i200_4_3	HDMI_VFRMT_720x576i200_4_3
#define HDMI_VFRMT_720x576i200_16_9	55
#define HDMI_VFRMT_1440x576i200_16_9	HDMI_VFRMT_720x576i200_16_9
#define HDMI_VFRMT_720x480p240_4_3	56
#define HDMI_VFRMT_720x480p240_16_9	57
#define HDMI_VFRMT_720x480i240_4_3	58
#define HDMI_VFRMT_1440x480i240_4_3	HDMI_VFRMT_720x480i240_4_3
#define HDMI_VFRMT_720x480i240_16_9	59
#define HDMI_VFRMT_1440x480i240_16_9	HDMI_VFRMT_720x480i240_16_9
#define HDMI_VFRMT_1280x720p24_16_9	60
#define HDMI_VFRMT_1280x720p25_16_9	61
#define HDMI_VFRMT_1280x720p30_16_9	62
#define HDMI_VFRMT_1920x1080p120_16_9	63
#define HDMI_VFRMT_1920x1080p100_16_9	64
#define HDMI_VFRMT_1280x720p24_64_27    65
#define HDMI_VFRMT_1280x720p25_64_27    66
#define HDMI_VFRMT_1280x720p30_64_27    67
#define HDMI_VFRMT_1280x720p50_64_27    68
#define HDMI_VFRMT_1280x720p60_64_27    69
#define HDMI_VFRMT_1280x720p100_64_27   70
#define HDMI_VFRMT_1280x720p120_64_27   71
#define HDMI_VFRMT_1920x1080p24_64_27   72
#define HDMI_VFRMT_1920x1080p25_64_27   73
#define HDMI_VFRMT_1920x1080p30_64_27   74
#define HDMI_VFRMT_1920x1080p50_64_27   75
#define HDMI_VFRMT_1920x1080p60_64_27   76
#define HDMI_VFRMT_1920x1080p100_64_27  77
#define HDMI_VFRMT_1920x1080p120_64_27  78
#define HDMI_VFRMT_1680x720p24_64_27    79
#define HDMI_VFRMT_1680x720p25_64_27    80
#define HDMI_VFRMT_1680x720p30_64_27    81
#define HDMI_VFRMT_1680x720p50_64_27    82
#define HDMI_VFRMT_1680x720p60_64_27    83
#define HDMI_VFRMT_1680x720p100_64_27   84
#define HDMI_VFRMT_1680x720p120_64_27   85
#define HDMI_VFRMT_2560x1080p24_64_27   86
#define HDMI_VFRMT_2560x1080p25_64_27   87
#define HDMI_VFRMT_2560x1080p30_64_27   88
#define HDMI_VFRMT_2560x1080p50_64_27   89
#define HDMI_VFRMT_2560x1080p60_64_27   90
#define HDMI_VFRMT_2560x1080p100_64_27  91
#define HDMI_VFRMT_2560x1080p120_64_27  92
#define HDMI_VFRMT_3840x2160p24_16_9    93
#define HDMI_VFRMT_3840x2160p25_16_9    94
#define HDMI_VFRMT_3840x2160p30_16_9    95
#define HDMI_VFRMT_3840x2160p50_16_9    96
#define HDMI_VFRMT_3840x2160p60_16_9    97
#define HDMI_VFRMT_4096x2160p24_256_135 98
#define HDMI_VFRMT_4096x2160p25_256_135 99
#define HDMI_VFRMT_4096x2160p30_256_135 100
#define HDMI_VFRMT_4096x2160p50_256_135 101
#define HDMI_VFRMT_4096x2160p60_256_135 102
#define HDMI_VFRMT_3840x2160p24_64_27   103
#define HDMI_VFRMT_3840x2160p25_64_27   104
#define HDMI_VFRMT_3840x2160p30_64_27   105
#define HDMI_VFRMT_3840x2160p50_64_27   106
#define HDMI_VFRMT_3840x2160p60_64_27   107

/* Video Identification Codes from 107-127 are reserved for the future */
#define HDMI_VFRMT_END			127

#define EVFRMT_OFF(x)			(HDMI_VFRMT_END + x)

/* extended video formats */
#define HDMI_EVFRMT_3840x2160p30_16_9	EVFRMT_OFF(1)
#define HDMI_EVFRMT_3840x2160p25_16_9	EVFRMT_OFF(2)
#define HDMI_EVFRMT_3840x2160p24_16_9	EVFRMT_OFF(3)
#define HDMI_EVFRMT_4096x2160p24_16_9	EVFRMT_OFF(4)
#define HDMI_EVFRMT_END			HDMI_EVFRMT_4096x2160p24_16_9

#define WQXGA_OFF(x)			(HDMI_EVFRMT_END + x)

/* WQXGA */
#define HDMI_VFRMT_2560x1600p60_16_9	WQXGA_OFF(1)
#define HDMI_WQXGAFRMT_END		HDMI_VFRMT_2560x1600p60_16_9

#define WXGA_OFF(x)			(HDMI_WQXGAFRMT_END + x)

/* WXGA */
#define HDMI_VFRMT_1280x800p60_16_10	WXGA_OFF(1)
#define HDMI_VFRMT_1366x768p60_16_10	WXGA_OFF(2)
#define HDMI_WXGAFRMT_END		HDMI_VFRMT_1366x768p60_16_10

#define ETI_OFF(x)			(HDMI_WXGAFRMT_END + x)

/* ESTABLISHED TIMINGS I */
#define HDMI_VFRMT_800x600p60_4_3	ETI_OFF(1)
#define ETI_VFRMT_END			HDMI_VFRMT_800x600p60_4_3

#define ETII_OFF(x)			(ETI_VFRMT_END + x)

/* ESTABLISHED TIMINGS II */
#define HDMI_VFRMT_1024x768p60_4_3	ETII_OFF(1)
#define HDMI_VFRMT_1280x1024p60_5_4	ETII_OFF(2)
#define ETII_VFRMT_END			HDMI_VFRMT_1280x1024p60_5_4

#define ETIII_OFF(x)			(ETII_VFRMT_END + x)

/* ESTABLISHED TIMINGS III */
#define HDMI_VFRMT_848x480p60_16_9	ETIII_OFF(1)
#define HDMI_VFRMT_1280x960p60_4_3	ETIII_OFF(2)
#define HDMI_VFRMT_1360x768p60_16_9	ETIII_OFF(3)
#define HDMI_VFRMT_1440x900p60_16_10	ETIII_OFF(4)
#define HDMI_VFRMT_1400x1050p60_4_3	ETIII_OFF(5)
#define HDMI_VFRMT_1680x1050p60_16_10	ETIII_OFF(6)
#define HDMI_VFRMT_1600x1200p60_4_3	ETIII_OFF(7)
#define HDMI_VFRMT_1920x1200p60_16_10	ETIII_OFF(8)
#define ETIII_VFRMT_END			HDMI_VFRMT_1920x1200p60_16_10

#define RESERVE_OFF(x)			(ETIII_VFRMT_END + x)

#define HDMI_VFRMT_RESERVE1		RESERVE_OFF(1)
#define HDMI_VFRMT_RESERVE2		RESERVE_OFF(2)
#define HDMI_VFRMT_RESERVE3		RESERVE_OFF(3)
#define HDMI_VFRMT_RESERVE4		RESERVE_OFF(4)
#define HDMI_VFRMT_RESERVE5		RESERVE_OFF(5)
#define HDMI_VFRMT_RESERVE6		RESERVE_OFF(6)
#define HDMI_VFRMT_RESERVE7		RESERVE_OFF(7)
#define HDMI_VFRMT_RESERVE8		RESERVE_OFF(8)
#define RESERVE_VFRMT_END		HDMI_VFRMT_RESERVE8

/* Disable to add timing parameter for LG VR */
//#define HDMI_VFRMT_MAX		(RESERVE_VFRMT_END + 1)

/* Add LGVR SVD LGE_S */
/* R1 TIMING I */
#define LGVR_OFF(x)			(RESERVE_VFRMT_END + x)

#define HDMI_VFRMT_1440x960p60_3_2	LGVR_OFF(1)
#define HDMI_VFRMT_1440x960p57_3_2	LGVR_OFF(2)
#define LGVR_VFRMT_END			HDMI_VFRMT_1440x960p57_3_2

#define HDMI_VFRMT_MAX			(LGVR_VFRMT_END + 1)
/* Add LGVR SVD LGE_E */

/* Timing information for supported modes */
#define VFRMT_NOT_SUPPORTED(VFRMT) \
	{VFRMT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false,		\
		HDMI_RES_AR_INVALID}

#define HDMI_VFRMT_640x480p60_4_3_TIMING				\
	{HDMI_VFRMT_640x480p60_4_3, 640, 16, 96, 48, true,		\
	 480, 10, 2, 33, true, 25200, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_720x480p60_4_3_TIMING				\
	{HDMI_VFRMT_720x480p60_4_3, 720, 16, 62, 60, true,		\
	 480, 9, 6, 30, true, 27027, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_720x480p60_16_9_TIMING				\
	{HDMI_VFRMT_720x480p60_16_9, 720, 16, 62, 60, true,		\
	 480, 9, 6, 30, true, 27027, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1280x720p60_16_9_TIMING				\
	{HDMI_VFRMT_1280x720p60_16_9, 1280, 110, 40, 220, false,	\
	 720, 5, 5, 20, false, 74250, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080i60_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080i60_16_9, 1920, 88, 44, 148, false,	\
	 540, 2, 5, 5, false, 74250, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1440x480i60_4_3_TIMING				\
	{HDMI_VFRMT_1440x480i60_4_3, 1440, 38, 124, 114, true,		\
	 240, 4, 3, 15, true, 27000, 60000, true, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1440x480i60_16_9_TIMING				\
	{HDMI_VFRMT_1440x480i60_16_9, 1440, 38, 124, 114, true,		\
	 240, 4, 3, 15, true, 27000, 60000, true, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080p60_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080p60_16_9, 1920, 88, 44, 148, false,	\
	 1080, 4, 5, 36, false, 148500, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_720x576p50_4_3_TIMING				\
	{HDMI_VFRMT_720x576p50_4_3, 720, 12, 64, 68, true,		\
	 576,  5, 5, 39, true, 27000, 50000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_720x576p50_16_9_TIMING				\
	{HDMI_VFRMT_720x576p50_16_9, 720, 12, 64, 68, true,		\
	 576,  5, 5, 39, true, 27000, 50000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1280x720p50_16_9_TIMING				\
	{HDMI_VFRMT_1280x720p50_16_9, 1280, 440, 40, 220, false,	\
	 720,  5, 5, 20, false, 74250, 50000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1440x576i50_4_3_TIMING				\
	{HDMI_VFRMT_1440x576i50_4_3, 1440, 24, 126, 138, true,		\
	 288,  2, 3, 19, true, 27000, 50000, true, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1440x576i50_16_9_TIMING				\
	{HDMI_VFRMT_1440x576i50_16_9, 1440, 24, 126, 138, true,		\
	 288,  2, 3, 19, true, 27000, 50000, true, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080p50_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080p50_16_9, 1920, 528, 44, 148, false,	\
	 1080, 4, 5, 36, false, 148500, 50000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080p24_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080p24_16_9, 1920, 638, 44, 148, false,	\
	 1080, 4, 5, 36, false, 74250, 24000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080p25_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080p25_16_9, 1920, 528, 44, 148, false,	\
	 1080, 4, 5, 36, false, 74250, 25000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1920x1080p30_16_9_TIMING				\
	{HDMI_VFRMT_1920x1080p30_16_9, 1920, 88, 44, 148, false,	\
	 1080, 4, 5, 36, false, 74250, 30000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1024x768p60_4_3_TIMING                               \
	{HDMI_VFRMT_1024x768p60_4_3, 1024, 24, 136, 160, false,         \
	768, 2, 6, 29, false, 65000, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1280x1024p60_5_4_TIMING				\
	{HDMI_VFRMT_1280x1024p60_5_4, 1280, 48, 112, 248, false,	\
	1024, 1, 3, 38, false, 108000, 60000, false, true, HDMI_RES_AR_5_4, 0}
#define HDMI_VFRMT_2560x1600p60_16_9_TIMING				\
	{HDMI_VFRMT_2560x1600p60_16_9, 2560, 48, 32, 80, false,		\
	 1600, 3, 6, 37, false, 268500, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_EVFRMT_3840x2160p30_16_9_TIMING				\
	{HDMI_EVFRMT_3840x2160p30_16_9, 3840, 176, 88, 296, false,	\
	 2160, 8, 10, 72, false, 297000, 30000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_EVFRMT_3840x2160p25_16_9_TIMING				\
	{HDMI_EVFRMT_3840x2160p25_16_9, 3840, 1056, 88, 296, false,	\
	 2160, 8, 10, 72, false, 297000, 25000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_EVFRMT_3840x2160p24_16_9_TIMING				\
	{HDMI_EVFRMT_3840x2160p24_16_9, 3840, 1276, 88, 296, false,	\
	 2160, 8, 10, 72, false, 297000, 24000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_EVFRMT_4096x2160p24_16_9_TIMING				\
	{HDMI_EVFRMT_4096x2160p24_16_9, 4096, 1020, 88, 296, false,	\
	 2160, 8, 10, 72, false, 297000, 24000, false, true, \
		HDMI_RES_AR_16_9, 0}

#define HDMI_VFRMT_800x600p60_4_3_TIMING				\
	{HDMI_VFRMT_800x600p60_4_3, 800, 40, 128, 88, false,	\
	 600, 1, 4, 23, false, 40000, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_848x480p60_16_9_TIMING				\
	{HDMI_VFRMT_848x480p60_16_9, 848, 16, 112, 112, false,	\
	 480, 6, 8, 23, false, 33750, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1280x960p60_4_3_TIMING\
	{HDMI_VFRMT_1280x960p60_4_3, 1280, 96, 112, 312, false,	\
	 960, 1, 3, 36, false, 108000, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1360x768p60_16_9_TIMING\
	{HDMI_VFRMT_1360x768p60_16_9, 1360, 64, 112, 256, false,	\
	 768, 3, 6, 18, false, 85500, 60000, false, true, HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_1440x900p60_16_10_TIMING\
	{HDMI_VFRMT_1440x900p60_16_10, 1440, 48, 32, 80, false,	\
	 900, 3, 6, 17, true, 88750, 60000, false, true, HDMI_RES_AR_16_10, 0}
#define HDMI_VFRMT_1400x1050p60_4_3_TIMING\
	{HDMI_VFRMT_1400x1050p60_4_3, 1400, 48, 32, 80, false,	\
	 1050, 3, 4, 23, true, 101000, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1680x1050p60_16_10_TIMING\
	{HDMI_VFRMT_1680x1050p60_16_10, 1680, 48, 32, 80, false,	\
	 1050, 3, 6, 21, true, 119000, 60000, false, true, HDMI_RES_AR_16_10, 0}
#define HDMI_VFRMT_1600x1200p60_4_3_TIMING\
	{HDMI_VFRMT_1600x1200p60_4_3, 1600, 64, 192, 304, false,	\
	 1200, 1, 3, 46, false, 162000, 60000, false, true, HDMI_RES_AR_4_3, 0}
#define HDMI_VFRMT_1920x1200p60_16_10_TIMING\
	{HDMI_VFRMT_1920x1200p60_16_10, 1920, 48, 32, 80, false,\
	 1200, 3, 6, 26, true, 154000, 60000, false, true, HDMI_RES_AR_16_10, 0}
#define HDMI_VFRMT_1366x768p60_16_10_TIMING\
	{HDMI_VFRMT_1366x768p60_16_10, 1366, 70, 143, 213, false,\
	 768, 3, 3, 24, false, 85500, 60000, false, true, HDMI_RES_AR_16_10, 0}
#define HDMI_VFRMT_1280x800p60_16_10_TIMING\
	{HDMI_VFRMT_1280x800p60_16_10, 1280, 72, 128, 200, true,\
	 800, 3, 6, 22, false, 83500, 60000, false, true, HDMI_RES_AR_16_10, 0}
#define HDMI_VFRMT_3840x2160p24_16_9_TIMING                             \
	{HDMI_VFRMT_3840x2160p24_16_9, 3840, 1276, 88, 296, false,      \
	 2160, 8, 10, 72, false, 297000, 24000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_3840x2160p25_16_9_TIMING                             \
	{HDMI_VFRMT_3840x2160p25_16_9, 3840, 1056, 88, 296, false,      \
	 2160, 8, 10, 72, false, 297000, 25000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_3840x2160p30_16_9_TIMING                             \
	{HDMI_VFRMT_3840x2160p30_16_9, 3840, 176, 88, 296, false,       \
	 2160, 8, 10, 72, false, 297000, 30000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_3840x2160p50_16_9_TIMING                             \
	{HDMI_VFRMT_3840x2160p50_16_9, 3840, 1056, 88, 296, false,      \
	 2160, 8, 10, 72, false, 594000, 50000, false, true, \
		HDMI_RES_AR_16_9, 0}
#define HDMI_VFRMT_3840x2160p60_16_9_TIMING                             \
	{HDMI_VFRMT_3840x2160p60_16_9, 3840, 176, 88, 296, false,       \
	 2160, 8, 10, 72, false, 594000, 60000, false, true, \
		HDMI_RES_AR_16_9, 0}

#define HDMI_VFRMT_4096x2160p24_256_135_TIMING                          \
	{HDMI_VFRMT_4096x2160p24_256_135, 4096, 1020, 88, 296, false,   \
	 2160, 8, 10, 72, false, 297000, 24000, false, true, \
		HDMI_RES_AR_256_135, 0}
#define HDMI_VFRMT_4096x2160p25_256_135_TIMING                          \
	{HDMI_VFRMT_4096x2160p25_256_135, 4096, 968, 88, 128, false,    \
	 2160, 8, 10, 72, false, 297000, 25000, false, true, \
		HDMI_RES_AR_256_135, 0}
#define HDMI_VFRMT_4096x2160p30_256_135_TIMING                          \
	{HDMI_VFRMT_4096x2160p30_256_135, 4096, 88, 88, 128, false,     \
	 2160, 8, 10, 72, false, 297000, 30000, false, true, \
		HDMI_RES_AR_256_135, 0}
#define HDMI_VFRMT_4096x2160p50_256_135_TIMING                          \
	{HDMI_VFRMT_4096x2160p50_256_135, 4096, 968, 88, 128, false,    \
	 2160, 8, 10, 72, false, 594000, 50000, false, true, \
		HDMI_RES_AR_256_135, 0}
#define HDMI_VFRMT_4096x2160p60_256_135_TIMING                          \
	{HDMI_VFRMT_4096x2160p60_256_135, 4096, 88, 88, 128, false,     \
	 2160, 8, 10, 72, false, 594000, 60000, false, true, \
		HDMI_RES_AR_256_135, 0}

#define HDMI_VFRMT_3840x2160p24_64_27_TIMING                             \
	{HDMI_VFRMT_3840x2160p24_64_27, 3840, 1276, 88, 296, false,      \
	 2160, 8, 10, 72, false, 297000, 24000, false, true, \
		HDMI_RES_AR_64_27, 0}
#define HDMI_VFRMT_3840x2160p25_64_27_TIMING                             \
	{HDMI_VFRMT_3840x2160p25_64_27, 3840, 1056, 88, 296, false,      \
	 2160, 8, 10, 72, false, 297000, 25000, false, true, \
		HDMI_RES_AR_64_27, 0}
#define HDMI_VFRMT_3840x2160p30_64_27_TIMING                             \
	{HDMI_VFRMT_3840x2160p30_64_27, 3840, 176, 88, 296, false,       \
	 2160, 8, 10, 72, false, 297000, 30000, false, true, \
		HDMI_RES_AR_64_27, 0}
#define HDMI_VFRMT_3840x2160p50_64_27_TIMING                             \
	{HDMI_VFRMT_3840x2160p50_64_27, 3840, 1056, 88, 296, false,      \
	 2160, 8, 10, 72, false, 594000, 50000, false, true, \
		HDMI_RES_AR_64_27, 0}
#define HDMI_VFRMT_3840x2160p60_64_27_TIMING                             \
	{HDMI_VFRMT_3840x2160p60_64_27, 3840, 176, 88, 296, false,       \
	 2160, 8, 10, 72, false, 594000, 60000, false, true, \
		HDMI_RES_AR_64_27, 0}
/* Add LGVR SVD LGE_S */
#define HDMI_VFRMT_1440x960p60_3_2_TIMING                             \
	{HDMI_VFRMT_1440x960p60_3_2, 1440, 52, 2, 60, false,       \
	 960, 16, 4, 16, false, 93000, 60000, false, true, \
		HDMI_RES_AR_3_2, 0}
#define HDMI_VFRMT_1440x960p57_3_2_TIMING                             \
	{HDMI_VFRMT_1440x960p57_3_2, 1440, 52, 4, 60, false,       \
	 960, 16, 4, 16, false, 89000, 57000, false, true, \
		HDMI_RES_AR_3_2, 0}
/* Add LGVR SVD LGE_E */

#define MSM_HDMI_MODES_SET_TIMING(LUT, MODE) do {		\
	struct msm_hdmi_mode_timing_info mode = MODE##_TIMING;	\
	LUT[MODE] = mode;\
	} while (0)

#define MSM_HDMI_MODES_INIT_TIMINGS(__lut)	\
do {	\
	unsigned int i;	\
	for (i = 0; i < HDMI_VFRMT_MAX; i++) {	\
		struct msm_hdmi_mode_timing_info mode =	\
			VFRMT_NOT_SUPPORTED(i);	\
		(__lut)[i] = mode;	\
	}	\
} while (0)

#define MSM_HDMI_MODES_SET_SUPP_TIMINGS(__lut, __type)	\
do {	\
	if (__type & MSM_HDMI_MODES_CEA) {	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_640x480p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_720x480p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_720x480p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1280x720p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080i60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x480i60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x480i60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_720x576p50_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_720x576p50_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1280x720p50_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x576i50_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x576i50_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080p50_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080p24_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080p25_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1080p30_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p24_16_9);  \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p25_16_9);  \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p30_16_9);  \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p50_16_9);  \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p60_16_9);  \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_4096x2160p24_256_135);\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_4096x2160p25_256_135);\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_4096x2160p30_256_135);\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_4096x2160p50_256_135);\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_4096x2160p60_256_135);\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p24_64_27); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p25_64_27); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p30_64_27); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p50_64_27); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_3840x2160p60_64_27); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x960p60_3_2); \
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x960p57_3_2); \
	}	\
	if (__type & MSM_HDMI_MODES_XTND) {	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_EVFRMT_3840x2160p30_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_EVFRMT_3840x2160p25_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_EVFRMT_3840x2160p24_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_EVFRMT_4096x2160p24_16_9);	\
	}	\
	if (__type & MSM_HDMI_MODES_DVI) {	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1024x768p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1280x1024p60_5_4);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_2560x1600p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_800x600p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_848x480p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1280x960p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1360x768p60_16_9);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1440x900p60_16_10);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1400x1050p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1680x1050p60_16_10);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1600x1200p60_4_3);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1920x1200p60_16_10);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1366x768p60_16_10);	\
		MSM_HDMI_MODES_SET_TIMING(__lut,	\
			HDMI_VFRMT_1280x800p60_16_10);	\
	}	\
} while (0)

#define MSM_HDMI_MODES_GET_DETAILS(mode, MODE) do {		\
	struct msm_hdmi_mode_timing_info info = MODE##_TIMING;	\
	*mode = info;						\
	} while (0)

#endif /* _UAPI_MSM_HDMI_MODES_H__ */
