<?php
/**
 * @file
 * Implements No Payment Required payment method.
 */

/**
 * Payment method callback: settings form.
 */
function commerce_nopayment_transaction_no_payment_settings_form($settings = NULL) {
  return array();
}

/**
 * Payment method callback: checkout form.
 */
function commerce_nopayment_transaction_no_payment_submit_form($payment_method, $pane_values, $checkout_pane, $order) {
  return array();
}

/**
 * Payment method callback: checkout form validation.
 */
function commerce_nopayment_transaction_no_payment_submit_form_validate($payment_method, $pane_form, $pane_values, $order, $form_parents = array()) {
  return TRUE;
}

/**
 * Payment method callback: checkout form submission.
 */
function commerce_nopayment_transaction_no_payment_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge) {
  // Create a payment transaction for logging purposes. No actual payment.
  $transaction = commerce_payment_transaction_new($payment_method['method_id'], $order->order_id);
  $transaction->instance_id = $payment_method['instance_id'];
  $transaction->amount = $charge['amount'];
  $transaction->currency_code = $charge['currency_code'];
  $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;
  $transaction->message = 'Transaction successful.';

  // Save the transaction information.
  commerce_payment_transaction_save($transaction);

  return TRUE;
}
