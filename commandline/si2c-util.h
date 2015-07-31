#define BIT_SDA 6
#define BIT_SCL 7

void set_sda(char value);
void set_scl(char value);

unsigned char get_status();
void si2c_tx_byte(unsigned char byte);

void si2c_start();
void si2c_stop();
void si2c_init();
void si2c_deinit();
