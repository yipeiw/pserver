// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: system/proto/heartbeat.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "system/proto/heartbeat.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace PS {

namespace {

const ::google::protobuf::Descriptor* HeartbeatReport_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeartbeatReport_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_system_2fproto_2fheartbeat_2eproto() {
  protobuf_AddDesc_system_2fproto_2fheartbeat_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "system/proto/heartbeat.proto");
  GOOGLE_CHECK(file != NULL);
  HeartbeatReport_descriptor_ = file->message_type(0);
  static const int HeartbeatReport_offsets_[15] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, task_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, hostname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, seconds_since_epoch_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, total_time_milli_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, busy_time_milli_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, net_in_mb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, net_out_mb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, process_cpu_usage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, host_cpu_usage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, process_rss_mb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, process_virt_mb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, host_in_use_gb_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, host_in_use_percentage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, host_net_in_bw_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, host_net_out_bw_),
  };
  HeartbeatReport_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeartbeatReport_descriptor_,
      HeartbeatReport::default_instance_,
      HeartbeatReport_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartbeatReport, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeartbeatReport));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_system_2fproto_2fheartbeat_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeartbeatReport_descriptor_, &HeartbeatReport::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_system_2fproto_2fheartbeat_2eproto() {
  delete HeartbeatReport::default_instance_;
  delete HeartbeatReport_reflection_;
}

void protobuf_AddDesc_system_2fproto_2fheartbeat_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034system/proto/heartbeat.proto\022\002PS\"\373\002\n\017H"
    "eartbeatReport\022\022\n\007task_id\030\001 \001(\005:\0010\022\020\n\010ho"
    "stname\030\016 \001(\t\022\033\n\023seconds_since_epoch\030\002 \001("
    "\r\022\030\n\020total_time_milli\030\r \001(\r\022\027\n\017busy_time"
    "_milli\030\003 \001(\r\022\021\n\tnet_in_mb\030\004 \001(\r\022\022\n\nnet_o"
    "ut_mb\030\005 \001(\r\022\031\n\021process_cpu_usage\030\006 \001(\r\022\026"
    "\n\016host_cpu_usage\030\007 \001(\r\022\026\n\016process_rss_mb"
    "\030\010 \001(\r\022\027\n\017process_virt_mb\030\t \001(\r\022\026\n\016host_"
    "in_use_gb\030\n \001(\r\022\036\n\026host_in_use_percentag"
    "e\030\017 \001(\r\022\026\n\016host_net_in_bw\030\013 \001(\r\022\027\n\017host_"
    "net_out_bw\030\014 \001(\r", 416);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "system/proto/heartbeat.proto", &protobuf_RegisterTypes);
  HeartbeatReport::default_instance_ = new HeartbeatReport();
  HeartbeatReport::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_system_2fproto_2fheartbeat_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_system_2fproto_2fheartbeat_2eproto {
  StaticDescriptorInitializer_system_2fproto_2fheartbeat_2eproto() {
    protobuf_AddDesc_system_2fproto_2fheartbeat_2eproto();
  }
} static_descriptor_initializer_system_2fproto_2fheartbeat_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HeartbeatReport::kTaskIdFieldNumber;
const int HeartbeatReport::kHostnameFieldNumber;
const int HeartbeatReport::kSecondsSinceEpochFieldNumber;
const int HeartbeatReport::kTotalTimeMilliFieldNumber;
const int HeartbeatReport::kBusyTimeMilliFieldNumber;
const int HeartbeatReport::kNetInMbFieldNumber;
const int HeartbeatReport::kNetOutMbFieldNumber;
const int HeartbeatReport::kProcessCpuUsageFieldNumber;
const int HeartbeatReport::kHostCpuUsageFieldNumber;
const int HeartbeatReport::kProcessRssMbFieldNumber;
const int HeartbeatReport::kProcessVirtMbFieldNumber;
const int HeartbeatReport::kHostInUseGbFieldNumber;
const int HeartbeatReport::kHostInUsePercentageFieldNumber;
const int HeartbeatReport::kHostNetInBwFieldNumber;
const int HeartbeatReport::kHostNetOutBwFieldNumber;
#endif  // !_MSC_VER

HeartbeatReport::HeartbeatReport()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HeartbeatReport::InitAsDefaultInstance() {
}

HeartbeatReport::HeartbeatReport(const HeartbeatReport& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HeartbeatReport::SharedCtor() {
  _cached_size_ = 0;
  task_id_ = 0;
  hostname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  seconds_since_epoch_ = 0u;
  total_time_milli_ = 0u;
  busy_time_milli_ = 0u;
  net_in_mb_ = 0u;
  net_out_mb_ = 0u;
  process_cpu_usage_ = 0u;
  host_cpu_usage_ = 0u;
  process_rss_mb_ = 0u;
  process_virt_mb_ = 0u;
  host_in_use_gb_ = 0u;
  host_in_use_percentage_ = 0u;
  host_net_in_bw_ = 0u;
  host_net_out_bw_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeartbeatReport::~HeartbeatReport() {
  SharedDtor();
}

void HeartbeatReport::SharedDtor() {
  if (hostname_ != &::google::protobuf::internal::kEmptyString) {
    delete hostname_;
  }
  if (this != default_instance_) {
  }
}

void HeartbeatReport::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeartbeatReport::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeartbeatReport_descriptor_;
}

const HeartbeatReport& HeartbeatReport::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_system_2fproto_2fheartbeat_2eproto();
  return *default_instance_;
}

HeartbeatReport* HeartbeatReport::default_instance_ = NULL;

HeartbeatReport* HeartbeatReport::New() const {
  return new HeartbeatReport;
}

void HeartbeatReport::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    task_id_ = 0;
    if (has_hostname()) {
      if (hostname_ != &::google::protobuf::internal::kEmptyString) {
        hostname_->clear();
      }
    }
    seconds_since_epoch_ = 0u;
    total_time_milli_ = 0u;
    busy_time_milli_ = 0u;
    net_in_mb_ = 0u;
    net_out_mb_ = 0u;
    process_cpu_usage_ = 0u;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    host_cpu_usage_ = 0u;
    process_rss_mb_ = 0u;
    process_virt_mb_ = 0u;
    host_in_use_gb_ = 0u;
    host_in_use_percentage_ = 0u;
    host_net_in_bw_ = 0u;
    host_net_out_bw_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeartbeatReport::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 task_id = 1 [default = 0];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &task_id_)));
          set_has_task_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_seconds_since_epoch;
        break;
      }

      // optional uint32 seconds_since_epoch = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_seconds_since_epoch:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &seconds_since_epoch_)));
          set_has_seconds_since_epoch();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_busy_time_milli;
        break;
      }

      // optional uint32 busy_time_milli = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_busy_time_milli:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &busy_time_milli_)));
          set_has_busy_time_milli();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_net_in_mb;
        break;
      }

      // optional uint32 net_in_mb = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_net_in_mb:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &net_in_mb_)));
          set_has_net_in_mb();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_net_out_mb;
        break;
      }

      // optional uint32 net_out_mb = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_net_out_mb:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &net_out_mb_)));
          set_has_net_out_mb();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_process_cpu_usage;
        break;
      }

      // optional uint32 process_cpu_usage = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_process_cpu_usage:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &process_cpu_usage_)));
          set_has_process_cpu_usage();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_host_cpu_usage;
        break;
      }

      // optional uint32 host_cpu_usage = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_host_cpu_usage:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &host_cpu_usage_)));
          set_has_host_cpu_usage();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_process_rss_mb;
        break;
      }

      // optional uint32 process_rss_mb = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_process_rss_mb:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &process_rss_mb_)));
          set_has_process_rss_mb();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_process_virt_mb;
        break;
      }

      // optional uint32 process_virt_mb = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_process_virt_mb:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &process_virt_mb_)));
          set_has_process_virt_mb();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_host_in_use_gb;
        break;
      }

      // optional uint32 host_in_use_gb = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_host_in_use_gb:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &host_in_use_gb_)));
          set_has_host_in_use_gb();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_host_net_in_bw;
        break;
      }

      // optional uint32 host_net_in_bw = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_host_net_in_bw:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &host_net_in_bw_)));
          set_has_host_net_in_bw();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_host_net_out_bw;
        break;
      }

      // optional uint32 host_net_out_bw = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_host_net_out_bw:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &host_net_out_bw_)));
          set_has_host_net_out_bw();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(104)) goto parse_total_time_milli;
        break;
      }

      // optional uint32 total_time_milli = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_total_time_milli:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &total_time_milli_)));
          set_has_total_time_milli();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(114)) goto parse_hostname;
        break;
      }

      // optional string hostname = 14;
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_hostname:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_hostname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->hostname().data(), this->hostname().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(120)) goto parse_host_in_use_percentage;
        break;
      }

      // optional uint32 host_in_use_percentage = 15;
      case 15: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_host_in_use_percentage:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &host_in_use_percentage_)));
          set_has_host_in_use_percentage();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void HeartbeatReport::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 task_id = 1 [default = 0];
  if (has_task_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->task_id(), output);
  }

  // optional uint32 seconds_since_epoch = 2;
  if (has_seconds_since_epoch()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->seconds_since_epoch(), output);
  }

  // optional uint32 busy_time_milli = 3;
  if (has_busy_time_milli()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->busy_time_milli(), output);
  }

  // optional uint32 net_in_mb = 4;
  if (has_net_in_mb()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->net_in_mb(), output);
  }

  // optional uint32 net_out_mb = 5;
  if (has_net_out_mb()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->net_out_mb(), output);
  }

  // optional uint32 process_cpu_usage = 6;
  if (has_process_cpu_usage()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->process_cpu_usage(), output);
  }

  // optional uint32 host_cpu_usage = 7;
  if (has_host_cpu_usage()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->host_cpu_usage(), output);
  }

  // optional uint32 process_rss_mb = 8;
  if (has_process_rss_mb()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->process_rss_mb(), output);
  }

  // optional uint32 process_virt_mb = 9;
  if (has_process_virt_mb()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->process_virt_mb(), output);
  }

  // optional uint32 host_in_use_gb = 10;
  if (has_host_in_use_gb()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->host_in_use_gb(), output);
  }

  // optional uint32 host_net_in_bw = 11;
  if (has_host_net_in_bw()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->host_net_in_bw(), output);
  }

  // optional uint32 host_net_out_bw = 12;
  if (has_host_net_out_bw()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->host_net_out_bw(), output);
  }

  // optional uint32 total_time_milli = 13;
  if (has_total_time_milli()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(13, this->total_time_milli(), output);
  }

  // optional string hostname = 14;
  if (has_hostname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->hostname().data(), this->hostname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      14, this->hostname(), output);
  }

  // optional uint32 host_in_use_percentage = 15;
  if (has_host_in_use_percentage()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(15, this->host_in_use_percentage(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HeartbeatReport::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 task_id = 1 [default = 0];
  if (has_task_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->task_id(), target);
  }

  // optional uint32 seconds_since_epoch = 2;
  if (has_seconds_since_epoch()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->seconds_since_epoch(), target);
  }

  // optional uint32 busy_time_milli = 3;
  if (has_busy_time_milli()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->busy_time_milli(), target);
  }

  // optional uint32 net_in_mb = 4;
  if (has_net_in_mb()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->net_in_mb(), target);
  }

  // optional uint32 net_out_mb = 5;
  if (has_net_out_mb()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->net_out_mb(), target);
  }

  // optional uint32 process_cpu_usage = 6;
  if (has_process_cpu_usage()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->process_cpu_usage(), target);
  }

  // optional uint32 host_cpu_usage = 7;
  if (has_host_cpu_usage()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->host_cpu_usage(), target);
  }

  // optional uint32 process_rss_mb = 8;
  if (has_process_rss_mb()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->process_rss_mb(), target);
  }

  // optional uint32 process_virt_mb = 9;
  if (has_process_virt_mb()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(9, this->process_virt_mb(), target);
  }

  // optional uint32 host_in_use_gb = 10;
  if (has_host_in_use_gb()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->host_in_use_gb(), target);
  }

  // optional uint32 host_net_in_bw = 11;
  if (has_host_net_in_bw()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->host_net_in_bw(), target);
  }

  // optional uint32 host_net_out_bw = 12;
  if (has_host_net_out_bw()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->host_net_out_bw(), target);
  }

  // optional uint32 total_time_milli = 13;
  if (has_total_time_milli()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(13, this->total_time_milli(), target);
  }

  // optional string hostname = 14;
  if (has_hostname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->hostname().data(), this->hostname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        14, this->hostname(), target);
  }

  // optional uint32 host_in_use_percentage = 15;
  if (has_host_in_use_percentage()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(15, this->host_in_use_percentage(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HeartbeatReport::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 task_id = 1 [default = 0];
    if (has_task_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->task_id());
    }

    // optional string hostname = 14;
    if (has_hostname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->hostname());
    }

    // optional uint32 seconds_since_epoch = 2;
    if (has_seconds_since_epoch()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->seconds_since_epoch());
    }

    // optional uint32 total_time_milli = 13;
    if (has_total_time_milli()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->total_time_milli());
    }

    // optional uint32 busy_time_milli = 3;
    if (has_busy_time_milli()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->busy_time_milli());
    }

    // optional uint32 net_in_mb = 4;
    if (has_net_in_mb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->net_in_mb());
    }

    // optional uint32 net_out_mb = 5;
    if (has_net_out_mb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->net_out_mb());
    }

    // optional uint32 process_cpu_usage = 6;
    if (has_process_cpu_usage()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->process_cpu_usage());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint32 host_cpu_usage = 7;
    if (has_host_cpu_usage()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->host_cpu_usage());
    }

    // optional uint32 process_rss_mb = 8;
    if (has_process_rss_mb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->process_rss_mb());
    }

    // optional uint32 process_virt_mb = 9;
    if (has_process_virt_mb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->process_virt_mb());
    }

    // optional uint32 host_in_use_gb = 10;
    if (has_host_in_use_gb()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->host_in_use_gb());
    }

    // optional uint32 host_in_use_percentage = 15;
    if (has_host_in_use_percentage()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->host_in_use_percentage());
    }

    // optional uint32 host_net_in_bw = 11;
    if (has_host_net_in_bw()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->host_net_in_bw());
    }

    // optional uint32 host_net_out_bw = 12;
    if (has_host_net_out_bw()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->host_net_out_bw());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HeartbeatReport::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeartbeatReport* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeartbeatReport*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeartbeatReport::MergeFrom(const HeartbeatReport& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_task_id()) {
      set_task_id(from.task_id());
    }
    if (from.has_hostname()) {
      set_hostname(from.hostname());
    }
    if (from.has_seconds_since_epoch()) {
      set_seconds_since_epoch(from.seconds_since_epoch());
    }
    if (from.has_total_time_milli()) {
      set_total_time_milli(from.total_time_milli());
    }
    if (from.has_busy_time_milli()) {
      set_busy_time_milli(from.busy_time_milli());
    }
    if (from.has_net_in_mb()) {
      set_net_in_mb(from.net_in_mb());
    }
    if (from.has_net_out_mb()) {
      set_net_out_mb(from.net_out_mb());
    }
    if (from.has_process_cpu_usage()) {
      set_process_cpu_usage(from.process_cpu_usage());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_host_cpu_usage()) {
      set_host_cpu_usage(from.host_cpu_usage());
    }
    if (from.has_process_rss_mb()) {
      set_process_rss_mb(from.process_rss_mb());
    }
    if (from.has_process_virt_mb()) {
      set_process_virt_mb(from.process_virt_mb());
    }
    if (from.has_host_in_use_gb()) {
      set_host_in_use_gb(from.host_in_use_gb());
    }
    if (from.has_host_in_use_percentage()) {
      set_host_in_use_percentage(from.host_in_use_percentage());
    }
    if (from.has_host_net_in_bw()) {
      set_host_net_in_bw(from.host_net_in_bw());
    }
    if (from.has_host_net_out_bw()) {
      set_host_net_out_bw(from.host_net_out_bw());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeartbeatReport::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeartbeatReport::CopyFrom(const HeartbeatReport& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartbeatReport::IsInitialized() const {

  return true;
}

void HeartbeatReport::Swap(HeartbeatReport* other) {
  if (other != this) {
    std::swap(task_id_, other->task_id_);
    std::swap(hostname_, other->hostname_);
    std::swap(seconds_since_epoch_, other->seconds_since_epoch_);
    std::swap(total_time_milli_, other->total_time_milli_);
    std::swap(busy_time_milli_, other->busy_time_milli_);
    std::swap(net_in_mb_, other->net_in_mb_);
    std::swap(net_out_mb_, other->net_out_mb_);
    std::swap(process_cpu_usage_, other->process_cpu_usage_);
    std::swap(host_cpu_usage_, other->host_cpu_usage_);
    std::swap(process_rss_mb_, other->process_rss_mb_);
    std::swap(process_virt_mb_, other->process_virt_mb_);
    std::swap(host_in_use_gb_, other->host_in_use_gb_);
    std::swap(host_in_use_percentage_, other->host_in_use_percentage_);
    std::swap(host_net_in_bw_, other->host_net_in_bw_);
    std::swap(host_net_out_bw_, other->host_net_out_bw_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeartbeatReport::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeartbeatReport_descriptor_;
  metadata.reflection = HeartbeatReport_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace PS

// @@protoc_insertion_point(global_scope)
