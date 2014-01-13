/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __UBI_USER_H__
#define __UBI_USER_H__

#include <linux/types.h>

#define UBI_VOL_NUM_AUTO (-1)
#define UBI_DEV_NUM_AUTO (-1)

#define UBI_MAX_VOLUME_NAME 127

#define UBI_IOC_MAGIC 'o'

#define UBI_IOCMKVOL _IOW(UBI_IOC_MAGIC, 0, struct ubi_mkvol_req)

#define UBI_IOCRMVOL _IOW(UBI_IOC_MAGIC, 1, __s32)

#define UBI_IOCRSVOL _IOW(UBI_IOC_MAGIC, 2, struct ubi_rsvol_req)

#define UBI_IOCRNVOL _IOW(UBI_IOC_MAGIC, 3, struct ubi_rnvol_req)

#define UBI_CTRL_IOC_MAGIC 'o'

#define UBI_IOCATT _IOW(UBI_CTRL_IOC_MAGIC, 64, struct ubi_attach_req)

#define UBI_IOCDET _IOW(UBI_CTRL_IOC_MAGIC, 65, __s32)

#define UBI_VOL_IOC_MAGIC 'O'

#define UBI_IOCVOLUP _IOW(UBI_VOL_IOC_MAGIC, 0, __s64)

#define UBI_IOCEBER _IOW(UBI_VOL_IOC_MAGIC, 1, __s32)

#define UBI_IOCEBCH _IOW(UBI_VOL_IOC_MAGIC, 2, __s32)

#define UBI_IOCEBMAP _IOW(UBI_VOL_IOC_MAGIC, 3, struct ubi_map_req)

#define UBI_IOCEBUNMAP _IOW(UBI_VOL_IOC_MAGIC, 4, __s32)

#define UBI_IOCEBISMAP _IOR(UBI_VOL_IOC_MAGIC, 5, __s32)

#define UBI_IOCSETPROP _IOW(UBI_VOL_IOC_MAGIC, 6, struct ubi_set_prop_req)

#define MAX_UBI_MTD_NAME_LEN 127

#define UBI_MAX_RNVOL 32

enum {
 UBI_LONGTERM = 1,
 UBI_SHORTTERM = 2,
 UBI_UNKNOWN = 3,
};

enum {
 UBI_DYNAMIC_VOLUME = 3,
 UBI_STATIC_VOLUME = 4,
};

enum {
 UBI_PROP_DIRECT_WRITE = 1,
};

struct ubi_attach_req {
 __s32 ubi_num;
 __s32 mtd_num;
 __s32 vid_hdr_offset;
 __s8 padding[12];
};

struct ubi_mkvol_req {
 __s32 vol_id;
 __s32 alignment;
 __s64 bytes;
 __s8 vol_type;
 __s8 padding1;
 __s16 name_len;
 __s8 padding2[4];
 char name[UBI_MAX_VOLUME_NAME + 1];
} __attribute__ ((packed));

struct ubi_rsvol_req {
 __s64 bytes;
 __s32 vol_id;
} __attribute__ ((packed));

struct ubi_rnvol_req {
 __s32 count;
 __s8 padding1[12];
 struct {
 __s32 vol_id;
 __s16 name_len;
 __s8 padding2[2];
 char name[UBI_MAX_VOLUME_NAME + 1];
 } ents[UBI_MAX_RNVOL];
} __attribute__ ((packed));

struct ubi_leb_change_req {
 __s32 lnum;
 __s32 bytes;
 __s8 dtype;
 __s8 padding[7];
} __attribute__ ((packed));

struct ubi_map_req {
 __s32 lnum;
 __s8 dtype;
 __s8 padding[3];
} __attribute__ ((packed));

struct ubi_set_prop_req {
 __u8 property;
 __u8 padding[7];
 __u64 value;
} __attribute__ ((packed));

#endif
