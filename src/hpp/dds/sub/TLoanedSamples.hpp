#ifndef OMG_DDS_SUB_TLOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_TLOANED_SAMPLES_HPP_

#include <dds/sub/Sample.hpp>

namespace dds { namespace sub {
    template <typename T, 
              template <typename Q> class DELEGATE>
    class LoanedSamples;
} }

template <typename T, template <typename Q> class DELEGATE>
class dds::sub::LoanedSamples : public dds::core::Value< DELEGATE<T> >
{
public:
    typedef T DataType;
    typedef Sample<DataType> SampleType;
    
public:
    LoanedSamples() { /* implementation-defined */ }
    LoanedSamples(const LoanedSamples& src);
    
    /**
     * Implicitly return the loan.
     */
    ~LoanedSamples() { /* implementation-defined */ }
    
public:
    class Iterator : public std::iterator<std::forward_iterator_tag, const SampleType>
    {
    public:
        Iterator() { /* implementation-defined */ }
        Iterator(const Iterator& src) { /* implementation-defined */ }
        ~Iterator() { /* implementation-defined */ }
        
    public:
        Iterator& operator=(const Iterator& src);
        
        bool operator==(const Iterator& other) const {
            // implementation-defined
            return false;
        }
        bool operator!=(const Iterator& other) const {
            // implementation-defined
            return false;
        }
        
        Iterator& operator++() {    // prefix
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::Iterator::++");
        }
        Iterator  operator++(int) { // postfix
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::Iterator::++");
        }
        
        const SampleType& operator*() {
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::begin");
        }
        const SampleType* operator->() {
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::end");
        }
    };
    
public:
    const Iterator begin() const {
        // implementation-defined
        throw dds::core::UnsupportedError("LoanedSamples::begin");
    }
    
    const Iterator end() const {
        // implementation-defined
        throw dds::core::UnsupportedError("LoanedSamples::end");
    }
    
public:
    void return_loan();     // explicitly return loan
    
};

#endif /* OMG_DDS_SUB_TLOANED_SAMPLES_HPP_ */
