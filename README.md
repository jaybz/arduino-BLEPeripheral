# Arduino BLEPeripheral 

Forked from [sandeepmistry's BLEPeripheral](https://github.com/sandeepmistry/arduino-BLEPeripheral), This adds a very very dirty hack that enables setting the GAP address for a BBC Micro:bit device (nRF51822 S110 softdevice).

### Sample code
```
BLEPeripheral blePeripheral = BLEPeripheral(0,0,0); // parameters are unused on nRF51822
uint8_t gap_address[BLE_GAP_ADDR_LEN] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 }; // GAP address: 01:02:03:04:05:06

void setup() {
  ble_gap_addr_t address;
  address.addr_type = BLE_GAP_ADDR_TYPE_PUBLIC;
  for (int i = 0; i < BLE_GAP_ADDR_LEN; i++) { // reversed gap_address
    int i2 = (BLE_GAP_ADDR_LEN - 1) - i;
    address.addr[i] = gap_address[i2];
  }
  blePeripheral.setGapAddress(&address);
  blePeripheral.begin();
}
```

### Additional modifications

Additional modifications (again, very dirty hacks) were made to add the following:
- Support for using BLE_GAP_AD_TYPE_SERVICE_DATA_32BIT_UUID via setServiceData32BitUuid()
- resetAdvertisingData() which resets advertising data to _serviceSolicitationUuid, _advertisedServiceUuid, _manufacturerData, and _serviceData32BitUuid.
- Fix setConnectionInterval so that it actually works
- Add setConnectionParams as an alternative to setConnectionInterval that includes additional parameters
- Support for BLE_GATTS_OP_EXEC_WRITE_REQ_NOW
