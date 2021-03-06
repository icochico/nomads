// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: topology.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "topology.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ddam {

namespace {

const ::google::protobuf::Descriptor* Topology_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Topology_reflection_ = NULL;
const ::google::protobuf::Descriptor* Topology_InternalsEntry_descriptor_ = NULL;
const ::google::protobuf::Descriptor* Topology_LocalGwsEntry_descriptor_ = NULL;
const ::google::protobuf::Descriptor* Topology_RemoteGwsEntry_descriptor_ = NULL;
const ::google::protobuf::Descriptor* Topology_ExternalsEntry_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_topology_2eproto() {
  protobuf_AddDesc_topology_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "topology.proto");
  GOOGLE_CHECK(file != NULL);
  Topology_descriptor_ = file->message_type(0);
  static const int Topology_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, internals_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, localgws_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, remotegws_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, externals_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, timestamp_),
  };
  Topology_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Topology_descriptor_,
      Topology::default_instance_,
      Topology_offsets_,
      -1,
      -1,
      -1,
      sizeof(Topology),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Topology, _is_default_instance_));
  Topology_InternalsEntry_descriptor_ = Topology_descriptor_->nested_type(0);
  Topology_LocalGwsEntry_descriptor_ = Topology_descriptor_->nested_type(1);
  Topology_RemoteGwsEntry_descriptor_ = Topology_descriptor_->nested_type(2);
  Topology_ExternalsEntry_descriptor_ = Topology_descriptor_->nested_type(3);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_topology_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Topology_descriptor_, &Topology::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        Topology_InternalsEntry_descriptor_,
        ::google::protobuf::internal::MapEntry<
            ::std::string,
            ::std::string,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            0>::CreateDefaultInstance(
                Topology_InternalsEntry_descriptor_));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        Topology_LocalGwsEntry_descriptor_,
        ::google::protobuf::internal::MapEntry<
            ::std::string,
            ::std::string,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            0>::CreateDefaultInstance(
                Topology_LocalGwsEntry_descriptor_));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        Topology_RemoteGwsEntry_descriptor_,
        ::google::protobuf::internal::MapEntry<
            ::std::string,
            ::std::string,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            0>::CreateDefaultInstance(
                Topology_RemoteGwsEntry_descriptor_));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        Topology_ExternalsEntry_descriptor_,
        ::google::protobuf::internal::MapEntry<
            ::std::string,
            ::std::string,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            0>::CreateDefaultInstance(
                Topology_ExternalsEntry_descriptor_));
}

}  // namespace

void protobuf_ShutdownFile_topology_2eproto() {
  delete Topology::default_instance_;
  delete Topology_reflection_;
}

void protobuf_AddDesc_topology_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2ftimestamp_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016topology.proto\022\004ddam\032\037google/protobuf/"
    "timestamp.proto\"\306\003\n\010Topology\0220\n\tinternal"
    "s\030\001 \003(\0132\035.ddam.Topology.InternalsEntry\022."
    "\n\010localGws\030\002 \003(\0132\034.ddam.Topology.LocalGw"
    "sEntry\0220\n\tremoteGws\030\003 \003(\0132\035.ddam.Topolog"
    "y.RemoteGwsEntry\0220\n\texternals\030\004 \003(\0132\035.dd"
    "am.Topology.ExternalsEntry\022-\n\ttimestamp\030"
    "\005 \001(\0132\032.google.protobuf.Timestamp\0320\n\016Int"
    "ernalsEntry\022\013\n\003key\030\001 \001(\t\022\r\n\005value\030\002 \001(\t:"
    "\0028\001\032/\n\rLocalGwsEntry\022\013\n\003key\030\001 \001(\t\022\r\n\005val"
    "ue\030\002 \001(\t:\0028\001\0320\n\016RemoteGwsEntry\022\013\n\003key\030\001 "
    "\001(\t\022\r\n\005value\030\002 \001(\t:\0028\001\0320\n\016ExternalsEntry"
    "\022\013\n\003key\030\001 \001(\t\022\r\n\005value\030\002 \001(\t:\0028\001B&\n\020us.i"
    "hmc.aci.ddamB\rTopologyProtoP\001\240\001\001b\006proto3", 560);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "topology.proto", &protobuf_RegisterTypes);
  Topology::default_instance_ = new Topology();
  Topology::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_topology_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_topology_2eproto {
  StaticDescriptorInitializer_topology_2eproto() {
    protobuf_AddDesc_topology_2eproto();
  }
} static_descriptor_initializer_topology_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Topology::kInternalsFieldNumber;
const int Topology::kLocalGwsFieldNumber;
const int Topology::kRemoteGwsFieldNumber;
const int Topology::kExternalsFieldNumber;
const int Topology::kTimestampFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Topology::Topology()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ddam.Topology)
}

void Topology::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  timestamp_ = const_cast< ::google::protobuf::Timestamp*>(&::google::protobuf::Timestamp::default_instance());
}

Topology::Topology(const Topology& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ddam.Topology)
}

void Topology::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  internals_.SetAssignDescriptorCallback(
      protobuf_AssignDescriptorsOnce);
  internals_.SetEntryDescriptor(
      &::ddam::Topology_InternalsEntry_descriptor_);
  localgws_.SetAssignDescriptorCallback(
      protobuf_AssignDescriptorsOnce);
  localgws_.SetEntryDescriptor(
      &::ddam::Topology_LocalGwsEntry_descriptor_);
  remotegws_.SetAssignDescriptorCallback(
      protobuf_AssignDescriptorsOnce);
  remotegws_.SetEntryDescriptor(
      &::ddam::Topology_RemoteGwsEntry_descriptor_);
  externals_.SetAssignDescriptorCallback(
      protobuf_AssignDescriptorsOnce);
  externals_.SetEntryDescriptor(
      &::ddam::Topology_ExternalsEntry_descriptor_);
  timestamp_ = NULL;
}

Topology::~Topology() {
  // @@protoc_insertion_point(destructor:ddam.Topology)
  SharedDtor();
}

void Topology::SharedDtor() {
  if (this != default_instance_) {
    delete timestamp_;
  }
}

void Topology::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Topology::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Topology_descriptor_;
}

const Topology& Topology::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_topology_2eproto();
  return *default_instance_;
}

Topology* Topology::default_instance_ = NULL;

Topology* Topology::New(::google::protobuf::Arena* arena) const {
  Topology* n = new Topology;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Topology::Clear() {
  if (GetArenaNoVirtual() == NULL && timestamp_ != NULL) delete timestamp_;
  timestamp_ = NULL;
  internals_.Clear();
  localgws_.Clear();
  remotegws_.Clear();
  externals_.Clear();
}

bool Topology::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ddam.Topology)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // map<string, string> internals = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_internals:
          ::google::protobuf::scoped_ptr<Topology_InternalsEntry> entry(internals_.NewEntry());
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
              input, entry.get()));
          (*mutable_internals())[entry->key()] = *entry->mutable_value();
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->key().data(), entry->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.InternalsEntry.key"));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->mutable_value()->data(),
            entry->mutable_value()->length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.InternalsEntry.value"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_internals;
        if (input->ExpectTag(18)) goto parse_loop_localGws;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // map<string, string> localGws = 2;
      case 2: {
        if (tag == 18) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_localGws:
          ::google::protobuf::scoped_ptr<Topology_LocalGwsEntry> entry(localgws_.NewEntry());
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
              input, entry.get()));
          (*mutable_localgws())[entry->key()] = *entry->mutable_value();
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->key().data(), entry->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.LocalGwsEntry.key"));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->mutable_value()->data(),
            entry->mutable_value()->length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.LocalGwsEntry.value"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_localGws;
        if (input->ExpectTag(26)) goto parse_loop_remoteGws;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // map<string, string> remoteGws = 3;
      case 3: {
        if (tag == 26) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_remoteGws:
          ::google::protobuf::scoped_ptr<Topology_RemoteGwsEntry> entry(remotegws_.NewEntry());
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
              input, entry.get()));
          (*mutable_remotegws())[entry->key()] = *entry->mutable_value();
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->key().data(), entry->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.RemoteGwsEntry.key"));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->mutable_value()->data(),
            entry->mutable_value()->length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.RemoteGwsEntry.value"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_loop_remoteGws;
        if (input->ExpectTag(34)) goto parse_loop_externals;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // map<string, string> externals = 4;
      case 4: {
        if (tag == 34) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_externals:
          ::google::protobuf::scoped_ptr<Topology_ExternalsEntry> entry(externals_.NewEntry());
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
              input, entry.get()));
          (*mutable_externals())[entry->key()] = *entry->mutable_value();
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->key().data(), entry->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.ExternalsEntry.key"));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            entry->mutable_value()->data(),
            entry->mutable_value()->length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ddam.Topology.ExternalsEntry.value"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_loop_externals;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectTag(42)) goto parse_timestamp;
        break;
      }

      // optional .google.protobuf.Timestamp timestamp = 5;
      case 5: {
        if (tag == 42) {
         parse_timestamp:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_timestamp()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ddam.Topology)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ddam.Topology)
  return false;
#undef DO_
}

void Topology::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ddam.Topology)
  // map<string, string> internals = 1;
  {
    ::google::protobuf::scoped_ptr<Topology_InternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->internals().begin();
        it != this->internals().end(); ++it) {
      entry.reset(internals_.NewEntryWrapper(it->first, it->second));
      ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
          1, *entry, output);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.InternalsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.InternalsEntry.value");
    }
  }

  // map<string, string> localGws = 2;
  {
    ::google::protobuf::scoped_ptr<Topology_LocalGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->localgws().begin();
        it != this->localgws().end(); ++it) {
      entry.reset(localgws_.NewEntryWrapper(it->first, it->second));
      ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
          2, *entry, output);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.LocalGwsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.LocalGwsEntry.value");
    }
  }

  // map<string, string> remoteGws = 3;
  {
    ::google::protobuf::scoped_ptr<Topology_RemoteGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->remotegws().begin();
        it != this->remotegws().end(); ++it) {
      entry.reset(remotegws_.NewEntryWrapper(it->first, it->second));
      ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
          3, *entry, output);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.RemoteGwsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.RemoteGwsEntry.value");
    }
  }

  // map<string, string> externals = 4;
  {
    ::google::protobuf::scoped_ptr<Topology_ExternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->externals().begin();
        it != this->externals().end(); ++it) {
      entry.reset(externals_.NewEntryWrapper(it->first, it->second));
      ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
          4, *entry, output);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.ExternalsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.ExternalsEntry.value");
    }
  }

  // optional .google.protobuf.Timestamp timestamp = 5;
  if (this->has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, *this->timestamp_, output);
  }

  // @@protoc_insertion_point(serialize_end:ddam.Topology)
}

::google::protobuf::uint8* Topology::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ddam.Topology)
  // map<string, string> internals = 1;
  {
    ::google::protobuf::scoped_ptr<Topology_InternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->internals().begin();
        it != this->internals().end(); ++it) {
      entry.reset(internals_.NewEntryWrapper(it->first, it->second));
      target = ::google::protobuf::internal::WireFormatLite::
          WriteMessageNoVirtualToArray(
              1, *entry, target);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.InternalsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.InternalsEntry.value");
    }
  }

  // map<string, string> localGws = 2;
  {
    ::google::protobuf::scoped_ptr<Topology_LocalGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->localgws().begin();
        it != this->localgws().end(); ++it) {
      entry.reset(localgws_.NewEntryWrapper(it->first, it->second));
      target = ::google::protobuf::internal::WireFormatLite::
          WriteMessageNoVirtualToArray(
              2, *entry, target);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.LocalGwsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.LocalGwsEntry.value");
    }
  }

  // map<string, string> remoteGws = 3;
  {
    ::google::protobuf::scoped_ptr<Topology_RemoteGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->remotegws().begin();
        it != this->remotegws().end(); ++it) {
      entry.reset(remotegws_.NewEntryWrapper(it->first, it->second));
      target = ::google::protobuf::internal::WireFormatLite::
          WriteMessageNoVirtualToArray(
              3, *entry, target);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.RemoteGwsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.RemoteGwsEntry.value");
    }
  }

  // map<string, string> externals = 4;
  {
    ::google::protobuf::scoped_ptr<Topology_ExternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->externals().begin();
        it != this->externals().end(); ++it) {
      entry.reset(externals_.NewEntryWrapper(it->first, it->second));
      target = ::google::protobuf::internal::WireFormatLite::
          WriteMessageNoVirtualToArray(
              4, *entry, target);
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->first.data(), it->first.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.ExternalsEntry.key");
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        it->second.data(), it->second.length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "ddam.Topology.ExternalsEntry.value");
    }
  }

  // optional .google.protobuf.Timestamp timestamp = 5;
  if (this->has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, *this->timestamp_, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:ddam.Topology)
  return target;
}

int Topology::ByteSize() const {
  int total_size = 0;

  // optional .google.protobuf.Timestamp timestamp = 5;
  if (this->has_timestamp()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->timestamp_);
  }

  // map<string, string> internals = 1;
  total_size += 1 * this->internals_size();
  {
    ::google::protobuf::scoped_ptr<Topology_InternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->internals().begin();
        it != this->internals().end(); ++it) {
      entry.reset(internals_.NewEntryWrapper(it->first, it->second));
      total_size += ::google::protobuf::internal::WireFormatLite::
          MessageSizeNoVirtual(*entry);
    }
  }

  // map<string, string> localGws = 2;
  total_size += 1 * this->localgws_size();
  {
    ::google::protobuf::scoped_ptr<Topology_LocalGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->localgws().begin();
        it != this->localgws().end(); ++it) {
      entry.reset(localgws_.NewEntryWrapper(it->first, it->second));
      total_size += ::google::protobuf::internal::WireFormatLite::
          MessageSizeNoVirtual(*entry);
    }
  }

  // map<string, string> remoteGws = 3;
  total_size += 1 * this->remotegws_size();
  {
    ::google::protobuf::scoped_ptr<Topology_RemoteGwsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->remotegws().begin();
        it != this->remotegws().end(); ++it) {
      entry.reset(remotegws_.NewEntryWrapper(it->first, it->second));
      total_size += ::google::protobuf::internal::WireFormatLite::
          MessageSizeNoVirtual(*entry);
    }
  }

  // map<string, string> externals = 4;
  total_size += 1 * this->externals_size();
  {
    ::google::protobuf::scoped_ptr<Topology_ExternalsEntry> entry;
    for (::google::protobuf::Map< ::std::string, ::std::string >::const_iterator
        it = this->externals().begin();
        it != this->externals().end(); ++it) {
      entry.reset(externals_.NewEntryWrapper(it->first, it->second));
      total_size += ::google::protobuf::internal::WireFormatLite::
          MessageSizeNoVirtual(*entry);
    }
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Topology::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Topology* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Topology>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Topology::MergeFrom(const Topology& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  internals_.MergeFrom(from.internals_);
  localgws_.MergeFrom(from.localgws_);
  remotegws_.MergeFrom(from.remotegws_);
  externals_.MergeFrom(from.externals_);
  if (from.has_timestamp()) {
    mutable_timestamp()->::google::protobuf::Timestamp::MergeFrom(from.timestamp());
  }
}

void Topology::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Topology::CopyFrom(const Topology& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Topology::IsInitialized() const {

  return true;
}

void Topology::Swap(Topology* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Topology::InternalSwap(Topology* other) {
  internals_.Swap(&other->internals_);
  localgws_.Swap(&other->localgws_);
  remotegws_.Swap(&other->remotegws_);
  externals_.Swap(&other->externals_);
  std::swap(timestamp_, other->timestamp_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Topology::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Topology_descriptor_;
  metadata.reflection = Topology_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Topology

// map<string, string> internals = 1;
int Topology::internals_size() const {
  return internals_.size();
}
void Topology::clear_internals() {
  internals_.Clear();
}
 const ::google::protobuf::Map< ::std::string, ::std::string >&
Topology::internals() const {
  // @@protoc_insertion_point(field_map:ddam.Topology.internals)
  return internals_.GetMap();
}
 ::google::protobuf::Map< ::std::string, ::std::string >*
Topology::mutable_internals() {
  // @@protoc_insertion_point(field_mutable_map:ddam.Topology.internals)
  return internals_.MutableMap();
}

// map<string, string> localGws = 2;
int Topology::localgws_size() const {
  return localgws_.size();
}
void Topology::clear_localgws() {
  localgws_.Clear();
}
 const ::google::protobuf::Map< ::std::string, ::std::string >&
Topology::localgws() const {
  // @@protoc_insertion_point(field_map:ddam.Topology.localGws)
  return localgws_.GetMap();
}
 ::google::protobuf::Map< ::std::string, ::std::string >*
Topology::mutable_localgws() {
  // @@protoc_insertion_point(field_mutable_map:ddam.Topology.localGws)
  return localgws_.MutableMap();
}

// map<string, string> remoteGws = 3;
int Topology::remotegws_size() const {
  return remotegws_.size();
}
void Topology::clear_remotegws() {
  remotegws_.Clear();
}
 const ::google::protobuf::Map< ::std::string, ::std::string >&
Topology::remotegws() const {
  // @@protoc_insertion_point(field_map:ddam.Topology.remoteGws)
  return remotegws_.GetMap();
}
 ::google::protobuf::Map< ::std::string, ::std::string >*
Topology::mutable_remotegws() {
  // @@protoc_insertion_point(field_mutable_map:ddam.Topology.remoteGws)
  return remotegws_.MutableMap();
}

// map<string, string> externals = 4;
int Topology::externals_size() const {
  return externals_.size();
}
void Topology::clear_externals() {
  externals_.Clear();
}
 const ::google::protobuf::Map< ::std::string, ::std::string >&
Topology::externals() const {
  // @@protoc_insertion_point(field_map:ddam.Topology.externals)
  return externals_.GetMap();
}
 ::google::protobuf::Map< ::std::string, ::std::string >*
Topology::mutable_externals() {
  // @@protoc_insertion_point(field_mutable_map:ddam.Topology.externals)
  return externals_.MutableMap();
}

// optional .google.protobuf.Timestamp timestamp = 5;
bool Topology::has_timestamp() const {
  return !_is_default_instance_ && timestamp_ != NULL;
}
void Topology::clear_timestamp() {
  if (GetArenaNoVirtual() == NULL && timestamp_ != NULL) delete timestamp_;
  timestamp_ = NULL;
}
const ::google::protobuf::Timestamp& Topology::timestamp() const {
  // @@protoc_insertion_point(field_get:ddam.Topology.timestamp)
  return timestamp_ != NULL ? *timestamp_ : *default_instance_->timestamp_;
}
::google::protobuf::Timestamp* Topology::mutable_timestamp() {
  
  if (timestamp_ == NULL) {
    timestamp_ = new ::google::protobuf::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:ddam.Topology.timestamp)
  return timestamp_;
}
::google::protobuf::Timestamp* Topology::release_timestamp() {
  
  ::google::protobuf::Timestamp* temp = timestamp_;
  timestamp_ = NULL;
  return temp;
}
void Topology::set_allocated_timestamp(::google::protobuf::Timestamp* timestamp) {
  delete timestamp_;
  if (timestamp != NULL && timestamp->GetArena() != NULL) {
    ::google::protobuf::Timestamp* new_timestamp = new ::google::protobuf::Timestamp;
    new_timestamp->CopyFrom(*timestamp);
    timestamp = new_timestamp;
  }
  timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ddam.Topology.timestamp)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace ddam

// @@protoc_insertion_point(global_scope)
