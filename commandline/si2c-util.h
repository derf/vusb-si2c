#define BIT_SDA 1
#define BIT_SCL 2

void set_sda(char value);
void set_scl(char value);

unsigned char get_status();
unsigned char i2c_tx_byte(unsigned char byte);
unsigned char i2c_rx_byte(unsigned char send_ack);

void i2c_start();
void i2c_stop();
void i2c_init();
void i2c_deinit();
