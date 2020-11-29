/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ToneDelayAudioProcessorEditor::ToneDelayAudioProcessorEditor (ToneDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize(600, 300);
    
    // Delay Time Knob
    delayTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    delayTimeSlider.setRange(0.0, 1000.0, 1.0);
    delayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 90, delayTimeSlider.getTextBoxHeight());
    delayTimeSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
    delayTimeSlider.setPopupDisplayEnabled(false, false, this);
    delayTimeSlider.setTextValueSuffix(" ms");
    delayTimeSlider.setValue(0.0);
    
    addAndMakeVisible(delayTimeLabel);
    delayTimeLabel.setText("Delay Time", juce::NotificationType::dontSendNotification);
    delayTimeLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    delayTimeLabel.attachToComponent(&delayTimeSlider, false);
    delayTimeLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(&delayTimeSlider);
    delayTimeSlider.addListener(this);
    
    
    // Feedback Knob
    feedbackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    feedbackSlider.setRange(0.0, 100.0, 1.0);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 90, feedbackSlider.getTextBoxHeight());
    feedbackSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
    feedbackSlider.setPopupDisplayEnabled(false, false, this);
    feedbackSlider.setTextValueSuffix("%");
    feedbackSlider.setValue(0.0);
    
    addAndMakeVisible(feedbackLabel);
    feedbackLabel.setText("Feedback", juce::NotificationType::dontSendNotification);
    feedbackLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    feedbackLabel.attachToComponent(&feedbackSlider, false);
    feedbackLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(&feedbackSlider);
    feedbackSlider.addListener(this);
    
    // Mix Knob
    mixSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setRange(0.0, 100.0, 1.0);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 125, mixSlider.getTextBoxHeight());
    mixSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
    mixSlider.setPopupDisplayEnabled(false, false, this);
    mixSlider.setTextValueSuffix("% Wet");
    mixSlider.setValue(0.0);
    
    addAndMakeVisible(mixLabel);
    mixLabel.setText("Mix", juce::NotificationType::dontSendNotification);
    mixLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    mixLabel.attachToComponent(&mixSlider, false);
    mixLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(&mixSlider);
    mixSlider.addListener(this);
}

void ToneDelayAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if(slider == &delayTimeSlider){
        audioProcessor.delayTime = delayTimeSlider.getValue();
    } else if(slider == &feedbackSlider) {
        audioProcessor.feedback = feedbackSlider.getValue();
    } else if(slider == &mixSlider) {
        audioProcessor.mix = mixSlider.getValue();
    }
}

ToneDelayAudioProcessorEditor::~ToneDelayAudioProcessorEditor()
{
}

//==============================================================================
void ToneDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::white);

    g.setColour(juce::Colours::black);
    g.setFont(15.0f);
    std::string headerText = "ToneDelay v";
    headerText += ProjectInfo::versionString;
    g.drawFittedText(headerText, 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void ToneDelayAudioProcessorEditor::resized()
{
    delayTimeSlider.setBounds(100, 75, getHeight() / 2, getHeight() / 2);
    delayTimeLabel.setBounds(0, 0, getWidth(), getHeight());
    feedbackSlider.setBounds((getWidth() / 2) + 50, 75, getHeight() / 2, getHeight() / 2);
    feedbackLabel.setBounds(0, 0, getWidth(), getHeight());
    mixSlider.setBounds((getWidth() / 2) - 50, 185, 100, 100);
    mixLabel.setBounds(0, 0, getWidth(), getHeight());
}
