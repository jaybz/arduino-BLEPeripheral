#ifndef _BLE_BOND_STORE_H_
#define _BLE_BOND_STORE_H_

class BLEBondStore
{
  public:
    BLEBondStore(int offset = 0);

    virtual bool hasData();
    virtual void clearData();
    virtual void putData(const unsigned char* data, unsigned int offset, unsigned int length);
    virtual void getData(unsigned char* data, unsigned int offset, unsigned int length);

  private:
#if defined(__AVR__) || defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MKL26Z64__)
    int             _offset;
#elif defined(NRF51)|| defined(NRF52) || defined(__RFduino__)
    uint32_t*       _flashPageStartAddress;
#endif
};

#endif
