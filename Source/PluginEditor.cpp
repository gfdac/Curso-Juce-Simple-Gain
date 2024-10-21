/*
  ==============================================================================

    PluginEditor.cpp
    Created: 20 Oct 2024 3:38:20pm
    Author:  Guh F

  ==============================================================================
*/

#include "PluginEditor.h"
#include "Constants.h"
#include "MyLookAndFeel.h" // Inclua o header do seu LookAndFeel

// Construtor: Cria o slider e conecta ao parâmetro de ganho.
CursoJuceSimpleGainEditor::CursoJuceSimpleGainEditor (CursoJuceSimpleGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

//    // Configure o Label com nome do plugin
//    mainLabel.setText ("Hello World!", juce::dontSendNotification);
//    mainLabel.setJustificationType(juce::Justification::centred);
    
    // Configurando a fonte com FontOptions
//    juce::FontOptions fontOptions ("Helvetica", 16.0f, juce::Font::bold); // Usando o novo construtor de FontOptions
//    juce::Font minhaFonte (fontOptions); // Criando a fonte com as opções definidas
//    mainLabel.setFont (minhaFonte);
    
//    ganhoLabel.attachToComponent (&ganhoSlider, false); // Posiciona o Label em relação ao slider
    
//    addAndMakeVisible (mainLabel);

    // Define o estilo da caixa de texto do slider.
//    ganhoSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 100, 30);
    
    // Define o sufixo do valor do texto
//    ganhoSlider.setTextValueSuffix(" dB");
    
    // Define o name associado ao componente slider
//    ganhoSlider.setName(Constants::GAIN_NAME);
    
    // Define o estilo do slider como Linear Vertical.
//     ganhoSlider.setSliderStyle (juce::Slider::LinearVertical);
    // Define o estilo do slider como Rotativo.
//    ganhoSlider.setSliderStyle (juce::Slider::RotaryVerticalDrag);

    // Aplique o LookAndFeel ao slider
//    ganhoSlider.setLookAndFeel (&myLookAndFeel);
    
    // Adiciona o slider à interface e o torna visível.
//    addAndMakeVisible (ganhoSlider);

    // Cria um SliderAttachment para conectar o slider ao parâmetro de ganho.
//    ganhoAttachment.reset (new juce::AudioProcessorValueTreeState::SliderAttachment (
//        audioProcessor.parameters, // Referência ao AudioProcessorValueTreeState que contém o parâmetro de ganho
//        Constants::GAIN_ID,       // ID do parâmetro de ganho, definido em Constants.h
//        ganhoSlider               // Referência ao Slider que controlará o parâmetro
//    ));

    
    
//    // Cria um ToggleButton para alternar o modo que o ganho é aplicado ao audio.
//    tipoGanhoCheckBox.setButtonText("ganho via DSP");
//    // Controla a visibilidade do componente
//    tipoGanhoCheckBox.setVisible(true);
//    // Adiciona o checkbox à interface.
//    addAndMakeVisible (tipoGanhoCheckBox);
//
//    // Define a ação a ser executada quando o checkbox for clicado.
//    tipoGanhoCheckBox.onClick = [this] {
//        if (tipoGanhoCheckBox.getToggleState())
//        {
//            // Checkbox ativado
//            bUsarDSP = true;
//        }
//        else
//        {
//            // Checkbox desativado
//            bUsarDSP = false;
//        }
//    };
    
    
    
    // Permite redimensionamento horizontal e vertical, com cantos redimensionáveis
//    setResizeLimits (400, 300, 1024, 768); // Define limites para o tamanho da janela
//    setResizable (true, true);
    
    // Define o tamanho inicial da janela do plugin.
    setSize (400, 300);
}

// Destrutor.
CursoJuceSimpleGainEditor::~CursoJuceSimpleGainEditor()
{
    // Limpando da memoria os objetos Look And Feel 
//    Component::setLookAndFeel (nullptr);
//    juce::LookAndFeel::setDefaultLookAndFeel (nullptr);
}

// Desenha o componente na tela.
void CursoJuceSimpleGainEditor::paint (juce::Graphics& g)
{
    // Preenche o fundo com a cor padrão da janela.
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

// Método chamado quando o tamanho do componente é alterado.
void CursoJuceSimpleGainEditor::resized()
{
//    // Define a largura e altura do slider.
//    int sliderWidth = 200;
//    int sliderHeight = 200;
//
//    // Calcula a posição x e y para centralizar o slider na janela.
//    int x = (getWidth() - sliderWidth) / 2;
//    int y = (getHeight() - sliderHeight) / 2;
//
//    // Define a posição e o tamanho do slider.
//    ganhoSlider.setBounds (x, y, sliderWidth, sliderHeight);
  
    
    
    // Define a posicao e tamanho do toogleButton
//    tipoGanhoCheckBox.setBounds(10, getBounds().getHeight() - 30, 200, 30);
}
