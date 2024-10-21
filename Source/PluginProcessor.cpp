/*
  ==============================================================================

    PluginProcessor.cpp
    Created: 20 Oct 2024 3:38:20pm
    Author:  Guh F

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Constants.h"

// Construtor: Inicializa o AudioProcessorValueTreeState com o parâmetro de ganho.
CursoJuceSimpleGainAudioProcessor::CursoJuceSimpleGainAudioProcessor()
//: parameters (*this, nullptr, juce::Identifier (Constants::PARAMETERS),
//  {
//      std::make_unique<juce::AudioParameterFloat> (
//          Constants::GAIN_ID,    // ID do parâmetro de ganho.
//          Constants::GAIN_NAME,  // Nome do parâmetro de ganho.
//          juce::NormalisableRange<float> (
//              Constants::MIN_GAIN_DB,   // Valor mínimo do ganho em dB.
//              Constants::MAX_GAIN_DB,   // Valor máximo do ganho em dB.
//              Constants::GAIN_STEP_DB), // Incremento do ganho em dB.
//          Constants::DEFAULT_GAIN_DB   // Valor inicial do ganho em dB.
//      )
//  })
//Construtor, colocar aqui possiveis inicializações e customizacoes
{
    // Define o ganho inicial do processador em decibéis.
    // O valor do ganho é obtido do parâmetro "ganho" armazenado no AudioProcessorValueTreeState.
    // gainProcessor.setGainDecibels (parameters.getRawParameterValue (Constants::GAIN_ID)->load());
}

// Destrutor.
CursoJuceSimpleGainAudioProcessor::~CursoJuceSimpleGainAudioProcessor()
{
    
    // O AudioProcessorValueTreeState é destruído automaticamente aqui,
    // juntamente com todos os seus parâmetros.

}

// Método chamado antes da reprodução começar.
// Nesse caso, só precisamos inicializar specs no prepareToPlay, se tivermos algum objeto externo que precise ser configurado com as especificações do áudio.
void CursoJuceSimpleGainAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
//    // Cria um objeto dsp::ProcessSpec para armazenar as especificações do áudio.
//    // Esse objeto contém informações como taxa de amostragem, tamanho máximo do bloco de amostras e número de canais.
//    juce::dsp::ProcessSpec specs;
//    
//    // Define o tamanho máximo do bloco de amostras.
//    // Essa informação é usada pelo processador de áudio para alocar buffers e otimizar o processamento.
//    specs.maximumBlockSize = samplesPerBlock;
//    
//    // Define a taxa de amostragem do áudio em Hz.
//    // Essa informação é crucial para que o processador de áudio funcione corretamente.
//    specs.sampleRate = sampleRate;
//    
//    // Define o número de canais de saída do processador de áudio.
//    // Essa informação é usada para configurar o processamento de áudio para o número correto de canais.
//    specs.numChannels = getTotalNumOutputChannels();
//
//    // Prepara o processador de ganho com as especificações do áudio.
//    // Isso permite que o processador de ganho se configure corretamente para processar o áudio com as especificações definidas.
//    gainProcessor.prepare (specs);
//    
//    // Define o tempo de rampa (em segundos) para as mudanças de ganho.
//    // Isso cria uma transição suave entre os valores de ganho, evitando "clicks" e "pops" no áudio.
//    gainProcessor.setRampDurationSeconds (0.02);
//    
//    // Define o ganho inicial do processador em decibéis.
//    // O valor do ganho é obtido do parâmetro "ganho" armazenado no AudioProcessorValueTreeState.
//    gainProcessor.setGainDecibels (parameters.getRawParameterValue (Constants::GAIN_ID)->load());
}

// Método chamado quando a reprodução termina.
void CursoJuceSimpleGainAudioProcessor::releaseResources()
{
    // Reseta o processador de ganho.
//    gainProcessor.reset();      
}

// Verifica se o layout de buses é suportado.
// Essa função é chamada pelo host para verificar se o plugin suporta um determinado layout de canais.
#ifndef JucePlugin_PreferredChannelConfigurations
bool CursoJuceSimpleGainAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    #if JucePlugin_IsMidiEffect // Se o plugin for um efeito MIDI
        juce::ignoreUnused (layouts); // Ignora o parâmetro layouts
        return true; // Retorna true, pois efeitos MIDI geralmente não processam áudio
    #else
        // Esta é a parte onde você verifica se o layout é suportado.
        // Neste código, suportamos apenas mono ou estéreo.
        // Alguns hosts, como certas versões do GarageBand, só carregam plugins que suportam layouts estéreo.

        // Verifica se o conjunto de canais de saída principal é diferente de mono e estéreo.
        if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
            return false; // Se for diferente de mono e estéreo, retorna false (layout não suportado)

        // Verifica se o layout de entrada corresponde ao layout de saída.
        // Isso é necessário para plugins que não são sintetizadores.
        #if ! JucePlugin_IsSynth
            if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
                return false; // Se os layouts de entrada e saída não corresponderem, retorna false
        #endif

        return true; // Se todas as verificações passarem, retorna true (layout suportado)
    #endif
}
#endif



// Processa um bloco de amostras de áudio.
// Este método é chamado pelo host a cada bloco de áudio durante a reprodução.
void CursoJuceSimpleGainAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{

    // Impede o processamento de números denormalizados, que podem causar problemas de performance em algumas plataformas.
    juce::ScopedNoDenormals noDenormals;

    // Obtém o número de canais de entrada do processador de áudio.
    auto totalNumInputChannels  = getTotalNumInputChannels();
    
    // Obtém o número de canais de saída do processador de áudio.
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Limpa os canais de saída extras (se houver). Isso garante que não haja
    // ruído residual nos canais de saída que não têm um canal de entrada correspondente.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    // Obtém o valor do ganho em dB do parâmetro "ganho" no AudioProcessorValueTreeState.
//    float ganhoDB = *parameters.getRawParameterValue (Constants::GAIN_ID);
    // Converte o ganho de dB para um valor linear.
//    float ganhoLinear = juce::Decibels::decibelsToGain (ganhoDB);

    // Aplica o ganho ao áudio sem interpolacao ("com ruido se mexer rapido")
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
//            channelData[sample] *= ganhoLinear;
        }
    }
     
    
    
//    // Verifica o estado do ToggleButton "Usar DSP" no editor:
//    // Tenta obter o editor do plugin e convertê-lo para o tipo CursoJuceGainEditor.
//    // Isso é necessário para acessar o estado do ToggleButton "Usar DSP" que está no editor.
//    if (auto* editor = dynamic_cast<CursoJuceSimpleGainEditor*> (getActiveEditor()))
//    {
//        // Verifica se o ToggleButton "Usar DSP" está ativado.
//        if (editor->getUsarDSP())
//        {
//            // Processamento com DSP e interpolação:
//
//            // Define o ganho do processador DSP.
//            gainProcessor.setGainLinear (ganhoLinear);
//
//            // Processa o áudio com o gainProcessor.
//            // Cria um AudioBlock que encapsula o buffer de áudio.
//            juce::dsp::AudioBlock<float> block (buffer);
//            
//            // Processa o bloco de áudio com o gainProcessor, substituindo os valores originais
//            // no buffer pelos valores processados.
//            gainProcessor.process (juce::dsp::ProcessContextReplacing<float> (block));
//        }
//        // Usar DSP desativado (faz o ganho de modo direto na manipulacao dos valores nos canais)
//        else
//        {
//            // Processamento direto com interpolação:
//            
//            // Calcula o incremento do ganho por amostra para criar uma transição suave entre o valor
//            // atual do ganho e o novo valor lido do parâmetro. Isso evita o "zipper noise" que
//            // pode ocorrer ao alterar o ganho abruptamente.
//            float ganhoIncremento = (ganhoLinear - ganhoAtual) / buffer.getNumSamples();
//            
//            // Aplica o ganho com interpolação linear a cada amostra do buffer.
//            for (int channel = 0; channel < totalNumInputChannels; ++channel)
//            {
//                // Obtém um ponteiro para os dados do canal atual.
//                auto* channelData = buffer.getWritePointer (channel);
//                
//                // Inicia o ganho com o valor atual do ganho (ganhoAtual).
//                float ganho = ganhoAtual;
//
//                // Itera sobre cada amostra do canal.
//                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
//                {
//                    // Multiplica o valor da amostra pelo ganho atual.
//                    channelData[sample] *= ganho;
//                    
//                    // Incrementa o ganho para a próxima amostra, criando a interpolação linear.
//                    ganho += ganhoIncremento;
//                }
//            }
//        }
//        
//        // Atualiza o ganhoAtual para o novo valor lido do parâmetro, para que a interpolação
//        // continue no próximo bloco de áudio.
//        ganhoAtual = ganhoLinear;
//    }
    
    
}


// Retorna o nome do plugin.
const juce::String CursoJuceSimpleGainAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

// Indica se o plugin aceita MIDI.
bool CursoJuceSimpleGainAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

// Indica se o plugin produz MIDI.
bool CursoJuceSimpleGainAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

// Indica se o plugin é um efeito MIDI.
bool CursoJuceSimpleGainAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

// Retorna o tempo de delay do plugin em segundos.
double CursoJuceSimpleGainAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

// Retorna o número de programas do plugin.
int CursoJuceSimpleGainAudioProcessor::getNumPrograms()
{
    return 1;
}

// Retorna o programa atual do plugin.
int CursoJuceSimpleGainAudioProcessor::getCurrentProgram()
{
    return 0;
}

// Define o programa atual do plugin.
void CursoJuceSimpleGainAudioProcessor::setCurrentProgram (int index)
{
}

// Retorna o nome do programa.
const juce::String CursoJuceSimpleGainAudioProcessor::getProgramName (int index)
{
    return {};
}

// Altera o nome do programa.
void CursoJuceSimpleGainAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

// Salva o estado do plugin.
void CursoJuceSimpleGainAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

// Carrega o estado do plugin.
void CursoJuceSimpleGainAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
bool CursoJuceSimpleGainAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

// Cria o editor gráfico do plugin.
juce::AudioProcessorEditor* CursoJuceSimpleGainAudioProcessor::createEditor()
{
    // Retorna uma nova instância do editor gráfico personalizado.
    return new CursoJuceSimpleGainEditor (*this);
}


// Cria uma instância do plugin.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CursoJuceSimpleGainAudioProcessor();
}

