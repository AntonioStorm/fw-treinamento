# fw-treinamento

Repositório de treinamento de firmware da **Warthog Robotics**. Reúne exemplos práticos e exercícios de sistemas embarcados usando o **RP2040** (Raspberry Pi Pico e RP2040-Zero) com o [pico-sdk](https://github.com/raspberrypi/pico-sdk).


## Primeiros passos

> Os scripts de instalação usam `dnf` (Fedora). Em outras distros, instale o equivalente: `arm-none-eabi-gcc`, `arm-none-eabi-newlib`, `cmake`, `git` e `gcc-c++`.

```bash
git clone git@github.com:AntonioStorm/fw-treinamento.git
cd fw-treinamento

make setup_all   # instala dependências, baixa o pico-sdk e compila tudo
```

Ou passo a passo:

| Comando                    | O que faz                                              |
|----------------------------|--------------------------------------------------------|
| `make installDependencies` | Instala toolchain ARM e dependências do sistema        |
| `make setup_sdk`           | Inicializa o submódulo `3rdparty/pico-sdk`             |
| `make build`               | Compila aproveitando o cache (uso no dia a dia)        |
| `make rebuild`             | Apaga `build/` e `dist/` e compila do zero             |

## Compilação

Um único build compila **todos os exemplos**. Cada um gera seu próprio `.uf2` em `dist/`:

```
dist/
├── blink_led_pico.uf2
├── blink_led_RP2040zero.uf2
├── hello_adc.uf2
├── hello_pwm.uf2
└── temp_sensor.uf2
```

## Gravando na placa

1. Segure o botão **BOOTSEL** e conecte a placa no USB. Ela aparece como um pendrive (`RPI-RP2`).
2. Arraste o `.uf2` do exemplo desejado de `dist/` para o pendrive.
3. A placa reinicia sozinha e já roda o firmware.

## Monitor serial

Os exemplos usam `printf` pela USB (115200 baud). Para ver a saída:

```bash
bash scripts/monitor.sh   # minicom em /dev/ttyACM0
```

Para sair do minicom: `Ctrl+A` e depois `X`.

## Adicionando um novo exemplo

1. Crie uma pasta em `examples/` com o `.c`, o `.h` e um `CMakeLists.txt`:

   ```cmake
   add_executable(meu_exemplo
       meu_exemplo.c)

   target_link_libraries(meu_exemplo
       pico_stdlib)

   # stdio USB, UF2/bin/elf e cópia para dist/meu_exemplo.uf2
   fw_example_outputs(meu_exemplo)
   ```

2. Adicione `add_subdirectory(meu_exemplo)` no `CMakeLists.txt` da pasta pai.
3. Rode `make build`. O binário aparece em `dist/meu_exemplo.uf2`.

> O nome do target precisa ser único no projeto. Use o nome da pasta.

A função `fw_example_outputs` fica no [CMakeLists.txt](CMakeLists.txt) da raiz.
