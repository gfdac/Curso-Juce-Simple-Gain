## Curso JUCE Simple Gain

**Dominando o JUCE: plugin de ganho simples com interface gráfica customizada**

Este repositório apresenta um plugin de áudio simples, "Simple Gain", criado com o framework JUCE. Ele oferece controle preciso sobre o ganho do sinal de áudio, permitindo ajustar o volume com um knob rotativo intuitivo.

**Recursos:**

* **Controle de Ganho:** Ajuste o ganho em decibéis (dB) usando um knob rotativo com `LookAndFeel` customizado.
* **Interpolação Suave:** Evite "clicks" e "pops" no áudio com interpolação linear durante as mudanças de ganho.
* **Opções de Processamento:** Escolha entre processamento com DSP ou manipulação direta do buffer de áudio.
* **Interface Gráfica Personalizada:** Design intuitivo e responsivo, adaptando-se a diferentes tamanhos de janela.
* **Código Limpo e Comentado:**  Código-fonte bem organizado e comentado para facilitar o aprendizado e a modificação.

**Preview:**

[Insira aqui uma imagem ou GIF animado do seu plugin em ação]

**Como usar:**

1. **Clone o repositório:** `git clone https://github.com/gfdac/Curso-Juce-Simple-Gain.git`
2. **Abra o projeto no JUCE:**  Abra o arquivo `CursoJuceGain.jucer` no JUCE.
3. **Compile o projeto:** Gere o plugin VST para sua plataforma (macOS, Windows, Linux).
4. **Descomente o código fonte seguindo o tutorial do vídeo no meu canal `https://www.youtube.com/@techinfostudiobr`
5. **Carregue o plugin na sua DAW:**  Abra sua DAW favorita e carregue o plugin "Simple Gain".

**Requisitos:**

* JUCE (versão mais recente)
* Compilador C++ (Xcode, Visual Studio, etc.)
* Uma DAW (Digital Audio Workstation) compatível com plugins VST/AU

**Contribuições:**

Sinta-se à vontade para contribuir com o projeto! 

* **Issues:** Reporte bugs, sugira melhorias ou novas funcionalidades.
* **Pull requests:**  Envie suas modificações e correções de código.


**Autor:**

gooh br

**Licença:**

MIT License

Copyright (c) [2024] gooh br

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
