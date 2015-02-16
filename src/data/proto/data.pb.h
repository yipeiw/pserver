// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: data/proto/data.proto

#ifndef PROTOBUF_data_2fproto_2fdata_2eproto__INCLUDED
#define PROTOBUF_data_2fproto_2fdata_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "util/proto/range.pb.h"
// @@protoc_insertion_point(includes)

namespace PS {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_data_2fproto_2fdata_2eproto();
void protobuf_AssignDesc_data_2fproto_2fdata_2eproto();
void protobuf_ShutdownFile_data_2fproto_2fdata_2eproto();

class DataConfig;
class HDFSConfig;

enum DataConfig_DataFormat {
  DataConfig_DataFormat_BIN = 1,
  DataConfig_DataFormat_PROTO = 2,
  DataConfig_DataFormat_TEXT = 3
};
bool DataConfig_DataFormat_IsValid(int value);
const DataConfig_DataFormat DataConfig_DataFormat_DataFormat_MIN = DataConfig_DataFormat_BIN;
const DataConfig_DataFormat DataConfig_DataFormat_DataFormat_MAX = DataConfig_DataFormat_TEXT;
const int DataConfig_DataFormat_DataFormat_ARRAYSIZE = DataConfig_DataFormat_DataFormat_MAX + 1;

const ::google::protobuf::EnumDescriptor* DataConfig_DataFormat_descriptor();
inline const ::std::string& DataConfig_DataFormat_Name(DataConfig_DataFormat value) {
  return ::google::protobuf::internal::NameOfEnum(
    DataConfig_DataFormat_descriptor(), value);
}
inline bool DataConfig_DataFormat_Parse(
    const ::std::string& name, DataConfig_DataFormat* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DataConfig_DataFormat>(
    DataConfig_DataFormat_descriptor(), name, value);
}
enum DataConfig_TextFormat {
  DataConfig_TextFormat_DENSE = 1,
  DataConfig_TextFormat_SPARSE = 2,
  DataConfig_TextFormat_SPARSE_BINARY = 3,
  DataConfig_TextFormat_ADFEA = 4,
  DataConfig_TextFormat_LIBSVM = 5,
  DataConfig_TextFormat_TERAFEA = 6,
  DataConfig_TextFormat_VW = 7
};
bool DataConfig_TextFormat_IsValid(int value);
const DataConfig_TextFormat DataConfig_TextFormat_TextFormat_MIN = DataConfig_TextFormat_DENSE;
const DataConfig_TextFormat DataConfig_TextFormat_TextFormat_MAX = DataConfig_TextFormat_VW;
const int DataConfig_TextFormat_TextFormat_ARRAYSIZE = DataConfig_TextFormat_TextFormat_MAX + 1;

const ::google::protobuf::EnumDescriptor* DataConfig_TextFormat_descriptor();
inline const ::std::string& DataConfig_TextFormat_Name(DataConfig_TextFormat value) {
  return ::google::protobuf::internal::NameOfEnum(
    DataConfig_TextFormat_descriptor(), value);
}
inline bool DataConfig_TextFormat_Parse(
    const ::std::string& name, DataConfig_TextFormat* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DataConfig_TextFormat>(
    DataConfig_TextFormat_descriptor(), name, value);
}
// ===================================================================

class DataConfig : public ::google::protobuf::Message {
 public:
  DataConfig();
  virtual ~DataConfig();

  DataConfig(const DataConfig& from);

  inline DataConfig& operator=(const DataConfig& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DataConfig& default_instance();

  void Swap(DataConfig* other);

  // implements Message ----------------------------------------------

  DataConfig* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DataConfig& from);
  void MergeFrom(const DataConfig& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef DataConfig_DataFormat DataFormat;
  static const DataFormat BIN = DataConfig_DataFormat_BIN;
  static const DataFormat PROTO = DataConfig_DataFormat_PROTO;
  static const DataFormat TEXT = DataConfig_DataFormat_TEXT;
  static inline bool DataFormat_IsValid(int value) {
    return DataConfig_DataFormat_IsValid(value);
  }
  static const DataFormat DataFormat_MIN =
    DataConfig_DataFormat_DataFormat_MIN;
  static const DataFormat DataFormat_MAX =
    DataConfig_DataFormat_DataFormat_MAX;
  static const int DataFormat_ARRAYSIZE =
    DataConfig_DataFormat_DataFormat_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  DataFormat_descriptor() {
    return DataConfig_DataFormat_descriptor();
  }
  static inline const ::std::string& DataFormat_Name(DataFormat value) {
    return DataConfig_DataFormat_Name(value);
  }
  static inline bool DataFormat_Parse(const ::std::string& name,
      DataFormat* value) {
    return DataConfig_DataFormat_Parse(name, value);
  }

  typedef DataConfig_TextFormat TextFormat;
  static const TextFormat DENSE = DataConfig_TextFormat_DENSE;
  static const TextFormat SPARSE = DataConfig_TextFormat_SPARSE;
  static const TextFormat SPARSE_BINARY = DataConfig_TextFormat_SPARSE_BINARY;
  static const TextFormat ADFEA = DataConfig_TextFormat_ADFEA;
  static const TextFormat LIBSVM = DataConfig_TextFormat_LIBSVM;
  static const TextFormat TERAFEA = DataConfig_TextFormat_TERAFEA;
  static const TextFormat VW = DataConfig_TextFormat_VW;
  static inline bool TextFormat_IsValid(int value) {
    return DataConfig_TextFormat_IsValid(value);
  }
  static const TextFormat TextFormat_MIN =
    DataConfig_TextFormat_TextFormat_MIN;
  static const TextFormat TextFormat_MAX =
    DataConfig_TextFormat_TextFormat_MAX;
  static const int TextFormat_ARRAYSIZE =
    DataConfig_TextFormat_TextFormat_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  TextFormat_descriptor() {
    return DataConfig_TextFormat_descriptor();
  }
  static inline const ::std::string& TextFormat_Name(TextFormat value) {
    return DataConfig_TextFormat_Name(value);
  }
  static inline bool TextFormat_Parse(const ::std::string& name,
      TextFormat* value) {
    return DataConfig_TextFormat_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .PS.DataConfig.DataFormat format = 1;
  inline bool has_format() const;
  inline void clear_format();
  static const int kFormatFieldNumber = 1;
  inline ::PS::DataConfig_DataFormat format() const;
  inline void set_format(::PS::DataConfig_DataFormat value);

  // optional .PS.DataConfig.TextFormat text = 2;
  inline bool has_text() const;
  inline void clear_text();
  static const int kTextFieldNumber = 2;
  inline ::PS::DataConfig_TextFormat text() const;
  inline void set_text(::PS::DataConfig_TextFormat value);

  // repeated string file = 3;
  inline int file_size() const;
  inline void clear_file();
  static const int kFileFieldNumber = 3;
  inline const ::std::string& file(int index) const;
  inline ::std::string* mutable_file(int index);
  inline void set_file(int index, const ::std::string& value);
  inline void set_file(int index, const char* value);
  inline void set_file(int index, const char* value, size_t size);
  inline ::std::string* add_file();
  inline void add_file(const ::std::string& value);
  inline void add_file(const char* value);
  inline void add_file(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& file() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_file();

  // optional .PS.HDFSConfig hdfs = 5;
  inline bool has_hdfs() const;
  inline void clear_hdfs();
  static const int kHdfsFieldNumber = 5;
  inline const ::PS::HDFSConfig& hdfs() const;
  inline ::PS::HDFSConfig* mutable_hdfs();
  inline ::PS::HDFSConfig* release_hdfs();
  inline void set_allocated_hdfs(::PS::HDFSConfig* hdfs);

  // optional .PS.PbRange range = 4;
  inline bool has_range() const;
  inline void clear_range();
  static const int kRangeFieldNumber = 4;
  inline const ::PS::PbRange& range() const;
  inline ::PS::PbRange* mutable_range();
  inline ::PS::PbRange* release_range();
  inline void set_allocated_range(::PS::PbRange* range);

  // optional bool ignore_feature_group = 6;
  inline bool has_ignore_feature_group() const;
  inline void clear_ignore_feature_group();
  static const int kIgnoreFeatureGroupFieldNumber = 6;
  inline bool ignore_feature_group() const;
  inline void set_ignore_feature_group(bool value);

  // optional int32 max_num_files_per_worker = 7 [default = -1];
  inline bool has_max_num_files_per_worker() const;
  inline void clear_max_num_files_per_worker();
  static const int kMaxNumFilesPerWorkerFieldNumber = 7;
  inline ::google::protobuf::int32 max_num_files_per_worker() const;
  inline void set_max_num_files_per_worker(::google::protobuf::int32 value);

  // optional int32 max_num_lines_per_file = 8 [default = -1];
  inline bool has_max_num_lines_per_file() const;
  inline void clear_max_num_lines_per_file();
  static const int kMaxNumLinesPerFileFieldNumber = 8;
  inline ::google::protobuf::int32 max_num_lines_per_file() const;
  inline void set_max_num_lines_per_file(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PS.DataConfig)
 private:
  inline void set_has_format();
  inline void clear_has_format();
  inline void set_has_text();
  inline void clear_has_text();
  inline void set_has_hdfs();
  inline void clear_has_hdfs();
  inline void set_has_range();
  inline void clear_has_range();
  inline void set_has_ignore_feature_group();
  inline void clear_has_ignore_feature_group();
  inline void set_has_max_num_files_per_worker();
  inline void clear_has_max_num_files_per_worker();
  inline void set_has_max_num_lines_per_file();
  inline void clear_has_max_num_lines_per_file();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  int format_;
  int text_;
  ::google::protobuf::RepeatedPtrField< ::std::string> file_;
  ::PS::HDFSConfig* hdfs_;
  ::PS::PbRange* range_;
  bool ignore_feature_group_;
  ::google::protobuf::int32 max_num_files_per_worker_;
  ::google::protobuf::int32 max_num_lines_per_file_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_data_2fproto_2fdata_2eproto();
  friend void protobuf_AssignDesc_data_2fproto_2fdata_2eproto();
  friend void protobuf_ShutdownFile_data_2fproto_2fdata_2eproto();

  void InitAsDefaultInstance();
  static DataConfig* default_instance_;
};
// -------------------------------------------------------------------

class HDFSConfig : public ::google::protobuf::Message {
 public:
  HDFSConfig();
  virtual ~HDFSConfig();

  HDFSConfig(const HDFSConfig& from);

  inline HDFSConfig& operator=(const HDFSConfig& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HDFSConfig& default_instance();

  void Swap(HDFSConfig* other);

  // implements Message ----------------------------------------------

  HDFSConfig* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HDFSConfig& from);
  void MergeFrom(const HDFSConfig& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string home = 1;
  inline bool has_home() const;
  inline void clear_home();
  static const int kHomeFieldNumber = 1;
  inline const ::std::string& home() const;
  inline void set_home(const ::std::string& value);
  inline void set_home(const char* value);
  inline void set_home(const char* value, size_t size);
  inline ::std::string* mutable_home();
  inline ::std::string* release_home();
  inline void set_allocated_home(::std::string* home);

  // optional string ugi = 2;
  inline bool has_ugi() const;
  inline void clear_ugi();
  static const int kUgiFieldNumber = 2;
  inline const ::std::string& ugi() const;
  inline void set_ugi(const ::std::string& value);
  inline void set_ugi(const char* value);
  inline void set_ugi(const char* value, size_t size);
  inline ::std::string* mutable_ugi();
  inline ::std::string* release_ugi();
  inline void set_allocated_ugi(::std::string* ugi);

  // optional string namenode = 4;
  inline bool has_namenode() const;
  inline void clear_namenode();
  static const int kNamenodeFieldNumber = 4;
  inline const ::std::string& namenode() const;
  inline void set_namenode(const ::std::string& value);
  inline void set_namenode(const char* value);
  inline void set_namenode(const char* value, size_t size);
  inline ::std::string* mutable_namenode();
  inline ::std::string* release_namenode();
  inline void set_allocated_namenode(::std::string* namenode);

  // @@protoc_insertion_point(class_scope:PS.HDFSConfig)
 private:
  inline void set_has_home();
  inline void clear_has_home();
  inline void set_has_ugi();
  inline void clear_has_ugi();
  inline void set_has_namenode();
  inline void clear_has_namenode();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* home_;
  ::std::string* ugi_;
  ::std::string* namenode_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_data_2fproto_2fdata_2eproto();
  friend void protobuf_AssignDesc_data_2fproto_2fdata_2eproto();
  friend void protobuf_ShutdownFile_data_2fproto_2fdata_2eproto();

  void InitAsDefaultInstance();
  static HDFSConfig* default_instance_;
};
// ===================================================================


// ===================================================================

// DataConfig

// required .PS.DataConfig.DataFormat format = 1;
inline bool DataConfig::has_format() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DataConfig::set_has_format() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DataConfig::clear_has_format() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DataConfig::clear_format() {
  format_ = 1;
  clear_has_format();
}
inline ::PS::DataConfig_DataFormat DataConfig::format() const {
  return static_cast< ::PS::DataConfig_DataFormat >(format_);
}
inline void DataConfig::set_format(::PS::DataConfig_DataFormat value) {
  assert(::PS::DataConfig_DataFormat_IsValid(value));
  set_has_format();
  format_ = value;
}

// optional .PS.DataConfig.TextFormat text = 2;
inline bool DataConfig::has_text() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void DataConfig::set_has_text() {
  _has_bits_[0] |= 0x00000002u;
}
inline void DataConfig::clear_has_text() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void DataConfig::clear_text() {
  text_ = 1;
  clear_has_text();
}
inline ::PS::DataConfig_TextFormat DataConfig::text() const {
  return static_cast< ::PS::DataConfig_TextFormat >(text_);
}
inline void DataConfig::set_text(::PS::DataConfig_TextFormat value) {
  assert(::PS::DataConfig_TextFormat_IsValid(value));
  set_has_text();
  text_ = value;
}

// repeated string file = 3;
inline int DataConfig::file_size() const {
  return file_.size();
}
inline void DataConfig::clear_file() {
  file_.Clear();
}
inline const ::std::string& DataConfig::file(int index) const {
  return file_.Get(index);
}
inline ::std::string* DataConfig::mutable_file(int index) {
  return file_.Mutable(index);
}
inline void DataConfig::set_file(int index, const ::std::string& value) {
  file_.Mutable(index)->assign(value);
}
inline void DataConfig::set_file(int index, const char* value) {
  file_.Mutable(index)->assign(value);
}
inline void DataConfig::set_file(int index, const char* value, size_t size) {
  file_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* DataConfig::add_file() {
  return file_.Add();
}
inline void DataConfig::add_file(const ::std::string& value) {
  file_.Add()->assign(value);
}
inline void DataConfig::add_file(const char* value) {
  file_.Add()->assign(value);
}
inline void DataConfig::add_file(const char* value, size_t size) {
  file_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
DataConfig::file() const {
  return file_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
DataConfig::mutable_file() {
  return &file_;
}

// optional .PS.HDFSConfig hdfs = 5;
inline bool DataConfig::has_hdfs() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void DataConfig::set_has_hdfs() {
  _has_bits_[0] |= 0x00000008u;
}
inline void DataConfig::clear_has_hdfs() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void DataConfig::clear_hdfs() {
  if (hdfs_ != NULL) hdfs_->::PS::HDFSConfig::Clear();
  clear_has_hdfs();
}
inline const ::PS::HDFSConfig& DataConfig::hdfs() const {
  return hdfs_ != NULL ? *hdfs_ : *default_instance_->hdfs_;
}
inline ::PS::HDFSConfig* DataConfig::mutable_hdfs() {
  set_has_hdfs();
  if (hdfs_ == NULL) hdfs_ = new ::PS::HDFSConfig;
  return hdfs_;
}
inline ::PS::HDFSConfig* DataConfig::release_hdfs() {
  clear_has_hdfs();
  ::PS::HDFSConfig* temp = hdfs_;
  hdfs_ = NULL;
  return temp;
}
inline void DataConfig::set_allocated_hdfs(::PS::HDFSConfig* hdfs) {
  delete hdfs_;
  hdfs_ = hdfs;
  if (hdfs) {
    set_has_hdfs();
  } else {
    clear_has_hdfs();
  }
}

// optional .PS.PbRange range = 4;
inline bool DataConfig::has_range() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void DataConfig::set_has_range() {
  _has_bits_[0] |= 0x00000010u;
}
inline void DataConfig::clear_has_range() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void DataConfig::clear_range() {
  if (range_ != NULL) range_->::PS::PbRange::Clear();
  clear_has_range();
}
inline const ::PS::PbRange& DataConfig::range() const {
  return range_ != NULL ? *range_ : *default_instance_->range_;
}
inline ::PS::PbRange* DataConfig::mutable_range() {
  set_has_range();
  if (range_ == NULL) range_ = new ::PS::PbRange;
  return range_;
}
inline ::PS::PbRange* DataConfig::release_range() {
  clear_has_range();
  ::PS::PbRange* temp = range_;
  range_ = NULL;
  return temp;
}
inline void DataConfig::set_allocated_range(::PS::PbRange* range) {
  delete range_;
  range_ = range;
  if (range) {
    set_has_range();
  } else {
    clear_has_range();
  }
}

// optional bool ignore_feature_group = 6;
inline bool DataConfig::has_ignore_feature_group() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void DataConfig::set_has_ignore_feature_group() {
  _has_bits_[0] |= 0x00000020u;
}
inline void DataConfig::clear_has_ignore_feature_group() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void DataConfig::clear_ignore_feature_group() {
  ignore_feature_group_ = false;
  clear_has_ignore_feature_group();
}
inline bool DataConfig::ignore_feature_group() const {
  return ignore_feature_group_;
}
inline void DataConfig::set_ignore_feature_group(bool value) {
  set_has_ignore_feature_group();
  ignore_feature_group_ = value;
}

// optional int32 max_num_files_per_worker = 7 [default = -1];
inline bool DataConfig::has_max_num_files_per_worker() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void DataConfig::set_has_max_num_files_per_worker() {
  _has_bits_[0] |= 0x00000040u;
}
inline void DataConfig::clear_has_max_num_files_per_worker() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void DataConfig::clear_max_num_files_per_worker() {
  max_num_files_per_worker_ = -1;
  clear_has_max_num_files_per_worker();
}
inline ::google::protobuf::int32 DataConfig::max_num_files_per_worker() const {
  return max_num_files_per_worker_;
}
inline void DataConfig::set_max_num_files_per_worker(::google::protobuf::int32 value) {
  set_has_max_num_files_per_worker();
  max_num_files_per_worker_ = value;
}

// optional int32 max_num_lines_per_file = 8 [default = -1];
inline bool DataConfig::has_max_num_lines_per_file() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void DataConfig::set_has_max_num_lines_per_file() {
  _has_bits_[0] |= 0x00000080u;
}
inline void DataConfig::clear_has_max_num_lines_per_file() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void DataConfig::clear_max_num_lines_per_file() {
  max_num_lines_per_file_ = -1;
  clear_has_max_num_lines_per_file();
}
inline ::google::protobuf::int32 DataConfig::max_num_lines_per_file() const {
  return max_num_lines_per_file_;
}
inline void DataConfig::set_max_num_lines_per_file(::google::protobuf::int32 value) {
  set_has_max_num_lines_per_file();
  max_num_lines_per_file_ = value;
}

// -------------------------------------------------------------------

// HDFSConfig

// optional string home = 1;
inline bool HDFSConfig::has_home() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void HDFSConfig::set_has_home() {
  _has_bits_[0] |= 0x00000001u;
}
inline void HDFSConfig::clear_has_home() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void HDFSConfig::clear_home() {
  if (home_ != &::google::protobuf::internal::kEmptyString) {
    home_->clear();
  }
  clear_has_home();
}
inline const ::std::string& HDFSConfig::home() const {
  return *home_;
}
inline void HDFSConfig::set_home(const ::std::string& value) {
  set_has_home();
  if (home_ == &::google::protobuf::internal::kEmptyString) {
    home_ = new ::std::string;
  }
  home_->assign(value);
}
inline void HDFSConfig::set_home(const char* value) {
  set_has_home();
  if (home_ == &::google::protobuf::internal::kEmptyString) {
    home_ = new ::std::string;
  }
  home_->assign(value);
}
inline void HDFSConfig::set_home(const char* value, size_t size) {
  set_has_home();
  if (home_ == &::google::protobuf::internal::kEmptyString) {
    home_ = new ::std::string;
  }
  home_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* HDFSConfig::mutable_home() {
  set_has_home();
  if (home_ == &::google::protobuf::internal::kEmptyString) {
    home_ = new ::std::string;
  }
  return home_;
}
inline ::std::string* HDFSConfig::release_home() {
  clear_has_home();
  if (home_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = home_;
    home_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void HDFSConfig::set_allocated_home(::std::string* home) {
  if (home_ != &::google::protobuf::internal::kEmptyString) {
    delete home_;
  }
  if (home) {
    set_has_home();
    home_ = home;
  } else {
    clear_has_home();
    home_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string ugi = 2;
inline bool HDFSConfig::has_ugi() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void HDFSConfig::set_has_ugi() {
  _has_bits_[0] |= 0x00000002u;
}
inline void HDFSConfig::clear_has_ugi() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void HDFSConfig::clear_ugi() {
  if (ugi_ != &::google::protobuf::internal::kEmptyString) {
    ugi_->clear();
  }
  clear_has_ugi();
}
inline const ::std::string& HDFSConfig::ugi() const {
  return *ugi_;
}
inline void HDFSConfig::set_ugi(const ::std::string& value) {
  set_has_ugi();
  if (ugi_ == &::google::protobuf::internal::kEmptyString) {
    ugi_ = new ::std::string;
  }
  ugi_->assign(value);
}
inline void HDFSConfig::set_ugi(const char* value) {
  set_has_ugi();
  if (ugi_ == &::google::protobuf::internal::kEmptyString) {
    ugi_ = new ::std::string;
  }
  ugi_->assign(value);
}
inline void HDFSConfig::set_ugi(const char* value, size_t size) {
  set_has_ugi();
  if (ugi_ == &::google::protobuf::internal::kEmptyString) {
    ugi_ = new ::std::string;
  }
  ugi_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* HDFSConfig::mutable_ugi() {
  set_has_ugi();
  if (ugi_ == &::google::protobuf::internal::kEmptyString) {
    ugi_ = new ::std::string;
  }
  return ugi_;
}
inline ::std::string* HDFSConfig::release_ugi() {
  clear_has_ugi();
  if (ugi_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = ugi_;
    ugi_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void HDFSConfig::set_allocated_ugi(::std::string* ugi) {
  if (ugi_ != &::google::protobuf::internal::kEmptyString) {
    delete ugi_;
  }
  if (ugi) {
    set_has_ugi();
    ugi_ = ugi;
  } else {
    clear_has_ugi();
    ugi_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string namenode = 4;
inline bool HDFSConfig::has_namenode() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void HDFSConfig::set_has_namenode() {
  _has_bits_[0] |= 0x00000004u;
}
inline void HDFSConfig::clear_has_namenode() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void HDFSConfig::clear_namenode() {
  if (namenode_ != &::google::protobuf::internal::kEmptyString) {
    namenode_->clear();
  }
  clear_has_namenode();
}
inline const ::std::string& HDFSConfig::namenode() const {
  return *namenode_;
}
inline void HDFSConfig::set_namenode(const ::std::string& value) {
  set_has_namenode();
  if (namenode_ == &::google::protobuf::internal::kEmptyString) {
    namenode_ = new ::std::string;
  }
  namenode_->assign(value);
}
inline void HDFSConfig::set_namenode(const char* value) {
  set_has_namenode();
  if (namenode_ == &::google::protobuf::internal::kEmptyString) {
    namenode_ = new ::std::string;
  }
  namenode_->assign(value);
}
inline void HDFSConfig::set_namenode(const char* value, size_t size) {
  set_has_namenode();
  if (namenode_ == &::google::protobuf::internal::kEmptyString) {
    namenode_ = new ::std::string;
  }
  namenode_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* HDFSConfig::mutable_namenode() {
  set_has_namenode();
  if (namenode_ == &::google::protobuf::internal::kEmptyString) {
    namenode_ = new ::std::string;
  }
  return namenode_;
}
inline ::std::string* HDFSConfig::release_namenode() {
  clear_has_namenode();
  if (namenode_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = namenode_;
    namenode_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void HDFSConfig::set_allocated_namenode(::std::string* namenode) {
  if (namenode_ != &::google::protobuf::internal::kEmptyString) {
    delete namenode_;
  }
  if (namenode) {
    set_has_namenode();
    namenode_ = namenode;
  } else {
    clear_has_namenode();
    namenode_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace PS

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PS::DataConfig_DataFormat>() {
  return ::PS::DataConfig_DataFormat_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PS::DataConfig_TextFormat>() {
  return ::PS::DataConfig_TextFormat_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_data_2fproto_2fdata_2eproto__INCLUDED
