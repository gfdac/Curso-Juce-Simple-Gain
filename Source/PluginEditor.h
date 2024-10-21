/*
  ==============================================================================

    PluginEditor.h
    Created: 20 Oct 2024 3:38:20pm
    Author:  Guh F

  ==============================================================================
*/

#pragma once

// Inclui o header do PluginProcessor.
#include "PluginProcessor.h"
#include "MyLookAndFeel.h"

// Define a classe do editor do plugin.
class CursoJuceSimpleGainEditor  : public juce::AudioProcessorEditor
{
public:
    // Construtor.
    CursoJuceSimpleGainEditor (CursoJuceSimpleGainAudioProcessor&);
    // Destrutor.
    ~CursoJuceSimpleGainEditor() override;

    // Métodos sobrescritos da classe AudioProcessorEditor.
    void paint (juce::Graphics&) override;
    void resized() override;

    //para controlar o fluxo de qual Ganho usar (via DSP ou cada amostra do buffer)
    bool bUsarDSP = false;  
    bool getUsarDSP() const { return bUsarDSP; }
    
private:
    // Referência para o processador de áudio.
    CursoJuceSimpleGainAudioProcessor& audioProcessor;
    
    // Nossa classe customizada para GUI do Slider (precisa criar antes do componente que vai utiliza-lo para nao gerar referencias fracas.
//    MyLookAndFeel myLookAndFeel;
    
    // Label principal da interface
//    juce::Label mainLabel;
    
    // Slider para controlar o ganho.
//    juce::Slider ganhoSlider;
    
    // Checkbox para alterar o tipo de ganho utilizado (DSP ou Generico)
//    juce::ToggleButton tipoGanhoCheckBox;
    
    // Conecta o slider ao parâmetro de ganho.
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ganhoAttachment;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CursoJuceSimpleGainEditor)
};
