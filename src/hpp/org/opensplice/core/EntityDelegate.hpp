#ifndef ORG_OPENSPLICE_CORE_ENTITY_DELEGATE_HPP_
#define ORG_OPENSPLICE_CORE_ENTITY_DELEGATE_HPP_

#include <dds/core/InstanceHandle.hpp>
#include <dds/core/status/State.hpp>

namespace org { namespace opensplice { namespace core {

   class EntityDelegate {
   public:
	   EntityDelegate();
      virtual ~EntityDelegate();

   public:
      EntityDelegate& operator=(const EntityDelegate& other);

   public:
      /**
       * Enables this entity.
       */
      virtual void enable();

      virtual const ::dds::core::status::StatusMask status_changes();

      virtual const ::dds::core::InstanceHandle instance_handle() const;

     virtual void close();

     virtual void retain();

   protected:
      static volatile unsigned int entityID_;
      bool enabled_;
   };

} } }

#endif /* ORG_OPENSPLICE_CORE_ENTITY_DELEGATE_HPP_ */
