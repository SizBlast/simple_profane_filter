<?php

function simple_profane_filter_admin_settings_form($form, &$form_state){
    $form['profane_words_add'] = array(
      '#type' => 'textarea',
      '#title' => t('Add profane words'),
      '#description' => t('Put here the profane words you want to filter. Please put one word per line.'),
    );
    $form['profane_words_remove'] = array(
      '#type' => 'textarea',
      '#title' => t('Remove profane words'),
      '#description' => t('Put here the profane words you want to remove from the filter. Please put one word per line.'),
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
    $form['#submit'][] = 'simple_profane_filter_admin_settings_form_submit';
    return $form;
}

function simple_profane_filter_admin_settings_form_submit($form, &$form_state){
    // Profane words that need to be inserted into the database
    $add = $form_state['values']['profane_words_add'];
    $insert = explode("\n", $add);
    dsm($insert);
    
    foreach ($insert as $item){
        simple_profane_filter_insert(rtrim($item));
    }
    
    // Profane words that need to be deleted from the database
    $remove = $form_state['values']['profane_words_remove'];
    $delete = explode("\n", $remove);
    dsm($delete);
    
    foreach ($delete as $item){
        simple_profane_filter_delete(rtrim($item));
    }
}