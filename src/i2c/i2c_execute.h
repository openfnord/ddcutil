/** @file i2c_execute.h
 *
 *  Low level functions for writing to and reading from the I2C bus,
 *  using various mechanisms.
 */
// Copyright (C) 2014-2022 Sanford Rockowitz <rockowitz@minsoft.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef I2C_EXECUTE_H_
#define I2C_EXECUTE_H_

#include "util/coredefs.h"
#include "base/status_code_mgt.h"

void set_i2c_fileio_use_timeout(bool yesno);
bool get_i2c_fileio_use_timeout();

/** Function template for I2C write function */
typedef Status_Errno_DDC (*I2C_Writer)(
      int    fd,
      Byte   slave_address,
      int    bytect,
      Byte * bytes_to_write);

/** Function template for I2C read function */
typedef Status_Errno_DDC (*I2C_Reader)(
      int fd,
      Byte   slave_addr,
      bool   read_bytewise,
      int    bytect,
      Byte * readbuf);

#ifndef I2C_IO_IOCTL_ONLY
Status_Errno_DDC i2c_fileio_writer(
      int    fd,
      Byte   slave_address,
      int    bytect,
      Byte * pbytes);

Status_Errno_DDC i2c_fileio_reader (
      int    fd,
      Byte   slave_address,
      bool   read_bytewise,
      int    bytect,
      Byte * readbuf);
#endif

Status_Errno_DDC i2c_ioctl_writer(
      int    fd,
      Byte   slave_address,
      int    bytect,
      Byte * pbytes);

Status_Errno_DDC i2c_ioctl_reader(
      int    fd,
      Byte   slave_address,
      bool   read_bytewise,
      int    bytect,
      Byte * readbuf);

void init_i2c_execute_func_name_table();

#endif /* I2C_EXECUTE_H_ */
