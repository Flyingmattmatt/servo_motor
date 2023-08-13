
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

const uint servoPin = 15;

int main(void) {


stdio_init_all();
sleep_ms(2000);
gpio_set_function(servoPin, GPIO_FUNC_PWM);

uint slice_num = pwm_gpio_to_slice_num(servoPin);
uint channel = pwm_gpio_to_channel(servoPin);

pwm_set_clkdiv(slice_num, 256.0f);
pwm_set_wrap(slice_num, 9804);
pwm_set_enabled(slice_num, true);

for (uint i = 0; i < 5; i++) {
    pwm_set_chan_level(slice_num, channel, 270);
    sleep_ms(2000);
    
    pwm_set_chan_level(slice_num, channel, 332);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 432);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 532);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 632);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 732);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 832);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 932);
    sleep_ms(900);
    pwm_set_chan_level(slice_num, channel, 1250);
    sleep_ms(900);
}
}
