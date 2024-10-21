/*
  ==============================================================================

    PluginProcessor.h
    Created: 20 Oct 2024 3:38:20pm
    Author:  Guh F

  ==============================================================================
*/

#pragma once

// Inclui o header principal do JUCE, que contém todas as classes e funções
// necessárias para desenvolver plugins de áudio no JUCE.
#include <JuceHeader.h>

// Define a classe do processador de áudio do plugin.
// Essa classe herda de juce::AudioProcessor e define o comportamento do plugin
// em relação ao processamento de áudio, gerenciamento de parâmetros e outras
// funcionalidades.
class CursoJuceSimpleGainAudioProcessor  : public juce::AudioProcessor
{
public:
    // Construtor da classe.
    // Inicializa o processador de áudio e seus parâmetros.
    CursoJuceSimpleGainAudioProcessor();
    
    // Destrutor da classe.
    // Libera os recursos alocados pelo processador de áudio.
    ~CursoJuceSimpleGainAudioProcessor() override;

    // Métodos sobrescritos da classe AudioProcessor.
    // Esses métodos são chamados pelo host em diferentes momentos do ciclo
    // de vida do plugin.

    // Método chamado antes da reprodução começar.
    // Usado para inicializar o processador de áudio com as especificações
    // do áudio (taxa de amostragem, tamanho do buffer, etc.).
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    
    // Método chamado quando a reprodução termina.
    // Usado para liberar os recursos alocados em prepareToPlay().
    void releaseResources() override;

    // Verifica se o layout de buses é suportado.
    // Usado pelo host para verificar se o plugin suporta um determinado
    // layout de canais (mono, estéreo, etc.).
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    // Processa um bloco de amostras de áudio.
    // Este é o método principal do processador de áudio, onde o
    // processamento do áudio acontece.
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    // Métodos relacionados à interface gráfica do plugin.

    // Cria o editor gráfico do plugin.
    // Retorna um ponteiro para o objeto AudioProcessorEditor que representa
    // a interface gráfica do plugin.
    juce::AudioProcessorEditor* createEditor() override;
    
    // Verifica se o plugin possui um editor gráfico.
    bool hasEditor() const override;

    //==============================================================================
    // Métodos para obter informações sobre o plugin.

    // Retorna o nome do plugin.
    const juce::String getName() const override;

    // Indica se o plugin aceita MIDI.
    bool acceptsMidi() const override;
    
    // Indica se o plugin produz MIDI.
    bool producesMidi() const override;
    
    // Indica se o plugin é um efeito MIDI.
    bool isMidiEffect() const override;
    
    // Retorna o tempo de delay do plugin em segundos.
    double getTailLengthSeconds() const override;

    //==============================================================================
    // Métodos para gerenciar programas do plugin.

    // Retorna o número de programas do plugin.
    int getNumPrograms() override;
    
    // Retorna o programa atual do plugin.
    int getCurrentProgram() override;
    
    // Define o programa atual do plugin.
    void setCurrentProgram (int index) override;
    
    // Retorna o nome do programa.
    const juce::String getProgramName (int index) override;
    
    // Altera o nome do programa.
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    // Métodos para salvar e carregar o estado do plugin.

    // Salva o estado do plugin em um MemoryBlock.
    void getStateInformation (juce::MemoryBlock& destData) override;
    
    // Carrega o estado do plugin a partir de um MemoryBlock.
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Armazena os parâmetros do plugin.
    // AudioProcessorValueTreeState é uma classe do JUCE que gerencia os
    // parâmetros do plugin de forma hierárquica.
//    juce::AudioProcessorValueTreeState parameters;

    //classe DSP para controle de ganho
//    juce::dsp::Gain<float> gainProcessor;

private:
    
    // utilizado para criar a interpolacao quando ganho sem DSP
//    float ganhoAtual = 1.0f; // Valor inicial do ganho (1.0f corresponde a 0dB)
    
    // Macro do JUCE para evitar cópia do objeto e detectar vazamentos de memória.
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CursoJuceSimpleGainAudioProcessor)
};
