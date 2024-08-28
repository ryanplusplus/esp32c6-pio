#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

enum {
  pin = 0,
  pixel_count = 60,
  step = 1
};

static Adafruit_NeoPixel pixels(pixel_count, pin, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin();
  pixels.clear();
}

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} Color;

static constexpr Color colors[] = {
  { 1, 0, 0 },
  { 1, 1, 0 },
  { 0, 1, 0 },
  { 0, 1, 1 },
  { 0, 0, 1 },
  { 1, 0, 1 }
};

void loop()
{
  for(size_t color = 0; color < sizeof(colors) / sizeof(colors[0]); color++) {
    for(int pixel = 0; pixel < pixel_count; pixel++) {
      pixels.setPixelColor(pixel, pixels.Color(colors[color].r, colors[color].g, colors[color].b));
      pixels.show();
      delay(step);
    }
  }
}
