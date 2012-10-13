#ifndef ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_
#define ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_


namespace org { namespace opensplice { namespace topic {

      template <typename Topic>
      struct topic_data_writer { };

      template <typename Topic>
      struct topic_data_reader { };

      template <typename Topic>
      struct topic_data_seq { };

    } 
  } 
}


#define REGISTER_TOPIC_TRAITS(TOPIC)					\
  namespace dds { namespace topic {					\
      template<> struct topic_type_support<TOPIC> {			\
	typedef TOPIC##TypeSupport type;				\
      };								\
      template<> struct is_topic_type<TOPIC> { enum {value = 1 }; };	\
      template<> struct topic_type_name<TOPIC> {			\
	static std::string value() {					\
	  static topic_type_support<TOPIC>::type ts;			\
          return ts.get_type_name();					\
	}								\
      };								\
    } }									\
									\
  namespace org { namespace opensplice { namespace topic {		\
  template<> struct topic_data_writer<TOPIC> {				\
    typedef TOPIC##DataWriter type;					\
  };									\
									\
  template<> struct topic_data_reader<TOPIC> {				\
    typedef TOPIC##DataReader type;					\
  };									\
  template<> struct topic_data_seq<TOPIC> {				\
    typedef TOPIC##Seq type;						\
    typedef TOPIC##Seq_uniq_ utype;					\
  }; } } }								


#endif /* ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_ */
