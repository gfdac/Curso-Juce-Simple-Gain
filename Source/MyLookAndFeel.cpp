/*
 ==============================================================================

 MyLookAndFeel.cpp
 Created: 20 Oct 2024 4:19:32pm
 Author:  Guh F

 ==============================================================================
 */

#include "MyLookAndFeel.h"

MyLookAndFeel::MyLookAndFeel() {}

void MyLookAndFeel::drawRotarySlider(juce::Graphics &g, int x, int y, int width,
                                     int height, float sliderPos,
                                     float rotaryStartAngle,
                                     float rotaryEndAngle, juce::Slider &slider)

{
    // Armazena o nome do slider para exibir no label
    _sliderName = slider.getName();

    // Define as cores para o knob
    const auto outlineColor = slider.findColour(
        juce::Slider::rotarySliderOutlineColourId); // Cor do contorno do knob
    const auto fillColor = slider.findColour(
        juce::Slider::rotarySliderFillColourId); // Cor de preenchimento do knob
    const auto mainColor =
        slider.findColour(juce::Slider::thumbColourId)
            .withAlpha(0.5f); // Cor principal do knob (com transparência)
    const auto brighterColor =
        slider.findColour(juce::Slider::thumbColourId)
            .withAlpha(0.5f)
            .brighter(0.4f); // Cor mais brilhante para o gradiente
    const auto dialOutlineColor = slider.findColour(
        juce::Slider::backgroundColourId); // Cor do contorno do dial

    // Define a área do dial
    auto dialBounds = juce::Rectangle<int>(x, y, width, height).toFloat();
    auto centre = dialBounds.getCentre(); // Centro do dial
    float sizeScalar = 0.6f; // Escala para ajustar o tamanho do knob
    auto fullRadius =
        juce::jmin(dialBounds.getWidth() * sizeScalar,
                   dialBounds.getHeight() * sizeScalar); // Raio total do knob

    // Ajusta o raio para o desenho do knob
    fullRadius -= width / 14.5;

    // Calcula o ângulo do knob com base na posição do slider
    auto toAngle =
        rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    // Define a espessura da trilha do knob
    float lineWidthMultiplier = width * 0.035;
    auto lineWidth = juce::jmin(lineWidthMultiplier, fullRadius * 0.5f);
    auto arcRadius = fullRadius - lineWidth * 2.25;

    // Cria o caminho para a trilha de fundo do knob
    juce::Path backgroundArc;
    backgroundArc.addCentredArc(dialBounds.getCentreX(),
                                dialBounds.getCentreY(), arcRadius, arcRadius,
                                0.0f, rotaryStartAngle, rotaryEndAngle, true);

    // Desenha a trilha de fundo do knob
    g.setColour(outlineColor);
    g.strokePath(backgroundArc,
                 juce::PathStrokeType(lineWidth, juce::PathStrokeType::curved,
                                      juce::PathStrokeType::rounded));

    // Calcula o raio do knob principal
    auto dialRadius = std::max(fullRadius - 4.0f * lineWidth, 10.0f);

    // Desenha o knob principal com gradiente
    {
        juce::Graphics::ScopedSaveState saved(
            g);                 // Salva o estado gráfico atual
        if (slider.isEnabled()) // Verifica se o slider está habilitado
        {
            // Cria um gradiente de cores para o knob
            juce::ColourGradient fillGradient(
                brighterColor, centre.getX() + lineWidth * 0.9f,
                centre.getY() - lineWidth * 4.0f, mainColor.darker(1.0),
                centre.getX() + dialRadius, centre.getY() + dialRadius, true);

            g.setGradientFill(
                fillGradient); // Define o gradiente como preenchimento
        }
        g.fillEllipse(centre.getX() - dialRadius, centre.getY() - dialRadius,
                      dialRadius * 2.0f,
                      dialRadius * 2.0f); // Desenha o knob
    }

    // Desenha o contorno do knob principal
    g.setColour(dialOutlineColor);
    auto scale = 2.0f; // Escala para o contorno do knob
    g.drawEllipse(centre.getX() - dialRadius, centre.getY() - dialRadius,
                  dialRadius * scale, dialRadius * scale,
                  4.5f); // Desenha o contorno

    // Cria o caminho para a trilha do valor do knob
    juce::Path dialValueTrack;
    dialValueTrack.addCentredArc(dialBounds.getCentreX(),
                                 dialBounds.getCentreY(), arcRadius, arcRadius,
                                 0.0f, rotaryStartAngle, toAngle, true);

    // Desenha a trilha do valor do knob
    g.setColour(fillColor);
    g.strokePath(dialValueTrack,
                 juce::PathStrokeType(lineWidth, juce::PathStrokeType::curved,
                                      juce::PathStrokeType::rounded));

    // Desenha o indicador do knob
    g.setColour(dialOutlineColor);
    juce::Path dialTick;
    dialTick.startNewSubPath(
        centre.getPointOnCircumference(dialRadius - lineWidth, toAngle));
    // Inicia o caminho do indicador
    dialTick.lineTo(centre.getPointOnCircumference(
        (dialRadius - lineWidth) * 0.6f,
        toAngle)); // Desenha a linha do indicador
    g.strokePath(dialTick,
                 juce::PathStrokeType(
                     lineWidth * 0.75, juce::PathStrokeType::curved,
                     juce::PathStrokeType::rounded)); // Desenha o indicador

    // Armazena a largura do slider para uso posterior
    _sliderWidth = slider.getWidth();
}

void MyLookAndFeel::drawLabel(juce::Graphics &g, juce::Label &label) {
    // Desenha o label do slider com o nome e valor
    g.fillAll(label.findColour(
        juce::Label::backgroundColourId)); // Preenche o fundo do label
    label.setEditable(true);               // Permite que o label seja editável

    if (!label.isBeingEdited()) // Verifica se o label não está sendo editado
    {
        auto alpha =
            label.isEnabled() ? 1.0f : 0.5f; // Define a transparência do label
        g.setColour(
            label.findColour(juce::Label::textColourId)
                .withMultipliedAlpha(alpha)); // Define a cor do texto do label

        // Cria um objeto FontOptions com a fonte Helvetica, tamanho calculado e
        // sem estilo.
        juce::FontOptions fontOptions(
            "Helvetica",
            juce::jmax(label.getWidth() * 0.12, label.getHeight() * 0.25),
            juce::Font::FontStyleFlags::plain);
        // Cria um objeto Font usando as opções definidas em fontOptions.
        const juce::Font font(fontOptions);
        g.setFont(font); // Define a fonte do label

        auto textArea = getLabelBorderSize(label).subtractedFrom(
            label.getLocalBounds()); // Define a área do texto do label

        juce::String labelText; // String para armazenar o texto do label
        if (auto *parentComponent =
                label.getParentComponent()) // Verifica se o label tem um
                                            // componente pai
        {
            if (auto *slider = dynamic_cast<juce::Slider *>(
                    parentComponent)) // Verifica se o componente pai é um
                                      // slider
            {
                // Verifica se o mouse está sobre o slider
                bool isMouseOver = slider->isMouseOver() || slider->isMouseButtonDown();

                // Obtém o valor do slider
                float value;
                if (_dialValueType ==
                    ValueType::kInt) // Verifica se o tipo de valor do dial é
                                     // inteiro
                {
                    value = static_cast<int>(
                        slider->getValue()); // Converte o valor do slider para
                                             // inteiro
                } else {
                    value =
                        slider
                            ->getValue(); // Mantém o valor do slider como float
                }

                // Formata o valor do slider como string
                juce::String valueText;
                if (value == 0.0f) // Se o valor for zero, exibe "0.0"
                    valueText = "0.0";
                else
                    valueText = juce::String(value,
                                             2); // Formata com 2 casas decimais

                juce::String suffix =
                    slider->getTextValueSuffix(); // Obtém o sufixo do valor do
                                                  // slider

                // Define o texto do label com base no estado do mouse
                if (isMouseOver)
                {
                    labelText = valueText + suffix; // Mostra o valor do slider com o sufixo
                }
                else
                {
                    labelText = slider->getName(); // Mostra o nome do slider
                }

                
            }
        }

        // Desenha o texto do label
        g.drawFittedText(labelText, textArea, label.getJustificationType(),
                         juce::jmax(1, (int)((float)textArea.getHeight() /
                                             font.getHeight())),
                         label.getMinimumHorizontalScale());

        g.setColour(label.findColour(juce::Label::outlineColourId)
                        .withMultipliedAlpha(alpha));
        // Define a cor do contorno do label
    } else if (label.isEnabled()) {
        g.setColour(label.findColour(
            juce::Label::outlineColourId)); // Define a cor do contorno do label
                                            // quando está sendo editado
    }

    g.drawRect(label.getLocalBounds()); // Desenha o retângulo do label
}


#pragma mark Dial Just Label

// Construtor da classe CustomDialLabel.
CustomDialLabel::CustomDialLabel() {}

// Método para desenhar o label do slider.
void CustomDialLabel::drawLabel (juce::Graphics& g, juce::Label& label)
{
    // Preenche o fundo do label com a cor de fundo definida para o label.
    g.fillAll (label.findColour (juce::Label::backgroundColourId));

    // Permite que o texto do label seja editável pelo usuário.
    label.setEditable (true);

    // Verifica se o label não está sendo editado no momento.
    if (!label.isBeingEdited())
    {
        // Define a transparência do texto do label com base no estado do label (habilitado ou desabilitado).
        auto alpha = label.isEnabled() ? 1.0f : 0.5f;

        // Define a cor do texto do label com a transparência definida.
        g.setColour (label.findColour (juce::Label::textColourId).withMultipliedAlpha (alpha));

        // Cria um objeto FontOptions com a fonte Helvetica, tamanho calculado e estilo negrito.
        juce::FontOptions fontOptions ("Helvetica",
                                       juce::jmax (label.getWidth() * 0.12, label.getHeight() * 0.75), // Calcula o tamanho da fonte dinamicamente
                                       juce::Font::FontStyleFlags::bold); // Define o estilo da fonte como negrito

        // Cria um objeto Font usando as opções definidas em fontOptions.
        const juce::Font font (fontOptions);

        // Define a fonte do contexto gráfico para a fonte criada.
        g.setFont (font);

        // Calcula a área de texto do label subtraindo a borda.
        auto textArea = getLabelBorderSize (label).subtractedFrom (label.getLocalBounds());

        // Cria uma string para armazenar o texto do label.
        juce::String labelText;

        // Verifica se o label tem um componente pai.
        if (auto* parentComponent = label.getParentComponent())
        {
            // Tenta converter o componente pai para um slider.
            if (auto* slider = dynamic_cast<juce::Slider*> (parentComponent))
            {
                // Verifica se o mouse está sobre o slider.
                bool isMouseOver = slider->isMouseOver() || slider->isMouseButtonDown();

                // Variável para armazenar o valor do slider.
                float value;

                // Verifica o tipo de valor do dial (inteiro ou float).
                if (_dialValueType == ValueType::kInt)
                {
                    // Converte o valor do slider para inteiro.
                    value = static_cast<int> (slider->getValue());
                }
                else
                {
                    // Ajusta o valor do slider com base na inversão e arredonda para duas casas decimais.
                    value = static_cast<float> (static_cast<int> ((slider->getValue() + 10.0 * isReversed) * 100.0)) / 100.0;
                }

                // Obtém o sufixo do texto do slider (se houver).
                juce::String suffix = slider->getTextValueSuffix();

                // Define o texto do label com base no estado do mouse.
                if (isMouseOver)
                {
                    // Se o mouse estiver sobre o slider, exibe o valor do slider com o sufixo.
                    labelText = juce::String (value) + suffix;
                }
                else
                {
                    // Caso contrário, exibe o nome do slider.
                    labelText = slider->getName();
                }
            }
        }

        // Desenha o texto do label na área de texto calculada, com a justificação, número máximo de linhas e escala horizontal definidos.
        g.drawFittedText (labelText, textArea, label.getJustificationType(),
                          juce::jmax (1, (int) ((float) textArea.getHeight() / font.getHeight())),
                          label.getMinimumHorizontalScale());


        // Define a cor do contorno do label com a transparência definida.
        g.setColour (label.findColour (juce::Label::outlineColourId).withMultipliedAlpha (alpha));
    }
    // Se o label estiver habilitado e sendo editado, define a cor do contorno do label.
    else if (label.isEnabled())
    {
        g.setColour (label.findColour (juce::Label::outlineColourId));
    }

    // Desenha um retângulo ao redor do label.
    g.drawRect (label.getLocalBounds());
}
