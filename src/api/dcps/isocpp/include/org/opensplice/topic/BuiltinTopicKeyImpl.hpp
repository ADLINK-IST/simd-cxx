#ifndef ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_KEY_IMPL_HPP_
#define ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_KEY_IMPL_HPP_

namespace org { namespace opensplice { namespace topic {

      class BuiltinTopicKeyImpl {
      public:
    typedef uint32_t VALUE_T;
      public:
    BuiltinTopicKeyImpl(uint32_t v) : key_(v) { }
      public:
    uint32_t value() const {
      return key_;
    }

      protected:
    uint32_t key_;
      };

    }
  }
}
#endif /* ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_KEY_IMPL_HPP_ */
