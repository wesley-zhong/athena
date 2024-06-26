// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoCommon.proto
// Protobuf C++ Version: 4.25.3

#ifndef GOOGLE_PROTOBUF_INCLUDED_ProtoCommon_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ProtoCommon_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025003 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ProtoCommon_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_ProtoCommon_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_ProtoCommon_2eproto;
class ErrorMessage;
struct ErrorMessageDefaultTypeInternal;
extern ErrorMessageDefaultTypeInternal _ErrorMessage_default_instance_;
class HeartBeatRequest;
struct HeartBeatRequestDefaultTypeInternal;
extern HeartBeatRequestDefaultTypeInternal _HeartBeatRequest_default_instance_;
class HeartBeatResponse;
struct HeartBeatResponseDefaultTypeInternal;
extern HeartBeatResponseDefaultTypeInternal _HeartBeatResponse_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

enum ProtoError : int {
  SUCCESS = 0,
  FAILED = 1,
  INVALID_LOGIN_TOKEN = 2,
  INVALID_GAME_TICKET = 3,
  INVALID_PARAM = 10,
  NAME_LENGTH_INVALID = 11,
  NOTICE_LENGTH_INVALID = 12,
  COST_NOT_ENOUGH = 13,
  ProtoError_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  ProtoError_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool ProtoError_IsValid(int value);
extern const uint32_t ProtoError_internal_data_[];
constexpr ProtoError ProtoError_MIN = static_cast<ProtoError>(0);
constexpr ProtoError ProtoError_MAX = static_cast<ProtoError>(13);
constexpr int ProtoError_ARRAYSIZE = 13 + 1;
const ::google::protobuf::EnumDescriptor*
ProtoError_descriptor();
template <typename T>
const std::string& ProtoError_Name(T value) {
  static_assert(std::is_same<T, ProtoError>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to ProtoError_Name().");
  return ProtoError_Name(static_cast<ProtoError>(value));
}
template <>
inline const std::string& ProtoError_Name(ProtoError value) {
  return ::google::protobuf::internal::NameOfDenseEnum<ProtoError_descriptor,
                                                 0, 13>(
      static_cast<int>(value));
}
inline bool ProtoError_Parse(absl::string_view name, ProtoError* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ProtoError>(
      ProtoError_descriptor(), name, value);
}
enum ProtoCode : int {
  INVALID = 0,
  ERROR_MESSAGE = 1,
  HEART_BEAT_REQUEST = 2,
  HEART_BEAT_RESPONSE = 3,
  LOGIN_REQUEST = 10,
  LOGIN_RESPONSE = 11,
  LOGOUT_REQUEST = 12,
  LOGOUT_RESPONSE = 13,
  KICK_OUT_REQUEST = 14,
  KICK_OUT_RESPONSE = 15,
  LOGIN_INIT_REQUEST = 20,
  PERFORMANCE_TEST_REQ = 21,
  PERFORMANCE_TEST_RES = 22,
  DIRECT_TO_GAME = 23,
  DIRECT_TO_WORLD = 24,
  DIRECT_FROM_WORLD_CLIENT = 25,
  DIRECT_FROM_GAME_CLIENT = 26,
  ProtoCode_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  ProtoCode_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool ProtoCode_IsValid(int value);
extern const uint32_t ProtoCode_internal_data_[];
constexpr ProtoCode ProtoCode_MIN = static_cast<ProtoCode>(0);
constexpr ProtoCode ProtoCode_MAX = static_cast<ProtoCode>(26);
constexpr int ProtoCode_ARRAYSIZE = 26 + 1;
const ::google::protobuf::EnumDescriptor*
ProtoCode_descriptor();
template <typename T>
const std::string& ProtoCode_Name(T value) {
  static_assert(std::is_same<T, ProtoCode>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to ProtoCode_Name().");
  return ProtoCode_Name(static_cast<ProtoCode>(value));
}
template <>
inline const std::string& ProtoCode_Name(ProtoCode value) {
  return ::google::protobuf::internal::NameOfDenseEnum<ProtoCode_descriptor,
                                                 0, 26>(
      static_cast<int>(value));
}
inline bool ProtoCode_Parse(absl::string_view name, ProtoCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ProtoCode>(
      ProtoCode_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class HeartBeatResponse final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:HeartBeatResponse) */ {
 public:
  inline HeartBeatResponse() : HeartBeatResponse(nullptr) {}
  ~HeartBeatResponse() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR HeartBeatResponse(::google::protobuf::internal::ConstantInitialized);

  inline HeartBeatResponse(const HeartBeatResponse& from)
      : HeartBeatResponse(nullptr, from) {}
  HeartBeatResponse(HeartBeatResponse&& from) noexcept
    : HeartBeatResponse() {
    *this = ::std::move(from);
  }

  inline HeartBeatResponse& operator=(const HeartBeatResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline HeartBeatResponse& operator=(HeartBeatResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HeartBeatResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const HeartBeatResponse* internal_default_instance() {
    return reinterpret_cast<const HeartBeatResponse*>(
               &_HeartBeatResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(HeartBeatResponse& a, HeartBeatResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(HeartBeatResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HeartBeatResponse* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HeartBeatResponse* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HeartBeatResponse>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const HeartBeatResponse& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const HeartBeatResponse& from) {
    HeartBeatResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(HeartBeatResponse* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "HeartBeatResponse";
  }
  protected:
  explicit HeartBeatResponse(::google::protobuf::Arena* arena);
  HeartBeatResponse(::google::protobuf::Arena* arena, const HeartBeatResponse& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kClientTimeFieldNumber = 1,
    kServerTimeFieldNumber = 2,
  };
  // int64 clientTime = 1;
  void clear_clienttime() ;
  ::int64_t clienttime() const;
  void set_clienttime(::int64_t value);

  private:
  ::int64_t _internal_clienttime() const;
  void _internal_set_clienttime(::int64_t value);

  public:
  // int64 serverTime = 2;
  void clear_servertime() ;
  ::int64_t servertime() const;
  void set_servertime(::int64_t value);

  private:
  ::int64_t _internal_servertime() const;
  void _internal_set_servertime(::int64_t value);

  public:
  // @@protoc_insertion_point(class_scope:HeartBeatResponse)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int64_t clienttime_;
    ::int64_t servertime_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ProtoCommon_2eproto;
};// -------------------------------------------------------------------

class HeartBeatRequest final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:HeartBeatRequest) */ {
 public:
  inline HeartBeatRequest() : HeartBeatRequest(nullptr) {}
  ~HeartBeatRequest() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR HeartBeatRequest(::google::protobuf::internal::ConstantInitialized);

  inline HeartBeatRequest(const HeartBeatRequest& from)
      : HeartBeatRequest(nullptr, from) {}
  HeartBeatRequest(HeartBeatRequest&& from) noexcept
    : HeartBeatRequest() {
    *this = ::std::move(from);
  }

  inline HeartBeatRequest& operator=(const HeartBeatRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline HeartBeatRequest& operator=(HeartBeatRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HeartBeatRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const HeartBeatRequest* internal_default_instance() {
    return reinterpret_cast<const HeartBeatRequest*>(
               &_HeartBeatRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(HeartBeatRequest& a, HeartBeatRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(HeartBeatRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HeartBeatRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HeartBeatRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HeartBeatRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const HeartBeatRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const HeartBeatRequest& from) {
    HeartBeatRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(HeartBeatRequest* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "HeartBeatRequest";
  }
  protected:
  explicit HeartBeatRequest(::google::protobuf::Arena* arena);
  HeartBeatRequest(::google::protobuf::Arena* arena, const HeartBeatRequest& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kClientTimeFieldNumber = 1,
  };
  // int64 clientTime = 1;
  void clear_clienttime() ;
  ::int64_t clienttime() const;
  void set_clienttime(::int64_t value);

  private:
  ::int64_t _internal_clienttime() const;
  void _internal_set_clienttime(::int64_t value);

  public:
  // @@protoc_insertion_point(class_scope:HeartBeatRequest)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int64_t clienttime_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ProtoCommon_2eproto;
};// -------------------------------------------------------------------

class ErrorMessage final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ErrorMessage) */ {
 public:
  inline ErrorMessage() : ErrorMessage(nullptr) {}
  ~ErrorMessage() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ErrorMessage(::google::protobuf::internal::ConstantInitialized);

  inline ErrorMessage(const ErrorMessage& from)
      : ErrorMessage(nullptr, from) {}
  ErrorMessage(ErrorMessage&& from) noexcept
    : ErrorMessage() {
    *this = ::std::move(from);
  }

  inline ErrorMessage& operator=(const ErrorMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline ErrorMessage& operator=(ErrorMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ErrorMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const ErrorMessage* internal_default_instance() {
    return reinterpret_cast<const ErrorMessage*>(
               &_ErrorMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ErrorMessage& a, ErrorMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(ErrorMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ErrorMessage* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ErrorMessage* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ErrorMessage>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ErrorMessage& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const ErrorMessage& from) {
    ErrorMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(ErrorMessage* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "ErrorMessage";
  }
  protected:
  explicit ErrorMessage(::google::protobuf::Arena* arena);
  ErrorMessage(::google::protobuf::Arena* arena, const ErrorMessage& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrCodeFieldNumber = 1,
  };
  // int32 errCode = 1;
  void clear_errcode() ;
  ::int32_t errcode() const;
  void set_errcode(::int32_t value);

  private:
  ::int32_t _internal_errcode() const;
  void _internal_set_errcode(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:ErrorMessage)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int32_t errcode_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ProtoCommon_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ErrorMessage

// int32 errCode = 1;
inline void ErrorMessage::clear_errcode() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.errcode_ = 0;
}
inline ::int32_t ErrorMessage::errcode() const {
  // @@protoc_insertion_point(field_get:ErrorMessage.errCode)
  return _internal_errcode();
}
inline void ErrorMessage::set_errcode(::int32_t value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:ErrorMessage.errCode)
}
inline ::int32_t ErrorMessage::_internal_errcode() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.errcode_;
}
inline void ErrorMessage::_internal_set_errcode(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.errcode_ = value;
}

// -------------------------------------------------------------------

// HeartBeatRequest

// int64 clientTime = 1;
inline void HeartBeatRequest::clear_clienttime() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clienttime_ = ::int64_t{0};
}
inline ::int64_t HeartBeatRequest::clienttime() const {
  // @@protoc_insertion_point(field_get:HeartBeatRequest.clientTime)
  return _internal_clienttime();
}
inline void HeartBeatRequest::set_clienttime(::int64_t value) {
  _internal_set_clienttime(value);
  // @@protoc_insertion_point(field_set:HeartBeatRequest.clientTime)
}
inline ::int64_t HeartBeatRequest::_internal_clienttime() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.clienttime_;
}
inline void HeartBeatRequest::_internal_set_clienttime(::int64_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.clienttime_ = value;
}

// -------------------------------------------------------------------

// HeartBeatResponse

// int64 clientTime = 1;
inline void HeartBeatResponse::clear_clienttime() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clienttime_ = ::int64_t{0};
}
inline ::int64_t HeartBeatResponse::clienttime() const {
  // @@protoc_insertion_point(field_get:HeartBeatResponse.clientTime)
  return _internal_clienttime();
}
inline void HeartBeatResponse::set_clienttime(::int64_t value) {
  _internal_set_clienttime(value);
  // @@protoc_insertion_point(field_set:HeartBeatResponse.clientTime)
}
inline ::int64_t HeartBeatResponse::_internal_clienttime() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.clienttime_;
}
inline void HeartBeatResponse::_internal_set_clienttime(::int64_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.clienttime_ = value;
}

// int64 serverTime = 2;
inline void HeartBeatResponse::clear_servertime() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.servertime_ = ::int64_t{0};
}
inline ::int64_t HeartBeatResponse::servertime() const {
  // @@protoc_insertion_point(field_get:HeartBeatResponse.serverTime)
  return _internal_servertime();
}
inline void HeartBeatResponse::set_servertime(::int64_t value) {
  _internal_set_servertime(value);
  // @@protoc_insertion_point(field_set:HeartBeatResponse.serverTime)
}
inline ::int64_t HeartBeatResponse::_internal_servertime() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.servertime_;
}
inline void HeartBeatResponse::_internal_set_servertime(::int64_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.servertime_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::ProtoError> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::ProtoError>() {
  return ::ProtoError_descriptor();
}
template <>
struct is_proto_enum<::ProtoCode> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::ProtoCode>() {
  return ::ProtoCode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ProtoCommon_2eproto_2epb_2eh