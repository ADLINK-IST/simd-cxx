#ifndef ORG_OPENSPLICE_CORE_CONDITION_IMPL_HPP_
#define ORG_OPENSPLICE_CORE_CONDITION_IMPL_HPP_


namespace org { namespace opensplice { namespace core {
      class ConditionImpl;
    }
  }
}

class org::opensplice::core::ConditionImpl {
public:
  virtual ~ConditionImpl();

public:
  virtual void dispatch() { }

  virtual bool trigger_value() {
    return false;
  }

protected:
  ConditionImpl();
};


#endif /* ORG_OPENSPLICE_CORE_CONDITION_IMPL_HPP_ */
