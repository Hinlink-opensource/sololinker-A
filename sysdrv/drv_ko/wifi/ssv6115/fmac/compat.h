#ifndef _COMPAT_H_
#define _COMPAT_H_

/* CFG80211 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 5, 0)
#define NL80211_NUM_ACS                NL80211_TXQ_Q_BK + 1
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 8, 0)) && !defined(IEEE80211_NUM_TIDS)
#define IEEE80211_NUM_TIDS             16
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 20, 0) && !defined(IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_MASK)
#define IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_MASK IEEE80211_HE_MAC_CAP3_MAX_A_AMPDU_LEN_EXP_MASK
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0)
#define IEEE80211_RADIOTAP_HE 23
#define IEEE80211_RADIOTAP_HE_MU 24

struct ieee80211_radiotap_he {
	__le16 data1, data2, data3, data4, data5, data6;
};

enum ieee80211_radiotap_he_bits {
    IEEE80211_RADIOTAP_HE_DATA1_FORMAT_MASK		= 3,
    IEEE80211_RADIOTAP_HE_DATA1_FORMAT_SU		= 0,
    IEEE80211_RADIOTAP_HE_DATA1_FORMAT_EXT_SU	= 1,
    IEEE80211_RADIOTAP_HE_DATA1_FORMAT_MU		= 2,
    IEEE80211_RADIOTAP_HE_DATA1_FORMAT_TRIG		= 3,

    IEEE80211_RADIOTAP_HE_DATA1_BSS_COLOR_KNOWN	        = 0x0004,
    IEEE80211_RADIOTAP_HE_DATA1_BEAM_CHANGE_KNOWN	    = 0x0008,
    IEEE80211_RADIOTAP_HE_DATA1_UL_DL_KNOWN		        = 0x0010,
    IEEE80211_RADIOTAP_HE_DATA1_DATA_MCS_KNOWN	        = 0x0020,
    IEEE80211_RADIOTAP_HE_DATA1_DATA_DCM_KNOWN	        = 0x0040,
    IEEE80211_RADIOTAP_HE_DATA1_CODING_KNOWN	        = 0x0080,
    IEEE80211_RADIOTAP_HE_DATA1_LDPC_XSYMSEG_KNOWN	    = 0x0100,
    IEEE80211_RADIOTAP_HE_DATA1_STBC_KNOWN		        = 0x0200,
    IEEE80211_RADIOTAP_HE_DATA1_SPTL_REUSE_KNOWN	    = 0x0400,
    IEEE80211_RADIOTAP_HE_DATA1_SPTL_REUSE2_KNOWN	    = 0x0800,
    IEEE80211_RADIOTAP_HE_DATA1_SPTL_REUSE3_KNOWN	    = 0x1000,
    IEEE80211_RADIOTAP_HE_DATA1_SPTL_REUSE4_KNOWN	    = 0x2000,
    IEEE80211_RADIOTAP_HE_DATA1_BW_RU_ALLOC_KNOWN	    = 0x4000,
    IEEE80211_RADIOTAP_HE_DATA1_DOPPLER_KNOWN	        = 0x8000,

    IEEE80211_RADIOTAP_HE_DATA2_PRISEC_80_KNOWN	        = 0x0001,
    IEEE80211_RADIOTAP_HE_DATA2_GI_KNOWN		        = 0x0002,
    IEEE80211_RADIOTAP_HE_DATA2_NUM_LTF_SYMS_KNOWN	    = 0x0004,
    IEEE80211_RADIOTAP_HE_DATA2_PRE_FEC_PAD_KNOWN	    = 0x0008,
    IEEE80211_RADIOTAP_HE_DATA2_TXBF_KNOWN		        = 0x0010,
    IEEE80211_RADIOTAP_HE_DATA2_PE_DISAMBIG_KNOWN	    = 0x0020,
    IEEE80211_RADIOTAP_HE_DATA2_TXOP_KNOWN		        = 0x0040,
    IEEE80211_RADIOTAP_HE_DATA2_MIDAMBLE_KNOWN	        = 0x0080,
    IEEE80211_RADIOTAP_HE_DATA2_RU_OFFSET		        = 0x3f00,
    IEEE80211_RADIOTAP_HE_DATA2_RU_OFFSET_KNOWN	        = 0x4000,
    IEEE80211_RADIOTAP_HE_DATA2_PRISEC_80_SEC	        = 0x8000,

    IEEE80211_RADIOTAP_HE_DATA3_BSS_COLOR		= 0x003f,
    IEEE80211_RADIOTAP_HE_DATA3_BEAM_CHANGE		= 0x0040,
    IEEE80211_RADIOTAP_HE_DATA3_UL_DL		    = 0x0080,
    IEEE80211_RADIOTAP_HE_DATA3_DATA_MCS		= 0x0f00,
    IEEE80211_RADIOTAP_HE_DATA3_DATA_DCM		= 0x1000,
    IEEE80211_RADIOTAP_HE_DATA3_CODING		    = 0x2000,
    IEEE80211_RADIOTAP_HE_DATA3_LDPC_XSYMSEG	= 0x4000,
    IEEE80211_RADIOTAP_HE_DATA3_STBC		    = 0x8000,

    IEEE80211_RADIOTAP_HE_DATA4_SU_MU_SPTL_REUSE	= 0x000f,
    IEEE80211_RADIOTAP_HE_DATA4_MU_STA_ID		    = 0x7ff0,
    IEEE80211_RADIOTAP_HE_DATA4_TB_SPTL_REUSE1	    = 0x000f,
    IEEE80211_RADIOTAP_HE_DATA4_TB_SPTL_REUSE2	    = 0x00f0,
    IEEE80211_RADIOTAP_HE_DATA4_TB_SPTL_REUSE3	    = 0x0f00,
    IEEE80211_RADIOTAP_HE_DATA4_TB_SPTL_REUSE4	    = 0xf000,

    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC	    = 0x000f,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_20MHZ	= 0,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_40MHZ	= 1,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_80MHZ	= 2,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_160MHZ	= 3,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_26T	= 4,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_52T	= 5,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_106T	= 6,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_242T	= 7,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_484T	= 8,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_996T	= 9,
    IEEE80211_RADIOTAP_HE_DATA5_DATA_BW_RU_ALLOC_2x996T	= 10,

    IEEE80211_RADIOTAP_HE_DATA5_GI			    = 0x0030,
    IEEE80211_RADIOTAP_HE_DATA5_GI_0_8			= 0,
    IEEE80211_RADIOTAP_HE_DATA5_GI_1_6			= 1,
    IEEE80211_RADIOTAP_HE_DATA5_GI_3_2			= 2,

    IEEE80211_RADIOTAP_HE_DATA5_LTF_SIZE		    = 0x00c0,
    IEEE80211_RADIOTAP_HE_DATA5_LTF_SIZE_UNKNOWN	= 0,
    IEEE80211_RADIOTAP_HE_DATA5_LTF_SIZE_1X			= 1,
    IEEE80211_RADIOTAP_HE_DATA5_LTF_SIZE_2X			= 2,
    IEEE80211_RADIOTAP_HE_DATA5_LTF_SIZE_4X			= 3,
    IEEE80211_RADIOTAP_HE_DATA5_NUM_LTF_SYMS	    = 0x0700,
    IEEE80211_RADIOTAP_HE_DATA5_PRE_FEC_PAD		    = 0x3000,
    IEEE80211_RADIOTAP_HE_DATA5_TXBF		        = 0x4000,
    IEEE80211_RADIOTAP_HE_DATA5_PE_DISAMBIG		    = 0x8000,

    IEEE80211_RADIOTAP_HE_DATA6_NSTS		        = 0x000f,
    IEEE80211_RADIOTAP_HE_DATA6_DOPPLER		        = 0x0010,
    IEEE80211_RADIOTAP_HE_DATA6_TXOP		        = 0x7f00,
    IEEE80211_RADIOTAP_HE_DATA6_MIDAMBLE_PDCTY	    = 0x8000,
};

struct ieee80211_radiotap_he_mu {
	__le16 flags1, flags2;
	u8 ru_ch1[4];
	u8 ru_ch2[4];
};

enum ieee80211_radiotap_he_mu_bits {
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_MCS		        = 0x000f,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_MCS_KNOWN		    = 0x0010,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_DCM		        = 0x0020,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_DCM_KNOWN		    = 0x0040,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_CH2_CTR_26T_RU_KNOWN	= 0x0080,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_CH1_RU_KNOWN		    = 0x0100,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_CH2_RU_KNOWN		    = 0x0200,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_CH1_CTR_26T_RU_KNOWN	= 0x1000,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_CH1_CTR_26T_RU		    = 0x2000,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_COMP_KNOWN	    = 0x4000,
	IEEE80211_RADIOTAP_HE_MU_FLAGS1_SIG_B_SYMS_USERS_KNOWN	= 0x8000,

	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW	    = 0x0003,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW_20MHZ	= 0x0000,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW_40MHZ	= 0x0001,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW_80MHZ	= 0x0002,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW_160MHZ	= 0x0003,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_BW_FROM_SIG_A_BW_KNOWN	= 0x0004,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_SIG_B_COMP		        = 0x0008,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_SIG_B_SYMS_USERS	    = 0x00f0,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_PUNC_FROM_SIG_A_BW	    = 0x0300,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_PUNC_FROM_SIG_A_BW_KNOWN = 0x0400,
	IEEE80211_RADIOTAP_HE_MU_FLAGS2_CH2_CTR_26T_RU		    = 0x0800,
};
#endif

#if defined(CONFIG_WPA_SUPPLICANT_CTL)
enum ssv_auth_type {
    SSV_NL80211_AUTHTYPE_SAE = NL80211_AUTHTYPE_NETWORK_EAP + 1,
};
 
enum ssv_feature_flags {
    SSV_NL80211_FEATURE_SAE  = 1 << 5,
};
#endif
 
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 8, 0) && !defined(CONFIG_SSV_CHANNEL_FOLLOW)
/**
 * enum nl80211_chan_width - channel width definitions
 *
 * These values are used with the %NL80211_ATTR_CHANNEL_WIDTH
 * attribute.
 *
 * @NL80211_CHAN_WIDTH_20_NOHT: 20 MHz, non-HT channel
 * @NL80211_CHAN_WIDTH_20: 20 MHz HT channel
 * @NL80211_CHAN_WIDTH_40: 40 MHz channel, the %NL80211_ATTR_CENTER_FREQ1
 *      attribute must be provided as well
 * @NL80211_CHAN_WIDTH_80: 80 MHz channel, the %NL80211_ATTR_CENTER_FREQ1
 *      attribute must be provided as well
 * @NL80211_CHAN_WIDTH_80P80: 80+80 MHz channel, the %NL80211_ATTR_CENTER_FREQ1
 *      and %NL80211_ATTR_CENTER_FREQ2 attributes must be provided as well
 * @NL80211_CHAN_WIDTH_160: 160 MHz channel, the %NL80211_ATTR_CENTER_FREQ1
 *      attribute must be provided as well
 */
enum nl80211_chan_width {
	NL80211_CHAN_WIDTH_20_NOHT,
	NL80211_CHAN_WIDTH_20,
	NL80211_CHAN_WIDTH_40,
	NL80211_CHAN_WIDTH_80,
	NL80211_CHAN_WIDTH_80P80,
	NL80211_CHAN_WIDTH_160,
};
 
/**
 * struct cfg80211_chan_def - channel definition
 * @chan: the (control) channel
 * @width: channel width
 * @center_freq1: center frequency of first segment
 * @center_freq2: center frequency of second segment
 *      (only with 80+80 MHz)
 */
struct cfg80211_chan_def {
	struct ieee80211_channel *chan;
	enum nl80211_chan_width width;
	u32 center_freq1;
	u32 center_freq2;
};
#endif


/* Generic */
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 9, 0)
#define __bf_shf(x) (__builtin_ffsll(x) - 1)
#define FIELD_PREP(_mask, _val) \
	(((typeof(_mask))(_val) << __bf_shf(_mask)) & (_mask))
#else
#include <linux/bitfield.h>
#endif

#endif
