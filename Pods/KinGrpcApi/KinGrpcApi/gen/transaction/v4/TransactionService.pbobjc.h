// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transaction/v4/transaction_service.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class APBCommonV3InvoiceError;
@class APBCommonV3InvoiceList;
@class APBCommonV4Blockhash;
@class APBCommonV4SolanaAccountId;
@class APBCommonV4StellarTransaction;
@class APBCommonV4Transaction;
@class APBCommonV4TransactionError;
@class APBCommonV4TransactionId;
@class APBCommonV4TransactionSignature;
@class APBTransactionV4Cursor;
@class APBTransactionV4HistoryItem;
@class APBTransactionV4HistoryItem_Payment;
GPB_ENUM_FWD_DECLARE(APBCommonV4Commitment);

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum APBTransactionV4GetHistoryRequest_Direction

typedef GPB_ENUM(APBTransactionV4GetHistoryRequest_Direction) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  APBTransactionV4GetHistoryRequest_Direction_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /**
   * ASC direction returns all history items in
   * ascending (based on chain order) from the cursor.
   **/
  APBTransactionV4GetHistoryRequest_Direction_Asc = 0,

  /**
   * DESC direction returns all history items in
   * descending (based on chain order) from _before_ the cursor.
   **/
  APBTransactionV4GetHistoryRequest_Direction_Desc = 1,
};

GPBEnumDescriptor *APBTransactionV4GetHistoryRequest_Direction_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL APBTransactionV4GetHistoryRequest_Direction_IsValidValue(int32_t value);

#pragma mark - Enum APBTransactionV4GetHistoryResponse_Result

typedef GPB_ENUM(APBTransactionV4GetHistoryResponse_Result) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  APBTransactionV4GetHistoryResponse_Result_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  APBTransactionV4GetHistoryResponse_Result_Ok = 0,
  APBTransactionV4GetHistoryResponse_Result_NotFound = 1,
};

GPBEnumDescriptor *APBTransactionV4GetHistoryResponse_Result_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL APBTransactionV4GetHistoryResponse_Result_IsValidValue(int32_t value);

#pragma mark - Enum APBTransactionV4SubmitTransactionResponse_Result

typedef GPB_ENUM(APBTransactionV4SubmitTransactionResponse_Result) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  APBTransactionV4SubmitTransactionResponse_Result_Ok = 0,

  /**
   * Indicates that the transaction has already been submitted.
   *
   * If the client is retrying a submission due to a transient
   * failure, then this can occur if the submission in a previous
   * attempt was successful. Otherwise, it may indicate that the
   * transcation is indistinguishable from a previous transaction
   * (i.e. same block hash, sender, dest, and amount), and the client
   * should use a different recent block hash and try again.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_AlreadySubmitted = 1,

  /**
   * There was an issue with submitting the transaction
   * to the underlying chain. Clients should retry with
   * a rebuilt transaction in case there are temporal
   * issues with the transaction, such as sequence number,
   * or some other chain-specific errors. The detail of
   * the error is present in the result xdr.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_Failed = 2,

  /**
   * Indicates that the configured webhook for this transaction
   * rejected the transaction without a specified reason.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_Rejected = 3,

  /**
   * Indicates there was an error with one or more of the
   * supplied invoices.
   *
   * See: invoice_errors.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_InvoiceError = 4,

  /**
   * Payer required indicates that the submitted transaction does not contain
   * a signature at for the transaction funder account (the account at the 0th index).
   *
   * This can occur if the service does not have a subsdizier configured, or if
   * the service refuses to subsidize this specific transaction. The latter
   * case can occur during rate limiting situations. In this case, the client
   * may either retry at a later time, or attempt to fund the transaction some
   * other way.
   **/
  APBTransactionV4SubmitTransactionResponse_Result_PayerRequired = 5,
};

GPBEnumDescriptor *APBTransactionV4SubmitTransactionResponse_Result_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL APBTransactionV4SubmitTransactionResponse_Result_IsValidValue(int32_t value);

#pragma mark - Enum APBTransactionV4GetTransactionResponse_State

typedef GPB_ENUM(APBTransactionV4GetTransactionResponse_State) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  APBTransactionV4GetTransactionResponse_State_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  APBTransactionV4GetTransactionResponse_State_Unknown = 0,
  APBTransactionV4GetTransactionResponse_State_Success = 1,
  APBTransactionV4GetTransactionResponse_State_Failed = 2,
  APBTransactionV4GetTransactionResponse_State_Pending = 3,
};

GPBEnumDescriptor *APBTransactionV4GetTransactionResponse_State_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL APBTransactionV4GetTransactionResponse_State_IsValidValue(int32_t value);

#pragma mark - APBTransactionV4TransactionServiceRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface APBTransactionV4TransactionServiceRoot : GPBRootObject
@end

#pragma mark - APBTransactionV4GetServiceConfigRequest

@interface APBTransactionV4GetServiceConfigRequest : GPBMessage

@end

#pragma mark - APBTransactionV4GetServiceConfigResponse

typedef GPB_ENUM(APBTransactionV4GetServiceConfigResponse_FieldNumber) {
  APBTransactionV4GetServiceConfigResponse_FieldNumber_SubsidizerAccount = 1,
  APBTransactionV4GetServiceConfigResponse_FieldNumber_TokenProgram = 2,
  APBTransactionV4GetServiceConfigResponse_FieldNumber_Token = 3,
};

@interface APBTransactionV4GetServiceConfigResponse : GPBMessage

/**
 * The public key of the account that the service will use to sign transactions for funding.
 * If not specified, the service is _not_ configured to fund transactions.
 **/
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *subsidizerAccount;
/** Test to see if @c subsidizerAccount has been set. */
@property(nonatomic, readwrite) BOOL hasSubsidizerAccount;

/** note: after release these values cannot change, and will be static per environment. */
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *tokenProgram;
/** Test to see if @c tokenProgram has been set. */
@property(nonatomic, readwrite) BOOL hasTokenProgram;

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *token;
/** Test to see if @c token has been set. */
@property(nonatomic, readwrite) BOOL hasToken;

@end

#pragma mark - APBTransactionV4GetMinimumKinVersionRequest

@interface APBTransactionV4GetMinimumKinVersionRequest : GPBMessage

@end

#pragma mark - APBTransactionV4GetMinimumKinVersionResponse

typedef GPB_ENUM(APBTransactionV4GetMinimumKinVersionResponse_FieldNumber) {
  APBTransactionV4GetMinimumKinVersionResponse_FieldNumber_Version = 1,
};

@interface APBTransactionV4GetMinimumKinVersionResponse : GPBMessage

@property(nonatomic, readwrite) uint32_t version;

@end

#pragma mark - APBTransactionV4GetRecentBlockhashRequest

@interface APBTransactionV4GetRecentBlockhashRequest : GPBMessage

@end

#pragma mark - APBTransactionV4GetRecentBlockhashResponse

typedef GPB_ENUM(APBTransactionV4GetRecentBlockhashResponse_FieldNumber) {
  APBTransactionV4GetRecentBlockhashResponse_FieldNumber_Blockhash = 1,
};

@interface APBTransactionV4GetRecentBlockhashResponse : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4Blockhash *blockhash;
/** Test to see if @c blockhash has been set. */
@property(nonatomic, readwrite) BOOL hasBlockhash;

@end

#pragma mark - APBTransactionV4GetMinimumBalanceForRentExemptionRequest

typedef GPB_ENUM(APBTransactionV4GetMinimumBalanceForRentExemptionRequest_FieldNumber) {
  APBTransactionV4GetMinimumBalanceForRentExemptionRequest_FieldNumber_Size = 1,
};

@interface APBTransactionV4GetMinimumBalanceForRentExemptionRequest : GPBMessage

@property(nonatomic, readwrite) uint64_t size;

@end

#pragma mark - APBTransactionV4GetMinimumBalanceForRentExemptionResponse

typedef GPB_ENUM(APBTransactionV4GetMinimumBalanceForRentExemptionResponse_FieldNumber) {
  APBTransactionV4GetMinimumBalanceForRentExemptionResponse_FieldNumber_Lamports = 1,
};

@interface APBTransactionV4GetMinimumBalanceForRentExemptionResponse : GPBMessage

@property(nonatomic, readwrite) uint64_t lamports;

@end

#pragma mark - APBTransactionV4GetHistoryRequest

typedef GPB_ENUM(APBTransactionV4GetHistoryRequest_FieldNumber) {
  APBTransactionV4GetHistoryRequest_FieldNumber_AccountId = 1,
  APBTransactionV4GetHistoryRequest_FieldNumber_Cursor = 2,
  APBTransactionV4GetHistoryRequest_FieldNumber_Direction = 3,
};

@interface APBTransactionV4GetHistoryRequest : GPBMessage

/** Account to get history for. */
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *accountId;
/** Test to see if @c accountId has been set. */
@property(nonatomic, readwrite) BOOL hasAccountId;

/**
 * An optional history cursor indicating where in
 * the history to 'resume' from.
 **/
@property(nonatomic, readwrite, strong, null_resettable) APBTransactionV4Cursor *cursor;
/** Test to see if @c cursor has been set. */
@property(nonatomic, readwrite) BOOL hasCursor;

/**
 * The order in which to return history items from
 * the cursor.
 **/
@property(nonatomic, readwrite) APBTransactionV4GetHistoryRequest_Direction direction;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4GetHistoryRequest's @c direction property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4GetHistoryRequest_Direction_RawValue(APBTransactionV4GetHistoryRequest *message);
/**
 * Sets the raw value of an @c APBTransactionV4GetHistoryRequest's @c direction property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4GetHistoryRequest_Direction_RawValue(APBTransactionV4GetHistoryRequest *message, int32_t value);

#pragma mark - APBTransactionV4GetHistoryResponse

typedef GPB_ENUM(APBTransactionV4GetHistoryResponse_FieldNumber) {
  APBTransactionV4GetHistoryResponse_FieldNumber_Result = 1,
  APBTransactionV4GetHistoryResponse_FieldNumber_ItemsArray = 2,
};

@interface APBTransactionV4GetHistoryResponse : GPBMessage

@property(nonatomic, readwrite) APBTransactionV4GetHistoryResponse_Result result;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<APBTransactionV4HistoryItem*> *itemsArray;
/** The number of items in @c itemsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger itemsArray_Count;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4GetHistoryResponse's @c result property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4GetHistoryResponse_Result_RawValue(APBTransactionV4GetHistoryResponse *message);
/**
 * Sets the raw value of an @c APBTransactionV4GetHistoryResponse's @c result property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4GetHistoryResponse_Result_RawValue(APBTransactionV4GetHistoryResponse *message, int32_t value);

#pragma mark - APBTransactionV4SubmitTransactionRequest

typedef GPB_ENUM(APBTransactionV4SubmitTransactionRequest_FieldNumber) {
  APBTransactionV4SubmitTransactionRequest_FieldNumber_Transaction = 1,
  APBTransactionV4SubmitTransactionRequest_FieldNumber_InvoiceList = 2,
  APBTransactionV4SubmitTransactionRequest_FieldNumber_Commitment = 3,
};

@interface APBTransactionV4SubmitTransactionRequest : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4Transaction *transaction;
/** Test to see if @c transaction has been set. */
@property(nonatomic, readwrite) BOOL hasTransaction;

/**
 * An optional invoice list associating each operation with an invoice.
 *
 * If an invoice list is included, it is expected that the foreign key in
 * the transaction memo is the SHA-224 hash of the serialized invoice list.
 *
 * The invoice list will be included in webhook calls for the application the
 * transaction pertains to (as specified by the memo app index).
 *
 * The submitted invoice data will only be available for retrieval from the service it
 * was submitted to and not directly from the blockchain nor any other deployments of
 * the service.
 **/
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV3InvoiceList *invoiceList;
/** Test to see if @c invoiceList has been set. */
@property(nonatomic, readwrite) BOOL hasInvoiceList;

@property(nonatomic, readwrite) enum APBCommonV4Commitment commitment;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4SubmitTransactionRequest's @c commitment property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4SubmitTransactionRequest_Commitment_RawValue(APBTransactionV4SubmitTransactionRequest *message);
/**
 * Sets the raw value of an @c APBTransactionV4SubmitTransactionRequest's @c commitment property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4SubmitTransactionRequest_Commitment_RawValue(APBTransactionV4SubmitTransactionRequest *message, int32_t value);

#pragma mark - APBTransactionV4SubmitTransactionResponse

typedef GPB_ENUM(APBTransactionV4SubmitTransactionResponse_FieldNumber) {
  APBTransactionV4SubmitTransactionResponse_FieldNumber_Result = 1,
  APBTransactionV4SubmitTransactionResponse_FieldNumber_Signature = 2,
  APBTransactionV4SubmitTransactionResponse_FieldNumber_TransactionError = 3,
  APBTransactionV4SubmitTransactionResponse_FieldNumber_InvoiceErrorsArray = 4,
};

@interface APBTransactionV4SubmitTransactionResponse : GPBMessage

@property(nonatomic, readwrite) APBTransactionV4SubmitTransactionResponse_Result result;

/** The signature of the transaction. */
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4TransactionSignature *signature;
/** Test to see if @c signature has been set. */
@property(nonatomic, readwrite) BOOL hasSignature;

/** Present when result = FAILED. */
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4TransactionError *transactionError;
/** Test to see if @c transactionError has been set. */
@property(nonatomic, readwrite) BOOL hasTransactionError;

/** Present when result = INVOICE_ERROR. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<APBCommonV3InvoiceError*> *invoiceErrorsArray;
/** The number of items in @c invoiceErrorsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger invoiceErrorsArray_Count;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4SubmitTransactionResponse's @c result property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4SubmitTransactionResponse_Result_RawValue(APBTransactionV4SubmitTransactionResponse *message);
/**
 * Sets the raw value of an @c APBTransactionV4SubmitTransactionResponse's @c result property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4SubmitTransactionResponse_Result_RawValue(APBTransactionV4SubmitTransactionResponse *message, int32_t value);

#pragma mark - APBTransactionV4GetTransactionRequest

typedef GPB_ENUM(APBTransactionV4GetTransactionRequest_FieldNumber) {
  APBTransactionV4GetTransactionRequest_FieldNumber_TransactionId = 1,
  APBTransactionV4GetTransactionRequest_FieldNumber_Commitment = 2,
};

@interface APBTransactionV4GetTransactionRequest : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4TransactionId *transactionId;
/** Test to see if @c transactionId has been set. */
@property(nonatomic, readwrite) BOOL hasTransactionId;

@property(nonatomic, readwrite) enum APBCommonV4Commitment commitment;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4GetTransactionRequest's @c commitment property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4GetTransactionRequest_Commitment_RawValue(APBTransactionV4GetTransactionRequest *message);
/**
 * Sets the raw value of an @c APBTransactionV4GetTransactionRequest's @c commitment property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4GetTransactionRequest_Commitment_RawValue(APBTransactionV4GetTransactionRequest *message, int32_t value);

#pragma mark - APBTransactionV4GetTransactionResponse

typedef GPB_ENUM(APBTransactionV4GetTransactionResponse_FieldNumber) {
  APBTransactionV4GetTransactionResponse_FieldNumber_State = 1,
  APBTransactionV4GetTransactionResponse_FieldNumber_Slot = 2,
  APBTransactionV4GetTransactionResponse_FieldNumber_Confirmations = 3,
  APBTransactionV4GetTransactionResponse_FieldNumber_Item = 4,
};

@interface APBTransactionV4GetTransactionResponse : GPBMessage

/**
 * The state of the transaction. The states are the same as
 * SubmitTransaction, with the exception of UNKNOWN, which indicates
 * that the system does not have a record of the transaction. This
 * can occur if the transaction is still pending or if it has failed.
 *
 * If the transaction state is UNKNOWN for an extended period of
 * time, it is likely that it was dropped. As a result, clients
 * should limit the total times GetTransaction is called for a
 * an UNKNOWN transaction.
 **/
@property(nonatomic, readwrite) APBTransactionV4GetTransactionResponse_State state;

/** Non-zero when state == State::SUCCESS */
@property(nonatomic, readwrite) uint64_t slot;

/**
 * The number of confirmations for the transaction.
 * The value is irrelevant when state != State::PENDING.
 **/
@property(nonatomic, readwrite) uint32_t confirmations;

/**
 * Present when state == State::SUCCESS.
 * May or may not be present in other cases.
 **/
@property(nonatomic, readwrite, strong, null_resettable) APBTransactionV4HistoryItem *item;
/** Test to see if @c item has been set. */
@property(nonatomic, readwrite) BOOL hasItem;

@end

/**
 * Fetches the raw value of a @c APBTransactionV4GetTransactionResponse's @c state property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t APBTransactionV4GetTransactionResponse_State_RawValue(APBTransactionV4GetTransactionResponse *message);
/**
 * Sets the raw value of an @c APBTransactionV4GetTransactionResponse's @c state property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetAPBTransactionV4GetTransactionResponse_State_RawValue(APBTransactionV4GetTransactionResponse *message, int32_t value);

#pragma mark - APBTransactionV4HistoryItem

typedef GPB_ENUM(APBTransactionV4HistoryItem_FieldNumber) {
  APBTransactionV4HistoryItem_FieldNumber_TransactionId = 1,
  APBTransactionV4HistoryItem_FieldNumber_Cursor = 2,
  APBTransactionV4HistoryItem_FieldNumber_SolanaTransaction = 3,
  APBTransactionV4HistoryItem_FieldNumber_StellarTransaction = 4,
  APBTransactionV4HistoryItem_FieldNumber_TransactionError = 5,
  APBTransactionV4HistoryItem_FieldNumber_PaymentsArray = 6,
  APBTransactionV4HistoryItem_FieldNumber_InvoiceList = 7,
};

typedef GPB_ENUM(APBTransactionV4HistoryItem_RawTransaction_OneOfCase) {
  APBTransactionV4HistoryItem_RawTransaction_OneOfCase_GPBUnsetOneOfCase = 0,
  APBTransactionV4HistoryItem_RawTransaction_OneOfCase_SolanaTransaction = 3,
  APBTransactionV4HistoryItem_RawTransaction_OneOfCase_StellarTransaction = 4,
};

@interface APBTransactionV4HistoryItem : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4TransactionId *transactionId;
/** Test to see if @c transactionId has been set. */
@property(nonatomic, readwrite) BOOL hasTransactionId;

/** The cursor position of this item. */
@property(nonatomic, readwrite, strong, null_resettable) APBTransactionV4Cursor *cursor;
/** Test to see if @c cursor has been set. */
@property(nonatomic, readwrite) BOOL hasCursor;

/** The raw transaction primitive for the transaction. */
@property(nonatomic, readonly) APBTransactionV4HistoryItem_RawTransaction_OneOfCase rawTransactionOneOfCase;

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4Transaction *solanaTransaction;

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4StellarTransaction *stellarTransaction;

/** Present if the transaction failed. */
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4TransactionError *transactionError;
/** Test to see if @c transactionError has been set. */
@property(nonatomic, readwrite) BOOL hasTransactionError;

/**
 * The set of payments contained in the raw_transaction.
 *
 * Payment is an abstract view over a StellarPayment or
 * a Solana transfer. In the Stellar case, the Stellar
 * accounts will be mapped to a SolanaAccountId.
 *
 * Note: A transaction _may_ not contain any transfers, in
 * which case `payments` will be empty.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<APBTransactionV4HistoryItem_Payment*> *paymentsArray;
/** The number of items in @c paymentsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger paymentsArray_Count;

/**
 * If an invoice list was submitted with the transaction, and the transaction
 * was submitted via this instance of the service, this field will be set.
 **/
@property(nonatomic, readwrite, strong, null_resettable) APBCommonV3InvoiceList *invoiceList;
/** Test to see if @c invoiceList has been set. */
@property(nonatomic, readwrite) BOOL hasInvoiceList;

@end

/**
 * Clears whatever value was set for the oneof 'rawTransaction'.
 **/
void APBTransactionV4HistoryItem_ClearRawTransactionOneOfCase(APBTransactionV4HistoryItem *message);

#pragma mark - APBTransactionV4HistoryItem_Payment

typedef GPB_ENUM(APBTransactionV4HistoryItem_Payment_FieldNumber) {
  APBTransactionV4HistoryItem_Payment_FieldNumber_Source = 1,
  APBTransactionV4HistoryItem_Payment_FieldNumber_Destination = 2,
  APBTransactionV4HistoryItem_Payment_FieldNumber_Amount = 3,
  APBTransactionV4HistoryItem_Payment_FieldNumber_Index = 4,
};

@interface APBTransactionV4HistoryItem_Payment : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *source;
/** Test to see if @c source has been set. */
@property(nonatomic, readwrite) BOOL hasSource;

@property(nonatomic, readwrite, strong, null_resettable) APBCommonV4SolanaAccountId *destination;
/** Test to see if @c destination has been set. */
@property(nonatomic, readwrite) BOOL hasDestination;

/** Amount in quarks */
@property(nonatomic, readwrite) int64_t amount;

/** The index of the transfer within the transaction. */
@property(nonatomic, readwrite) uint32_t index;

@end

#pragma mark - APBTransactionV4Cursor

typedef GPB_ENUM(APBTransactionV4Cursor_FieldNumber) {
  APBTransactionV4Cursor_FieldNumber_Value = 1,
};

@interface APBTransactionV4Cursor : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *value;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
