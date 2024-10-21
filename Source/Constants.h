/*
  ==============================================================================

    Constants.h
    Created: 20 Oct 2024 3:38:20pm
    Author:  Guh F

  ==============================================================================
*/

#pragma once

// Define um namespace para as constantes.
namespace Constants
{
    // Constantes para a faixa de ganho em dB.
    constexpr float MIN_GAIN_DB = -60.0f; // Ganho mínimo em dB.
    constexpr float MAX_GAIN_DB = 24.0f;  // Ganho máximo em dB.
    constexpr float GAIN_STEP_DB = 0.01f; // Incremento do ganho em dB.

    // Valor padrão do ganho em dB.
    constexpr float DEFAULT_GAIN_DB = 0.0f;

    // Valor Unícos em texto para Identificar Componentes
    const juce::String PARAMETERS = "parametros";
    const juce::String GAIN_ID = "ganho";
    const juce::String GAIN_NAME = "Ganho";
}
