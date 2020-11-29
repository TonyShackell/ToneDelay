/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ToneDelayAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    ToneDelayAudioProcessorEditor (ToneDelayAudioProcessor&);
    ~ToneDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (juce::Slider* slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ToneDelayAudioProcessor& audioProcessor;
    
    // Declare UI elements
    juce::Slider delayTimeSlider;
    juce::Label delayTimeLabel;
    
    juce::Slider feedbackSlider;
    juce::Label feedbackLabel;
    
    juce::Slider mixSlider;
    juce::Label mixLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneDelayAudioProcessorEditor)
};
