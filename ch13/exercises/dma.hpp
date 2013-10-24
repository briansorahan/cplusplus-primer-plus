// dma.hpp -- inheritance and dynamic memory allocation
#ifndef __DMA_HPP__
#define __DMA_HPP__

#include <iostream>
#include <cstring>

class abstractDMA {
public:
    abstractDMA();
    abstractDMA(const abstractDMA& adma);
    virtual ~abstractDMA() = 0;
    // pure virtual
    // virtual std::ostream& operator<<(const abstractDMA& adma) = 0;
    virtual void ViewDMA() = 0;
};

class baseDMA : public abstractDMA {
private:
    char* label;
    int rating;
public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    // virtual void ViewDMA();
    baseDMA& operator=(const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
    virtual void ViewDMA();
    char* getLabel() { return label; }
    int getRating() { return rating; }
};

class lacksDMA : public baseDMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    // void ViewDMA();
    friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
    virtual void ViewDMA();
};

class hasDMA : public baseDMA {
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null", int r = 0);
    hasDMA(const char* s, const baseDMA& rs);
    hasDMA(const hasDMA& hs);
    ~hasDMA();
    // void ViewDMA();
    hasDMA& operator=(const hasDMA& rs);
    friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
    virtual void ViewDMA();
};

#endif
