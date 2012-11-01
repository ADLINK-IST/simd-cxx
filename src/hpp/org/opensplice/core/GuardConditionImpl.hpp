#ifndef ORG_OPENSPLICE_CORE_GUARD_CONDITION_IMPL_HPP_
#define ORG_OPENSPLICE_CORE_GUARD_CONDITION_IMPL_HPP_

#include <org/opensplice/core/FunctorHolder.hpp>
#include <org/opensplice/core/ConditionImpl.hpp>

namespace org { namespace opensplice { namespace core {

      class GuardConditionImpl : public ConditionImpl {
      public:
    GuardConditionImpl()
      :  trigger_(false),
         fholder_(0)
    { }

    template <typename Functor>
    GuardConditionImpl(const Functor& func)
    :  trigger_(false),
       fholder_(new VoidFunctorHolder<Functor>(func))
    { }

    virtual ~GuardConditionImpl() {
      delete fholder_;
    }


    using ConditionImpl::trigger_value;

    virtual void trigger_value(bool b) {
      trigger_ = b;
    }

    virtual  void dispatch() {
          if (trigger_)
        fholder_->invoke();
    }

      public:
    template <typename Functor>
    void set_handler(const Functor& func) {
      org::opensplice::core::FunctorHolder* tmp = fholder_;
      fholder_ = new org::opensplice::core::VoidFunctorHolder<Functor>(func);
      if (tmp != 0)
            delete tmp;
    }

    void reset_handler() {
          org::opensplice::core::FunctorHolder* tmp = fholder_;
          fholder_ = 0;
          delete tmp;
    }

      private:
    GuardConditionImpl& operator= (const GuardConditionImpl&);
    GuardConditionImpl(const GuardConditionImpl&);

      private:
    bool trigger_;
    org::opensplice::core::FunctorHolder* fholder_;

      };

    } } }

#endif /* ORG_OPENSPLICE_CORE_GUARD_CONDITION_IMPL_HPP_ */
