/*
 ==============================================================================

  MyLookAndFeel.h
  Created: 20 Oct 2024 4:19:32pm
  Author:  Guh F

 ==============================================================================
*/

#pragma once

// Inclui o header principal do JUCE
#include <JuceHeader.h>

// Define a classe do LookAndFeel personalizado.
// Essa classe herda de juce::LookAndFeel_V4 e sobrescreve os métodos drawRotarySlider e drawLabel
// para customizar a aparência dos sliders rotativos e labels.
class MyLookAndFeel : public juce::LookAndFeel_V4
{
public:
    // Construtor da classe MyLookAndFeel.
    MyLookAndFeel();

    // Desenha um slider rotativo customizado.
    // g: Contexto gráfico para desenhar.
    // x, y, width, height: Posição e tamanho do slider.
    // sliderPos: Posição atual do slider (0.0 a 1.0).
    // rotaryStartAngle, rotaryEndAngle: Ângulos inicial e final do slider.
    // slider: Referência para o objeto Slider.
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override;

    // Desenha um label customizado para o slider.
    // g: Contexto gráfico para desenhar.
    // label: Referência para o objeto Label.
    void drawLabel (juce::Graphics& g, juce::Label& label) override;

    // Enumeração para definir o tipo de valor do dial (inteiro ou float).
    enum class ValueType
    {
        kInt,
        kFloat
    };

    // Retorna o tipo de valor do dial.
    ValueType getDialValueType()
    {
        return _dialValueType;
    }

    // Define o tipo de valor do dial.
    void setDialValueType (ValueType newValueType)
    {
        _dialValueType = newValueType;
    }

private:
    // Variáveis privadas da classe.
    float _sliderWidth; // Largura do slider.
    juce::String _sliderName = ""; // Nome do slider.
    ValueType _dialValueType = ValueType::kFloat; // Tipo de valor do dial.
};

// Define uma classe para customizar apenas o label do dial.
// Essa classe herda de juce::LookAndFeel_V4 e sobrescreve o método drawLabel.
class CustomDialLabel : public juce::LookAndFeel_V4
{
public:
    // Construtor da classe CustomDialLabel.
    CustomDialLabel();

    // Desenha um label customizado para o slider.
    // g: Contexto gráfico para desenhar.
    // label: Referência para o objeto Label.
    void drawLabel (juce::Graphics& g, juce::Label& label) override;

    // Enumeração para definir o tipo de valor do dial (inteiro ou float).
    enum class ValueType
    {
        kInt,
        kFloat
    };

    // Retorna o tipo de valor do dial.
    ValueType getDialValueType()
    {
        return _dialValueType;
    }

    // Define o tipo de valor do dial.
    void setDialValueType (ValueType newValueType)
    {
        _dialValueType = newValueType;
    }

    // Define se o dial está invertido.
    void setIsReversed (bool reverse) { isReversed = reverse; };

private:
    // Variáveis privadas da classe.
    float _sliderWidth; // Largura do slider.
    bool sliderIsDial = true; // Indica se o slider é um dial.
    bool isReversed = false; // Indica se o dial está invertido.
    juce::String _sliderName = ""; // Nome do slider.
    ValueType _dialValueType = ValueType::kFloat; // Tipo de valor do dial.
};
