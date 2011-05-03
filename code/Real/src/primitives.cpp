#include "primitives.h"


// Išsiunčia baitą į nurodytą portą.
void send_byte(u16int port, u8int value) {
  asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
  }


// Nuskaito baitą iš nurodyto porto.
u8int get_byte(u16int port) {
  u8int result;
  asm volatile("inb %1, %0" : "=a" (result) : "dN" (port));
  return result;
  }


// Nuskaito baitų porą iš nurodyto porto.
u16int get_bytes2(u16int port) {
  u16int result;
  asm volatile("inw %1, %0" : "=a" (result) : "dN" (port));
  return result;
  }

// Nusiunčia baitą į Bochs. (Funkcija skirta derinimui.)
void debug_ping() {
  debug_string("Veikia.\n");
  }


// Nusiunčia baitą į Bochs. (Funkcija skirta derinimui.)
void debug_char(char c) {
  send_byte(0xE9, c);
  }


// Nusiunčia simbolių seką, kurios pabaigos požymis yra 0, į Bochs.
// (Funkcija skirta derinimui.)
void debug_string(const char *str) {
  for (const char *i = str; *i; i++) {
    send_byte(0xE9, *i);
    }
  
  }
