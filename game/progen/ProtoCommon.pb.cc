// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: ProtoCommon.proto
// Protobuf C++ Version: 5.29.3

#include "ProtoCommon.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr HeartBeatResponse::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : clienttime_{::int64_t{0}},
        servertime_{::int64_t{0}},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR HeartBeatResponse::HeartBeatResponse(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct HeartBeatResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HeartBeatResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~HeartBeatResponseDefaultTypeInternal() {}
  union {
    HeartBeatResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartBeatResponseDefaultTypeInternal _HeartBeatResponse_default_instance_;

inline constexpr HeartBeatRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : clienttime_{::int64_t{0}},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR HeartBeatRequest::HeartBeatRequest(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct HeartBeatRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HeartBeatRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~HeartBeatRequestDefaultTypeInternal() {}
  union {
    HeartBeatRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartBeatRequestDefaultTypeInternal _HeartBeatRequest_default_instance_;

inline constexpr ErrorMessage::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : errcode_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ErrorMessage::ErrorMessage(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct ErrorMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ErrorMessageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ErrorMessageDefaultTypeInternal() {}
  union {
    ErrorMessage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ErrorMessageDefaultTypeInternal _ErrorMessage_default_instance_;
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_ProtoCommon_2eproto[2];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_ProtoCommon_2eproto = nullptr;
const ::uint32_t
    TableStruct_ProtoCommon_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::ErrorMessage, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::ErrorMessage, _impl_.errcode_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::HeartBeatRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::HeartBeatRequest, _impl_.clienttime_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::HeartBeatResponse, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::HeartBeatResponse, _impl_.clienttime_),
        PROTOBUF_FIELD_OFFSET(::HeartBeatResponse, _impl_.servertime_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::ErrorMessage)},
        {9, -1, -1, sizeof(::HeartBeatRequest)},
        {18, -1, -1, sizeof(::HeartBeatResponse)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_ErrorMessage_default_instance_._instance,
    &::_HeartBeatRequest_default_instance_._instance,
    &::_HeartBeatResponse_default_instance_._instance,
};
const char descriptor_table_protodef_ProtoCommon_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\021ProtoCommon.proto\"\037\n\014ErrorMessage\022\017\n\007e"
    "rrCode\030\001 \001(\005\"&\n\020HeartBeatRequest\022\022\n\nclie"
    "ntTime\030\001 \001(\003\";\n\021HeartBeatResponse\022\022\n\ncli"
    "entTime\030\001 \001(\003\022\022\n\nserverTime\030\002 \001(\003*\263\001\n\nPr"
    "otoError\022\013\n\007SUCCESS\020\000\022\n\n\006FAILED\020\001\022\027\n\023INV"
    "ALID_LOGIN_TOKEN\020\002\022\027\n\023INVALID_GAME_TICKE"
    "T\020\003\022\021\n\rINVALID_PARAM\020\n\022\027\n\023NAME_LENGTH_IN"
    "VALID\020\013\022\031\n\025NOTICE_LENGTH_INVALID\020\014\022\023\n\017CO"
    "ST_NOT_ENOUGH\020\r*\211\003\n\tProtoCode\022\013\n\007INVALID"
    "\020\000\022\021\n\rERROR_MESSAGE\020\001\022\026\n\022HEART_BEAT_REQU"
    "EST\020\002\022\027\n\023HEART_BEAT_RESPONSE\020\003\022\021\n\rLOGIN_"
    "REQUEST\020\n\022\022\n\016LOGIN_RESPONSE\020\013\022\022\n\016LOGOUT_"
    "REQUEST\020\014\022\023\n\017LOGOUT_RESPONSE\020\r\022\024\n\020KICK_O"
    "UT_REQUEST\020\016\022\025\n\021KICK_OUT_RESPONSE\020\017\022\026\n\022L"
    "OGIN_INIT_REQUEST\020\024\022\030\n\024PERFORMANCE_TEST_"
    "REQ\020\025\022\030\n\024PERFORMANCE_TEST_RES\020\026\022\022\n\016DIREC"
    "T_TO_GAME\020\027\022\023\n\017DIRECT_TO_WORLD\020\030\022\034\n\030DIRE"
    "CT_FROM_WORLD_CLIENT\020\031\022\033\n\027DIRECT_FROM_GA"
    "ME_CLIENT\020\032B\033\n\016com.game.protoZ\t/protoGen"
    "b\006proto3"
};
static ::absl::once_flag descriptor_table_ProtoCommon_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_ProtoCommon_2eproto = {
    false,
    false,
    768,
    descriptor_table_protodef_ProtoCommon_2eproto,
    "ProtoCommon.proto",
    &descriptor_table_ProtoCommon_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_ProtoCommon_2eproto::offsets,
    file_level_enum_descriptors_ProtoCommon_2eproto,
    file_level_service_descriptors_ProtoCommon_2eproto,
};
const ::google::protobuf::EnumDescriptor* ProtoError_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_ProtoCommon_2eproto);
  return file_level_enum_descriptors_ProtoCommon_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t ProtoError_internal_data_[] = {
    262144u, 32u, 960u, };
bool ProtoError_IsValid(int value) {
  return 0 <= value && value <= 13 && ((15375u >> value) & 1) != 0;
}
const ::google::protobuf::EnumDescriptor* ProtoCode_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_ProtoCommon_2eproto);
  return file_level_enum_descriptors_ProtoCommon_2eproto[1];
}
PROTOBUF_CONSTINIT const uint32_t ProtoCode_internal_data_[] = {
    262144u, 32u, 8327104u, };
bool ProtoCode_IsValid(int value) {
  return 0 <= value && value <= 26 && ((133233679u >> value) & 1) != 0;
}
// ===================================================================

class ErrorMessage::_Internal {
 public:
};

ErrorMessage::ErrorMessage(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:ErrorMessage)
}
ErrorMessage::ErrorMessage(
    ::google::protobuf::Arena* arena, const ErrorMessage& from)
    : ErrorMessage(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE ErrorMessage::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void ErrorMessage::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.errcode_ = {};
}
ErrorMessage::~ErrorMessage() {
  // @@protoc_insertion_point(destructor:ErrorMessage)
  SharedDtor(*this);
}
inline void ErrorMessage::SharedDtor(MessageLite& self) {
  ErrorMessage& this_ = static_cast<ErrorMessage&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.~Impl_();
}

inline void* ErrorMessage::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) ErrorMessage(arena);
}
constexpr auto ErrorMessage::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(ErrorMessage),
                                            alignof(ErrorMessage));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull ErrorMessage::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_ErrorMessage_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &ErrorMessage::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<ErrorMessage>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &ErrorMessage::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<ErrorMessage>(), &ErrorMessage::ByteSizeLong,
            &ErrorMessage::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(ErrorMessage, _impl_._cached_size_),
        false,
    },
    &ErrorMessage::kDescriptorMethods,
    &descriptor_table_ProtoCommon_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* ErrorMessage::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> ErrorMessage::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::ErrorMessage>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int32 errCode = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(ErrorMessage, _impl_.errcode_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(ErrorMessage, _impl_.errcode_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 errCode = 1;
    {PROTOBUF_FIELD_OFFSET(ErrorMessage, _impl_.errcode_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void ErrorMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:ErrorMessage)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.errcode_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* ErrorMessage::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const ErrorMessage& this_ = static_cast<const ErrorMessage&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* ErrorMessage::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const ErrorMessage& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:ErrorMessage)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int32 errCode = 1;
          if (this_._internal_errcode() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<1>(
                    stream, this_._internal_errcode(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:ErrorMessage)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t ErrorMessage::ByteSizeLong(const MessageLite& base) {
          const ErrorMessage& this_ = static_cast<const ErrorMessage&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t ErrorMessage::ByteSizeLong() const {
          const ErrorMessage& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:ErrorMessage)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // int32 errCode = 1;
            if (this_._internal_errcode() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_errcode());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void ErrorMessage::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<ErrorMessage*>(&to_msg);
  auto& from = static_cast<const ErrorMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ErrorMessage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_errcode() != 0) {
    _this->_impl_.errcode_ = from._impl_.errcode_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ErrorMessage::CopyFrom(const ErrorMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ErrorMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void ErrorMessage::InternalSwap(ErrorMessage* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
        swap(_impl_.errcode_, other->_impl_.errcode_);
}

::google::protobuf::Metadata ErrorMessage::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class HeartBeatRequest::_Internal {
 public:
};

HeartBeatRequest::HeartBeatRequest(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:HeartBeatRequest)
}
HeartBeatRequest::HeartBeatRequest(
    ::google::protobuf::Arena* arena, const HeartBeatRequest& from)
    : HeartBeatRequest(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE HeartBeatRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void HeartBeatRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.clienttime_ = {};
}
HeartBeatRequest::~HeartBeatRequest() {
  // @@protoc_insertion_point(destructor:HeartBeatRequest)
  SharedDtor(*this);
}
inline void HeartBeatRequest::SharedDtor(MessageLite& self) {
  HeartBeatRequest& this_ = static_cast<HeartBeatRequest&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.~Impl_();
}

inline void* HeartBeatRequest::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) HeartBeatRequest(arena);
}
constexpr auto HeartBeatRequest::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(HeartBeatRequest),
                                            alignof(HeartBeatRequest));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull HeartBeatRequest::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_HeartBeatRequest_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &HeartBeatRequest::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<HeartBeatRequest>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &HeartBeatRequest::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<HeartBeatRequest>(), &HeartBeatRequest::ByteSizeLong,
            &HeartBeatRequest::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(HeartBeatRequest, _impl_._cached_size_),
        false,
    },
    &HeartBeatRequest::kDescriptorMethods,
    &descriptor_table_ProtoCommon_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* HeartBeatRequest::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> HeartBeatRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::HeartBeatRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int64 clientTime = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(HeartBeatRequest, _impl_.clienttime_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(HeartBeatRequest, _impl_.clienttime_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 clientTime = 1;
    {PROTOBUF_FIELD_OFFSET(HeartBeatRequest, _impl_.clienttime_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void HeartBeatRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:HeartBeatRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.clienttime_ = ::int64_t{0};
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* HeartBeatRequest::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const HeartBeatRequest& this_ = static_cast<const HeartBeatRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* HeartBeatRequest::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const HeartBeatRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:HeartBeatRequest)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int64 clientTime = 1;
          if (this_._internal_clienttime() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<1>(
                    stream, this_._internal_clienttime(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:HeartBeatRequest)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t HeartBeatRequest::ByteSizeLong(const MessageLite& base) {
          const HeartBeatRequest& this_ = static_cast<const HeartBeatRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t HeartBeatRequest::ByteSizeLong() const {
          const HeartBeatRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:HeartBeatRequest)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // int64 clientTime = 1;
            if (this_._internal_clienttime() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_clienttime());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void HeartBeatRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<HeartBeatRequest*>(&to_msg);
  auto& from = static_cast<const HeartBeatRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:HeartBeatRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_clienttime() != 0) {
    _this->_impl_.clienttime_ = from._impl_.clienttime_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void HeartBeatRequest::CopyFrom(const HeartBeatRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HeartBeatRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void HeartBeatRequest::InternalSwap(HeartBeatRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
        swap(_impl_.clienttime_, other->_impl_.clienttime_);
}

::google::protobuf::Metadata HeartBeatRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class HeartBeatResponse::_Internal {
 public:
};

HeartBeatResponse::HeartBeatResponse(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:HeartBeatResponse)
}
HeartBeatResponse::HeartBeatResponse(
    ::google::protobuf::Arena* arena, const HeartBeatResponse& from)
    : HeartBeatResponse(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE HeartBeatResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void HeartBeatResponse::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, clienttime_),
           0,
           offsetof(Impl_, servertime_) -
               offsetof(Impl_, clienttime_) +
               sizeof(Impl_::servertime_));
}
HeartBeatResponse::~HeartBeatResponse() {
  // @@protoc_insertion_point(destructor:HeartBeatResponse)
  SharedDtor(*this);
}
inline void HeartBeatResponse::SharedDtor(MessageLite& self) {
  HeartBeatResponse& this_ = static_cast<HeartBeatResponse&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.~Impl_();
}

inline void* HeartBeatResponse::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) HeartBeatResponse(arena);
}
constexpr auto HeartBeatResponse::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(HeartBeatResponse),
                                            alignof(HeartBeatResponse));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull HeartBeatResponse::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_HeartBeatResponse_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &HeartBeatResponse::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<HeartBeatResponse>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &HeartBeatResponse::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<HeartBeatResponse>(), &HeartBeatResponse::ByteSizeLong,
            &HeartBeatResponse::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_._cached_size_),
        false,
    },
    &HeartBeatResponse::kDescriptorMethods,
    &descriptor_table_ProtoCommon_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* HeartBeatResponse::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> HeartBeatResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::HeartBeatResponse>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int64 serverTime = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(HeartBeatResponse, _impl_.servertime_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.servertime_)}},
    // int64 clientTime = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(HeartBeatResponse, _impl_.clienttime_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.clienttime_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 clientTime = 1;
    {PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.clienttime_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // int64 serverTime = 2;
    {PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.servertime_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void HeartBeatResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:HeartBeatResponse)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.clienttime_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.servertime_) -
      reinterpret_cast<char*>(&_impl_.clienttime_)) + sizeof(_impl_.servertime_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* HeartBeatResponse::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const HeartBeatResponse& this_ = static_cast<const HeartBeatResponse&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* HeartBeatResponse::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const HeartBeatResponse& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:HeartBeatResponse)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int64 clientTime = 1;
          if (this_._internal_clienttime() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<1>(
                    stream, this_._internal_clienttime(), target);
          }

          // int64 serverTime = 2;
          if (this_._internal_servertime() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<2>(
                    stream, this_._internal_servertime(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:HeartBeatResponse)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t HeartBeatResponse::ByteSizeLong(const MessageLite& base) {
          const HeartBeatResponse& this_ = static_cast<const HeartBeatResponse&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t HeartBeatResponse::ByteSizeLong() const {
          const HeartBeatResponse& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:HeartBeatResponse)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // int64 clientTime = 1;
            if (this_._internal_clienttime() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_clienttime());
            }
            // int64 serverTime = 2;
            if (this_._internal_servertime() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_servertime());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void HeartBeatResponse::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<HeartBeatResponse*>(&to_msg);
  auto& from = static_cast<const HeartBeatResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:HeartBeatResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_clienttime() != 0) {
    _this->_impl_.clienttime_ = from._impl_.clienttime_;
  }
  if (from._internal_servertime() != 0) {
    _this->_impl_.servertime_ = from._impl_.servertime_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void HeartBeatResponse::CopyFrom(const HeartBeatResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HeartBeatResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void HeartBeatResponse::InternalSwap(HeartBeatResponse* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.servertime_)
      + sizeof(HeartBeatResponse::_impl_.servertime_)
      - PROTOBUF_FIELD_OFFSET(HeartBeatResponse, _impl_.clienttime_)>(
          reinterpret_cast<char*>(&_impl_.clienttime_),
          reinterpret_cast<char*>(&other->_impl_.clienttime_));
}

::google::protobuf::Metadata HeartBeatResponse::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_ProtoCommon_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
