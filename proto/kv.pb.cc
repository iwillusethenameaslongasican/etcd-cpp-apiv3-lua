// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kv.proto

#include "kv.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_kv_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_KeyValue_kv_2eproto;
namespace mvccpb {
class KeyValueDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<KeyValue> _instance;
} _KeyValue_default_instance_;
class EventDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Event> _instance;
} _Event_default_instance_;
}  // namespace mvccpb
static void InitDefaultsscc_info_Event_kv_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mvccpb::_Event_default_instance_;
    new (ptr) ::mvccpb::Event();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mvccpb::Event::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Event_kv_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_Event_kv_2eproto}, {
      &scc_info_KeyValue_kv_2eproto.base,}};

static void InitDefaultsscc_info_KeyValue_kv_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mvccpb::_KeyValue_default_instance_;
    new (ptr) ::mvccpb::KeyValue();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mvccpb::KeyValue::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_KeyValue_kv_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_KeyValue_kv_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_kv_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_kv_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_kv_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_kv_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, key_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, create_revision_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, mod_revision_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, version_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, value_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::KeyValue, lease_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, type_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, kv_),
  PROTOBUF_FIELD_OFFSET(::mvccpb::Event, prev_kv_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::mvccpb::KeyValue)},
  { 11, -1, sizeof(::mvccpb::Event)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mvccpb::_KeyValue_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mvccpb::_Event_default_instance_),
};

const char descriptor_table_protodef_kv_2eproto[] =
  "\n\010kv.proto\022\006mvccpb\"u\n\010KeyValue\022\013\n\003key\030\001 "
  "\001(\014\022\027\n\017create_revision\030\002 \001(\003\022\024\n\014mod_revi"
  "sion\030\003 \001(\003\022\017\n\007version\030\004 \001(\003\022\r\n\005value\030\005 \001"
  "(\014\022\r\n\005lease\030\006 \001(\003\"\221\001\n\005Event\022%\n\004type\030\001 \001("
  "\0162\027.mvccpb.Event.EventType\022\034\n\002kv\030\002 \001(\0132\020"
  ".mvccpb.KeyValue\022!\n\007prev_kv\030\003 \001(\0132\020.mvcc"
  "pb.KeyValue\" \n\tEventType\022\007\n\003PUT\020\000\022\n\n\006DEL"
  "ETE\020\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_kv_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_kv_2eproto_sccs[2] = {
  &scc_info_Event_kv_2eproto.base,
  &scc_info_KeyValue_kv_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_kv_2eproto_once;
static bool descriptor_table_kv_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_kv_2eproto = {
  &descriptor_table_kv_2eproto_initialized, descriptor_table_protodef_kv_2eproto, "kv.proto", 293,
  &descriptor_table_kv_2eproto_once, descriptor_table_kv_2eproto_sccs, descriptor_table_kv_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_kv_2eproto::offsets,
  file_level_metadata_kv_2eproto, 2, file_level_enum_descriptors_kv_2eproto, file_level_service_descriptors_kv_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_kv_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_kv_2eproto), true);
namespace mvccpb {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Event_EventType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_kv_2eproto);
  return file_level_enum_descriptors_kv_2eproto[0];
}
bool Event_EventType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Event_EventType Event::PUT;
constexpr Event_EventType Event::DELETE;
constexpr Event_EventType Event::EventType_MIN;
constexpr Event_EventType Event::EventType_MAX;
constexpr int Event::EventType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void KeyValue::InitAsDefaultInstance() {
}
class KeyValue::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int KeyValue::kKeyFieldNumber;
const int KeyValue::kCreateRevisionFieldNumber;
const int KeyValue::kModRevisionFieldNumber;
const int KeyValue::kVersionFieldNumber;
const int KeyValue::kValueFieldNumber;
const int KeyValue::kLeaseFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

KeyValue::KeyValue()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mvccpb.KeyValue)
}
KeyValue::KeyValue(const KeyValue& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.key().size() > 0) {
    key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.key_);
  }
  value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.value().size() > 0) {
    value_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  ::memcpy(&create_revision_, &from.create_revision_,
    static_cast<size_t>(reinterpret_cast<char*>(&lease_) -
    reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
  // @@protoc_insertion_point(copy_constructor:mvccpb.KeyValue)
}

void KeyValue::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_KeyValue_kv_2eproto.base);
  key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&create_revision_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&lease_) -
      reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
}

KeyValue::~KeyValue() {
  // @@protoc_insertion_point(destructor:mvccpb.KeyValue)
  SharedDtor();
}

void KeyValue::SharedDtor() {
  key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  value_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void KeyValue::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const KeyValue& KeyValue::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_KeyValue_kv_2eproto.base);
  return *internal_default_instance();
}


void KeyValue::Clear() {
// @@protoc_insertion_point(message_clear_start:mvccpb.KeyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  key_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  value_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&create_revision_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&lease_) -
      reinterpret_cast<char*>(&create_revision_)) + sizeof(lease_));
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* KeyValue::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes key = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_key(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 create_revision = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          create_revision_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 mod_revision = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          mod_revision_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 version = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes value = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_value(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 lease = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          lease_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool KeyValue::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:mvccpb.KeyValue)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bytes key = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadBytes(
                input, this->mutable_key()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 create_revision = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &create_revision_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 mod_revision = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (24 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &mod_revision_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 version = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (32 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes value = 5;
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (42 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadBytes(
                input, this->mutable_value()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 lease = 6;
      case 6: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (48 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &lease_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:mvccpb.KeyValue)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:mvccpb.KeyValue)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void KeyValue::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:mvccpb.KeyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes key = 1;
  if (this->key().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->key(), output);
  }

  // int64 create_revision = 2;
  if (this->create_revision() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(2, this->create_revision(), output);
  }

  // int64 mod_revision = 3;
  if (this->mod_revision() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(3, this->mod_revision(), output);
  }

  // int64 version = 4;
  if (this->version() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(4, this->version(), output);
  }

  // bytes value = 5;
  if (this->value().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->value(), output);
  }

  // int64 lease = 6;
  if (this->lease() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(6, this->lease(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:mvccpb.KeyValue)
}

::PROTOBUF_NAMESPACE_ID::uint8* KeyValue::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:mvccpb.KeyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes key = 1;
  if (this->key().size() > 0) {
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesToArray(
        1, this->key(), target);
  }

  // int64 create_revision = 2;
  if (this->create_revision() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->create_revision(), target);
  }

  // int64 mod_revision = 3;
  if (this->mod_revision() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->mod_revision(), target);
  }

  // int64 version = 4;
  if (this->version() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->version(), target);
  }

  // bytes value = 5;
  if (this->value().size() > 0) {
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesToArray(
        5, this->value(), target);
  }

  // int64 lease = 6;
  if (this->lease() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(6, this->lease(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mvccpb.KeyValue)
  return target;
}

size_t KeyValue::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mvccpb.KeyValue)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes key = 1;
  if (this->key().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->key());
  }

  // bytes value = 5;
  if (this->value().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->value());
  }

  // int64 create_revision = 2;
  if (this->create_revision() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->create_revision());
  }

  // int64 mod_revision = 3;
  if (this->mod_revision() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->mod_revision());
  }

  // int64 version = 4;
  if (this->version() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->version());
  }

  // int64 lease = 6;
  if (this->lease() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->lease());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void KeyValue::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mvccpb.KeyValue)
  GOOGLE_DCHECK_NE(&from, this);
  const KeyValue* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<KeyValue>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mvccpb.KeyValue)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mvccpb.KeyValue)
    MergeFrom(*source);
  }
}

void KeyValue::MergeFrom(const KeyValue& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mvccpb.KeyValue)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.key().size() > 0) {

    key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.key_);
  }
  if (from.value().size() > 0) {

    value_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  if (from.create_revision() != 0) {
    set_create_revision(from.create_revision());
  }
  if (from.mod_revision() != 0) {
    set_mod_revision(from.mod_revision());
  }
  if (from.version() != 0) {
    set_version(from.version());
  }
  if (from.lease() != 0) {
    set_lease(from.lease());
  }
}

void KeyValue::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mvccpb.KeyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void KeyValue::CopyFrom(const KeyValue& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mvccpb.KeyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool KeyValue::IsInitialized() const {
  return true;
}

void KeyValue::Swap(KeyValue* other) {
  if (other == this) return;
  InternalSwap(other);
}
void KeyValue::InternalSwap(KeyValue* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  key_.Swap(&other->key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  value_.Swap(&other->value_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(create_revision_, other->create_revision_);
  swap(mod_revision_, other->mod_revision_);
  swap(version_, other->version_);
  swap(lease_, other->lease_);
}

::PROTOBUF_NAMESPACE_ID::Metadata KeyValue::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Event::InitAsDefaultInstance() {
  ::mvccpb::_Event_default_instance_._instance.get_mutable()->kv_ = const_cast< ::mvccpb::KeyValue*>(
      ::mvccpb::KeyValue::internal_default_instance());
  ::mvccpb::_Event_default_instance_._instance.get_mutable()->prev_kv_ = const_cast< ::mvccpb::KeyValue*>(
      ::mvccpb::KeyValue::internal_default_instance());
}
class Event::HasBitSetters {
 public:
  static const ::mvccpb::KeyValue& kv(const Event* msg);
  static const ::mvccpb::KeyValue& prev_kv(const Event* msg);
};

const ::mvccpb::KeyValue&
Event::HasBitSetters::kv(const Event* msg) {
  return *msg->kv_;
}
const ::mvccpb::KeyValue&
Event::HasBitSetters::prev_kv(const Event* msg) {
  return *msg->prev_kv_;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Event::kTypeFieldNumber;
const int Event::kKvFieldNumber;
const int Event::kPrevKvFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Event::Event()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mvccpb.Event)
}
Event::Event(const Event& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_kv()) {
    kv_ = new ::mvccpb::KeyValue(*from.kv_);
  } else {
    kv_ = nullptr;
  }
  if (from.has_prev_kv()) {
    prev_kv_ = new ::mvccpb::KeyValue(*from.prev_kv_);
  } else {
    prev_kv_ = nullptr;
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:mvccpb.Event)
}

void Event::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Event_kv_2eproto.base);
  ::memset(&kv_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&type_) -
      reinterpret_cast<char*>(&kv_)) + sizeof(type_));
}

Event::~Event() {
  // @@protoc_insertion_point(destructor:mvccpb.Event)
  SharedDtor();
}

void Event::SharedDtor() {
  if (this != internal_default_instance()) delete kv_;
  if (this != internal_default_instance()) delete prev_kv_;
}

void Event::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Event& Event::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Event_kv_2eproto.base);
  return *internal_default_instance();
}


void Event::Clear() {
// @@protoc_insertion_point(message_clear_start:mvccpb.Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == nullptr && kv_ != nullptr) {
    delete kv_;
  }
  kv_ = nullptr;
  if (GetArenaNoVirtual() == nullptr && prev_kv_ != nullptr) {
    delete prev_kv_;
  }
  prev_kv_ = nullptr;
  type_ = 0;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Event::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .mvccpb.Event.EventType type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          set_type(static_cast<::mvccpb::Event_EventType>(val));
        } else goto handle_unusual;
        continue;
      // .mvccpb.KeyValue kv = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(mutable_kv(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .mvccpb.KeyValue prev_kv = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(mutable_prev_kv(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Event::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:mvccpb.Event)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .mvccpb.Event.EventType type = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::mvccpb::Event_EventType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .mvccpb.KeyValue kv = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_kv()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .mvccpb.KeyValue prev_kv = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (26 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_prev_kv()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:mvccpb.Event)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:mvccpb.Event)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Event::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:mvccpb.Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .mvccpb.Event.EventType type = 1;
  if (this->type() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // .mvccpb.KeyValue kv = 2;
  if (this->has_kv()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, HasBitSetters::kv(this), output);
  }

  // .mvccpb.KeyValue prev_kv = 3;
  if (this->has_prev_kv()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, HasBitSetters::prev_kv(this), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:mvccpb.Event)
}

::PROTOBUF_NAMESPACE_ID::uint8* Event::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:mvccpb.Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .mvccpb.Event.EventType type = 1;
  if (this->type() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // .mvccpb.KeyValue kv = 2;
  if (this->has_kv()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, HasBitSetters::kv(this), target);
  }

  // .mvccpb.KeyValue prev_kv = 3;
  if (this->has_prev_kv()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, HasBitSetters::prev_kv(this), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mvccpb.Event)
  return target;
}

size_t Event::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mvccpb.Event)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .mvccpb.KeyValue kv = 2;
  if (this->has_kv()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *kv_);
  }

  // .mvccpb.KeyValue prev_kv = 3;
  if (this->has_prev_kv()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *prev_kv_);
  }

  // .mvccpb.Event.EventType type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->type());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Event::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mvccpb.Event)
  GOOGLE_DCHECK_NE(&from, this);
  const Event* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Event>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mvccpb.Event)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mvccpb.Event)
    MergeFrom(*source);
  }
}

void Event::MergeFrom(const Event& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mvccpb.Event)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_kv()) {
    mutable_kv()->::mvccpb::KeyValue::MergeFrom(from.kv());
  }
  if (from.has_prev_kv()) {
    mutable_prev_kv()->::mvccpb::KeyValue::MergeFrom(from.prev_kv());
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
}

void Event::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mvccpb.Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Event::CopyFrom(const Event& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mvccpb.Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Event::IsInitialized() const {
  return true;
}

void Event::Swap(Event* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Event::InternalSwap(Event* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(kv_, other->kv_);
  swap(prev_kv_, other->prev_kv_);
  swap(type_, other->type_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Event::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace mvccpb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mvccpb::KeyValue* Arena::CreateMaybeMessage< ::mvccpb::KeyValue >(Arena* arena) {
  return Arena::CreateInternal< ::mvccpb::KeyValue >(arena);
}
template<> PROTOBUF_NOINLINE ::mvccpb::Event* Arena::CreateMaybeMessage< ::mvccpb::Event >(Arena* arena) {
  return Arena::CreateInternal< ::mvccpb::Event >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
